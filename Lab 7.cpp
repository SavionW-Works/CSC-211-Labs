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

struct RainCity {
	string city;
	float rainfall;
	string restriction;


};



char Restriction(RainCity& place);


void main()
{
	

	RainCity city;

	cout << "What is the name and rainfall of your current city?"; 
	cin >> city.city >> city.rainfall; 
	cout << "\n";
	cout << left << setfill(' ') 
		<< setw(15) << "Name of city" 
		<< setw(15) << "rainfall" 
		<< setw(15) << "restrictions in place?\n";
	
	
	//Restriction(city); 
	cout << left << setfill(' ')
		<< setw(15) << city.city
		<< setw(15) << city.rainfall
		<< setw(18) << Restriction(city); //"city.restriction" will only print last letter of string for some reason
	
	

} 

char Restriction(RainCity& place) {  
	if (place.rainfall < 4) {
		place.restriction = 'yes'; //Only assigns last character of 'yes'. Why?
		return 'y';
	}

	else { 
		place.restriction = 'no'; //Only assigns last character of 'yes'. Why? 
		return 'n';
	}
		
	
}


