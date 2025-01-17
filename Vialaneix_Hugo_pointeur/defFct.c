#include <stdio.h>
#include "header.h"
#include <Windows.h>

void displayMenu(const application* app) {
	

	printf("---%s---\n", app->nom);
	
	for (int i = 0; i < app->nb_menus; i++) {
		int j = i + 1;
		printf("%d. %s\n", j, app->menus[i].option);
	}
	printf("choississez une option(0 pour quitter");
}

void runApplication(const application* app) {

	while (1) {
		displayMenu(&app);
		system("cls");
		Sleep(150);
	}
	printf("veuillez choisir le chiffre d'option");
	int optChoix = 0;
	scanf_s("%d", &optChoix);
}