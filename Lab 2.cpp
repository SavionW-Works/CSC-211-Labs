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

string month_interp(int); 
int header_printer(int);

int main()
{
	//Problem 1: 
	
	int i;
	int j;
	int num = 0;
	int space = 2;
	int max_space;
	int max_space2;
	cout << "Enter a number from 1 to 9 for your pyramid:";
	cin >> num;

	/* PROGRAM NOTES
	-I decided it would be easiest to find the right spacing for the first number in the row, and printing simply afterward

	-The following condition finds the highest amount of spaces before the first num of and row

	-It only works for number from 0-99. IS there a function that can find bases? (i.e 10 = base 10, 100 = base 100)

	-max_space helps with printing by defining how far the first numbers should be spaced

	-after the first number is printed, all other numbers are printed normally with the same space in between

	-The next line position changes by 2 from max_space UNTIL we get to the first double digit number, 10.

	-Then it changes by 3. This is accounted for by subtracting 19 or (10*2 - 1) from max_space.

	-I'm not sure why it takes some time to print all the numbers :(
	*/
	if (num > 9) {
		max_space = (num * 2) + (num - 10);
		max_space2 = max_space - 19;

	}


	else
		max_space = (num * 2) - 1;

	for (i = 1; i <= num; i++) { //Outer loop

		for (j = i; j <= num + 1; j--) { //Inner loop

			if (j > 0) {
				if (j == i) {  //Sets up the first number


					if (i < 10) { //Prints the first numbers that are less than 10
						cout << right << setw(max_space - 2 * (i - 1)) << j;
					}

					else { //Prints the first numbers that are greater than 10
						cout << right << setw(max_space2 + 1) << j;
						max_space2 -= 3;
					}

				}

				else { //Prints numbers after the first and stops at 1

					if (j > 9) {
						cout << right << setw(space + 1) << j;
					}

					else {
						cout << right << setw(space) << j;
					}

				}
			}





		}

		for (j = 1; j < i + 1; j++) { //Prints numbers after 1

			if (j > 1) {
				if (j > 9) {
					cout << right << setw(space + 1) << j;
				}

				else {
					cout << right << setw(space) << j;
				}


			}




		}

		cout << "\n"; //Skips lines

	}
	
	
	//Start of Problem 2 
	//CALENDER CONDITIONS: 
	/* 
	-12 months per year in the following order: (Jan, Feb, March, April, June, July, Aug, Sep, Oct, Nov, Dec)
	-All years start on January 1st 
	-Months with 30 days: (Sep, April, June, Nov) 
	-Months with 31 days: (Jan, March, July, Aug, Oct, Dec) 
	-Leap years occur on year numbers divisible by 4 
	-On a leap year, Feburary has 29 days, OTHERWISE is had only 28 
	
	*/ 

	int year = 0; 
	int month = 1; 
	int week = 0; 
	int week_day = 0; //0 is Sunday and 6 is Saturday
	int day = 1; 
	int day_max = 0;

	int space_2 = 7; 
	

	cout << "Enter the year and week day that starts your calender: ";
	cin >> year >> week_day; 

	//MAIN CODE*********************************************************
	for (month = 1; month <= 12; month++) {
		//Header set-up:
		cout << "\n\n\t" << month_interp(month) << " " << to_string(year) << "\n";
		cout << "---------------------------------------------------- \n";
		header_printer(space_2);
		//--------------------------------  

		//Month conditions
		if (month == 1 or month == 3 or month == 5 or month == 7 or month == 8 or month == 10 or month == 12 && month != 2) { //Procedure for months with 31 days
			day_max = 31;


		}

		else if (month != 2)
			day_max = 30;

		else if (year % 4 == 0 && year % 100 != 0)
			day_max = 29;
		else
			day_max = 28;


		int i;
		//First day of each month
		if (week_day == 0)
			cout << "\r" << day; // "\r" starts at the beginning of the line
		else
			cout << right << setw((space_2 * (week_day)) - 1) << day; //Spaces accordingly for other weekdays 

		day++;
		//--------------------------------------------------

		//Main loop for month printing 
		for (i = day; i <= day_max; i++) {

			if (week_day == 6) {  //Skips line after 7th weekday
				cout << "\n\r";
				cout << day;
			}

			else //Spaces and prints normally if weekday != 7
				if (day > 9) {
					if (day > 10)
						cout << right << setw(space_2) << day;
					else
						cout << right << setw(space_2 + 1) << day;
				}


				else
					cout << right << setw(space_2) << day;


			//increases days and weekdays
			week_day++;
			day++;

			if (week_day > 6) { //Keeps week_day between 0 and 6 (inclusive)
				week_day = 0;
			}




		} 

		//Keeps week_day between 0 and 6 (inclusive) ; needed again right before next month
		if (week_day == 6) { 
			week_day = 0;
		}

		else
			week_day++;
		
		day = 1;

		//MAIN CODE**********************************************
	}
	
	

//END OF (Problem 2)
}  

int header_printer(int a) { 
	 
	cout << left << setw(a) << "Sun";
	cout << left << setw(a) << "Mon";
	cout << left << setw(a) << "Tue";
	cout << left << setw(a) << "Wed";
	cout << left << setw(a) << "Thu";
	cout << left << setw(a) << "Fri";
	cout << left << setw(a) << "Sat \n"; 
	return 0;
}

string month_interp(int a) { 
	//-Months with 31 days: (Jan, March, July, Aug, Oct, Dec)
	string name;
	switch (a) {
		case 1: 
			name = "January";  
			break;

		case 2: 
			name = "February";  
			break;

		case 3: 
			name = "March";  
			break;

		case 4:
			name = "April"; 
			break;

		case 5:
			name = "May"; 
			break;

		case 6:
			name = "June"; 
			break;

		case 7:
			name = "July"; 
			break;

		case 8:
			name = "August"; 
			break;

		case 9:
			name = "September"; //Longest month name! 
			break;

		case 10:
			name = "October";  
			break;

		case 11:
			name = "November"; 
			break;

		case 12:
			name = "December";
			break;
		
		default: 
			name = "January";
	}
	return name;
} 

