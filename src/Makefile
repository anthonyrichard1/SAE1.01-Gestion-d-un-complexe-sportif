all : menus adherents activites complexe

menus : menus.c testMenus.c adherents.c activites.c
	gcc -Wall $^ -o menus.o

adherents : adherents.c testAdherents.c
	gcc -Wall $^ -o adherents.o

activites : adherents.c activites.c testActivites.c
	gcc -Wall $^ -o activites.o

complexe : menus.c adherents.c activites.c complexe.c
	gcc -Wall $^ -o complexe.exe
clean :
	rm -f *.o complexe.exe
