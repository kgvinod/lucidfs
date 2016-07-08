#
# 'make'        build executable file 'lucidfstest'
# 'make clean'  removes all .o and executable files
#

# Compiler to use
CC = g++

# Compile-time flags
CFLAGS = -Wall -g -std=c++11

# Include paths
INCLUDES = -I.

# Library paths 
#LFLAGS = 

# Libraries to link into executable
#LIBS = -lpthread

# Source files
SRCS = main.cpp fsnode.cpp dirfsnode.cpp filefsnode.cpp lnkfsnode.cpp lucidfs.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# define the executable file 
MAIN = lucidfstest


.PHONY: clean

all:$(MAIN)

$(MAIN):$(OBJS) 
	$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS)

# Suffix replacement rule 
.cpp.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@

clean:
	$(RM) *.o *~ $(MAIN)

