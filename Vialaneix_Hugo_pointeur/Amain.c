#include <stdio.h>
#include "header.h"



int main() {
	menu a = { "test" };
	printf("%s", a.option);
	application b = { "apptest",{&a},10 };

	printf("%s et , %s et %i", b.nom, *b.menus, b.nb_menus);



}