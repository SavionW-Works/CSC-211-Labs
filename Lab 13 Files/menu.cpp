#include "menu.h"

void showMenu(bool show_quant = false) {
	int i;
	for (i = 0; i < lines; i++) {
		cout << left << setw(spacing) << menuList[i].menuItem;

		if (show_quant == true) {
			cout << right << setw(spacing) << Receipt[i].Count; //<--- Is misalgined when i = 0 for some reason :/
		}

		cout << right << setw(spacing) << "$" << setprecision(2) << fixed << menuList[i].menuPrice; //<--- Is misalgined when i = 0 for some reason :/

	}

}

void printCheck() {
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


void MenuSearch(int num, int quantity) {
	Receipt[num].Count = quantity;
}

void getData(string file) {

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

