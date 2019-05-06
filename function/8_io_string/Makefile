#CC	= aarch64-linux-gnu-gcc
#LD	= aarch64-linux-gnu-gcc
#AR	= aarch64-linux-gnu-ar

CC	= g++
LD	= g++
AR	= ar

INC_DIR := ./inc
LIB_DIR := ./lib/
COMMON_INC = ../common/include/     
COMMON_SRC = ../common/lib/
#LIB = $(COMMON_SRC)/libsdsicommon.a $(COMMON_SRC)/libi2c.a
#INSTALL_DIR =  ../../../Platform/trunk/lightspeed_platform/images/ls30/lightspeed/
OBJ_DIR   = ./

CFLAGS = -g -O2 -Wall -std=c++11 -I$(INC_DIR) -I$(COMMON_INC) -I$(LIB_DIR) -lpthread
#
# the objects are defined here.
#
TARGET=func
SRCS = ./main.cpp                 \


TEMOBJS := $(SRCS:.c=.o)
OBJS = $(addprefix $(OBJ_DIR), $(TEMOBJS))

ALLOBJS := $(wildcard ../objs/*.o)
ALLOBJS	+= $(OBJS)
#$(ALIBS)
ALIBS := $(wildcard ../lib/*.o)

#
# the rule of the compiler is in here.
#

all:$(TARGET)

$(TARGET):$(OBJS)
	$(LD) $(OBJS) $(CFLAGS) -L$(LIB_DIR)  $(LIB) $(LDFLAGS) -o $@ 
	chmod a+x $@
$(OBJ_DIR)%.o:%.cpp
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	rm -rf  $(TARGET) 

