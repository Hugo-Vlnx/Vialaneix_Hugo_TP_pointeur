#ifndef HEADER_H
#define HEADER_H

typedef struct {
	const char* option;

}menu ;

typedef struct  {
	const char* nom;
	menu* menus;
	int nb_menus;
}application;

void displayMenu(const application* app);
void runApplication(const application* app);
void runPhone(application* app1, application* app2);
void updateMenu(application* app, int menuIndex, const char* newOption);
void updateApplication(application* app, const char* newName, menu* newMenus, int newMenuCount);


#endif
