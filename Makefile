#project name 
PROJECT_NAME = application

#microcontroller used
MMCU = atmega328p

#Compiler 
CC = avr-gcc

#Object copy 
OBJCOPY = avr-objcopy

#Source directory
SOURCE_DIR = ./src

#include directory
INCLUDE_DIR = ./include

#build directory
BUILD_DIR = ./build

#out directory 
OUT_DIR = ./bin

#Source files 
vpath %.c $(SOURCE_DIR)/test:$(SOURCE_DIR)/drivers

#compiler flags
COMPILER_FLAGS = -O2 -mmcu=$(MMCU) 

#compiling c files and storing object files into the build folder
%.o : %.c  
	$(CC) -c $(COMPILER_FLAGS) -I $(INCLUDE_DIR) -o $(BUILD_DIR)/$@ $<

#linking object files and generating hex files
application : $(wildcard $(BUILD_DIR)/*.o)
	$(CC) -g -mmcu=$(MMCU) -o $(OUT_DIR)/$(PROJECT_NAME).elf $^
	$(OBJCOPY) -j .text -j .data -j .rodata -O ihex $(OUT_DIR)/$(PROJECT_NAME).elf $(OUT_DIR)/$(PROJECT_NAME).hex


