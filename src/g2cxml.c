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

    doc = xmlReadFile("CodeFlag.xml", NULL, 0);
	
    if (doc == NULL )
    {
	fprintf(stderr,"Document not parsed successfully. \n");
	return G2C_EXML;
    }
    root_element = xmlDocGetRootElement(doc);
    printf("root_element: %s\n", root_element->name);
    
    /* print_element_names(root_element); */
    
    xmlFreeDoc(doc);
    xmlCleanupParser();

    return G2C_NOERROR;
}
