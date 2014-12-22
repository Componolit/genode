TARGET = gtest

GTEST_DIR := $(call select_from_ports,googletest)/src/lib/googletest/googletest

INC_DIR += $(GTEST_DIR)

SRC_CC = $(GTEST_DIR)/src/gtest_main.cc
SRC_CC += $(GTEST_DIR)/test/gtest_all_test.cc

LIBS = config_args stdcxx gtest
