#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main()
{

	int key;
	int number;
	int coins;
	char answear;
	PAR2:coins = 100;
	if(coins==0)
	{
		
	}
	printf("You have: %d$\n", coins);
	PAR1:printf("Enter a number between 1 and 5: \n");
	
	if(scanf("%d", &number)==0)
	{
		printf("You have entered a wrong number:\n");
		goto PAR1;
	}
	if(number>5 || number <1)
	{
		printf("The number does not exist on the table!\n");
		goto PAR1;
	}
	
	printf("Your number is: %d\n", number);
	key=(rand ()%5)+1;
	if(key==number)
	{
		printf("Congratulations! You have won 10$.\n");
		coins = coins+10;		
	}
	else 
	{
		printf("You are not so lucky this time!\n");
		coins = coins-10;
		if(coins==0)
		{
		PAR3:printf("Sorry but you have no dollars left. Try again Y/N?\n");
		answear = getch();
		switch (answear)
		{
			case 'Y': {
				
				goto PAR2;
			}
			case 'y':{
				goto PAR2;
			}
			case 'N': {
				
				exit(1);
			}
			case 'n':{
				exit(1);
			}
			default: {
				goto PAR3;
			}
			
		}
		
		}
	}		
		/*if(answear == 'Y' || 'y')
		{
			goto PAR2;
		}
		if(answear == 'N' || 'n')
		{
			exit(1);
		}
		else
		{
			printf("Your answear is uncertain! Try again!\n");
			goto PAR3;
		}
		}*/
	
	printf("The extracted number is: %d\n", key);
	printf("You have: %d$\n", coins);
	goto PAR1;

	getch();
	return 0;
}


