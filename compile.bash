#!/bin/bash

######################################################
#   Compiles main.cpp and lang.cpp  #
######################################################

set -e    # halt on first error

link=all  # link all binaries by default
linked=no # track whether we linked

case $1 in  
  -nolink) link=none ; shift ;;  # don't link
esac

# use 'clang++' as the compiler
CPP=clang++

# be aggressive about warnings and errors
FLAGS="-g -O -Wall -Wextra -Werror -Wfatal-errors -std=c++11 -pedantic"

# clear out old object files
rm -f *.o

# compile

case $link in
  all) $CPP $FLAGS -o main.cpp lang.cpp
                  linked=yes ;;
  none) $CPP $FLAGS -c lang.cpp ;;
esac
