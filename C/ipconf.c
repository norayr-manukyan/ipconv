#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>
#include <string.h>

int* tobinary(int decimal) {
	int currbin, currbinary[32], currbinlen, i, m, number = 0;
    int *binary = (int*) malloc(32 * sizeof(int));

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
	return  binary;
}


int * bintoip(int binary[]){

	int * bintoip(int binary[]){
	int *ip = (int*) malloc(4 * sizeof(int));
	int num = 0, y[] = {128,64,32,16,8,4,2,1}, i, j;

	for(i = 0; i < 4; i++){
		for(j = 0; j < 8; j++){
			num = num + y[j] * binary[8*i+j];
}
		ip[i] = num;
		num = 0;
}

return ip;

	}




int main (int argc, char *argv[]){

	const char* short_options = "h:p:x:c:n:";

	const struct option long_options[] = {
		{"help", no_argument, NULL, 'h'},
		{"dectoip", optional_argument, NULL, 'p'},
		{"iptodec", optional_argument, NULL, 'c'},
		{"iptohex", optional_argument, NULL, 'x'},
        {"iptobin", optional_argument, NULL, 'n'},
        {NULL, 0, NULL, 0}
	};

	int rez, x;
    int option_index;
    int* binary;		

	while ((rez=getopt_long(argc, argv, short_options, long_options, &option_index)) != -1){
		switch(rez){
			case 'h': {
				printf("This is demo help. Try -h or --help.\n");
				printf("option_index = %d (\"%s\",%d,%c)\n",
					option_index,
					long_options[option_index].name,
					long_options[option_index].has_arg,
					long_options[option_index].val
				);
				break;
			};
			case 'p': {
				if (optarg){
                    x = atoi(optarg);
					binary = tobinary(x);
	                for (int i= 0; i < 32; i ++)
	                {
		                printf("i = %d\n", binary[i]);
	                }
                    printf("%d\n", x);
                }
                else
					printf("found size without value\n");
				break;
			};
			case 'c': {
				printf("file = %s\n",optarg);
				break;
			};
            case 'x': {
				printf("file = %s\n",optarg);
				break;
			};
            case 'n': {
				printf("file = %s\n",optarg);
				break;
			};
			case '?': default: {
				printf("found unknown option\n");
				break;
			};
		};
	};
	return 0;
};
