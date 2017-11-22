#!/bin/bash

u=`whoami`
g++ -std=c++11 -static *.cpp
mv a.out frupal.cgi
mv frupal.cgi ../../build
chmod -R 755 ../../build
