@mainpage

## Introduction

This document briefly describes the routines available for
encoding/decoding GRIB Edition 2 (GRIB2) messages with the
NCEPLIBS-g2c library.

A GRIB Edition 2 message is a machine independent format for storing
one or more gridded data fields. Each GRIB2 message consists of the
following sections:

<pre>
SECTION 0 - Indicator Section
SECTION 1 - Identification Section
SECTION 2 - (Local Use Section) - optional                           }
SECTION 3 - Grid Definition Section                     }            }
SECTION 4 - Product Definition Section    }             }            }(repeated)
SECTION 5 - Data Representation Section   }             }(repeated)  }
SECTION 6 - Bit-map Section               }(repeated)   }            }
SECTION 7 - Data Section                  }             }            }
SECTION 8 - End Section                   }             }            }
</pre>

Sequences of GRIB sections 2 to 7, 3 to 7, or sections 4 to 7 may be
repeated within a single GRIB message. All sections within such
repeated sequences must be present and shall appear in the numerical
order noted above. Unrepeated sections remain in effect until
redefined.

For detailed information on GRIB2 see the [NCEP WMO GRIB2
Documentation](https://www.nco.ncep.noaa.gov/pmb/docs/grib2/grib2_doc/).

## GRIB2 Encoding Routines

Since a GRIB2 message can contain gridded fields for many parameters
on a number of different grids, several routines are used to encode a
message. This should give users more flexibility in how to organize
data within one or more GRIB2 messages.

To start a new GRIB2 message, call function g2_create(). It encodes
Sections 0 and 1 at the beginning of the message. This routine must be
used to create each message.

Function g2_addlocal() can be used to add a Local Use Section (Section
2). Note that section is optional and need not appear in a GRIB2
message.

Function g2_addgrid() is used to encode a grid definition into Section
3 - The Grid Definition Section. This grid definition defines the
geometry of the the data values in the fields that follow it. Function
addgrid() can be called again to change the grid definition describing
subsequent data fields.

Each data field is added to the GRIB2 message using routine
g2_addfield(), which adds Sections 4, 5, 6, and 7 to the message.

After all desired data fields have been added to the GRIB2 message, a
call to routine g2_gribend() is needed to add the final section 8 to the
message and to update the length of the message. A call to g2_gribend()
is required for each GRIB2 message.

## GRIB2 Decoding Routines

Function g2_info() can be used to find out how many Local Use
sections and data fields are contained in a given GRIB2 message. In
addition, this routine also returns the number of octets of the
largest Local Use section in the message.

g2_getfld() can be used to get all information pertaining to the nth
data field in the message. An option exists that lets the user decide
if the function should unpack the Bit-map (if applicable) and the
data values or just return the field description information.

## Extracting GRIB2 Fields from a GRIB2 file

Function g2_info() can be used to find out how many Local Use
sections and data fields are contained in a given GRIB2 message.

## GRIB2 Tables/Templates

NCO Provides documentation on WMO GRIB2 at
https://www.nco.ncep.noaa.gov/pmb/docs/grib2/grib2_doc/

WMO's GRIB2 specification "FM 92-XII GRIB - General
Regularly-distributed Information in Binary Form" contains
descriptions of each template and code table information. This
document can be found at https://codes.wmo.int/grib2/_codeflag (PDF
and MSWord formats are available).

## Documentation for Previous Versions of NCEPLIBS-g2c

* [NCEPLIBS-g2c Version 1.9.0](ver-1.9.0/index.html)
* [NCEPLIBS-g2c Version 1.8.0](ver-1.8.0/index.html)
* [NCEPLIBS-g2c Version 1.7.0](ver-1.7.0/index.html)
* [NCEPLIBS-g2c Version 1.6.4](ver-1.6.4/index.html)

