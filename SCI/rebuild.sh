#!/bin/sh

rm -r build_profile
mkdir build_profile
cd build_profile
cmake -DCMAKE_INSTALL_PREFIX=./install .. -DBUILD_TESTS=ON -DBUILD_NETWORKS=ON -DNO_REVEAL_OUTPUT=ON -DCMAKE_CXX_FLAGS=-pg -DCMAKE_EXE_LINKER_FLAGS=-pg -DCMAKE_SHARED_LINKER_FLAGS=-pg

cmake --build . --target install --parallel
