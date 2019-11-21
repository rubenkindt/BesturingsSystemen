#!/usr/bin/csh
if ( $#argv == 0 ) then
     echo "Graag argumenten"
     exit 1
endif
echo $*
foreach i ( $* )
if ( -d $i ) then
     echo "$i is een directory"
else if ( -r $i ) then
     echo "$i is een file"
else
     echo "$i is nog iets anders"
endif
end
