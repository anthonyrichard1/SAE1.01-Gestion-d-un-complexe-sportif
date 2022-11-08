all : menus adherents activites
	
menus : menus.c testMenus.c adherents.c activites.c
	gcc -Wall $^ -o menus.o
	
adherents : adherents.c testAdherents.c
	gcc -Wall $^ -o adherents.o
	
activites : activites.c adherents.c testActivites.c
	gcc -Wall $^ -o activites.o

clean :
	rm *.o
