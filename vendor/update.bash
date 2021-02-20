#!/bin/bash
pdir=$1
cwd=$pdir/vendor

mkdir -p .tmp

for LIB in glfw
do
    cd $cwd/_origin/$LIB
    echo "=== $LIB ==="
    echo "--> Retrieving updates"
    status=$(git pull)
    if [ "$status" == "Already up-to-date." ]
    then   
        echo "--> Moving files"
        mkdir -p $cwd/src/$LIB
        mv src/* $cwd/src/$LIB           
        mkdir -p $cwd/include/$LIB
        mv include/$LIB/* $cwd/include/$LIB
        mv LICENSE.* $cwd/include/$LIB/LICENSE

        if [ "$LIB" == "glfw" ]
        then
            for file in glx_ linux_ null_ win32_ wgl_ wl_ x11_ posix_time
            do 
                rm -rf $cwd/src/glfw/$file*.*
            done
            rm -rf $cwd/src/glfw/CMakeLists.txt
        fi

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