
# NCEPLIBS-g2c

This library contains C decoder/encoder routines for GRIB edition 2.

This is related to the
[NCEPLIBS](https://github.com/NOAA-EMC/NCEPLIBS) project.

For complete documentation see the latest [NCEPLIBS-g2c
documentation](https://noaa-emc.github.io/NCEPLIBS-g2c/). For more
about GRIB2 see the [NCEP WMO GRIB2
Documentation](https://www.nco.ncep.noaa.gov/pmb/docs/grib2/grib2_doc/). For
the WMO GRIB2 templates and tables see [WMO Information Management
GRIB2 GitHub repository](https://github.com/wmo-im/GRIB2).

The NCEPLIBS-g2c library is used by the
[wgrib2](https://www.cpc.ncep.noaa.gov/products/wesley/wgrib2/),
[GRaDS](http://cola.gmu.edu/grads/), and [Model Evaluation Tools
(MET)](https://metplus.readthedocs.io/en/latest/) projects, among
others.

To submit bug reports, feature requests, or other code-related issues including installation and usage questions, please create a [GitHub issue](https://github.com/NOAA-EMC/NCEPLIBS-g2c/issues). For general NCEPLIBS inquiries, contact [Ed Hartnett](mailto:edward.hartnett@noaa.gov) (secondary point of contact [Alex Richert](mailto:alexander.richert@noaa.gov)).

## Related NCEPLIBS Projects

Repository | Notes
-----------|------
[NCEPLIBS-g2](https://github.com/NOAA-EMC/NCEPLIBS-g2) | Fortran implementation of the GRIB 2 functions
[NCEPLIBS-grib_util](https://github.com/NOAA-EMC/NCEPLIBS-grib_util) | A collection of GRIB1 and GRIB2 utilities
[NCEPLIBS-g2tmpl](https://github.com/NOAA-EMC/NCEPLIBS-g2tmpl) | Utilities for GRIB2 templates

## Authors

Stephen Gilbert, Wesley Ebisuzaki, Boi Vuong, Edward Hartnett

Code Manager: [Hang Lei](mailto:hang.lei@noaa.gov), [Ed Hartnett](mailto:edward.hartnett@noaa.gov)

## Prerequisites

- [libjasper.a](http://www.ece.uvic.ca/~mdadams/jasper/) - This
  library is a C implementation of the JPEG-2000 Part-1 standard
  (i.e., ISO/IEC 15444-1). Tested version: jasper-1.900.1. More
  information about JPEG2000 can be found at
  http://www.jpeg.org/JPEG2000.html.

- [libpng.a](http://www.libpng.org/pub/png/libpng.html) - This library
  is a C implementation of the Portable Network Graphics PNG image
  compression format. Tested version: libpng-1.2.44. More information
  about PNG can be found at http://www.libpng.org/pub/png/.

- [libz.a](http://www.gzip.org/zlib/) - This library contains
  compression/decompression routines used by libpng.a for PNG image
  compression support. Tested version: zlib-1.2.6.

- [openjpeg.a](https://www.openjpeg.org/) - OpenJPEG is an open-source
  JPEG 2000 codec written in C language. OpenJPEG is only used if
  CMake build option USE_OpenJPEG is turned on.

## Building

Download the tarball from the release page and unpack it, and cd into
the main directory of the library. Then run the following commands,
substituting your directory locations for the CMAKE_INSTALL_PREFIX
(where the NCEPLIBS-g2c library will be installed), and the
CMAKE_PREFIX_PATH (where the build will look for dependencies):

<pre>
mkdir build
cd build
cmake -DCMAKE_INSTALL_PREFIX=/usr/local/NCEPLIBS-g2c -DCMAKE_PREFIX_PATH=/usr/local/jasper-3.0.5 ..
make
make test
make install
</pre>

The NCEPLIBS-g2c library supports the PNG and JPEG2000 methods of image compression
algorithms within the GRIB2 standard.

By default the library uses Jasper for JPEG functionality, use the
USE_OpenJPEG to use the OpenJPEG library instead.

## References

Hartnett, E., Lei, H., Curtis, B, Gerheiser K., [Presentation -
Improving Documentation, Testing, Process, and Code for Legacy NOAA
GRIB2 C Fortran
Libraries](https://www.researchgate.net/publication/360757566_Presentation_-_Improving_Documentation_Testing_Process_and_Code_for_Legacy_NOAA_GRIB2_C_Fortran_Libraries),
NCAR Improving Scientific Software, April 2022.  .

Kumar, V. Krishna, Gilbert, Stephen A., [GRIB2 conversion and its
usage at NCEP](docs/GRIB2_conversion_and_its_usage_at_NCEP.pdf), 14-18
November 2005, 10th Workshop on Meteorological Operational Systems
ECMWF User Orientation, retrieved on July 27, 2021 from
https://www.yumpu.com/en/document/view/11925806/grib2-conversion-and-its-usage-at-ncep.

## Disclaimer

The United States Department of Commerce (DOC) GitHub project code is
provided on an "as is" basis and the user assumes responsibility for
its use. DOC has relinquished control of the information and no longer
has responsibility to protect the integrity, confidentiality, or
availability of the information. Any claims against the Department of
Commerce stemming from the use of its GitHub project will be governed
by all applicable Federal law. Any reference to specific commercial
products, processes, or services by service mark, trademark,
manufacturer, or otherwise, does not constitute or imply their
endorsement, recommendation or favoring by the Department of
Commerce. The Department of Commerce seal and logo, or the seal and
logo of a DOC bureau, shall not be used in any manner to imply
endorsement of any commercial product or activity by DOC or the United
States Government.
