/** @file
 *
 * @brief This file reads the GRIB2 XML files.
 * @author Ed Hartnett @date 8/25/22
 */

#include <libxml/tree.h>
#include <libxml/parser.h>
#include <grib2_int.h>

/**
 * Init.
 *
 * @return
 * - ::G2C_NOERROR No error.
 *
 * @author Ed Hartnett @date 8/26/22
 */
int
init()
{
    xmlDocPtr doc;
    xmlNodePtr cur;

    doc = xmlParseFile("CodeFlag.xml");
	
    if (doc == NULL )
    {
	fprintf(stderr,"Document not parsed successfully. \n");
	return G2C_EXML;
    }

    cur = xmlDocGetRootElement(doc);
	
    if (cur == NULL)
    {
	fprintf(stderr,"empty document\n");
	xmlFreeDoc(doc);
	return G2C_EXML;
    }
	
    if (xmlStrcmp(cur->name, (const xmlChar *) "story")) {
	fprintf(stderr,"document of the wrong type, root node != story");
	xmlFreeDoc(doc);
	return G2C_EXML;
    }

    return G2C_NOERROR;
}
