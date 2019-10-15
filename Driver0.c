#include<stdio.h>
#include<string.h>
#include"ArrayLib.h"//testing compilation of ArrayLib


int main(){
// MENU SECTION
/*The menu should prompt user to input data coresponding to
what datatype they want to use, what sorting method they use,
what sorting algorithm they use, and what element to search
for.*/
	int mode, input; //declares input and mode.
	//mode is sorting algorthm varriable
	/*input is a catch all varriable to avoid user input going directly into
	other varriables*/
	scanf("%d",&input);
	if(input==1){mode+=6;} //recomend putting scanf's into do wile loops
	input=0;
	while(input>6 || input<1){
		scanf("%d",&input);
	}
	mode+=input;
	if(mode==1){}
	else if(mode==2){}
	else if(mode==3){}
	else if(mode==4){}
	else if(mode==5){}
	else if(mode==6){}
	else if(mode==7){}
	else if(mode==8){}
	else if(mode==9){}
	else if(mode==10){}
	else if(mode==11){}
	else if(mode==12){}
	else{}

	return 0;

}
