GTEST_PORT_DIR := $(call select_from_ports,googletest)
INC_DIR += $(GTEST_PORT_DIR)/include $(GTEST_PORT_DIR)/include
INC_DIR += $(GTEST_PORT_DIR)/include/internal $(GTEST_PORT_DIR)/include/internal

