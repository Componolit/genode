GMOCK_DIR := $(call select_from_ports,googletest)/src/lib/googletest/googlemock
GTEST_DIR := $(call select_from_ports,googletest)/src/lib/googletest/googletest

SHARED_LIB = yes

SRC_CC = $(GMOCK_DIR)/src/gmock-all.cc

vpath %.cc += $(GMOCK_DIR)

INC_DIR += $(GMOCK_DIR)
INC_DIR += $(GMOCK_DIR)/include
INC_DIR += $(GMOCK_DIR)/include/internal

INC_DIR += $(GTEST_DIR)/include
INC_DIR += $(GTEST_DIR)/include/internal

CC_OPT += -DGTEST_HAS_PTHREAD=0
CC_OPT += -DGTEST_HAS_RTTI=0

LIBS += stdcxx
