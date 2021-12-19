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

class Customer {
public: 
	char CustomerName[15]; //Should NOT be of type string. strings are lists of CHARs. A list of strings is just a list of strings.
	int ArrivalTime;
	int ServiceTime;
	int FinishTime;

};

class FCFSQueue {
public: 
	Customer CustomerList[100];
	int length = 0; //Number of customers in the queue 
	
	bool IsEmpty();
	int GetLength();
	void Enqueue(Customer);
	void Dequeue();

};



//Queue functions operate for FIFO (first in, first out) structures

int main()
{


	//----------STEP 3-------------------------

	//Part #1
	FCFSQueue myQueue;
	myQueue.length = 0;

	cout << "Is the queue empty? ";
	if (myQueue.IsEmpty() == 1)
		cout << "Yes. \n";
	else
		cout << "No. \n";


	//Part #2 
	Customer newCus = { "Tom", 1, 0, 0 }; 
	

	//Part #3
	myQueue.Enqueue(newCus);
	cout << "A new customer named " << myQueue.CustomerList[0].CustomerName << " is added. \n";

	//Part #4 
	newCus = { "Bob", 3, 0, 0 }; 

	//Part #5 
	myQueue.Enqueue(newCus);
	cout << "A new customer named " << myQueue.CustomerList[1].CustomerName << " is added. \n";

	
	cout << "The queue now has " << myQueue.GetLength() << " people \n"; 
	cout << "\n";

	cout << "Is the queue empty? ";
	if (myQueue.IsEmpty() == 1)
		cout << "Yes. \n";
	else
		cout << "No. \n";

	//Parts #7-9
	cout << myQueue.CustomerList[0].CustomerName << " is leaving the queue." << endl; //Prints out the name of thecustomer about to leave the queue
	myQueue.Dequeue();

	cout << myQueue.CustomerList[0].CustomerName << " is leaving the queue." << endl; //Prints out the name of thecustomer about to leave the queue
	myQueue.Dequeue(); 

	cout << "Is the queue empty? ";
	if (myQueue.IsEmpty() == 1)
		cout << "Yes. \n";
	else
		cout << "No. \n";

	cout << "The queue now has " << myQueue.GetLength() << " people \n";
	cout << "\n";

	//----------------- END OF STEP 3----------------------------

}

bool FCFSQueue::IsEmpty() {
	if (length == 0)
		return true;
	else
		return false;

}

int FCFSQueue::GetLength() {
	return length;
}

void FCFSQueue::Enqueue(Customer cus) {
	if (length < 100) {
		CustomerList[length] = cus; //Adds new customer to queue if the queue is not full. Tested and seems to work 
		length += 1;
	}


	else
		cout << "Queue is full";
}

void FCFSQueue::Dequeue() {
	Customer cus;
	if (length > 0) { //Checks if queue is empty
		cus = CustomerList[0]; //Saves and removes the first customer from the list

		for (int i = 0; i < (length - 1); i++) { //Only goes up to 99 as i is for the index. There is no index of 100.
			CustomerList[i] = CustomerList[i + 1]; //Shifts all values to the left
		}

		CustomerList[99] = {}; //Prevents a duplicate of the last value from being left behind 
		length -= 1; //Decrements list length
	}


	else
		cout << "Queue is empty";
}



