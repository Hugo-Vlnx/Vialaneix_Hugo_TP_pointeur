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


#endif
