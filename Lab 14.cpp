#include <iostream> //Needed for <fstream> to funciton

using namespace std;

//PROBLEM 2: 
class DayOfYear {
public:
	int month, day;
	void output();
};




void main()
{
	//PROBLEM 1:
	int** board; 
	int row, column; 
	cout << "Enter the number of rows and columns in your board"; 
	cin >> row >> column; 
	board = new int* [row]; //Allocates first dimension of rows
	for (int i = 0; i < row; i++) { 
		board[i] = new int[column];  
	}//Allocates each part of the second dimension of rows 

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) 
			cout << "* "; 
		cout << '\n';
	}
	//END OF PROBLEM 1 


	//PROBLEM 2: 
	DayOfYear today, birthday; 
	today.month = 2; 
	today.day = 15; 
	today.output();  
	cout << "\n";

	cout << "Enter your date of birth (month then day): "; 
	cin >> birthday.month >> birthday.day; 

	if (birthday.month == today.month)
		if (birthday.day == today.day)
			cout << "Happy Birthday!";
		else
			cout << "Happy Unbirthday!"; 
	else
		cout << "Happy Unbirthday!";
}  

void DayOfYear::output() { 
	cout << "Month: " << month << " Day: " << day;

}

