#!/usr/bin/csh
set a = ( 1 2 3 4 5 )
nog:
	echo $a
	shift a
	if ( $#a > 0 ) then
		goto nog
	endif
	echo $?a

