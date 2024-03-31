#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

int moneyloss(char answear,int coins) //if the coins are 0; call this function
{
		switch (answear) //if answear was 'y' get the coins back to 100;
			{
			case 'y':
				{		
					coins=100;
					break;
				}
			case 'n':
				{
					exit(1); // if the answear was 'n';
				}
			}
	return coins; // get the coins to the main function;
}
				

int winlose(int key, int number, int coins) //this function check if the game was won, or lost;
{
		key=(rand ()%5)+1; // get a random key number;
		printf("The extracted number is: %d\n", key);
		if(key==number) // if the number entered by the user, and the key number are equal
		{
			printf("Congratulations! You have won 10$.\n"); // winner;
			coins = coins+10;		// get money;
		}
		else //enter here if the user did not guessed;
		{
			printf("You are not so lucky this time!\n");
			coins = coins-10; //game was lost, money will decrease;
		}
	return coins;	//return the money;
}

void rotate (char answear, int coins) //rotate function designed for the game to continue
{
	FILE *fp; //file pointer
	switch (answear)
		{
		case 'y': // if answear was 'y';
			{	
				system("cls");	//clear the screen;
				break; // exit the whole switch statement;
			}
		case 'n': // if the answear was 'n';
			{
				fp=fopen("D://coins.txt", "w"); // open the file for writing;
				fprintf(fp,"%d", coins); // put the current money on the file, create the savegame;
				fclose(fp); // close the file;
				exit(1); //exit the game;
			}
		}	
}


char getanswear (char answear) //function to take an answear;
{
	int n;
	for(n=1;n>0;n++) // infinite loop;
	{
		answear=0; // answear is initialized, with 'not an option' value;
		fflush(stdin); // clear the buffer, to avoid having trouble while getting the answear from the keyboard;
		answear=tolower(getchar()); // convert the answear to lower case;
		printf("You answeared: %c\n", answear); // print the answear on the screen;
		if(answear=='n'||answear=='y') // if the answear is what we expected, enter here.
		{
			return answear; // return the answear to main function;
			break; // get out from the infinite loop;
		}
		else // else enter here;
		printf("Not an option. Try again!\n");
	}
	
}

int main()
{
	//Declarating the variables;
	int key; 
	int c = 0;
	int number;
	int coins;
	char answear;
	int n;		
	
	FILE *fp; //declaring the file pointer;
	fp=fopen("D://coins.txt", "r"); // open the file for reading;
	coins = 100; // coins are initialized;
	
	if(!fp) // if fp does not previously exist;
	{
		printf("No previous data!.\n"); 
	}
	
	if (!feof(fp)) // if the end of the file was not reached, the file contains data, enter here;
	{
		printf("Taking values:\n"); // print this;
		fscanf(fp, "%d", &c); // get the data;
		coins = c; //the data will be stored in coins;
	}
	
	fclose(fp);		// close the file;
	for(n=1;n>0;) // infinite loop;
	{	
		number=0;	//number initialization;
		if(coins<=0) //if the coins are 0;
		{
			printf("Sorry but you have no dollars left. Try again Y/N?\n");
			fflush(stdin); // clears the buffer, so we won't have trouble while getting the answear from the keyboard;
			answear=getanswear(answear);//answear is equal with what returns the getanswear function;
			coins=moneyloss(answear,coins); // get coins from moneyloss function;
		}
		printf("You have: %d$\n", coins); // print out the coins;
		printf("\nEnter your number! WARNING: it must be between 1 and 5 only.\n"); //print message;
		fflush(stdin); // clears the buffer, so we won't have trouble entering a value from the keyboard;
		scanf("%d", &number); // get a value from the keyboard;
		if(number>0&&number<6) // if the value is between 1 and 5;
		{	
		printf("Your number is: %d\n", number); //print the value of the number;
		coins=winlose(key,number,coins); // call the winlose function, see if you won, or lost,
		//coins will take the value returned by winlose;
		printf("Rotate again? Y/N!\n"); // ask for replay;
		answear=getanswear(answear); // take the answear;
		rotate(answear, coins); // rotate again or not, depending on the answear;
		}
		else // if the number is not between 1 and 5;
			printf("You have entered a wrong value\n");						
		
	}
	getch(); // keep the screen open;
	return 0; // return nothing, when the game closes;
}


