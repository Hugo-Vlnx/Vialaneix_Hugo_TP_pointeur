#include <stdio.h>
#include "header.h"
#include <Windows.h>

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
			return 0;
		}
		else if (optChoix > app->nb_menus) {
			printf("option indisponible,veuillez choisir le chiffre d'option: ");
			int optChoix = 0;
			scanf_s("%d", &optChoix);
		}
		else {
			printf(" vous avez choisis: %s\n ", app->menus[optChoix - 1].option);
		}
		Sleep(4000);
		system("cls");
	}
}
void runPhone(application * app1, application * app2) {
		printf("-- - Applications-- - \n1. Photos\n2. Messages\n0. Quitter");
		int choix = 0;
		scanf_s("%d", &choix);

		if(choix==0){
			return 0;
		}
		else if{

		}
		else if{

		}
		else {

		}
		
}
