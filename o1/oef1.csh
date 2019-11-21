#!/usr/bin/csh
if ( $#argv == 0 ) then
     echo "Graag argumenten"
     exit 1
endif
echo $*
foreach i ( $* )
if ( -d $i ) then
     echo "$i is een directory"
	set gr='ls *.csh'
	set teller=1
	foreach j ($gr)
		echo $teller : $j
		@ teller++
	end
	echo type een nr:
	set typenr=$<
	if ( $typenr <= 0 || $typenr >= $teller ) then
		echo "een number van hierboven volgende keer aub"
		exit 1
	endif
echo "keuze verwerken"
	set teller=1
	foreach k ($gr)
		if ( $teller == $typenr )  then
			echo $k
			more $k
		endif
		@ teller++
	end
else if (-r $i) then
	more $i
else
	echo "type iets zinniger in volgende keer"
endif 
end
exit 0
