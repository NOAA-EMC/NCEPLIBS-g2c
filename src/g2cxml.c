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

/** Pointer to the list of code tables. */
G2C_CODE_TABLE_T *g2c_table = NULL;

/** Print the table data.
 *
 * @author Ed Hartnett @date 8/28/22
 */
void
g2c_print_tables()
{
    G2C_CODE_TABLE_T *t;

    for (t = g2c_table; t; t = t->next)
    {
	G2C_CODE_ENTRY_T *e;
	
	printf("%s\n", t->title);
	for (e = t->entry; e; e = e->next)
	    printf("code %s desc %s status %s\n", e->code, e->desc, e->status);
	
    }
}

/** Free table memory.
 *
 * @author Ed Hartnett @date 8/28/22
 */
void
g2c_free_tables()
{
    G2C_CODE_TABLE_T *t, *the_next = NULL;

    /* If g2c_table is NULL, then tables have already been
     * freed. */
    if (!g2c_table)
	return;

    /* Free each table. */
    for (t = g2c_table; t; t = the_next)
    {
	G2C_CODE_ENTRY_T *e;
	G2C_CODE_ENTRY_T *e_next;

	/* Free each entry in the table. */
	the_next = t->next;
	for (e = t->entry; e; e = e_next)
	{
	    e_next = e->next;
	    free(e);
	}

	free(t);
    }

    /* Set to NULL so we all know g2c_table has been freed. */
    g2c_table = NULL;
}

/** Given a table title and a code, find a description.
 *
 * @param title Title of table.
 * @param code Code to search for.
 * @param desc Pointer that gets a copy of the description. Must be
 * allocated to ::G2C_MAX_GRIB_DESC_LEN + 1.
 *
 * @author Ed Hartnett @date 8/28/22
 *
 * @return 0 for success, error code otherwise.
 */
int
g2c_find_desc_str(char *title, char *code, char *desc)
{
    G2C_CODE_TABLE_T *t = NULL;
    int found = 0;

    /* Check inputs. */
    if (!title || strlen(title) > G2C_MAX_GRIB_TITLE_LEN
	|| !code || strlen(code) > G2C_MAX_GRIB_CODE_LEN || !desc)
	return G2C_EINVAL;
    
    /* Find table. */
    for (t = g2c_table; !found && t; t = t->next)
    {
	if (!strncmp(title, t->title, strlen(title)))
	{
	    G2C_CODE_ENTRY_T *e = NULL;
	    
	    /* Find entry. */
	    for (e = t->entry; e; e = e->next)
	    {
		if (!strncmp(code, e->code, strlen(code)))
		{
		    strcpy(desc, e->desc);
		    found++;
		    break;
		}
	    }
	}
    }

    if (!found)
	return G2C_ENOTFOUND;
    
    return G2C_NOERROR;
}

/** Given a table title and an integer code, find a description.
 *
 * @param title Title of table.
 * @param code Code to search for as an int.
 * @param desc Pointer that gets a copy of the description. Must be
 * allocated to ::G2C_MAX_GRIB_DESC_LEN + 1.
 *
 * @author Ed Hartnett @date 8/28/22
 *
 * @return 0 for success, error code otherwise.
 */
int
g2c_find_desc(char *title, int code, char *desc)
{
    char str_code[G2C_MAX_GRIB_CODE_LEN + 1];

    sprintf(str_code, "%d", code);
    return g2c_find_desc_str(title, str_code, desc);
}

/** Find a table given a key.
 *
 * @param key The table title to find.
 *
 * @author Ed Hartnett @date 8/28/22
 *
 * @return a pointer to the matching code table, or NULL if not found.
 */
G2C_CODE_TABLE_T *
g2c_find_table(char *key)
{
    G2C_CODE_TABLE_T *g;

    for (g = g2c_table; g; g = g->next)
	if (!strncmp(key, g->title, G2C_MAX_GRIB_TITLE_LEN))
	    return g;

    return NULL;
}

/** Find an entry in a table given a description.
 *
 * @param desc The description of the entry to find.
 * @param table A pointer to the table to search.
 *
 * @author Ed Hartnett @date 8/29/22
 *
 * @return a pointer to the matching entry, or NULL if not found.
 */
G2C_CODE_ENTRY_T *
g2c_find_entry(char *desc, G2C_CODE_TABLE_T *table)
{
    G2C_CODE_ENTRY_T *e;

    for (e = table->entry; e; e = e->next)
	if (!strncmp(desc, e->desc, G2C_MAX_GRIB_DESC_LEN))
	    return e;

    return NULL;
}

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
    xmlNode *cur;
    xmlChar *key;
    G2C_CODE_TABLE_T *my_table = NULL;
    G2C_CODE_ENTRY_T *new_entry = NULL;

    /* If g2c_table is not NULL, then tables have already been
     * initialized. */
    if (g2c_table)
	return G2C_NOERROR;

    /* Ingest the XML document. */
    if (!(doc = xmlReadFile("CodeFlag.xml", NULL, 0)))
	return G2C_EXML;

    /* Go through the document and save table data. */
    cur = xmlDocGetRootElement(doc)->xmlChildrenNode;
    while (cur)
    {
	xmlNode *child = cur->xmlChildrenNode;

	/* Each child at this level is a table of codes. */
	while (child)
	{
	    G2C_CODE_TABLE_T *new_table = NULL;
	    
	    if ((!xmlStrcmp(child->name, (const xmlChar *)"Title_en")))
	    {
		key = xmlNodeListGetString(doc, child->xmlChildrenNode, 1);
		if (strlen((char *)key) > G2C_MAX_GRIB_TITLE_LEN)
		    return G2C_ENAMETOOLONG;
		if (!(my_table = g2c_find_table((char *)key)))
		{
		    if (!(new_table = calloc(1, sizeof(G2C_CODE_TABLE_T))))
			return G2C_ENOMEM;
		    strncpy(new_table->title, (char *)key, G2C_MAX_GRIB_TITLE_LEN);
		    /* printf("title: %s\n", key); */
		    my_table = new_table;
		}
		xmlFree(key);
	    }

	    if (my_table)
	    {
		if ((!xmlStrcmp(child->name, (const xmlChar *)"CodeFlag")))
		{
		    G2C_CODE_ENTRY_T *e;
		    
		    if (!(new_entry = calloc(1, sizeof(G2C_CODE_ENTRY_T))))
			return G2C_ENOMEM;
		    if (child->xmlChildrenNode)
		    {
			key = xmlNodeListGetString(doc, child->xmlChildrenNode, 1);
			if (strlen((char *)key) > G2C_MAX_GRIB_CODE_LEN)
			    return G2C_ENAMETOOLONG;
			strncpy(new_entry->code, (char *)key, G2C_MAX_GRIB_CODE_LEN);
			/* printf("code: %s\n", key); */
			xmlFree(key);
		    }

		    /* Add entry at end of list. */
		    if (my_table->entry)
		    {
			for (e = my_table->entry; e->next; e = e->next)
			    ;
			e->next = new_entry;
		    }
		    else
			my_table->entry = new_entry;
		}
		if ((!xmlStrcmp(child->name, (const xmlChar *)"MeaningParameterDescription_en")))
		{
		    key = xmlNodeListGetString(doc, child->xmlChildrenNode, 1);
		    if (strlen((char *)key) > G2C_MAX_GRIB_DESC_LEN)
			return G2C_ENAMETOOLONG;
		    if (!new_entry)
			return G2C_EXML;
		    strncpy(new_entry->desc, (char *)key, G2C_MAX_GRIB_DESC_LEN);
		    /* printf("description: %s\n", key); */
		    xmlFree(key);
		}
		if ((!xmlStrcmp(child->name, (const xmlChar *)"Status")))
		{
		    key = xmlNodeListGetString(doc, child->xmlChildrenNode, 1);
		    if (strlen((char *)key) > G2C_MAX_GRIB_STATUS_LEN)
			return G2C_ENAMETOOLONG;
		    if (!new_entry)
			return G2C_EXML;
		    strncpy(new_entry->status, (char *)key, G2C_MAX_GRIB_STATUS_LEN);
		    /* printf("status: %s\n", key); */
		    xmlFree(key);
		}
	    }

	    /* Move to next node of XML document. */
	    child = child->next;

	    /* Add this table to our list of GRIB tables. */
	    if (new_table)
	    {
		if (!g2c_table)
		    g2c_table = new_table;
		else
		{
		    G2C_CODE_TABLE_T *g = g2c_table;
		    
		    /* Go to end of list and add the table. */
		    if (g)
		    {
			for (; g->next; g = g->next)
			    ;
			g->next = new_table;
		    }
		    else
		    {
			g2c_table = new_table;
		    }
		}
		new_table = NULL;
	    }
	}
	
	cur = cur->next;
    }


    /* Uncomment this to see the tables. */
    /* g2c_print_tables(); */

    xmlFreeDoc(doc);
    xmlCleanupParser();

    return G2C_NOERROR;
}
