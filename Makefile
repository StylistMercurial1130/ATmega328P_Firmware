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
COMPILER_FLAGS = -O1 -mmcu=$(MMCU) 

#compiling c files and storing object files into the build folder
%.o : %.c  
	@echo "Compiling"
	$(CC) -c $(COMPILER_FLAGS) -I $(INCLUDE_DIR) -o $(BUILD_DIR)/$@ $<

#linking object files and generating hex files
% : $(wildcard $(BUILD_DIR)/*.o)
	@echo "Linking"
	$(CC) -g -o $(OUT_DIR)/$@.elf $^
	@echo "Generating hex file"
	$(OBJCOPY) -O ihex $(OUT_DIR)/$@.elf $(OUT_DIR)/$@.hex


