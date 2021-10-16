//
// Created by Aaron Belyeu on 3/29/2021.
//

#ifndef MINICLOCK_CASINONUMGUESSGAME_H
#define MINICLOCK_CASINONUMGUESSGAME_H
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

void printCasinoNumGues()
{
    string playerName;
    int balance;  //stores player's balance
    int bettingAmount;
    int guess;
    int dice; //stores the random number
    string choice;

    srand(time(0));   //"seed" the random generator

    cout << "\n\t\t========WELCOME TO CASINO WORLD==========\n\n";
   // cout << system("cls");
    cout << "\t\t==========CASINO NUMBER GUESSING RULES!==========\n";
    cout << "\t1. Choose a number between 1 to 10\n";
    cout << "\t2. Winner get 10 time of the money bet\n";
    cout << "\t3. Wrong bet, and you lose the amount you bet\n\n";


    cout << "\n\nWhat's your Name: ";
    getline(cin, playerName);
    cout << "\n\nWhat's the starting balance to play game: $";
    cin >> balance;

    do {
        do {
            cout << "Hey, " << playerName << ", enter amount to bet : $";
            cin >> bettingAmount;      //geting players balance
            if (bettingAmount > balance) {
                cout << "Betting balance can't be more than current balance!\n"
                     << "\nRe-enter balance\n ";
            }
        } while (bettingAmount > balance);
        //get player's numbers
        do {
            cout << "Guess any betting number between 1 & 10 :" <<endl;
            cin >> guess;
            if (guess <= 0 || guess > 10) {
                cout << "\nNumber should be between 1 to 10\n"
                     << "Re-enter number:\n ";
            }
        } while (guess <= 0 || guess > 10);
        dice = rand() % 10 + 1;

        if (dice == guess) {
            cout << "\n\nYou Lucky!!, you won $" << bettingAmount * 10;
            balance = balance + bettingAmount * 10;
        } else {
            cout << "Ha ha ha, you lost $" << bettingAmount << endl;
            balance = balance - bettingAmount;
            cout << "The number was " << dice;
        }
        if (balance == 0) {
            cout << "You have no money. You broke!. Go get more to play:)";
            break;
        }
        cout << "\n\n-->Do you want to play again (y/n)? ";
        cin >> choice;
    }
    while (choice == "Y" || choice == "y");
    cout << "\n\n\n";
    cout << "\n\nThanks for playing the game. Yur balance is $ " << balance << endl;


}




#endif //MINICLOCK_CASINONUMGUESSGAME_H
