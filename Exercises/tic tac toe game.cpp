#include <iostream>
#include <ctype.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>

//Global variables;
//these two are for X coordinates;
int Xcol;
int Xrow;
//these two are for O coordinates;
int Orow;
int Ocol;
char a[3][3]={{ '.' , '.' , '.' },{ '.' , '.' , '.' },{ '.' , '.' , '.' }}; //gaming table;
bool Gameover =false; //let the game be true;
using namespace std;
int Score=0; //starting score;
int poscount=0; //ocuppied positions on the gaming table;
int Cash=1000;
int bet=0;
bool xwin=false;

void placebet() // function that will place a bet on your game;
{
	char answear;
	bool betplaced,refuse=false;
	if(Cash>=10) // the bet is only posible if you have money at least for the smallest prize.
	{
		cout<<"Would you like to bet on this game? Y/N"; // print the question on the screen
		cout<<endl; // go to the next line;
		while(1) // infinite loop
		{
			cin>>answear; // take the answear from the keyboard
			answear=tolower(answear); // convert the answear stricly on small letter lowecase letter to minimize switch's cases
			switch(answear) // test the variable "answear".
			{
				case 'y': // if the answear was 'y'.
				{
					cout<<"Place your bet: "; // print this message on the screen.
					cout<<endl;
					cout<<"A.10$	B.50$	C.100$	 D.500$"; //print this message on the screen.
					cout<<endl;
					while(1) // infinite loop;
					{
						cin>>answear; // take the answear from the keyboard;
						answear=tolower(answear); // convert the answear into lowecase.
						switch(answear) //test the answear;
						{
							case 'a': //if answear was 'a';
								{
									if(Cash>10)
									{
										bet=10; //make the bet =10;
										betplaced=true; // this variable becomes true, because the bet was placed.
										break;	
									}
								}	
							case 'b': //if answear was 'b';
								{
									if(Cash>=50) // if the cash are higher than 50;
									{
										bet=50; //make the bet=50;
										betplaced=true; //the bet was placed, so this is true;
										break;
									}
									else // enter here if the cash are lower than 50;
									{
										cout<< "You don't have enough money!";
										cout<< endl;
										break;
									}
								}
							case 'c': //if the answear was 'c';
								{
									if(Cash>=100) // check if the money are enough to place the bet;
									{
										bet=100; //if the cash are enough, place the bet;
										betplaced=true; // make this become true;
										break;
									}	
									else //enter here if the money are not enough;
									{
										cout<< "You don't have enough money!";
										cout<< endl;
										break;
									}
								}
							case 'd': // if the answear was 'd';
								{
									if(Cash>=500) // test if the cash are enough
									{
										bet=500; //place the bet, because once entered in this if statement it means that money
										//are enough.
										betplaced=true; // the bet was placed;
										break;
									}
									else // enter here only if it could enter above;
									{
										cout<< "You don't have enough money!";
										cout<< endl;
										break;
									}	
								}
							default: // if other answear was given;
								{
									cout << "Not an option";
									cout << endl;
									break;
								}		
						}
						if(betplaced==true) // if the bet was placed... leave the infinite loop;
						{
							break;
						}
					}	
					break; //leave the previous switch, because the case was found.
				}
				case 'n': //if the first answear of placing the bet was 'n';
					{
						bet=0; // there will be no bet;
						refuse=true;// the bet was refused.
						break;
					}
				default: // if other key was entered, print the message down, and loop again;
					{
						cout << "Not an answear!";
						cout << endl;
					}
			}
			if(betplaced==true||refuse==true) // if the bet was placed, or if there was a refuse, break the infinite loop;
			{
				break;
			}
		}
	}
}

char askreplay() //when the game is over, this function asks for replay;
{
	int j2;
	char ansgame;
	if(Gameover==true) // if the game has ended;
	{
		if(xwin==true)
		{
			Cash=Cash+bet;
			Score++;
		}
		if(xwin!=true)
		{
			Cash=Cash-bet;
		}
		for(j2=1;j2>0;j2++) //infinite loop
		{
			cout << "Play again? Y/N"; // printed message;
			cout << endl;
			cin >> ansgame; // getting the answear;
			ansgame=tolower(ansgame); //converting the answear to a low character, in order to minimize the switch's cases
			switch(ansgame)
			{
				case 'y': //if the answear is positive;
					{
						return ansgame;
					}
					case 'n': //if the answear is negative;
					{
						exit(1);
					}
					default: //answeared with a wrong key; 
						break;		
			}
		} // nothing gets out of here;
	}
}

bool askcontinue() //if wrong coordinates has been entered, this function, asks for some other;
{
	char answear;
	int k1;
	bool ans=false;
	cout << "Enter another position? Y/N"; //printed message;
	cout << endl;	
	for(k1=1;k1>0;k1++) //infinite loop;
	{
		answear=getchar();  //getting the answear;
		answear=tolower(answear); //converting the answear to a low character, in order to minimize the switch statement's cases
		switch(answear)
			{
				case 'y':
					{
						ans=true; //the bool variable is set true;
						break;
					}
				case 'n':
					{
						exit(1); //if the answear is n, close the game.
					}	
				default:
					{
						break; //for any other key, repeat the loop.
					}
			}
		if (ans==true) //if the bool is true, get out of here. 
		{
			break;
		}
	}
	//return ans;	// return the answear to the main function.
}

void cleanfile () //this function cleans the file, when a position becames occupied, also tries to randomize the O's placement.
{
	FILE *fp;
	fp=fopen("D://xando.txt", "w"); //file open for writing/rewriting.
	int randy=rand()%3; //choices for writing movements.
	int c=0; //counter
	bool step1,step2,step3=false; //steps travelled
	while(1) //infine loop
	{
		if(randy==0) //if rand() function has 0 value
		{
			for (int i=0;i<3;i++)
			{	for (int j=3-i-1;j<3;j++) // write first the second diagonal and the elements from downside of it
						if(a[i][j]=='.') //if a free position has been found
						{
							fprintf(fp," %d %d \n", i,j); //put the free coordinates back in the file, to be used.
						}
					
			}
			if(c==0) // if c=0, it means this is the first time in the loop, so enter here.
			{
				step1=true; //completed the step 1;
				randy=1; //let randy go into the next if statement
				c++; //let c is running  for the second time into the loop.
			}
			if(step2==true||step3==true) // if step2 is true, it means that c>0, so the statement above is ignored, and all the free positions
			//have been written to the file, but still c needs and incrementation to get out of the loop.
			{
				if(step3==true)
					randy=1;
					
				if(step2==true)
						randy=2;
				if(step2==true&&step3==true)
					randy=3;		
					
				step1=true;
				c++; //c variable has completed it's path, it's next step is to go out of the loop now.
			}
		}
		if(randy==1) //if randy is one, from the rand() function or from the if above, let it enter here.
		{	
			for (int i=0;i<2;i++)
			{	for (int j=0;j<2;j++) //copy elements in this way, copy only untile the second colomn, one element will be 
			//written twice, but it won't bother us at all.
						if(a[i][j]=='.')
						{
							fprintf(fp," %d %d \n", i,j); //put the free coordinates back in the file to be used.
						}
					
			}
			if(c==0) //if c is zero it means randy comes here with a value from the rand() function, so the if statement above
			//has been ignore, so let randy now store 0, to may enter into it.
			{
				step2=true; //if c let us enter here, it means step one is not completed yet, but step 2 it is, will let
				//go on, to step 1, by setting randy 0.
				randy=2;
				c++; //c is now one, so it will ignore this if from now on.
			}
			if(step1==true||step3==true)//if step one was completed, it means the if statement above us, was ignored, because c has already
			//the value of one. 
			{
				if(step1==true)
					randy=2;
					
				if(step3==true)
						randy=0;
				if(step3==true&&step1==true)
					randy=3;
					
				step2=true;	
				
				c++; // still we need value of two for c to exit from the infinite loop, so let have it now.
			}
		}
		//------------------
			if(randy==2) //if rand() function has 2 value
			{
			for (int i=0;i<3;i++)
				{	for (int j=0;j<=i;j++) // write first the second diagonal and the elements from downside of it
						if(a[i][j]=='.') //if a free position has been found
						{
							fprintf(fp," %d %d \n", i,j); //put the free coordinates back in the file, to be used.
						}
					
				}
				if(c==0) //if c is zero it means randy comes here with a value from the rand() function, so the if statement above
				//has been ignore, so let randy now store 0, to may enter into it.
				{
					step3=true; 
					randy=0;
					c++; //c is now one, so it will ignore this if from now on.
				}
				if(step1==true||step2==true)//if step one was completed, it means the if statement above us, was ignored, because c has already
				//the value of one. 
				{
					if(step2==true)
						randy=0;
					if(step1==true)
						randy=1;
					if(step2==true&&step1==true)
					randy=3;
					
					step3=true;
					c++; // still we need value of two for c to exit from the infinite loop, so let have it now.
				}
			}
		if(c==2||step1&&step2==true||step2&&step3==true||step1&&step3==true)//finaly here, c exits from infinity.
		{
			break;
		}
	}
	fclose(fp);	//close file;
}

void draw() // this function makes the draw, so it will put the x and the o into the table.
{
	int i,j;
	cout << endl;
	for (i=0;i<3;i++) // 3 rows
	{
		for(j=0;j<3;j++) // 3 colomns
		{
			cout << " ";
			cout << a[i][j]; // draw them.
			cout << " ";	
		}
		cout << endl;
	}
}

void reset() //if the game has ended, reset it.
{
	FILE *fp;
	fp=fopen("D://xando.txt", "w");
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
			{
				a[i][j]='.';
				fprintf(fp," %d %d \n", i,j); //write all the positions back in, the matrix is free again.
				Gameover=false; //let the game take place.
				bet=0;
				xwin=false;
				poscount=0; //all the positions are free.
			}		
	fclose(fp);			//close the file.
}

bool fct() //this function, checks for the winner.
{
	for (int i=0;i<3;i++)
	{
		for (int j=0;j<3;j++)
		{
			if(j==1&&Gameover!=true)//if we are in the first colomn
			{
				if(a[i][j]==a[i][j-1]&&a[i][j-1]==a[i][j+1]) //check for the winner.
				{
					switch (a[i][j])
					{
						case 'X':
							{
								xwin=true;
								cout << "X is a winner!";
								cout << endl;
								Gameover=true;
								return Gameover;
								break;	
							}
						case 'O':
							{
								cout << "O is a winner!";
								cout << endl;
								Gameover=true;
								return Gameover;
								break;	
							}
						default :
						{
							break;
						} 		
					}
				}
				if(Gameover==true)
				{
					break;
				}
			}
			if(i==1&&Gameover!=true) //if we are in the first row.
			{
				if(a[i-1][j]==a[i][j]&&a[i][j]==a[i+1][j])//check for the winner
				{
					switch (a[i][j])
					{
						case 'X':
							{
								xwin=true;
								cout << "X is a winner!";
								cout << endl;
								Gameover=true;
								return Gameover;
								break;	
							}
						case 'O':
							{
								cout << "O is a winner!";
								cout << endl;
								Gameover=true;
								return Gameover;
								break;	
							}
						default:
							{
								break;
							}		
					}
				}
				if(Gameover==true)
				{
					break;
				}
			}
			if(i==1&&j==1&&Gameover!=true)//if we are in the middle position
			{
				if(a[i-1][j-1]==a[i][j]&&a[i][j]==a[i+1][j+1]) // check for the winner
				{
					switch (a[i][j])
					{
						case 'X':
							{
								xwin=true;
								cout << "X is a winner!";
								cout << endl;
								Gameover=true;
								return Gameover;
								break;	
							}
						case 'O':
							{
								cout << "O is a winner!";
								cout << endl;
								Gameover=true;
								return Gameover;
								break;	
							}
						default:
							{
								break;
							}		
					}
					if(Gameover==true)
					{
						break;
					}
				}
				
				if(a[i-1][j+1]==a[i][j]&&a[i][j]==a[i+1][j-1])
				{
					switch (a[i][j])
					{
						case 'X':
							{
								xwin=true;
								cout << "X is a winner!";
								cout << endl;
								Gameover=true;
								return Gameover;
								break;	
							}
						case 'O':
							{
								cout << "O is a winner!";
								cout << endl;
								Gameover=true;
								return Gameover;
								break;	
							}
						default:
							{
								break;
							}		
					}
					if(Gameover==true)
					{
						break;
					}
				}
			}
		}
		if(Gameover==true)
		{
			break;
		}
	}
}

void nowinner() // this function checks if the game ended as a draw.
{
	int elemctr=0;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
		{
			if(a[i][j]=='X'||a[i][j]=='O') // if a position is occupied
			{
				elemctr++;
			}
		}
		if(elemctr==9&&Gameover!=true) // of all positions are occupied, game is not ended, the fct() function found no winner
		{
			cout<< "Match ended as a draw";
			cout<< endl;
			Gameover=true; //end the game up, because there are no free positions.
		}
}

void map () // first map - at the game's start;
{
	int i,j;
	cout << endl;
	for (i=0;i<3;i++) // 3 rows
	{
		for(j=0;j<3;j++)
		{
			cout<< " ";
			cout<<a[i][j]; //draw the first table.
			cout<< " ";	
		}
		cout << endl;
	}
	cout << "Cash: ";
	cout << Cash;
	cout << "$";
	cout << endl;
	cout << "You score is: "; //print the score
	cout << Score;
		if(Score==0) //if the score is 0;
		{
			cout << ". You are playing the first match!";
			cout << endl;
		}
	cout << endl;
}

int main() //the heart of the game.
{
	FILE *fp;
	bool ans,check,outrange,ocalled,postpone;
	char ansgame;
	int i;
	map ();
	cleanfile();
	placebet();
	for (i=1;i>0;i++) //infinite loop, the game ends only when it's specified.
	{
		postpone=false;
		outrange=true;
		ans=false;
		if(check==true) //if the X is chosen, and the O is chosen
		{
			check=false;
			ocalled=false;
			draw(); // draw them on the table.
			fct(); // check for the winner.
			nowinner(); //check for a draw.
			cleanfile(); //clean the file, let only the free position.
			ansgame=askreplay(); //if the game is ended, ask for replay.
			if(ansgame=='y') //if answear for replay is 'y'.
			{
				system("cls"); //let the console be cleared.
				reset(); // reset the game.
				map();
				placebet();
			}
		}
		Xrow,Xcol=4; // initialization of the x coordinates.
		cout << "Enter the coordinates for X";
		cout << endl;
		cout << "row = ";
		cin >> Xrow; //take the coordinates for the x;
		cout << "col = ";
		cin >> Xcol; //take the coordinates for the x;
		cout << endl;
		if(Xcol>2 || Xrow>2 || Xcol<0 || Xrow<0) //if the x coordinates are not valid.
		{
			cout << "Out of the table";
			cout << endl;
			askcontinue(); //ask if you want to answear again
			postpone=true;
		}	
		if(Xrow<3 && Xrow >=0 && Xcol<3 && Xcol>=0) //enter here only if the x coordinates are valid.
		{
			outrange=false; //if the coordinates are valid, this one's value must be false.
			if(a[Xrow][Xcol]!='X'&&a[Xrow][Xcol]!='O') //if the x coordinates represents a free position.
			{
				cout << "X is done";
				cout << endl;
				check = true; //the x is checked, so it can be drawed on the table later.
				a[Xrow][Xcol]='X'; //get 'X' value on this coordinates.
				cleanfile(); // the X is set, so clear it's position from the file, because it became occupied.
				fct(); // check for the winner.
				poscount++; // one more position has been occupied.
			}
			if(check!=true) //if the entered coordinates for X are occupied.
			{		
				cout << "Position occupied!"; //print this message on the screen.
				cout << endl;			
				askcontinue(); //ask if the user wants to enter another position.
				postpone=true;
			}		
		}
		cout << "before final if";
		cout << endl;
//		-----------------------------------------------------------------
		if(postpone!=true&&poscount<9) // if the game was not intrerupted by wrong coordinates of X, enter here.
		{
			if(!feof(fp)) //check if the file has values into it.
			while(1) // infinite loop
			{
				fp=fopen("D://xando.txt", "r"); //open this file for reading.
				fscanf (fp, "%d %d", &Orow, &Ocol); //get this coordinates for O
				cout << "Coord read from file are: "; 
				cout << Orow;
				cout << Ocol;
				cout << endl;
				cout << "in while";
				cout << endl;
	
				if(a[Orow][Ocol]=='.') // if the coordinates are good
				{
					poscount++; //one more position has been ocuppied.
					a[Orow][Ocol]='O'; // get O to this coordinates.
					fct(); // check for the winner.
					ocalled=true; //the O has been set.
					cleanfile(); //clean the file, erase O's position from there.
				}
				if(ocalled==true) // if the O has been set.
				{
					break; // get out from the infinite loop.
				}
				else //if the O is not set, we are stuck in the infinite loop, clean the file, maybe there is a wrong value.
				{
					cleanfile();
				}
			}
		}	
		if(ocalled==true) //if the O has been set, let the user see where is was placed.
		{
			cout << "Coordinates of zero are: ";
			cout << Orow;
			cout <<" ";
			cout << Ocol;
			cout << endl;	
		}
		if(outrange==true) // if X's coordinates we're out of range
		{
			cout << "Wrong value has been entered!";
			cout << endl;
		}
		fclose(fp); //close the file, prepare for iteration.
	}	
		
	_getch(); // let the console's screen stay open.
	return 0; // return nothing back, after closing.
}
