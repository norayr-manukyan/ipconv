#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>
#include <string.h>

int* tobinary(int decimal) {
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

	for (int i= 0; i < 32; i ++)
	{
		printf("i = %d\n", binary[i]);
	}

	return  binary;
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
					tobinary(x);
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
