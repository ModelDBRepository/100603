
kerg.o : 6erg.h k6erg.c
	gcc -c k6erg.c 
kergdriver.o : 6erg.h kergdriver.c k6erg.c
	gcc -c kergdriver.c 
ergout.o : 6erg.h ergout.c
	gcc -c ergout.c 
radau5.o: 6erg.h radau5.f
	gfortran  -c radau5.f
decsol.o: 6erg.h decsol.f
	gfortran -c decsol.f
koprisan:  radau5.o decsol.o ergout.o kergdriver.o kerg.o 6erg.h cblock.h
	gcc   -o koprisan radau5.o decsol.o  ergout.o  kergdriver.o -lm -lgfortran 
