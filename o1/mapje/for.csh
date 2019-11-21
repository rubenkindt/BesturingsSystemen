#!/usr/bin/csh
set a = ( aap beer das geit )
    foreach i ( $a )
		echo -n $i " : " 
		echo  $i | rev
	end

