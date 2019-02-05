/* 
Eudoro Olivares
CSCI 230 
Homework1
*/


#include<stdio.h>
#include<stdlib.h>
int main()
{
float r = 0.25; // interest rate 
float B = 2000.0; // the loan 
float P =0; // Instantiating the user input

printf("Please enter your monthly payment rate");

scanf("%f", &P); // uses the Scanner to get the user input for the monthly payment

printf("r = %.2f",r);
printf("\nB = %.2f",B);
printf("\nP = %.2f",P);


float I =0; // instantiating the interest payment

I = (r/12)*B; // gets the first value for the interest payments


int count = 1; // this is a count for the number of months that it takes to pay off the loan and the interest 

float total =0;

// formats the text 
printf("\n");
printf("\n");
while(B > 0-P) // this allows us to acess all months including the term right after the loan has been payed off 
{

//.2f will give us two decimal places 


printf("%d %.2f %.2f\n",count,I,B);

// this ignores adding the last term so that it does not reduce the total  
if(I > 0){

total += I;


}
//using the given formulas to calculate B and I
B = (B-P +I);
I = (r/12.0)*B;
count++; // tracks the number of months that have passed
  

}



 // prints out the total interest two decimal places foward.
printf("\n");
printf("Total intrest paid: %.2f", total); 



return 0;

}
