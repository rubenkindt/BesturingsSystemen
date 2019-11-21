#!/usr/bin/csh
if ( $#argv == 0) then 
	echo "meer argumenten volgende keer"
	exit 1
endif
set home = `pwd`
set maps = `find /student/e4/hfd/tmp/oef2 -type d -print`
echo "home is $home"
foreach map ($maps)
	if ($map == . ) then
		continue
	endif
	cp -r $map $home
	echo $map copied
end
cd $home
chmod 0750 oef2
rm -r oef2
set homemaps = `find . -type d -print`
set dot="."
foreach map ( $homemaps )
	if ( $map == . ) then
		continue
	endif
	echo bezig met $map
	set files=`ls $map`
	foreach file ( $files )
		set name = `echo $file |cut -c1-5`
	#	set suffix = `find $map -name $file -type f -print | cut -d. -f3`
		echo name: $name -------------------------
	#	echo suffix: $suffix
		chmod 0750 $map/$file
		mv $map/$file $map/$name$1
	end
end
exit 0


