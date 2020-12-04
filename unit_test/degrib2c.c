/** @file
 *  @author Vuong @date 2020-12-03
 *
 *   This program tests G2C library by calling number of routines
 *   to read GRIB2 file and makes an inventory of GRIB2 file.
 *   The inventory will displays: 
 *   -SECTION 0, 1
 *   -Grid Definition in section 3 (GDS)
 *   -Product Definition Templates (PDT) used in Section 4
 *   -Data Representation Section (DRS) in Section 5
 *   -Data Values in Data section
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "grib2.h"

int main(int argc, char *argv[])
{
      unsigned char *cgrib=0;
      g2int  listsec0[3],listsec1[13];
      g2int numlocal,numfields;
      g2int currlen=0,itot,lskip,j,n,icount,lgrib,iseek;
      g2int unpack,expand,ret,ierr;
      g2float fldmax,fldmin,sum;
      gribfield  *gfld;
      FILE  *ifl1;
      size_t  lengrib;

      g2int  msk1=32000;

      //start();
      unpack=1;
      expand=0;
      
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//  GET ARGUMENTS
      if (argc != 2) {
        printf("degrib2c:  Incorrect usage\n");
        printf("Usage: degrib2c grib2file\n");
        return 2;
      }

      ifl1=fopen(argv[1],"r");
      if ( ifl1 == 0 ) {
         perror("cannot open file:");
         return 3;
      }

      itot=0;
      icount=0;
      iseek=0;

      for (;;) {
         seekgb(ifl1,iseek,msk1,&lskip,&lgrib);
         if (lgrib == 0) break;    // end loop at EOF or problem
         if (lgrib > currlen) {
            if (cgrib!=0) free(cgrib);
            cgrib=(unsigned char *)malloc(lgrib);
            currlen=lgrib;
         }
         //call baread(ifl1,lskip,lgrib,lengrib,cgrib)
         ret=fseek(ifl1,lskip,SEEK_SET);
         lengrib=fread(cgrib,sizeof(unsigned char),lgrib,ifl1);
         if (lgrib != lengrib) {
            printf(" degrib2c: IO Error.\n");
            return 9;
         }
         iseek=lskip+lgrib;
         icount++;

         printf("\n GRIB MESSAGE  %ld starts at %ld \n\n",icount,lskip+1);

// Unpack GRIB2 field
         ierr=g2_info(cgrib,listsec0,listsec1,&numfields,&numlocal);
         if (ierr != 0) {
           printf(" ERROR querying GRIB2 message = %d\n",ierr);
           return 10;
         }
         itot=itot+numfields;
         printf("  SECTION 0:  ");
         for (j=0;j<3;j++) printf("%ld ",listsec0[j]);
         printf("\n");
         printf("  SECTION 1:  ");
         for (j=0;j<13;j++) printf("%ld ",listsec1[j]);
         printf("\n");
         printf("  Contains  %ld  Local Sections  and  %ld  data fields.\n",
                numlocal,numfields);

         for (n=0;n<numfields;n++) {
           ierr=g2_getfld(cgrib,n+1,unpack,expand,&gfld);
           if (ierr != 0) {
             printf(" ERROR extracting field = %d\n",ierr);
             continue;
           }

           printf("\n  FIELD  %ld\n",n+1);
           if (n==0) {
             printf("  SECTION 0:  %ld %ld\n",gfld->discipline,gfld->version);
             printf("  SECTION 1:  ");
             for (j=0;j<gfld->idsectlen;j++) printf("%ld ",gfld->idsect[j]);
             printf("\n");
           }
           if ( gfld->local!=0 && gfld->locallen>0 ) {
              printf("  SECTION 2: %d bytes\n",gfld->locallen);
              /*for (j=0;j<gfld->locallen;j++) printf("%c",gfld->local[j]);
              printf("\n");*/
           }
           printf("  SECTION 3:  %ld %ld %ld %ld %ld\n",
                    gfld->griddef,gfld->ngrdpts,gfld->numoct_opt,
                    gfld->interp_opt,gfld->igdtnum);
           printf("  GRID TEMPLATE 3. %ld :  ",gfld->igdtnum);
           for (j=0;j<gfld->igdtlen;j++) printf("%ld ",gfld->igdtmpl[j]);
           printf("\n");
           if ( gfld->num_opt == 0 ) 
             printf("  NO Optional List Defining Number of Data Points.\n");
           else {
             printf("  Section 3 Optional List: ");
             for (j=0;j<gfld->num_opt;j++) printf("%ld ",gfld->list_opt[j]);
             printf("\n");
           }
           printf("  PRODUCT TEMPLATE 4. %ld :  ",gfld->ipdtnum);
           for (j=0;j<gfld->ipdtlen;j++) printf("%ld ",gfld->ipdtmpl[j]);
           printf("\n");
           if ( gfld->num_coord == 0 )
             printf("  NO Optional Vertical Coordinate List.\n");
           else {
             printf("  Section 4 Optional Coordinates:  ");
             for (j=0;j<gfld->num_coord;j++) printf("%10.6f ",gfld->coord_list[j]);
             printf("\n");
           }

           if ( gfld->ibmap != 255 )
              printf("  Num. of Data Points =  %ld     with BIT-MAP %ld\n",
                     gfld->ndpts,gfld->ibmap);
           else
              printf("  Num. of Data Points =  %ld     NO BIT-MAP\n",gfld->ndpts);

           printf("  DRS TEMPLATE 5. %ld :  ",gfld->idrtnum);
           for (j=0;j<gfld->idrtlen;j++) printf("%ld ",gfld->idrtmpl[j]);
           printf("\n");
           //printf(" SAGlist:   ");
           //for (j=0;j<100;j++) printf("%f ",gfld->fld[j]);
           //printf("\n");

           fldmax=gfld->fld[0];
           fldmin=gfld->fld[0];
           sum=gfld->fld[0];
           for (j=1;j<gfld->ndpts;j++) {
             if (gfld->fld[j] > fldmax) fldmax=gfld->fld[j];
             if (gfld->fld[j] < fldmin) fldmin=gfld->fld[j];
             sum=sum+gfld->fld[j];
           }
           printf("  Data Values:\n");
           printf("  MIN=%21.8f  AVE=%21.8f  MAX=%21.8f\n",
                  fldmin,sum/gfld->ndpts,fldmax);

           g2_free(gfld);
         }

      }

      printf("\n");
      printf("  Total number of fields found = %ld \n",itot);
      //summary();
      printf("\n");
}
