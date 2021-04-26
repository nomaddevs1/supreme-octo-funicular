
#include <iostream>
#include <string> // Needed to use strings
#include <cstdlib> // Needed to use random numbers
#include <ctime>
#include <fstream>
using namespace std;
 
void drawLine(int n, char symbol);
int playerNumber( int &guess);
void rules();
 
int main()
{
    string playerName;
    int amount; // hold player's balance amount
    int bettingAmount; 
    int guess;
    int dice; // hold computer generated number
    char choice;
    ofstream playerDetails("casinoJournal.txt", std::ios_base::app);
    srand(time(0)); // "Seed" the random generator

    drawLine(60,'_');
    cout << "\n\n\n\t\tCASINO GAME\n\n\n\n";
    drawLine(60,'_');
 
    cout << "\n\nEnter Your Name : ";
    getline(cin, playerName);
    playerDetails<<endl;
    playerDetails<<"Player: "<<playerName <<endl;
 
    cout << "\n\nEnter Deposit amount to play game : $";
    cin >> amount;
    playerDetails<<"Amount Deposited: " <<amount<<endl;
 
       if(amount > 0){
      do
      {
        system("cls");
        rules();
        cout << "\n\nYour current balance is $ " << amount << "\n";
		
		// Get player's betting amount
   
        do
        {
            cout <<playerName<<", enter money to bet : $";
            cin >> bettingAmount;
            if(bettingAmount > amount || bettingAmount <= 0)
                cout << "Your betting amount is more than your current balance or is less than zero\n"
                       <<"\nRe-enter data\n ";
        }while(bettingAmount > amount || bettingAmount <= 0 );
 
		// Get player's numbers
      playerNumber(guess);
        
        dice = rand()%10 + 1; // Will hold the randomly generated integer between 1 and 10
    
        if(dice == guess)
        {
            cout << "\n\nGood Luck!! You won Rs." << bettingAmount * 10;
            amount = amount + bettingAmount * 10;
            cout << guess << endl;
            playerDetails<<"Guess: "<<guess<<" equal to "<<"Computer's guess: "<<dice<<"\n"<<"New Amount: "<<amount<<endl;
        }
        else
        {
            cout << "Bad Luck this time !! You lost $ "<< bettingAmount <<"\n";
            amount = amount - bettingAmount;
            cout << guess << endl;
            playerDetails << "Guess: " << guess << " is not equal to "
                          << "Computer's guess: " << dice << "\n"
                          << "New Amount: " << amount << endl;
        }
 
        cout << "\nThe winning number was : " << dice <<"\n";
        cout << "\n"<<playerName<<", You have $ " << amount << "\n";
        if(amount == 0)
        {
            cout << "You have no money to play ";
            break;
        }
        cout << "\n\n-->Do you want to play again (y/n)? ";		
        cin >> choice;
    }while(choice =='Y'|| choice=='y');
    
    cout << "\n\n\n";
    drawLine(70,'=');
    cout << "\n\nThanks for playing game. Your balance amount is $ " << amount << "\n\n";
    playerDetails<<"Final Amount: "<<amount<<endl;
    drawLine(70,'=');
    }
    else{
      cout << "The amount is too small for a bet"<<endl;
    };

    return 0;
}
 
 int playerNumber(int &guess){
     do
     {
         cout << "Guess your number to bet between 1 to 10 :";
         cin >> guess;
         if (guess <= 0 || guess > 10)
             cout << "Please check the number!! should be between 1 to 10\n"
                  << "\nRe-enter data\n ";
     } while (guess <= 0 || guess > 10);
     cout << guess<<endl;
     return guess;
 }

void drawLine(int n, char symbol)
{
    for(int i=0; i<n; i++)
        cout << symbol;
    cout << "\n" ;
}
 
void rules()
{

    cout << "\n\n";
    drawLine(80,'-');
    cout << "\t\tRULES OF THE GAME\n";
    drawLine(80,'-');
    cout << "\t1. Choose any number between 1 to 10\n";
    cout << "\t2. If you win you will get 10 times of money you bet\n";
    cout << "\t3. If you bet on wrong number you will lose your betting amount\n\n";
    drawLine(80,'-');
}
 
// END OF PROGRAM

 
