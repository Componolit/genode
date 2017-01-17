TARGET = gtest

GTEST_DIR := $(call select_from_ports,googletest)/src/lib/googletest/googletest

SRC_CC = gtest_main.cc gtest_all_test.cc

vpath gtest_main.cc     $(GTEST_DIR)/src
vpath gtest_all_test.cc $(GTEST_DIR)/test

INC_DIR += $(GTEST_DIR)

LIBS = config_args stdcxx gtest
