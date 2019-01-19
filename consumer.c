#include <stdlib.h>
#include <stdio.h>


void consumer(){
	
	FILE *data;
	int x=1;

	while(x==1){ //this is an infinite loop, it will only exit when mydata.txt reaches the end 

		FILE *turn;
		char letter;
		char who;

		while( (turn = fopen("TURN.txt", "rt")) == NULL);
		who = fgetc(turn);
		fclose(turn);

		if(who=='1'){ //this makes sure that it is consumer's turn

			while( (data = fopen("DATA.txt", "rt")) == NULL);
			letter = fgetc(data);
			fclose(data);
			
			if(letter < 0) exit(1);
			//this is for when producer reaches EOF, 
			//it will send an ASCII that is less than 0
			//and this will tell consumer to exit()
			
			printf("%c", letter);

			while( (turn = fopen("TURN.txt", "r+")) == NULL);
			fputc(48, turn);
			fclose(turn);
		}

	}



}
