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



void main()
{
	//pa and pb are pointers
	float a, * pa;
	float b, * pb;
	float c;
	const float *holder; 
	const float * holder2;
	
	a = 3.0;
	b = 1.9;
	
	pa = &a; 
	cout << "pa = " << pa << " or the address of a." << endl;  
	cout << "*&a = " << *&a << " is the value of a, or &a dereferenced." << endl;
	holder = pa;  
	//cout << "holder: " << holder << endl;
	
	*pa = 3 * a; 
	cout << "*pa = " << *pa << " or 3 * a." << endl; 
	cout << "a = " << a << endl;

	pb = &b; 
	cout << "pb = " << pb << " or the address of b." << endl; 
	
	*pb += 0.5; 
	cout << "&(*pb) = " << &(*pb) << " which is also the address of b, or *pb referenced." << endl;

	c = *pa + *pb; 
	cout << "c = " << c << " or the value of a + b after their increases." << endl;

} 


