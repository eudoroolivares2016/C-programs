#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Eudoro Olivares 
Read the contents of a file
find out how many lines are in the file so you can allocate the right amount of space for the structure vi malloc
put the contents into an array of structures  Struct  dividing the struct
/ open up the main menu to the user and take input into a switch statement
sort the structure by the values inside of them depending on what they chose for the switch
print out the values of the sorted stuff
*/
struct car { /*creates the structure car with the members name,model,price,color  */ 
char name[42]; // apperently this is the answer to the universe
float model;
int price;
char color[42]; // apperently this is the answer to the universe
}car; // creates an instance 

// I spelled arrayptr wrong but, I ran with it all the way through
void sortByFloat( struct car *arryptr, int count)
{ 
int i, j;
struct car *swap; // creates a tempory pointer of type struct car to store the strcutrue that is getting shifted 
swap = (struct car*)calloc(1,sizeof(struct car));   // allocates space and creates the swap array structure
for (i = 0; i < count-1; i++){
    for (j = 0; j < count-i-1; j++){
		if (arryptr[j].model > arryptr[j+1].model) // if the value of the model in the strucutre is bigger swap them 
        {
            swap[0] = arryptr[j]; // put in temp struct array 
            arryptr[j] = arryptr[j+1];
        arryptr[j+1] = swap[0];
        }


}

}
free(swap); //frees swap
}


void sortByInteger( struct car *arryptr, int count)
{ 
int i, j;
struct car *swap;
swap = (struct car*)calloc(1,sizeof(struct car));
    for (i = 0; i < count-1; i++){
    for (j = 0; j < count-i-1; j++){
		if (arryptr[j].price > arryptr[j+1].price)
        {
            swap[0] = arryptr[j];
            arryptr[j] = arryptr[j+1];
        arryptr[j+1] = swap[0];
        }


    }


}
free(swap);

}


void printLowToHigh(struct car *arryptr, int count){


int index;
int structNumber = 0; 
// starts at the begining of the array 
for(index = 0; index < count; index++) // count is the size of the array UND Home Page
{

printf("Struct Number: %d\n name: %s\n Model: %.1lf \n Price: %d\n color: %s\n",structNumber,arryptr[index].name, arryptr[index].model, arryptr[index].price, arryptr[index].color);
structNumber++;

} 


}




void printHighToLow(struct car *arryptr, int count){


int index;
int structNumber = 0; 
// same but, backwards
for(index = count-1; index >= 0; index--)
{

printf("Struct Number: %d\n name: %s\n Model: %.1lf \n Price: %d\n color: %s\n",structNumber,arryptr[index].name, arryptr[index].model, arryptr[index].price, arryptr[index].color);
structNumber++;

} 


}



void fileReader(int whichType, int whichOrder){
FILE *fPointer;
fPointer = fopen("hw3.data","r");
int c;
int count =0;

while(1){
    c = fgetc(fPointer); //file get chracter gets one character from the fiile starting at the top and then reads through it 
    if(feof(fPointer)){
    break; // breaks when it gets to the end of the file 
    }

    if(c == '\n')
    {
    count++; // if it gets a new line character then it will increment count to get the total number of car structures we need in the array

    }

}

//printf("%d",count); 

struct car *info;
// creates an empty pointer of type struct car 

info = (struct car*)calloc(count,sizeof(struct car )); // this creates the actual array of type struct car 

rewind(fPointer); // takes you back to the top of the file without having to repoen it since we were at the bottom due to feof()


int position =0; //This will be 4 positions long just like in the example text 
char tempString[42];

for(int i =0; i < count; i++  ){
    for(int j = 0; j < 4; j++){

fscanf(fPointer, "%s", tempString); // readers the f pointer and putting the contents of each member into a tempString 

    if(position >= 4) // because we only have 4 positions/ members of the structure car 
    {

    position = 0; // reset to the next line


    }

    if(position == 0){

    strcpy(info[i].name,tempString);

    }

    if(position == 1){

    info[i].model = atof(tempString); // converts the temp String into a float and puts it in the correct position

    }

    if(position == 2){


    info[i].price = atoi(tempString);



    }

    if(position == 3){

    strcpy(info[i].color,tempString);


    }


    position = position +1;
}

}

    if(whichType == 0) // does the sorting by integer values

    {

    sortByInteger(info,count);

    }

    if(whichType == 1) // does the sorting by float values
    {

    sortByFloat(info,count);

    }


// next this will decide which way to print the results 



    if(whichOrder == 0) // low to high 
    {

    printLowToHigh(info,count);

    }


    if(whichOrder == 1)// from high to low 

        {



    printHighToLow(info,count); 


    }
free(info); // frees the memory allocation
fclose(fPointer); // closes the file 

}





int main()
{
int choice =0;
while(1){
printf("What would you like to do? \n Enter 1 to sort the array by its float value from low to high \n Enter 2 to sort the array by its float value from high to low \n Enter 3 to sort the array by its integer value from low to high \n Enter 4 to sort the array by its integer value from high to low \n Enter 5 to exit");
scanf("%d",&choice);// gets user input on the choice he wants 
    if(choice == 1){ // prints float low to high

    fileReader(1,0);

    }

     else if(choice == 2) // prints the array from high to low by float 
    {

    fileReader(1,1);

    }


    else if(choice == 3) //low to high by integer 
    {

    fileReader(0,0);
    }



    else if(choice == 4) // high to low by integer 
    {

    fileReader(0,1);

    }



    else if(choice == 5){ //exits the program

    exit(0);
    }

    else{
    printf("Sorry wrong input"); // error handling 

    exit(0);

    }

    }

}
