/*************************************************
Program: nim.cpp
Author: Robert Payne
Lab section: L15
Date: 3-30-2012
Purpose:    This is the game of nim, which allows
            the user to play against the CPU. The
            game randomly selects turn order and
            difficulty and then prompts the user
            to enter the number of marbles they
            would like to pick up each turn. This
            repeats until there is only one marble
            left.
/**************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    //variables
    bool playerFirst; //true if player is first at the start of the game
    bool firstTurn;   //true if it is still on the first turn
    bool gameOver;    //true if a condition that ends the game is triggered
    bool isExpert;    //randomly assigned, if true, CPU will use expert strategy
    int playerChoice; //used for player choices on menus
    int marblesPickUp;//number of marbles picked up in the current turn
    int marblesRemaining;//number of marbles left in play
    int halfRemaining;//half of the number of marbles left over
    int i;            //iteration variable; used in for loops
    char contGame;    //character used to start over after a game over


    srand(time(0));     //seed the random number generator

    do  //while continue == y after a game over; brings the user back to the title screen
    {
        //initialize turnNumber and gameOver
        firstTurn = true;
        gameOver = false;

        do
        {
            for(i =0; i < 15; i++) //clear screen
                cout<<endl;
            //title/menu
            cout<<"\t\t---------------------------------------------"<<endl;
            cout<<"\t\t|                                           |"<<endl;
            cout<<"\t\t|     Game                                  |"<<endl;
            cout<<"\t\t|      ---                                  |"<<endl;
            cout<<"\t\t|                  of                       |"<<endl;
            cout<<"\t\t|                   -                       |"<<endl;
            cout<<"\t\t|                              Nim          |"<<endl;
            cout<<"\t\t|                               --          |"<<endl;
            cout<<"\t\t\\==========================================="<<endl;
            cout<<endl;
            cout<<"\t\t\t1. Start game"<<endl;
            cout<<"\t\t\t\t2. Rules";

            for(i =0; i < 7; i++)//spacing
                cout<<endl;

            do
            {
                cout<<"\t\t\t\t\tChoice? ";// menu choice prompt
                cin>>playerChoice;
            }
            while(playerChoice > 2 || playerChoice < 1); //menu choice validation

            if(playerChoice == 2) //menu choice for rules
            {

                for(i = 0; i < 15; i++) //clear screen
                    cout<<endl;
                //rules screen
                cout<<"\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
                cout<<"\t\t|                                           |"<<endl;
                cout<<"\t\t|   The object of Game of Nim is to not be  |"<<endl;
                cout<<"\t\t| the one to pick up the last marble. You   |"<<endl;
                cout<<"\t\t| will take turns picking up marbles against|"<<endl;
                cout<<"\t\t| the CPU player. The most marbles you can  |"<<endl;
                cout<<"\t\t| pick up in one turn is half the total     |"<<endl;
                cout<<"\t\t| remaining marbles. However, you must pick |"<<endl;
                cout<<"\t\t| up AT LEAST one marble per turn.          |"<<endl;
                cout<<"\t\t|                             Good luck =]  |"<<endl;
                cout<<"\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;

                for(i = 0; i <7; i++) //centers the rules on the screen
                    cout<<endl;

                cout<<"Press enter to return to the menu";
                cin.get(); //clear the keyboard buffer from menu selection
                cin.get(); //waits for user to press enter
            }

        }
        while(playerChoice != 1);  //keeps the user in the menu until start game has been
                                    //choosen

        //randomly changes the difficulty of the CPU before the game starts
        if((rand()%2) == 0)
            isExpert = false;
        else
            isExpert = true;

        //randomly picks if the user or CPU goes first
        if((rand()%2) == 1)
            playerFirst = true;
        else
            playerFirst = false;

        //randomly starts the game with a marble value of 10 to 100
        marblesRemaining = (rand()%91) + 10;

        do      //while !gameOver
        {
/*///////////////////////////////////////
/Main game section
/*///////////////////////////////////////

            if(!firstTurn || playerFirst)//checks to see if the player goes first
            {
                if(!gameOver)
                {
                    halfRemaining = marblesRemaining / 2; //sets the value for half remaining

                    for(i = 0; i < 20; i++) //clears the screen
                        cout<<endl;

                    //fancy output(boarders and marbles)
                    cout<<endl<<"\t\t------------------------------------------------\n"<<endl;
                    for(i = 0; i < marblesRemaining; i++)
                    {
                        if((i % 5) == 0)
                            cout<<"\t\t|\t";
                        cout<<"*\t";
                        if((i % 5) == 4)
                                cout<<"|"<<endl;
                    }

                    cout<<endl<<"\t\t------------------------------------------------\n"<<endl;
                    cout<<"\t\tYour turn!\n";
                    cout<<"\t\tMarbles remaining: " <<marblesRemaining<<endl;
                    cout<<"\t\tHow many: ";

                    //validates user input of number of marbles to pick up
                    do
                    {
                        cin>>marblesPickUp;
                    }
                    while(marblesPickUp > halfRemaining || marblesPickUp < 1);

                    //calculating new marble total
                    marblesRemaining -= marblesPickUp;

                    //checking for a win condition
                    if(marblesRemaining == 1)
                    {
                        cout<<"\n\n\t\t\t\t\a***You win!***\n";
                        gameOver = true;
                    }
                }
            }

                //CPU's turn
                if(!gameOver)
                {
                    //sets half remaining value
                    halfRemaining = marblesRemaining / 2;

                    for(i = 0; i < 5; i++)//scrolls the screen output
                        cout<<endl;

                    //outputs boarders and marbles
                    cout<<endl<<"\t\t------------------------------------------------\n"<<endl;
                    for(i = 0; i < marblesRemaining; i++)
                    {
                        if((i % 5) == 0)
                            cout<<"\t\t|\t";
                        cout<<"*\t";
                        if((i % 5) == 4)
                                cout<<"|"<<endl;
                    }

                    cout<<endl<<"\t\t------------------------------------------------\n"<<endl;
                    cout<<"\t\tThere were "<<marblesRemaining<<" marbles remaining...\n";
                    cout<<"\n\t\tComputer picked up: ";

                    marblesPickUp = 1;

                    //expert's playing strategy
                    if(isExpert)
                    {
                        if(marblesRemaining >= 64)
                        {
                            for(i=0; (marblesRemaining - i) != 63; i++)
                                ;
                            marblesPickUp = i;
                         }else if(marblesRemaining >= 32)
                                {
                                    for(i=0; (marblesRemaining - i) != 31; i++)
                                        ;
                                    marblesPickUp = i;
                                }else if(marblesRemaining >= 16)
                                        {
                                            for(i=0; (marblesRemaining - i) != 15; i++)
                                        ;
                                    marblesPickUp = i;
                                        }else if(marblesRemaining >= 8)
                                               {
                                                    for(i=0; (marblesRemaining- i) != 7; i++)
                                                        ;
                                                    marblesPickUp = i;
                                                }else if(marblesRemaining >= 4)
                                                        {
                                                            for(i=0; (marblesRemaining - i) != 3; i++)
                                                                ;
                                                            marblesPickUp = i;
                                                        }else
                                                            marblesPickUp = 1;
                    }


                    //non-expert strategy, random marbles
                    if(marblesPickUp > halfRemaining || !isExpert)
                        marblesPickUp = (rand() % halfRemaining) + 1;



                    cout<<marblesPickUp<<endl;

                    //calculates the new marble total
                    marblesRemaining -= marblesPickUp;

                    //output status after CPU turn
                    cout<<"\t\tMarbles remaining: " <<marblesRemaining<<endl;
                    cout<<endl<<"\t\tPress Enter...";
                    cin.get();//clears the keyboard buffer
                    cin.get();//waits for user to press enter

                    if(marblesRemaining == 1)//checks for a lose condition
                    {
                        cout<<"\n\n\t\t\t\a***You lose!***";
                        gameOver = true;
                    }
                }

                firstTurn = false; //takes the first turn flag away

            }while(!gameOver);//stops the game after a win or loss

        cout<<"\n\n\t\t\tCont? (y/n) ";//allows the user to play again
        cin>>contGame;

    }while(contGame == 'y');//stops the program if the user does not want to play again

    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
    <<"\t\t\tThanks for playing!\n\n\n\n\n";

    return 0;
}
