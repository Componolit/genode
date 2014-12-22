GTEST_DIR := $(call select_from_ports,googletest)/src/lib/googletest/googletest

SRC_CC = $(GTEST_DIR)/src/gtest-all.cc

vpath %.cc += $(GTEST_DIR)

INC_DIR += $(GTEST_DIR)
INC_DIR += $(GTEST_DIR)/include
INC_DIR += $(GTEST_DIR)/include/internal

CC_OPT += -DGTEST_HAS_PTHREAD=0
CC_OPT += -DGTEST_HAS_RTTI=0

LIBS += libc libm stdcxx
