SHELL=/bin/sh
#

SRCS=   degrib2c.c
OBJS=   degrib2c.o

# Tunable parameters
#
# CF		Name of the fortran compiling system to use
# LDFLAGS	Flags to the loader
# LIBS		List of libraries
# CMD		Name of the executable
# PROFLIB	Library needed for profiling
#
CF = icc
LDFLAGS =   -p
INC=/gpfs/dell2/emc/modeling/noscrub/Boi.Vuong/g2c/NCEPLIBS-g2c/src
G2C_LIB4=/gpfs/dell2/emc/modeling/noscrub/Boi.Vuong/g2c/lib/libg2c.a

LIBS=-lm ${G2C_LIB4} ${JASPER_LIB} ${PNG_LIB} ${Z_LIB}

CMD =		degrib2c
PROFLIB =	-lprof

# To perform the default compilation, use the first line
# To compile with flowtracing turned on, use the second line
# To compile giving profile additonal information, use the third line
# WARNING:  SIMULTANEOUSLY PROFILING AND FLOWTRACING IS NOT RECOMMENDED 
CFLAGS =	 -g -O3  -m64 -D__64BIT__

#FFLAGS =	 -F
#FFLAGS =	 -Wf"-ez"

# Lines from here on down should not need to be changed.  They are the
# actual rules which make uses to build a.out.
#
all:		degrib2c

degrib2c.o:	degrib2c.c
	$(CF) -c $(CFLAGS) -I $(INC) degrib2c.c

degrib2c:		degrib2c.o
	$(CF) $(LDFLAGS) -o $(@) degrib2c.o $(LIBS)

# Make the profiled version of the command and call it a.out.prof
#
$(CMD).prof:	$(OBJS)
	$(CF) $(LDFLAGS) -o $(@) $(OBJS) $(PROFLIB) $(LIBS)

clean:
	-rm -f $(OBJS)

clobber:	clean
	-rm -f $(CMD) $(CMD).prof

void:	clobber
	-rm -f $(SRCS) makefile
