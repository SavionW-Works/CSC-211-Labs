#ifndef MENU_H 
#define MENU_H

#include <iostream> //Needed for <fstream> to funciton
#include <iomanip> 
#include <string> 
#include <istream>
#include <cstdlib> 
#include <cstdlib>
#include <ctime> //Needed for rand(); set seed with srand(time(0));
#include <cmath> 
#include <fstream>  
#include <stdio.h>
#include <ctype.h> 
#include <typeinfo>   

using namespace std; 

struct menuItemType {
	string menuItem;
	double menuPrice;
	int Count;

};   

void showMenu(bool);

void getData(string);

void MenuSearch(int, int);

void printCheck();

int spacing = 15;
const int lines = 8;

menuItemType menuList[lines];

menuItemType Receipt[lines]; 

#endif



