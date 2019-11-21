#!/usr/bin/csh
set c=cut
set f=/student/e4/hfd/csh/*.csh
set d=`grep -l goto $f`
@ j = 2
foreach i ( $d )
	echo  $i:h $i:r $i:e $i:t
    set e=`echo $i | $c -d/ -f$j`
	echo $e
	@ j++
end

