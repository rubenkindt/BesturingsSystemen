#!/usr/bin/csh
@ i = 1
while ( $i < 20 )
	@ j = $i % 2
	if ( $j == 0 ) then
		echo $i
	endif
	@ i++
end
