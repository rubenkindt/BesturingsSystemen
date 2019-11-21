#!/usr/bin/csh
     set i = `grep hcr /etc/group | cut -d: -f1`
     set j = `echo $i | tr e a`
     echo $i "->" $j
