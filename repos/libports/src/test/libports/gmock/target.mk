TARGET = gmock

GMOCK_DIR := $(call select_from_ports,googletest)/src/lib/googletest/googlemock
GTEST_DIR := $(call select_from_ports,googletest)/src/lib/googletest/googletest

SRC_CC = gmock_test.cc gtest_main.cc

vpath gmock_test.cc $(GMOCK_DIR)/test
vpath gtest_main.cc $(GTEST_DIR)/src

INC_DIR += $(GMOCK_DIR) $(GTEST_DIR)
CC_OPT  += -DGTEST_HAS_PTHREAD=0

LIBS = config_args stdcxx gtest gmock
