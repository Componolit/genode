TARGET = gtest-samples

GTEST_DIR := $(call select_from_ports,googletest)/src/lib/googletest/googletest

INC_DIR += $(GTEST_DIR)/samples

SRC_CC = $(GTEST_DIR)/src/gtest_main.cc
SRC_CC += $(GTEST_DIR)/samples/sample1.cc
SRC_CC += $(GTEST_DIR)/samples/sample1_unittest.cc

LIBS = config_args stdcxx gtest
