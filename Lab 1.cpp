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



int main()

{
	//-------------------------------------------------(Problem 1):
	int i; 
	int n; 
	
	for (n = 8; n > 0; n--)
	{
		for (i = n; i > 0; i--)
			cout << "*";
		cout << "\n";
	}
		
	//-------------------------------------------------END OF (Problem 1) 

	cout << "\n"; 

	//-------------------------------------------------(Problem 2): 
	
	int spacing = 15; //Ideal spacing between text
	int list_ind = 0; //Holds the index of the list used to store numbers that are averaged
	int word_num = 0; //The number representing the place of the current word
	float total = 0; //Holds the total that is used to calculate the averages

	float price_list[4]; //List that holds price values
	int food_list[4]; //List that holds food values
	
	string bird;  //String that holds the name of a bird 
	string price; //String that holds the price of a bird
	string food; //String that holds the amount of food a bird consumes (in pounds)
	
	ifstream inData;  
	ofstream outData;
	
	//Header set-up
	cout << left << setw(spacing) << "BIRD";  
	cout << right << setw(spacing) << "PRICE"; 
	cout << right << setw(spacing) << "FOOD"; 
	cout << right << setw(spacing+2) << "HOOKBILL";
	cout << left << setw(0) << "\n";
	cout << "---------------------------------------------------------------"; //<--DO NO CHANGE!
	cout << left << setw(0) << "\n";
	//Header set-up

	inData.open("BIRD.txt");
	
	if (!inData) {  
		cout << "Error opening my file"; 
	} 

	//while (!inData.eof()) {
	for (word_num = 0; word_num < 12; word_num+=3) {
		inData >> bird >> price >> food;  
		
		//Name printing 
		cout << left << setw(spacing) << bird;
		
		//Price printing: 
		cout << right << setw(spacing) << price;
		price_list[list_ind] = stof(price);

		//Food printing: 
		cout << right << setw(spacing) << food;
		food_list[list_ind] = stoi(food); 

		if (stoi(food) >= 15) { //Determines which type of hookbill based on food consumption
			cout << right << setw(spacing);
			cout << "L \n";
		}

		else { //Determines which type of hookbill based on food consumption
			cout << right << setw(spacing);
			cout << "S \n";
		} 
		
		list_ind++;

	} 
	
	//Calculates the total for prices
	for (i = 3; i >= 0; i--) { 
		total += price_list[i]; 
	} 
	//Finds average
	total = total / 4;  
	cout << "\n" << left << setw(0) << "The average price is: " << fixed << setprecision(2) << total << "\n";  

	total = 0;
	//Calculates the total for food
	for (i = 3; i >= 0; i--) {
		total += food_list[i];
	}
	//Finds average
	total = total / 4;
	cout << "The average food is: " << fixed << setprecision(2) << total; 
	
	inData.close();
	
	//-------------------------------------------------END OF (Problem 2)
}

