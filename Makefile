# ----------------------------------------------------------------------------
#   Ludil - Scheme/C game programming framework
#   Copyright (C) 2010,2011 Josef P. Bernhart <bernhartjp@yahoo.de>
#
#   This program is free software: you can redistribute it and/or modify
#   it under the terms of the GNU General Public License as published by
#   the Free Software Foundation, either version 3 of the License, or
#   (at your option) any later version.
#
#   This program is distributed in the hope that it will be useful,
#   but WITHOUT ANY WARRANTY; without even the implied warranty of
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#   GNU General Public License for more details.
#
#   You should have received a copy of the GNU General Public License
#   along with this program.  If not, see <http://www.gnu.org/licenses/>.
#
# ----------------------------------------------------------------------------

# ----------------------------------------------------------------------------
# This file was written for:
# GNU Make 4.0
# ----------------------------------------------------------------------------
 

# Variables 
# ----------------------------------------------------------------------------
PROJ_NAME = ludil
PROJ_VERSION = 0.1

PROJ_SRC = src
PROJ_OBJ = obj
PROJ_LIB = lib
PROJ_INC = inc
PROJ_DOC = doc
PROJ_BIN = bin

# Important compilation variables
CC = gcc
CFLAGS = -Wall -Werror -I$(PROJ_INC) -L$(PROJ_LIB) -ldl -lpthread -fPIC

# For compiling shared libraries
LIBCC = $(CC) $(CFLAGS) -shared -o 

LINE = ---------------------------------------------------------------------------

base_lib = $(PROJ_NAME)Basic
base_lib_full = $(PROJ_LIB)/lib$(base_lib).so
# ----------------------------------------------------------------------------


# Reset the search path to nothingv
# ----------------------------------------------------------------------------
vpath
vpath %.h $(PROJ_INC)
vpath %.so $(PROJ_LIB)
# ----------------------------------------------------------------------------

.PHONY: all base_lib libs clean base_tests

all: libs 

libs: base_lib base_tests

base_lib: $(base_lib_full)

# ----------------------------------------------------------------------------
# implicit rules
# ----------------------------------------------------------------------------
%.o : %.c

$(PROJ_OBJ)/%.o: $(PROJ_SRC)/%.c
	$(CC) -c $(CFLAGS) -o $@ $<


# ----------------------------------------------------------------------------
# specific rules
# ----------------------------------------------------------------------------

# Base module library rules
# ----------------------------------------------------------------------------
base_names = Memory \
						 Point \
						 Io \
						 String \
						 Bitmask \
						 Blob \
						 Kernel

base_obj_pattern = $(PROJ_OBJ)/$(PROJ_NAME)Basic$(name).o
base_objs := $(foreach name,$(base_names),$(base_obj_pattern))

base_inc_pattern = $(PROJ_NAME)$(name).h
base_incs := $(foreach name,$(base_names),$(base_inc_pattern))
					
base_files = $(base_objs) $(base_incs)

$(base_lib_full): $(base_files)
	@echo $(LINE)
	@echo "Making base module library"
	@echo $(LINE)
	$(CC) -shared -fPIC -o $@ $(base_objs)
# ----------------------------------------------------------------------------

# Tests for base module library
# ----------------------------------------------------------------------------
base_test_pattern = $(PROJ_BIN)/$(PROJ_NAME)Basic$(name)Test
base_test_bins := $(foreach name,$(base_names),$(base_test_pattern))

base_test_files = $(base_test_bins)
base_test_opts = $(PROJ_OBJ)/$(PROJ_NAME)Test.o lib$(base_lib).so

$(PROJ_BIN)/$(PROJ_NAME)Basic%Test: $(PROJ_OBJ)/$(PROJ_NAME)Basic%Test.o $(base_test_opts)
	$(CC) $(CFLAGS) -o $@ $< -l$(base_lib) $(PROJ_OBJ)/$(PROJ_NAME)Test.o

base_tests: $(base_test_files)
# ----------------------------------------------------------------------------


clean:
	rm -f $(PROJ_LIB)/*.so
	rm -f $(PROJ_OBJ)/*.o
	rm -f $(PROJ_BIN)/*
