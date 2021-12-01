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

const int MAX = 6;

void swap(int &n1, int &n2);

class bubble {
private: 
	int arr[MAX];
	int n = 0; 

public:  
	void getarr(); 
	void showarr();
	void sortarr(); 



};


void main()
{
	bubble sorter; 

	sorter.getarr();  
	sorter.showarr();
	sorter.sortarr();
	sorter.showarr(); 
	
} 

void bubble::getarr() { 
	int num;
	cout << "You may type in up to " << MAX << " values in your array. \n";  
	cout << "How many items are in your array?"; 
	cin >> n; 
	if (n > MAX) {
		n = MAX;
	}
		


	for (int i = 0; i < n; i++) {
		cout << "\n";
		cout << "What is item number " << i + 1 << " in your array?"; 
		cin >> arr[i];
	}
	
} 

void bubble::showarr() {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " "; 
		
	}
	cout << "\n";
} 

void bubble:: sortarr() {
	int runs = n; 

	for (int i = 0; i < runs; i++) {
		
		for (int j = 0; j < runs-i-1; j++) { //Should use runs - (i-1) instead of runs-2 to ensure proper number of swaps.
			// could j <= runs-2; also work consistently?
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}

		}
	
	}

} 

void swap(int &n1, int &n2) {
	int hold = n1;  
	n1 = n2; 
	n2 = hold; 
}