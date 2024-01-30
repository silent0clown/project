#!/bin/bash
BUILD_DIR="build"
INSTALL_DIR=$(pwd)/output
rm -rf "${BUILD_DIR}"

#Config
BUILD_TYPE=Debug
cmake -B "${BUILD_DIR}" -DCMAKE_INSTALL_PREFIX="${INSTALL_DIR}" -DCMAKE_BUILD_TYPE=${BUILD_TYPE} \
      -DCPACK_OUTPUT_FILE_PREFIX="${INSTALL_DIR}"

#Build
cmake --build "${BUILD_DIR}"

#Test
#cd "${BUILD_DIR}"


