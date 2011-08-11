#!/bin/bash

#set this to the development root directory if you have one
#export PREFIX=/usr/local/

export SCRIPT_DIR=`dirname $0`;
export CMAKE_PREFIX_PATH=$PREFIX:CMAKE_PREFIX_PATH
export PKG_CONFIG_PATH=$PREFIX/lib/pkgconfig/:PKG_CONFIG_PATH
cmake -G "Eclipse CDT4 - Unix Makefiles" -DECLIPSE_CDT4_GENERATE_SOURCE_PROJECT=TRUE -DCMAKE_INSTALL_PREFIX=$PREFIX $SCRIPT_DIR

