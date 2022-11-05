all : menus adherents
	
menus : menus.c testMenus.c adherents.c
	gcc -Wall $^ -o menus.o
	
adherents : adherents.c testAdherents.c
	gcc -Wall $^ -o adherents.o
	
clean :
	rm *.o
