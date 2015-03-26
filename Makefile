#-------------------------------------------------
#                    VARIABLES                    
#-------------------------------------------------
CC = gcc
CFLAGS = -g -Wall -pedantic -std=c99 -Iinclude/
LFLAGS = -L$(DIR_LIB)
EXEC = test_lib
DEBUG = 0

DIR_INCLUDE = include/
DIR_SRC = src/
DIR_LIB = lib/
DIR_TGT = target/

LFLAGS = -L$(DIR_LIB)
LIBS = -ltokenize

OBJS = $(DIR_TGT)main.o $(DIR_TGT)struct.o

#-------------------------------------------------
#                     LINKINGS                    
#-------------------------------------------------
all: $(EXEC)

test_lib: $(OBJS) $(DIR_LIB)libtokenize.dylib
	@echo ------------- Generating $@ -------------
	$(CC) -o $(DIR_TGT)$@ $(OBJS) $(LFLAGS) $(LIBS)
	@echo -e
	
#-------------------------------------------------
#                   DEPENDENCIES                  
#-------------------------------------------------

$(DIR_TGT)main.o: $(DIR_INCLUDE)read_word.h $(DIR_INCLUDE)struct.h
$(DIR_TGT)struct.o: $(DIR_INCLUDE)struct.h

#--------------
#		Global	
#--------------
$(DIR_TGT)%.o: $(DIR_SRC)%.c
	@echo ------------- Generating $@ -------------
	$(CC) -o $@ -c $< $(CFLAGS)
	@echo -e

#-------------------------------------------------
#                     CLEANING                    
#-------------------------------------------------

clean:
	rm -f $(DIR_TGT)*
	
