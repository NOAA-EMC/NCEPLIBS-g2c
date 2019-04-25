
   A=Sigio     ;     B=Landsfcutil
   A=Bufr      ;     B=Sp
   A=Sp        ;     B=W3nco
   A=W3nco     ;     B=Nemsio
   A=Nemsio    ;     B=Nemsiogfs
   A=Nemsiogfs ;     B=W3emc
   A=W3emc     ;     B=G2
   A=G2        ;     B=G2c

 mv ${A}_gnu_General.sh   ${B}_gnu_General.sh
 mv ${A}_intel_Cray.sh    ${B}_intel_Cray.sh
 mv ${A}_intel_Dell.sh    ${B}_intel_Dell.sh
 mv ${A}_intel_General.sh ${B}_intel_General.sh
 mv ${A}_intel_Theia.sh   ${B}_intel_Theia.sh
 mv ${A}_intel_Wcoss.sh   ${B}_intel_Wcoss.sh

