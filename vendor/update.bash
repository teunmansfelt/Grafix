#!/bin/bash
pdir=$1
cwd=$pdir/vendor

mkdir -p .tmp

for LIB in spdlog glfw imgui
do
    cd $cwd/_origin/$LIB
    echo "=== $LIB ==="
    echo "--> Retrieving updates"
    status=$(git pull)
    if [ "$status" != "Already up-to-date." ]
    then
        echo "--> Moving files"
        mkdir -p $cwd/$LIB

        case $LIB in

            spdlog)
                mv src/* $cwd/$LIB           
                mv include/$LIB/* $cwd/$LIB
                mv LICENSE $cwd/$LIB/
                ;;
            
            glfw)
                mv src/* $cwd/$LIB           
                mv include/$LIB/* $cwd/$LIB 
                mv LICENSE.md $cwd/$LIB 

                for file in glx_ linux_ null_ win32_ wgl_ wl_ x11_ posix_time
                do 
                    rm -rf $cwd/glfw/$file*.*
                done
                rm -rf $cwd/glfw/CMakeLists.txt
                ;;
            
            imgui)
                mv *.cpp $cwd/$LIB 
                mv *.h $cwd/$LIB 
                mv LICENSE.txt $cwd/$LIB 
                ;;

        esac

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