/*--------------------------------------------------------------------------
	Title	:	B&W chapter 3 programming problem 3
	Source	:   FACTORLS.C
	Date	:	27 April 1996
	Modified:	14 January 2013 - Change getch() to getc().
	Author	:   P.A. Morris
	Input	:	One non-negative integer, n.
	Output	:	The value a n!, or a table showing all factorial values from
				0! to n! at the user's option.
Description	:	A menu-driven interactive program.
				References to Borland conio.h removed in 2013.
--------------------------------------------------------------------------*/

#include	<stdio.h>
#include	<ctype.h>		/*	needed for toupper()	*/

void		singlefactorial(void),	multifactorial(void);

long int 	factorial(int number);	/*	long int needed since !s are BIG,
									this will allow up to 13!.			  */

int main(){
	char	option;

	while( 1 ){					/*	infinite while loop			*/
		printf("\n\t!!Factorials!!\t\tS .. Simple factorial of a number");
		printf("\n\t(c) P.A. Morris\t\tT .. Table of factorials"
				" from 0 to your number");
		printf("\n\t1996\t\t\tESC  Exit the program\n\n\t?");

		option = toupper(getc());	/*	trap lower-case entry		*/
		switch( option ){
			case'\x1b':	exit(0);	/*	ESC to leave the while loop	*/
			case'S':	singlefactorial();
						break;
			case'T':	multifactorial();
						break;
/*		default:	printf("\nEnter S, M, or ESC to exit...");
						break;                                  */
		}
	}
}

/*------------------------------------------------------------------------*/

void singlefactorial(void){
	int number;

	printf("\bEnter an integer between 1 and 13..:");

	scanf("%d", &number);
	if(( number > 0 ) && ( number < 14 )){
		printf("\n\n\t%d! is %ld\n\n\t?",
				number, (long int) factorial(number));
	}
	else{
		printf("\n\n\tNumber out of range...Hit a menu key and try again...");
	}
}

/*------------------------------------------------------------------------*/

void multifactorial(void){
	int number, i;

	printf("\bEnter an integer between 1 and 13..:");

	scanf("%d", &number);
	if(( number > 0 ) && ( number < 14 )){
		printf("\n\tNumber\tFactorial");
		for(i = 0; i <= number; i++){
			printf("\n\t%d\t%ld", i, (long int) factorial(i));
		}
	}
	else{
		printf("\n\n\tNumber out of range...Hit a menu key to try again");
	}
	printf("\n\n\t?");
}

/*------------------------------------------------------------------------*/

long int factorial(int number){
	int i;
	long int value;

	value = 1;
	for(i = 1; i <= number; i++){
		 value *= i;
	 }
	return value;
}

/*========================================================================*/

