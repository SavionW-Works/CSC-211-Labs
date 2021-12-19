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

int spacing = 15;
const int lines = 8;

struct menuItemType { //Changed from structure to class
	string menuItem;
	double menuPrice;
	int Count; 
	
}; 

class navigation {
public: 
	
	
	menuItemType menuList[lines];

	menuItemType Receipt[lines];  

	void showMenu(bool);


	void MenuSearch(int, int);

	void printCheck(); 
	void getData(string);



}; 



//menuItemType structM menuList[lines];

//menuItemType structR Receipt[lines];







/*
THINGS TO FIX:
-Have every price show digits up to the hundredth (even with zeros)

*/

void main()
{

	//NOTE: Skip one line in menu.txt to fix alignment of the first item
	bool Ordering = true;
	string ans;
	int item;
	int quant; 

	navigation Johnny; 


	cout << "Welcome to Johnny's Restaurant";
	cout << "\n";
	Johnny.getData("menu.txt");   //menulist is filled
	cout << "\n";
	Johnny.showMenu(false);





	while (Ordering == true) {
		cout << "\n" << "Would you like to order (again)? (Y or N)" << endl;
		cin >> ans;

		if (ans == "Y" || ans == "y") {


			cout << "\n" << "Please enter your item by number: " << endl;
			cin >> item;


			cout << "\n" << "Please enter your item quantity: ";
			cin >> quant;


			Johnny.MenuSearch(item, quant);
			cout << "\n" << "Here is your current order: \n\n";
			Johnny.showMenu(true);


		}

		else
			Ordering = false;

	}

	cout << "\nYour bill is shown below. Thank you for ordering at Johnny's Restaurant. \n";
	Johnny.printCheck();





}

void navigation::showMenu(bool show_quant = false) {
	int i;
	for (i = 0; i < lines; i++) {
		cout << left << setw(spacing) << menuList[i].menuItem;

		if (show_quant == true) {
			cout << right << setw(spacing) << Receipt[i].Count; //<--- Is misalgined when i = 0 for some reason :/
		}

		cout << right << setw(spacing) << "$" << setprecision(2) << fixed << menuList[i].menuPrice; //<--- Is misalgined when i = 0 for some reason :/

	}

}

void navigation::printCheck() {
	int i;
	double total = 0;
	for (i = 0; i < lines; i++) {
		cout << left << setw(spacing) << Receipt[i].menuItem;
		cout << right << setw(spacing) << Receipt[i].Count; //<--- Is misalgined when i = 0 for some reason :/
		cout << right << setw(spacing) << "$" << setprecision(2) << fixed << (Receipt[i].menuPrice * Receipt[i].Count); //<--- Is misalgined when i = 0 for some reason :/
		total += (Receipt[i].menuPrice * Receipt[i].Count);


	}

	cout << "\n\n";
	cout << left << setw(spacing) << "Total:";
	cout << right << setw(spacing) << "$" << total << "\n";

	cout << left << setw(spacing) << "Tax:";
	cout << right << setw(spacing) << "$" << setprecision(2) << fixed << total * 0.05 << "\n";

	cout << left << setw(spacing) << "Amount Due:";
	cout << right << setw(spacing) << "$" << setprecision(2) << fixed << total * 1.05 << "\n";



}


void navigation::MenuSearch(int num, int quantity) {
	Receipt[num].Count = quantity;
}

void navigation::getData(string file) {

	ifstream inData;
	ofstream outData;
	inData.open(file);

	if (!inData) {
		cout << "Error opening my file";
	}


	string text;
	double price;
	int i;

	menuItemType hold;


	for (i = 0; i < lines; i++) {
		getline(inData, text, '$'); //inData will continue after '$' the next time it is read
		inData >> price; //<- Gets the price without the '$' :)
		hold = { text, price, 0 };
		menuList[i] = hold;
		Receipt[i] = hold;




	}





}

