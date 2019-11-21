#!/usr/bin/csh
if ( $#argv == 0) then 
	echo "meer argumenten volgende keer"
	exit 1
endif
set home = `pwd`
set lastigaard = "/student/e4/hfd/tmp/oef3"
set maps = `ls /student/e4/hfd/tmp/oef3/ `
echo "home is $home"
foreach map ($maps)
	if ($map == "" ) then
		continue
	endif
	mkdir $home/$map
	set files = `ls $lastigaard/$map`
	foreach file ( $files )
		set naam = `echo $file |cut -c6-8`
		echo $naam naam
		echo $1	input
		if ( -r $file && $naam == $1 ) then
			echo $file | cut -c1-5
			set begin = `echo $file | cut -c1-5`
			cp $lastigaard/$map/$file $home/$map/$begin$2
		endif

	end
end
exit 0

#	cp -r $map $home
