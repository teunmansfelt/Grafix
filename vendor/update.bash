#!/bin/bash
cwd=$1

mkdir -p .tmp

for LIB in spdlog
do
    cd $cwd/_origin/$LIB
    echo "=== $LIB ==="
    echo "--> Retrieving updates"
    status=$(git pull)
    if [ "$status" != "Already up-to-date." ]
    then   
        echo "--> Moving files"
        mkdir -p $cwd/src/$LIB
        mv src/* $cwd/src/$LIB
        mkdir -p $cwd/include/$LIB
        mv include/$LIB/* $cwd/include/$LIB
        mv LICENSE $cwd/include/$LIB

        echo "--> Cleaning _origin"
        mv .git* $cwd/.tmp
        rm -rf * .[!.]*
        mv $cwd/.tmp/.git* ./
    else
        echo "$status"
    fi
done

cd $cwd
rm -rf .tmp