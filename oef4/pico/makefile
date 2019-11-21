all : hfs

CFLAGS=-g 
LFLAGS=-L.

.c.o:
	cc -c $(CFLAGS) $<

# de studenten kunnen gewoon hun nieuw .o bij de linklijn bijvoegen
# bvb cc -o .... hfs.o mkfs.o -lsub -lbasis

libbasis.a: fstat.o namei.o makf.o lnk.o unlnk.o makdir.o mkfs.o  \
				 curd.o chmode.o chuid.o
	ar cr libbasis.a  fstat.o namei.o makf.o lnk.o unlnk.o makdir.o mkfs.o \
		             curd.o chmode.o chuid.o

namei.o: namei.c hfs.h
	cc -c -DSTUB $(CFLAGS) namei.c

#libsub.a: fssubr.o
#	ar cr libsub.a fssubr.o

hfs: hfs.o libsub.a libbasis.a
	cc -o hfs $(CFLAGS) $(LFLAGS) hfs.o -lsub -lbasis 

