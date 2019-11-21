#!/usr/bin/csh
set antw=ongeldig
while ( $antw == "ongeldig" )
	echo "1: (c) aanpassing inode"
	echo "2: (l) aanpassing file"
	echo "3: (u) toegang file" 
    echo -n "Keuze : "
	set keuze=$<
	if ( ($keuze<1) || ($keuze>3) ) continue
    set antw = geldig
end
switch ( $keuze )
case 1 :
		set a=c
		breaksw
case 2 :
		set a=l
		breaksw
case 3 :
		set a=u
		breaksw
endsw
ls -l$a
