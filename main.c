#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void producer();
void consumer();


int main(){
	FILE *turn = fopen("TURN.txt", "wt");
	fputc('0', turn);
	fclose(turn);

	FILE *data = fopen("DATA.txt", "wt");
	fclose(data);

	int pid = fork();
	if(pid == -1){
                exit(1);
        }
	if(pid == 0){
		consumer();
		
	}
	if(pid != 0){
		producer();
	}

}
