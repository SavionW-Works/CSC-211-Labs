#include "menu.h"


//-------------LAB 13---------------------------
void main()
{

	//NOTE: Skip one line in menu.txt to fix alignment of the first item
	bool Ordering = true;
	string ans;
	int item;
	int quant;

	
	cout << "Welcome to Johnny's Restaurant";
	cout << "\n";
	getData("menu.txt");   //menulist is filled
	cout << "\n";
	showMenu(false);





	while (Ordering == true) {
		cout << "\n" << "Would you like to order (again)? (Y or N)" << endl;
		cin >> ans;

		if (ans == "Y" || ans == "y") {


			cout << "\n" << "Please enter your item by number: " << endl;
			cin >> item;


			cout << "\n" << "Please enter your item quantity: ";
			cin >> quant;


			MenuSearch(item, quant);
			cout << "\n" << "Here is your current order: \n\n";
			showMenu(true);


		}

		else
			Ordering = false;

	}

	cout << "\nYour bill is shown below. Thank you for ordering at Johnny's Restaurant. \n";
	printCheck();





} 




