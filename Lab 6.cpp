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

enum triangleType {scalene, isosceles, equilateral, noTriangle};

int triangleShape(int, int, int);

int main()
{
	triangleType shape; 
	int side_1, side_2, side_3; 

	cout << "Input your triangle side lengths:"; 
	cin >> side_1 >> side_2 >> side_3;  
	cout << "\n";
	shape = triangleType(triangleShape(side_1, side_2, side_3)); 
	

	switch (shape)
	{ 
		case scalene: 
			cout << "Your shape is scalene" << endl; 
			break; 
		
		case isosceles:
			cout << "Your shape is isosceles" << endl;
			break; 

		case equilateral:
			cout << "Your shape is equilateral" << endl;
			break; 

		case noTriangle:
			cout << "Your shape is not a triangle" << endl;
			break; 

		default: 
			cout << "ERROR: No values given" << endl;
	
	} 
	return 0;
} 

int triangleShape(int side1, int side2, int side3) { 
	int samesides = 0; 
	

	if ((side1 + side2) > side3 && (side2 + side3) > side1 && (side1 + side3) > side2) {

		if (side1 == side2)
			samesides += 2;

		if (side2 == side3)
			samesides += 2;

		if (side1 == side3)
			samesides += 2;

		if (samesides >= 4)
			return 2;

		else if (samesides == 2)
			return 1;

		else
			return 0;

	}

	else
		return 3;
	
	



}