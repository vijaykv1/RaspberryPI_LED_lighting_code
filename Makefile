#######################################################################
#Description  Makefile to create a Gertboard Application in RaspberryPI
#	            Cross Compilation GCC switch performed here.
#
#Authors      Priya Chandanshive , Varun Vijaykumar
#
#Date 	      24 Nov 2015
########################################################################

#Flag set
CC = arm-linux-gnueabihf-gcc
SOURCES=./src/blink.c
LDIR = ./lib/
IDIR = ./include/
CFLAGS = -I $(IDIR) -L $(LDIR) -l wiringPi -l wiringPiDev -o

bin = blink

$(bin) : $(SOURCES)
	$(CC) $^ $(CFLAGS) $@

clean:
	rm -vrf $(bin)
