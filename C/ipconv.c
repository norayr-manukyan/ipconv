#include <stdio.h>
#include <string.h>


int * tobinary(int decimal) {
	int currbin,binary[32],currbinary[32],currbinlen,i,m, number = 0; 
	
	i=0;
	for(decimal; decimal/2 > 0 ; decimal/=2){
		if (decimal % 2 == 1){
			currbinary[i] = 1;
		}
		else currbinary[i] = 0;
		i++;
	}
	if (decimal % 2 == 1) {currbinary[i] = 1;}
	else currbinary[i] = 0;
	i++;
	currbinlen = i;
	currbin = i-1;
	for(i= 0; i<32;i++ )
	{
		if (i < 32-currbinlen) {
			binary[i] = 0;
		}
		else { binary[i] = currbinary[currbin]; currbin--;}
	}

	for (int i= 0; i <32; i ++)
	{
		printf("i = %d\n", binary[i]);
	}


return  binary;
}








