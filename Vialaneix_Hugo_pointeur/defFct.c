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
		
void runPhone(application * app1, application * app2) {
		int choix = 1;

		while (choix != 0) {
			printf("--- Applications ---\n");
			printf("1. %s\n", app1->nom);
			printf("2. %s\n", app2->nom);
			printf("3. Modifier le menu de '%s'\n", app1->nom);
			printf("4. Modifier l'application '%s'\n", app2->nom);
			printf("0. Quitter\n");
			printf("Votre choix : ");
			scanf_s("%d", &choix);

			system("cls");
			switch (choix)
			{
			 case 1: {
				runApplication(app1);
				break;
			 }
			 case 2: {
				runApplication(app2);
				break;
			 }
			 case 3:{
				int menuIndex;
				char newOption[50];
				printf("Entrez l'index du menu à modifier dans '%s' : ", app1->nom);
				scanf_s("%d", &menuIndex);
				printf("Entrez la nouvelle option : ");
				scanf_s(" %s", &newOption, (unsigned)sizeof(newOption));
				updateMenu(app1, menuIndex, newOption);
				break;
			 }
			 case 4: {
				char newName[50];
				int newMenuCount;
				Menu newMenus[10];

				printf("Entrez le nouveau nom de l'application '%s' : ", app2->nom);
				scanf_s("%s", &newName, (unsigned)sizeof(newName));
				printf("Entrez le nombre de menus pour '%s' : ", newName);
				scanf_s("%d", &newMenuCount);

				for (int i = 0; i < newMenuCount; i++) {
					printf("Entrez l'intitulé du menu %d : ", i + 1);
					scanf_s(" %s", &newMenus[i].option, (unsigned)sizeof(newMenus[i].option));
				}

				updateApplication(app2, newName, newMenus, newMenuCount);
				break;
			 }
			 case 0: {
				printf("Fermeture du programme...\n");
				break;
			 }
				 Sleep(2000);
				 system("cls");
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