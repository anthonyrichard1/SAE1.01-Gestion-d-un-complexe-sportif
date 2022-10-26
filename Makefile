all :
	make -C src all
	make -C doc all

doc :
	make -C doc all

src :
	make -C src all
	
clean :
	make -C src clean
	make -C doc clean
