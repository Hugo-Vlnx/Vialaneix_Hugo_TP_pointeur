#include <stdio.h>
#include "header.h"
#include <Windows.h>



int main() {
	/*menu a = { "test" };
	printf("%s", a.option);
	application b = { "apptest",{&a},10 };

	printf("%s et , %s et %i", b.nom, *b.menus, b.nb_menus);*/

	menu photoMenus[3] = { "Regarder une photo", "Prendre une photo","modifier une photo" };
	application photoApp = { "appareil Photo", {&photoMenus}, 3 };

	displayMenu( &photoApp);

}