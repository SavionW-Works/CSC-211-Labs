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

struct Customer {
	char CustomerName[15]; //Should NOT be of type string. strings are lists of CHARs. A list of strings is just a list of strings.
	int ArrivalTime; 
	int ServiceTime; 
	int FinishTime;

}; 

struct FCFSQueue {
	Customer CustomerList[100]; 
	int length = 0; //Number of customers in the queue

}; 

bool IsEmpty(FCFSQueue); 

int GetLength(FCFSQueue); 

void Enqueue(FCFSQueue&, Customer); 

void Dequeue(FCFSQueue&);  

//Queue functions operate for FIFO (first in, first out) structures

int main()
{
	
	
	//----------STEP 3-------------------------
	
	//Part #1
	FCFSQueue myQueue; 
	myQueue.length = 0;  

	//Part #2 
	Customer newCus = {"Tom", 1, 0, 0}; 
	
	//Part #3
	Enqueue(myQueue, newCus);
	
	//Part #4 
	newCus = {"Bob", 3, 0, 0}; 

	//Part #5 
	Enqueue(myQueue, newCus); 

	//Parts #7-9
	cout << myQueue.CustomerList[0].CustomerName << " is leaving the queue." << endl; //Prints out the name of thecustomer about to leave the queue
	Dequeue(myQueue);  

	cout << myQueue.CustomerList[0].CustomerName << " is leaving the queue." << endl; //Prints out the name of thecustomer about to leave the queue
	Dequeue(myQueue);  

	//----------------- END OF STEP 3----------------------------

}  

bool IsEmpty(FCFSQueue queue) { 
	if (queue.length == 0)
		return true;
	else
		return false;

} 

int GetLength(FCFSQueue queue) {
	return queue.length;
}  

void Enqueue(FCFSQueue& queue, Customer cus) {
	if (queue.length < 100) {
		queue.CustomerList[queue.length] = cus; //Adds new customer to queue if the queue is not full. Tested and seems to work 
		queue.length += 1; 
	}
		  

	else
		cout << "Queue is full";
} 

void Dequeue(FCFSQueue& queue) {
	Customer cus;   
	if (queue.length > 0) { //Checks if queue is empty
		cus = queue.CustomerList[0]; //Saves and removes the first customer from the list

		for (int i = 0; i < (queue.length - 1); i++) { //Only goes up to 99 as i is for the index. There is no index of 100.
			queue.CustomerList[i] = queue.CustomerList[i + 1]; //Shifts all values to the left
		} 

		queue.CustomerList[99] = {}; //Prevents a duplicate of the last value from being left behind 
		queue.length -= 1; //Decrements list length
	}


	else
		cout << "Queue is empty";
}



