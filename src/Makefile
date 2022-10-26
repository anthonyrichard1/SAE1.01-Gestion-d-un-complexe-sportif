all : menus adherents
	
menus : menus.c testMenus.c adherents.c
	gcc -Wall menus.c testMenus.c adherents.c -o complexe
	
adherents : adherents.c testAdherents.c
	gcc -Wall adherents.c testAdherents.c -o adherents
		
clean :
	rm complexe adherents
