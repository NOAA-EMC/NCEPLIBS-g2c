/** @file
 *
 * @brief This file reads the GRIB2 XML files.
 * @author Ed Hartnett @date 8/25/22
 */

#include <libxml/tree.h>
#include <libxml/parser.h>
#include <grib2_int.h>

/** Contains the parsed XML document. */
xmlDocPtr doc;

#define G2C_MAX_GRIB_DESC_LEN 40 /**< Maximum length of code description. */
#define G2C_MAX_GRIB_STATUS_LEN 40 /**< Maximum length of code status. */
#define G2C_MAX_GRIB_CODE_LEN 10 /**< Maximum length of code. */
#define G2C_MAX_GRIB_TITLE_LEN 80 /**< Maximum length of code table title. */

/** An entry in a GRIB2 code table. */
typedef struct g2c_entry
{
    struct g2c_entry *next;
    char desc[G2C_MAX_GRIB_DESC_LEN + 1];
    char status[G2C_MAX_GRIB_STATUS_LEN + 1];
    char code[G2C_MAX_GRIB_CODE_LEN + 1];
} G2C_CODE_ENTRY_T;

/** A GRIB2 code table. */
typedef struct g2c_code_table
{
    struct g2c_code_table *next;
    char title[G2C_MAX_GRIB_TITLE_LEN + 1];
    G2C_CODE_ENTRY_T *entry;
} G2C_CODE_TABLE_T;

/* static void */
/* print_element_names(xmlNode *a_node) */
/* { */
/*     xmlNode *cur_node = NULL; */

/*     for (cur_node = a_node; cur_node; cur_node = cur_node->next) */
/*     { */
/* 	if (cur_node->type == XML_ELEMENT_NODE) */
/* 	    printf("node type: Element, name: %s\n", cur_node->name); */
/* 	print_element_names(cur_node->children); */
/*     } */
/* } */

/**
 * Init.
 *
 * @return
 * - ::G2C_NOERROR No error.
 *
 * @author Ed Hartnett @date 8/26/22
 */
int
g2c_xml_init()
{
    xmlNode *root_element = NULL;    
    xmlNode *cur;
    xmlChar *key;
	
    doc = xmlReadFile("CodeFlag.xml", NULL, 0);
	
    if (doc == NULL )
    {
	fprintf(stderr,"Document not parsed successfully. \n");
	return G2C_EXML;
    }
    root_element = xmlDocGetRootElement(doc);
    printf("root_element: %s\n", root_element->name);
    cur = root_element->xmlChildrenNode;
    while (cur)
    {
	xmlNode *child = cur->xmlChildrenNode;
	while (child)
	{
	    if ((!xmlStrcmp(child->name, (const xmlChar *)"Title_en"))) {
		key = xmlNodeListGetString(doc, child->xmlChildrenNode, 1);
		printf("title: %s\n", key);
		xmlFree(key);
	    }
	    if ((!xmlStrcmp(child->name, (const xmlChar *)"CodeFlag"))) {
		key = xmlNodeListGetString(doc, child->xmlChildrenNode, 1);
		printf("code: %s\n", key);
		xmlFree(key);
	    }
	    if ((!xmlStrcmp(child->name, (const xmlChar *)"MeaningParameterDescription_en"))) {
		key = xmlNodeListGetString(doc, child->xmlChildrenNode, 1);
		printf("description: %s\n", key);
		xmlFree(key);
	    }
	    if ((!xmlStrcmp(child->name, (const xmlChar *)"Status"))) {
		key = xmlNodeListGetString(doc, child->xmlChildrenNode, 1);
		printf("status: %s\n", key);
		xmlFree(key);
	    }
	    child = child->next;
	}
	
	cur = cur->next;
    }
    
    /* print_element_names(root_element); */
    
    xmlFreeDoc(doc);
    xmlCleanupParser();

    return G2C_NOERROR;
}
