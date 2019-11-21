#!/usr/bin/csh
	echo $*
	echo $0
	echo $1
	echo $argv[$#argv]
if ( $1 =~ [0-9]* ) then
	echo "Stoppen met status " $1
	exit $1
endif
