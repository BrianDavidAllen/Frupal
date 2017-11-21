#!/bin/bash
if [ $# -eq 0 ]; then 
echo "*********WHO DOING WHAT?*********************"
echo "David Gilmore"
w | grep 'dwg2'
echo "*********************************************"
echo "Ben Portis"
w | grep 'bportis'
echo "*********************************************"
echo "Paul Hubbard"
w | grep 'phubbard'
echo "*********************************************"
echo "Austin Baugh"
w | grep 'abaugh'
echo "*********************************************"
echo "Brian Allen"
w | grep 'briallen'
echo "*********************************************"
echo "Daniel Dupriest"
w | grep 'dd4'
echo "*********************************************"
echo "Punam Pal" 
w | grep 'punam'
else
member=$1
w | grep "$member"
fi
