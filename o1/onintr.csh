#!/usr/bin/csh
set inter=nee
onintr opvang
@ i = 1
start:
       while ( $inter == nee )
              echo -n "."
              @ i++
       end
       @ j =  $i % 256
       echo $i, $j
       exit( $i )
opvang:
        echo
        echo "het wordt tijd"
        set inter=ja
        goto start
