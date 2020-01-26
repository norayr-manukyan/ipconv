#include <stdio.h>

int * bintoip(int binary[]) {

   int *ip = (int*) malloc(4*sizeof(int));
   int num = 0, y[] = {128,64,32,16,8,4,2,1}, i, j;

for (int i = 0; i < 4; i++) {
	for (int j = 0; j < 8; j++ ) {
		num = num + y[j] * binary[8*i+j];
	}
	ip[i] = num;
	num = 0;	
}

	return ip;
}
