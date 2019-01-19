#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

//Producer method written by Jessica Callegaro


void producer(){
	char c;
	char t;

	// Open my data.txt
	FILE *p;
	while( (p = fopen("mydata.txt", "rt")) == NULL);
	
	//read one character from mydata
	//c = fgetc(p);
	
	//while the end of my data is not reached
	while(!feof(p)){
		// open TURN.txt
		FILE *turn;
		while((turn = fopen("TURN.txt", "r+")) == NULL);
		
		
		//read TURN.txt and then close
		t = fgetc(turn);
		rewind(turn);
		fclose(turn);

		//if TURN is ‘0’ (48) then open DATA.txt and write the char from mydata
		if(t == 48){
			//read one character from mydata
			c = fgetc(p);

			FILE *data;
			while( (data = fopen("DATA.txt", "r+")) == NULL);
			
		
			fputc(c, data);
			fclose(data);
			
			// write ‘1’ (49) to indicate consumer’s TURN
			FILE *turn;
			while( (turn = fopen("TURN.txt", "r+")) == NULL);
			
			fputc(49,turn);
			fclose(turn);

		}
	}
	fclose(p);
}

