#!/bin/bash -ev

export PATH=${PATH}:/usr/local/bin

# Download and install Genode toolchain
curl -O -J -L https://sourceforge.net/projects/genode/files/genode-toolchain/17.05/genode-toolchain-17.05-x86_64.tar.xz
sudo tar -xf genode-toolchain-17.05-x86_64.tar.xz -C /

# Prepare required ports
./tool/ports/prepare_port libc stdcxx

# Create build directory
./tool/create_builddir x86_64 BUILD_DIR=build

# Run all tests
KERNEL=linux make -C build run/init
