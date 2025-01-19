#include <stdio.h>
#include "header.h"
#include <Windows.h>
#include <string.h>

void displayMenu(const application* app) {
	

	printf("---%s---\n", app->nom);
	
	for (int i = 0; i < app->nb_menus; i++) {
		int j = i + 1;
		printf("%d. %s\n", j, app->menus[i].option);
	}
	printf("choississez une option, (0) pour quitter: ");
}

void runApplication(const application* app) {
	int optChoix = 2;
	while (optChoix != 0) {
		displayMenu(app);



		scanf_s("%d", &optChoix);
		if (optChoix == 0) {
			system("cls");
			break;
		}
		else if (optChoix > app->nb_menus) {
			printf("option indisponible,veuillez choisir le chiffre d'option: ");
			int optChoix = 0;
			scanf_s("%d", &optChoix);
		}
		else {
			printf(" vous avez choisis: %s\n ", app->menus[optChoix - 1].option);
		}
		Sleep(2500);
		system("cls");
	}
}
void runPhone(application * app1, application * app2) {
		
		int choix = 1;
		
		while (choix != 0) {
            printf("-- - Applications-- - \n1. Photos\n2. Messages\n0. Quitter\n");
            scanf_s("%d", &choix);
			if (choix == 0) {
				system("cls");
				runPhone(app1, app2);
			}
			else if (choix == 1) {
				system("cls");
				runApplication(app1);

			}
			else if (choix == 2) {
				system("cls");
				runApplication(app2);
			}
			else if (choix > 2) {
				printf("option indisponible,veuillez choisir le chiffre d'option: ");
				int Choix = 0;
				scanf_s("%d", &Choix);
			}
		}
}

void updateMenu(application* app, int menuIndex, const char* newOption) {
	printf("quelle index voulait vous modifier ?\n");
	scanf_s("d", &menuIndex);
	if (menuIndex < 0 || menuIndex >= app->nb_menus) {
		printf("Index invalide. Veuillez fournir un index entre 1 et %d.\n", app->nb_menus - 1);
		return;
	}
	else {
		strncpy(app->menus[menuIndex-1].option, newOption, sizeof(app->menus[menuIndex].option));
		printf("L'option %d a été mise à jour avec succès : %s\n", menuIndex, app->menus[menuIndex - 1].option);
	}
}
void updateApplication(application* app, const char* newName, menu* newMenus, int newMenuCount) {
	strncpy(app->nom, newName, sizeof(newName));
	app->nb_menus= newMenuCount;
	for (int i = 0; i < app->nb_menus; i++) {
		strncpy(app->menus[i].option, newMenus[i].option, sizeof(app->menus[i].option));
	}

}