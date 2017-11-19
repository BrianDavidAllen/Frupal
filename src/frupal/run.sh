#!/bin/bash

u=`whoami`
g++ -std=c++11 -static *.cpp
mv a.out frupal.cgi
mv frupal.cgi /u/$u/public_html/frupal/TheBestCS300Group/build
