#!/bin/bash
pdir=$1
cwd=$pdir/vendor

echo $cwd

mkdir -p .tmp

for LIB in glfw
do
    cd $cwd/_origin/$LIB
    echo "=== $LIB ==="
    echo "--> Retrieving updates"
    status=$(git pull)
    if [ "$status" != "Already up-to-date." ]
    then   
        if [ "$LIB" == "glfw" ]
        then
            cmake .
            make
            make install
            make clean
            cp /usr/local/lib/libglfw3.a $pdir/bin
            rm -rf $cwd/src/$LIB
        fi

        echo "--> Moving files"
        if [ "$LIB" == "spdlog" ]
        then
            mkdir -p $cwd/src/$LIB
            mv src/* $cwd/src/$LIB
        fi
            
        mkdir -p $cwd/include/$LIB
        mv include/$LIB/* $cwd/include/$LIB
        mv LICENSE.* $cwd/include/$LIB/LICENSE

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