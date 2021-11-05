#include <iostream> //Needed for <fstream> to funciton
#include <iomanip> 
#include <string> 
#include <cstdlib> 
#include <cstdlib>
#include <ctime> //Needed for rand(); set seed with srand(time(0));
#include <cmath> 
#include <fstream>  
#include <stdio.h>
#include <ctype.h> 
#include <typeinfo>
using namespace std;


//------FROM LAB 8------------
struct menuItemType {
	string menuItem;
	double menuPrice;
	int Count;

};

void showMenu(menuItemType*, bool);

menuItemType*getData();

void MenuSearch(menuItemType*, int, int);

void printCheck(menuItemType*);

int spacing = 15; 
//const int NumOfItems = 1; 


//menuItemType menuList[NumOfItems];
//menuItemType Receipt[NumOfItems];


 
int lines = 0;

//----------------------------




int main()
{
	//---------SALES FIGURES PROGRAM---------------
	double* Sales; 
	int numDays;  

	
	
	double Total = 0;
	double Average = 0; 

	cout << "Enter the number of days you performed sales: "; 
	cin >> numDays;  

	double* SalesDays = new double[numDays]; 

	for (int i = 0; i < numDays; i++) {
		cout << "Enter the sales figures for day " << i + 1 << ":"; 
		cin >> SalesDays[i]; 
		cout << "\n";
	} 

	for (int j = 0; j < numDays; j++) {
		Total += SalesDays[j];
	}

	cout << "All of your sales total to: $" << Total << endl;
	cout << "Your average sales figure is: $" << Total / numDays << endl; 

	//NOTE: Skip one line in menu.txt to fix alignment of the first item
	


	
	//-------------------------------------



	//---------BREAKFAST BILLING PROGRAM--------------------
	bool Ordering = true;
	string ans;
	int item;
	int quant; 

	
	
	
	
	cout << "Welcome to Johnny's Restaurant";
	cout << "\n"; 

	//menuItemType menuList;

	//menuItemType Receipt; 

	
	menuItemType* menu_point; 
	menu_point = getData();   //Menu is created

	
	cout << "\n";
	showMenu(menu_point, false);
	
	
	while (Ordering == true) {
		cout << "\n" << "Would you like to order (again)? (Y or N)" << endl;
		cin >> ans;

		if (ans == "Y" || ans == "y") {


			cout << "\n" << "Please enter your item by number: " << endl;
			cin >> item;


			cout << "\n" << "Please enter your item quantity: ";
			cin >> quant;


			MenuSearch(menu_point, item, quant);
			cout << "\n" << "Here is your current order: \n\n";
			showMenu(menu_point, true);


		}

		else
			Ordering = false;

	}

	cout << "\nYour bill is shown below. Thank you for ordering at Johnny's Restaurant. \n";
	printCheck(menu_point);
} 

//LAB 8 FUNCTIONS: 
void showMenu(menuItemType *point, bool show_quant = false ) {
	int i;
	for (i = 0; i < lines; i++) {
		//cout << left << setw(spacing) << menuList[i].menuItem;
		cout << left << setw(spacing) << point[i].menuItem;
		if (show_quant == true) {
			cout << right << setw(spacing) << point[i].Count; //<--- Is misalgined when i = 0 for some reason :/
		}

		cout << right << setw(spacing) << "$" << setprecision(2) << fixed << point[i].menuPrice; //<--- Is misalgined when i = 0 for some reason :/ 
		cout << "\n";

	}

}

void printCheck(menuItemType *point) {
	int i;
	double total = 0;
	for (i = 0; i < lines; i++) {
		cout << left << setw(spacing) << point[i].menuItem;
		cout << right << setw(spacing) << point[i].Count; //<--- Is misalgined when i = 0 for some reason :/
		cout << right << setw(spacing) << "$" << setprecision(2) << fixed << (point[i].menuPrice * point[i].Count); 
		cout << "\n"; //<--- Is misalgined when i = 0 for some reason :/
		total += (point[i].menuPrice * point[i].Count);


	}

	cout << "\n\n";
	cout << left << setw(spacing) << "Total:";
	cout << right << setw(spacing) << "$" << total << "\n";

	cout << left << setw(spacing) << "Tax:";
	cout << right << setw(spacing) << "$" << setprecision(2) << fixed << total * 0.05 << "\n";

	cout << left << setw(spacing) << "Amount Due:";
	cout << right << setw(spacing) << "$" << setprecision(2) << fixed << total * 1.05 << "\n";



}


void MenuSearch(menuItemType* point, int num, int quantity) {
	point[num].Count = quantity;
}

menuItemType*getData() {
	
	int NumOfItems; 
	double enter_price; 
	string enter_name;
	
	cout << "How many items are on the menu?: ";
	cin >> NumOfItems; 
	lines = NumOfItems;
	cout << "\n";


	menuItemType *menuList = new menuItemType[NumOfItems];  
	//menuItemType * Receipt = new menuItemType[NumOfItems]; 
	menuItemType* p = &menuList[0];
	

	

	for (int i = 0; i < NumOfItems; i++) { //<--- Allows the user to make the menu themselves.
		cout << "Enter the item name: "; 
		cin >> enter_name;   
		menuList[i].menuItem = enter_name;
		//Receipt[i].menuItem = menuList[i].menuItem;
		cout << "\n"; 

		cout << "Enter the item price: $";
		cin >> enter_price;
		menuList[i].menuPrice = enter_price;
		//Receipt[i].menuPrice = menuList[i].menuPrice;
		menuList[i].Count = 0; 
		
		//Receipt[i].Count = 0;
		cout << "\n"; 



	} 

	

	return p;


}

