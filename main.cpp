//lib for hendeling a input and output
#include <iostream>
// lib for hendeling random numbers
#include <random>
//lib for hendeling a sleep 
#include <unistd.h>
//enable name space to not writing std:: to use libs
using namespace std;

//variables initialization
short int Level_Of_Diffucalty = 1;

unsigned char Math_Operator = 0;

int Random_Number_One = 0;

int Random_Number_Two = 0;

short int Score = 0;

short int Maximum_Score = 0;

int User_Answer = 0;

int Solution = 0;

char Loses = 1;

//calculation function
int calculations(int First_Number, int Second_number, char Math_Operator){
                // we need to select a arithmetic operator. 0 is +, 1 is -, 2 is * and 3 is /
                
                if (Math_Operator == 0){ // operator +

                    cout << First_Number << "+" << Second_number << endl; // show user a equation

                    Solution = First_Number + Second_number; // Solve a equation

                    return Solution; // return solution

                }
                else if (Math_Operator == 1)// operator -
                {
                    cout << First_Number << "-" << Second_number << endl; // show user a equation

                    Solution = First_Number - Second_number;// Solve a equation

                    return Solution;// return solution

                }
                else if (Math_Operator == 2)// operator *
                {
                    // multiply is harder than adding or subtracting and have larger number to prevent game from reaching integer limits we just make numbers smaller by 98% 
                    
                    First_Number = lround(First_Number * 0.02); // round a number and decrease by 98%

                    Second_number = lround(Second_number * 0.02);// round a number and decrease by 98%

                    cout << First_Number << "*" << Second_number << endl; // show user a equation

                    Solution = First_Number * Second_number;// Solve a equation

                    return Solution;// return solution

                }
                else if (Math_Operator == 3)// operator /
                {
                    // devision is harder than adding or subtracting and have larger number to prevent game from reaching integer limits we just make numbers smaller by 98% 
                    
                    First_Number = lround(First_Number * 0.02); // round a number and decrease by 98%

                    Second_number = lround(Second_number * 0.02);// round a number and decrease by 98%

                    cout << First_Number << "/" << Second_number << endl; // show user a equation

                    Solution = First_Number / Second_number;// Solve a equation

                    return Solution;// return solution

                }
                else{ // if generator of random numbers made mistake we just return a operator +
                    cout << First_Number << "+" << Second_number << endl;

                    Solution = First_Number + Second_number;// Solve a equation

                    return Solution;// return solution
                }
                
                
                
                



}

    
    
    
        
  
//main function

int main(){
        // Main Loop 
        while(true){

            system("clear");

            // Random Numbers 
            Random_Number_One = rand() % 50 * Level_Of_Diffucalty; // Generate Pseudo Random Number From 0 To 50 and multiplying by Level of Diffucalty

            Random_Number_Two = rand() % 90 * Level_Of_Diffucalty; // Generate Pseudo Random Number From 0 To 90 and multiplying by Level of Diffucalty
            
            Math_Operator = rand( ) % 3; // Generate Pseudo Random Number From 0 To 3 to decide arithmetic operator
            
            cout << "Score : " << Score << endl; // Tell Score 
            
            cout << "Level " <<  Level_Of_Diffucalty << " of 255" << endl; // Tell Levels 
            
            Solution = calculations(Random_Number_One,Random_Number_Two, Math_Operator); // Function to create equations by using random numbers
            
            cout << "Your Answer : "; // hendle a user answer
            
            cin >> User_Answer; // hendle a user answer
            if (User_Answer == Solution){// check does user answer and solution is the same
                Score ++; // add 1 to score
                
                if (Level_Of_Diffucalty == 255){ //if level is 255 show win message
                        system("clear");

                        cout << "You Win" << endl << "You Beat all 255 levels" << endl << "Your Score is " + Score << endl << "Your Maximum Score is " + Maximum_Score;
                        break; // close game
                 
                    }
                if (Score >= Maximum_Score){ // check does score more than max scor then add 1 
                    
                    Maximum_Score ++; //add 1 to max score
                
                }
                
                if (Loses >= 2){ // if player answer right we decrease points with will be subtracted if player make mistake.
                    
                    Loses -= 1;  // subtract 1 point
                
                }
                Level_Of_Diffucalty ++; // Increase Diffucalty / Change Level

            }
            else
            {
                if(Score <= 0){ // if score is 0 or lover game over
                    system("clear");
                    // game over title
                    cout << "Game Over" << endl << "Your Maximum Score was " << Maximum_Score << endl;
                    // close game
                    break;
                }
                else
                {
                if (Score <= 10){ // if score is less or equal to 10 we decrease a panishment points
                    
                    Loses = 1; //set panishment points to 1 per mistake
               
                }

                 // if player make more mistakes we subtrack more points
                Score -= Loses; 
                // and chenge level back
                Level_Of_Diffucalty --;
                // increase count of points with will be subtreacted if player make mistake
                Loses += 1; // add 1 point 
                
                    
                system("clear");
                // if player make mistake we show player a his answer and right one
                cout << "Your Answer :"<< User_Answer << endl;

                cout << "Right Answer :" << Solution << endl;

                cout << "Your Score Was Decreased"<< endl << "Your Score Now is "<< Score << endl;
                //wait 3 seconds before start again
                sleep(3);
                
                }
                
            }
  
        }
          return 0;
    }