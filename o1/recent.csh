#!/usr/bin/csh
# om recente bestanden te printen van een gebruiker
# Gebruik : recent.csh loginnaam aantal_dagen suffix
#    kan best als root uitgevoerd worden
grep $1 /etc/passwd | cut -d: -f1,5 > /tmp/naam$$
cd ~$1
find . \( -ctime -$2  -a -name \*.$3 \) -print > /tmp/lijst$$
/usr/local/bin/listing  /tmp/naam$$ `cat /tmp/lijst$$`
rm /tmp/naam$$
rm /tmp/lijst$$
