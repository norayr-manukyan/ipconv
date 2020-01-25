#include <stdio.h>

int main() {
  
int x[] = {0,1,0,0,1,0,0,1,1,0,0,1,0,1,1,0,0,0,0,0,0,0,1,0,1,1,0,1,0,0,1,0};

int y[] = {128,64,32,16,8,4,2,1};

int num = 0;
int i,j;
for (int i = 0; i < 4; i++) {
	for (int j = 0; j < 8; j++ ) {
		num = num + y[j] * x[8*i+j];
			
	}

	printf("%d.", num);
	num = 0;	
}

}
