TARGET = gmock

GMOCK_DIR := $(call select_from_ports,googletest)/src/lib/googletest/googlemock
GTEST_DIR := $(call select_from_ports,googletest)/src/lib/googletest/googletest

SRC_CC += $(GMOCK_DIR)/test/gmock_all_test.cc

INC_DIR += $(GMOCK_DIR)
INC_DIR += $(GMOCK_DIR)/include
INC_DIR += $(GMOCK_DIR)/include/internal

INC_DIR += $(GTEST_DIR)
INC_DIR += $(GTEST_DIR)/include
INC_DIR += $(GTEST_DIR)/include/internal

CC_OPT += -DGTEST_HAS_PTHREAD=0

LIBS = stdcxx config_args gtest gmock
