#include <iostream> //Needed for <fstream> to funciton

using namespace std;

//PROBLEM 2: 
class DayOfYear {
private:
	int month, day;

public:
	
	DayOfYear() { month = 1; day = 1; } //Constructor with no parameters

	DayOfYear(int m, int d); //Constructor with 2 Parameters
	 
	DayOfYear(int m); 

	void output();

	//get and set are industry standard terminology for class functions! 
	//get means to receive 
	//set means to assign
	int getDay(int& num) { num = day; return num; }
	int getMonth(int& num) { num = month; return num; } //Does not need return since it is called by reference 
	//This also coerces that the parameter should be a VARIABLE, that takes the current value of month/day
	 

	void setMonth(int num) { month = num; }
	void setDay(int num) { day = num; } 
	
	friend bool Compare(DayOfYear d1, DayOfYear d2) { //Returns True if d1 == d2 
		if ((d1.month == d2.month) && (d1.day == d2.day))
			return true;
		else
			return false;

	};

	bool compareDate(const DayOfYear myday) { //Has a parameter to switch between original and revision  
		if ((myday.month == month) && (myday.day == day))
			return true;
		else
			return false;	
	
	} 
	
	
	void increMonth() {
		if (month == 12) {
			month = 1;
		}

		else
			month += 1;
	} 

	void increDay();



};




int main()
{
	DayOfYear Today;   
	DayOfYear Special_Day = {5, 13};
	int m , d;

	
	Today = DayOfYear();
	cout << "DayOfYear() is called" << endl;
	cout << Today.getMonth(m) << " " << Today.getDay(d) << endl;

	Today = DayOfYear(2, 2); 
	cout << "DayOfYear(2, 2) is called" << endl;
	cout << Today.getMonth(m) << " " << Today.getDay(d) << endl;

	Today = DayOfYear(13); 
	cout << "DayOfYear(13) is called. Which should default the month to 1." << endl;
	cout << Today.getMonth(m) << " " << Today.getDay(d) << endl;

	Today.setMonth(6); 
	Today.setDay(27); 
	cout << "setMonth(6) and setDay(27) are called" << endl;
	cout << Today.getMonth(m) << " " << Today.getDay(d) << endl;

	Today.increMonth();
	Today.increDay(); 
	cout << "increMonth() and increDay() are called" << endl;
	cout << Today.getMonth(m) << " " << Today.getDay(d) << endl;

	cout << "Is March 13 the current day? " << endl; 

	if (Today.compareDate(Special_Day) == true)
		cout << "Yes! \n";
	else
		cout << "No. \n"; 

	cout << "When we use the friend function Compare(Special_Day,Today), we can also see that March 13th... \n"; 

	if (Compare(Special_Day, Today) == true)
		cout << "Is today!";
	else
		cout << "Is NOT today.";

	
	

}

void DayOfYear::output() {
	cout << "Month: " << month << " Day: " << day;

} 

void DayOfYear::increDay() {
	int day_max; 
	if (month == 1 or month == 3 or month == 5 or month == 7 or month == 8 or month == 10 or month == 12 && month != 2) { //Procedure for months with 31 days
		day_max = 31;


	}

	else if (month != 2)
		day_max = 30;

	else
		day_max = 29; 

	if (day != day_max) {
		day += 1;
	}

	else
		day = 1;

} 

DayOfYear::DayOfYear(int m, int d) {
	if (m <= 12)
		month = m;
	else
		month = 1;
	
	int day_max;
	if (month == 1 or month == 3 or month == 5 or month == 7 or month == 8 or month == 10 or month == 12 && month != 2) { //Procedure for months with 31 days
		day_max = 31;


	}

	else if (month != 2)
		day_max = 30;

	else
		day_max = 29;  

	if (m <= day_max) {
		day = m;
	}

	else
		day = 1;
} 

DayOfYear::DayOfYear(int m) {
	if (m <= 12)
		month = m;
	else
		month = 1;

	day = 1;

}

