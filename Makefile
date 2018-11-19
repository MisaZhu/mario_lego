ifeq ($(CROSS_COMPILE),)
CROSS_COMPILE=arm-none-linux-gnueabi-
endif

ifeq ($(MARIO_LANG),)
MARIO_LANG = js
endif

ifeq ($(MARIO_VM),)
MARIO_VM = ../../mario_vm/vm
endif

CC := $(CROSS_COMPILE)g++
CXX := $(CROSS_COMPILE)g++
AR := $(CROSS_COMPILE)ar
LD := $(CROSS_COMPILE)g++

mario_OBJS= $(MARIO_VM)/mario_utils.o $(MARIO_VM)/mario_bc.o $(MARIO_VM)/mario_vm.o $(MARIO_VM)/mario_lex.o

OBJS= $(mario_OBJS) \
	src/native_ev3.o \
	src/Ports.o \
	src/Port.o \
	src/Sound.o \
	src/Motor.o \
	src/DCMotor.o \
	src/ServoMotor.o \
	src/Ultrasonic.o \
	src/Infrared.o \
	src/Button.o \
	src/Remote.o \
	src/Touch.o \
	src/Gyro.o \
	src/ColorSensor.o \
	src/ev3dev.o


CXXFLAGS =  -I$(MARIO_VM) -g -Wall -DMARIO_DEBUG -DMARIO_CACHE -fPIC -std=c++0x  -I. -DEV3DEV_PLATFORM=EV3
LDFLAGS = -lstdc++

CXXFLAGS +=  -DMARIO_THREAD
LDFLAGS += -lpthread

CFLAGS =  $(CXXFLAGS)

NAME=lego_ev3
TARGET=native_$(NAME).so
INST_DST=/usr/local/mario

all: $(OBJS)
	$(LD) -shared -o $(TARGET) $(OBJS) $(LDFLAGS)

clean:
	rm -fr $(TARGET) $(OBJS) *.dSYM

install:
	mkdir -p $(INST_DST)/natives
	cp $(TARGET) $(INST_DST)/natives
	mkdir -p $(INST_DST)/test/$(MARIO_LANG)/$(NAME)
	cp test/$(MARIO_LANG)/* $(INST_DST)/test/$(MARIO_LANG)/$(NAME)
