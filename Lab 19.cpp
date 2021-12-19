#include <iostream> //Needed for <fstream> to funciton
#include <string> 
#include<set> //Allows for the creation of sets (not arrays) that hold data in classes 
//every item in a set must be unique. Therefore, insert_item() will not add items that already exist in the set
#include <list>   //Also needed for sets
#include<iterator> 

using namespace std;

int const MAX = 15;

template <class T> 
class lister {
	
	public: 
		T arr[12] = {1,1,1};
		void insert_item(T num); 
		int get_size();
		T* get_point(); 

};

void main()
{
	
	lister<int> int_lister; //creates a lister class with int
	int n = sizeof(int_lister.arr) / sizeof(int_lister.arr[0]); 
	
	int_lister.insert_item(3);
	cout << "3 was placed as the last value in the list \n";
	cout << "last value in the list: " << int_lister.arr[n-1] << "\n";

	cout << "\n";
	cout << "address of list: " << &(int_lister.arr);
	cout << "\n"; 
	int *garb1 = (int_lister.get_point());
	cout << "result of pointer function: " << garb1 ; 
	cout << "\n\n"; 
	garb1 = NULL; 
	delete garb1;

	lister<char> char_lister; 
	n = sizeof(char_lister.arr) / sizeof(char_lister.arr[0]);
	
	char_lister.insert_item('p');
	cout << "p was placed as the last value in the list \n";
	cout << "last value in the list: " << char_lister.arr[n-1] << "\n";

	cout << "\n";
	cout << "address of list: " << &(char_lister.arr); 
	cout << "\n"; 
	cout << "or " << int(&(char_lister.arr)) << " as an integer. \n";
	char* garb2 = (char_lister.get_point());
	cout << "result of pointer function: " << (garb2);
	cout << "\n";
	cout << "or " << int(garb2) << " as an integer. (since each byte is being converted to a character).";
	cout << "\n\n"; 
	garb2 = NULL; 
	delete garb2; 

	lister<double> double_lister;
	n = sizeof(double_lister.arr) / sizeof(double_lister.arr[0]);

	double_lister.insert_item(3.33);
	cout << "3.33 was placed as the last value in the list \n";
	cout << "last value in the list: " << double_lister.arr[n-1] << "\n";

	cout << "\n";
	cout << "address of list: " << &(double_lister.arr);
	cout << "\n";
	double* garb3 = (double_lister.get_point());
	cout << "result of pointer function: " << (garb3);
	
	cout << "\n\n";
	garb3 = NULL;
	delete garb3;
}  

template <class T> 
//Did insert mean append? I would need vectors to append, so I simply changed the last value in the list
void lister<T>::insert_item(T num) { 
	int n = sizeof(arr) / sizeof(arr[0]);
	bool can_add = 1;

	if (n >= MAX)
		can_add = 0;

	for (int i = 0; i < n; i++) {
		if (num == arr[i])
			can_add = 0;
	}

	if (can_add == 1) {
		int size = *(&arr + 1) - arr;
		arr[size - 1] = num;
	}

	
} 

template <class T>
int lister<T>::get_size() {
	int size = *(&arr + 1) - arr;
	
	return size;
}

template <class T>
T* lister<T>::get_point() {
	int size = *(&arr + 1) - arr;
	
	 
	T *dy_arr = new T[size];
	 dy_arr = &arr[0];
	 
	

	/* 
	T *dy_arr = new T[size]; 
	for (int i = 0; i < size; i++) {
		dy_arr+i = &arr[i];
	} 
	*/
	
	return dy_arr;
	
}