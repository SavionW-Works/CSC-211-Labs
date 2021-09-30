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

float Craps(int, bool);

void main()
{
	
	int Games = 1; 
	float chance = Craps(2.7,true); 
	cout << setprecision(4);
	cout << "After playing " << Games << " game(s), your chance of winning Craps is: " << chance*100 <<"% \n";  
	cout << "Games won: " << int(Games * chance) << "\n"; 
	cout << "Games lost: " << int(Games - (Games * chance));

} 

float Craps(int plays = 1, bool Show=false) { //Settings plays=1 is the default when no parameters are passed
	
	srand(time(0)); //Random number generator seed
	
	int num1; //First die
	int num2; //Second die
	int points = 0;
	int i; 
	bool Continue = 0;

	float Wins = 0; //Set to flaot to calculate probability
	float Losses = 0; //Set to flaot to calculate probability 
	float Ratio = 0; //Will equal probability of winning based on all games played.
	
	
	for (i = plays; i > 0; i--) { //Repeats program depending on the number of plays
		
		if (Show == true) { 
			points = 0;
			cout << "Let's play Craps! We're playing: " << plays << " game(s)! \n";

			num1 = rand() % 5 + 1; //Dice roll
			num2 = rand() % 5 + 1; //Second dice roll

			cout << "Dice #1: " << num1 << "  Dice #2: " << num2 << "\n";
			cout << "Roll Sum: " << num1 + num2 << "\n";

			if (num1 + num2 == 2 or num1 + num2 == 3 or num1 + num2 == 12) { //Checks for initial loss
				Losses += 1;
				cout << "You got craps. You lose! \n"; //Player loses game

			}

			else if (num1 + num2 == 7 or num1 + num2 == 11) { //Checks for initial win
				Wins += 1;
				cout << "You got a natural. You win! \n"; //Player win game
			}

			else { //Point gained

				points = (num1 + num2); //Points are calculated

				cout << "You got a point! Let's roll again. \n\n";

				Continue = 1;

				while (Continue == 1) {

					num1 = rand() % 5 + 1;
					num2 = rand() % 5 + 1;
					cout << "Die 1: " << num1 << "  Die 2: " << num2 << "\n";
					cout << "Roll Sum: " << num1 + num2 << "\n";

					if (num1 + num2 == points) {
						Wins += 1;
						Continue = 0;
						cout << "The new point matches. You win! \n"; //Player wins game
					}

					else if (num1 + num2 == 7) {
						Losses += 1;
						Continue = 0;
						cout << "The new point is 7. You lose! \n"; //Player loses game
					}

					else {
						cout << "The new point does not match. Keep going! \n\n"; //Player continues game 
						points = (num1 + num2);
					}



				}

			cout << "Game Over! \n\n\n";
			} //END OF PRINT VERSION 

		
		
		} 

		else {   ///NON PRINT VERSION
			points = 0;
			

			num1 = rand() % 5 + 1; //Dice roll
			num2 = rand() % 5 + 1; //Second dice roll

			

			if (num1 + num2 == 2 or num1 + num2 == 3 or num1 + num2 == 12) { //Checks for initial loss
				Losses += 1;
				 //Player loses game

			}

			else if (num1 + num2 == 7 or num1 + num2 == 11) { //Checks for initial win
				Wins += 1;
				 //Player win game
			}

			else { //Point gained

				points = (num1 + num2); //Points are calculated

				//cout << "You got a point! Let's roll again. \n\n";

				Continue = 1;

				while (Continue == 1) {

					num1 = rand() % 5 + 1;
					num2 = rand() % 5 + 1;
					

					if (num1 + num2 == points) {
						Wins += 1;
						Continue = 0;
						 //Player wins game
					}

					else if (num1 + num2 == 7) {
						Losses += 1;
						Continue = 0;
						 //Player loses game
					}

					else {
						//Player continues game 
						points = (num1 + num2);
					}



				}





			}
		}
		 

		
		
	
	}
	

	Ratio = Wins/(Wins+Losses); //Probability of winning is calculated
	
	return Ratio;  //Probability of winning is returned
	
}