#-------------------------------------------------
#                    VARIABLES                    
#-------------------------------------------------
CC = gcc
CFLAGS = -g -Wall -pedantic -std=c99 -Iinclude/
LFLAGS = -L$(DIR_LIB)
EXEC = dictionarize64 dictionarize32 dictionarize16 dictionarize8
DEBUG = 0

DIR_INCLUDE = include/
DIR_SRC = src/
DIR_LIB = lib/
DIR_TGT = target/

LFLAGS = -L$(DIR_LIB)
LIBS = -ltokenize

OBJS = $(DIR_TGT)main.o $(DIR_TGT)dictionnaire.o 

#-------------------------------------------------
#                     LINKINGS                    
#-------------------------------------------------
all: $(EXEC)

dictionarize64: $(OBJS) $(DIR_TGT)utils64.o $(DIR_TGT)maillon64.o $(DIR_TGT)mot64.o $(DIR_LIB)libtokenize.dylib
	@echo ------------- Generating $@ -------------
	$(CC) -o $(DIR_TGT)$@ $(OBJS) $(DIR_TGT)utils64.o $(DIR_TGT)maillon64.o $(DIR_TGT)mot64.o $(LFLAGS) $(LIBS)
	@echo -e

dictionarize32: $(OBJS) $(DIR_TGT)utils32.o $(DIR_TGT)maillon32.o $(DIR_TGT)mot32.o $(DIR_LIB)libtokenize.dylib
	@echo ------------- Generating $@ -------------
	$(CC) -o $(DIR_TGT)$@ $(OBJS) $(DIR_TGT)utils32.o $(DIR_TGT)maillon32.o $(DIR_TGT)mot32.o $(LFLAGS) $(LIBS)
	@echo -e

dictionarize16: $(OBJS) $(DIR_TGT)utils16.o $(DIR_TGT)maillon16.o $(DIR_TGT)mot16.o $(DIR_LIB)libtokenize.dylib
	@echo ------------- Generating $@ -------------
	$(CC) -o $(DIR_TGT)$@ $(OBJS) $(DIR_TGT)utils16.o $(DIR_TGT)maillon16.o $(DIR_TGT)mot16.o $(LFLAGS) $(LIBS)
	@echo -e

dictionarize8: $(OBJS) $(DIR_TGT)utils8.o $(DIR_TGT)maillon8.o $(DIR_TGT)mot8.o $(DIR_LIB)libtokenize.dylib
	@echo ------------- Generating $@ -------------
	$(CC) -o $(DIR_TGT)$@ $(OBJS) $(DIR_TGT)utils8.o $(DIR_TGT)maillon8.o $(DIR_TGT)mot8.o $(LFLAGS) $(LIBS)
	@echo -e

#-------------------------------------------------
#                   DEPENDENCIES                  
#-------------------------------------------------

$(DIR_TGT)main.o: $(DIR_INCLUDE)read_word.h $(DIR_INCLUDE)maillon.h $(DIR_INCLUDE)dictionnaire.h
$(DIR_TGT)dictionnaire.o: $(DIR_INCLUDE)dictionnaire.h $(DIR_INCLUDE)mot.h

#--------------
#    64bits	
#--------------

$(DIR_TGT)utils64.o: $(DIR_SRC)utils.c $(DIR_INCLUDE)utils.h
	@echo ------------- Generating $@ -------------
	$(CC) -o $@ -c -DDEBUG=$(DEBUG) -DNBL=12 $< $(CFLAGS)
	@echo -e

$(DIR_TGT)maillon64.o: $(DIR_SRC)maillon.c $(DIR_INCLUDE)maillon.h $(DIR_INCLUDE)utils.h 
	@echo ------------- Generating $@ -------------
	$(CC) -o $@ -c -DNBL=12 $< $(CFLAGS)
	@echo -e

$(DIR_TGT)mot64.o: $(DIR_SRC)mot.c $(DIR_INCLUDE)mot.h $(DIR_INCLUDE)maillon.h
	@echo ------------- Generating $@ -------------
	$(CC) -o $@ -c -DNBL=12 $< $(CFLAGS)
	@echo -e

#--------------
#    32bits	
#--------------

$(DIR_TGT)utils32.o: $(DIR_SRC)utils.c $(DIR_INCLUDE)utils.h
	@echo ------------- Generating $@ -------------
	$(CC) -o $@ -c -DDEBUG=$(DEBUG) -DNBL=6 $< $(CFLAGS)
	@echo -e

$(DIR_TGT)maillon32.o: $(DIR_SRC)maillon.c $(DIR_INCLUDE)maillon.h $(DIR_INCLUDE)utils.h 
	@echo ------------- Generating $@ -------------
	$(CC) -o $@ -c -DNBL=6 $< $(CFLAGS)
	@echo -e

$(DIR_TGT)mot32.o: $(DIR_SRC)mot.c $(DIR_INCLUDE)mot.h $(DIR_INCLUDE)maillon.h
	@echo ------------- Generating $@ -------------
	$(CC) -o $@ -c -DNBL=6 $< $(CFLAGS)
	@echo -e

#--------------
#    16bits	
#--------------

$(DIR_TGT)utils16.o: $(DIR_SRC)utils.c $(DIR_INCLUDE)utils.h
	@echo ------------- Generating $@ -------------
	$(CC) -o $@ -c -DDEBUG=$(DEBUG) -DNBL=3 $< $(CFLAGS)
	@echo -e

$(DIR_TGT)maillon16.o: $(DIR_SRC)maillon.c $(DIR_INCLUDE)maillon.h $(DIR_INCLUDE)utils.h 
	@echo ------------- Generating $@ -------------
	$(CC) -o $@ -c -DNBL=3 $< $(CFLAGS)
	@echo -e

$(DIR_TGT)mot16.o: $(DIR_SRC)mot.c $(DIR_INCLUDE)mot.h $(DIR_INCLUDE)maillon.h
	@echo ------------- Generating $@ -------------
	$(CC) -o $@ -c -DNBL=3 $< $(CFLAGS)
	@echo -e

#--------------
#    8bits	
#--------------

$(DIR_TGT)utils8.o: $(DIR_SRC)utils.c $(DIR_INCLUDE)utils.h
	@echo ------------- Generating $@ -------------
	$(CC) -o $@ -c -DDEBUG=$(DEBUG) -DNBL=1 $< $(CFLAGS)
	@echo -e

$(DIR_TGT)maillon8.o: $(DIR_SRC)maillon.c $(DIR_INCLUDE)maillon.h $(DIR_INCLUDE)utils.h 
	@echo ------------- Generating $@ -------------
	$(CC) -o $@ -c -DNBL=1 $< $(CFLAGS)
	@echo -e

$(DIR_TGT)mot8.o: $(DIR_SRC)mot.c $(DIR_INCLUDE)mot.h $(DIR_INCLUDE)maillon.h
	@echo ------------- Generating $@ -------------
	$(CC) -o $@ -c -DNBL=1 $< $(CFLAGS)
	@echo -e


#--------------
#    Global	
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
	
