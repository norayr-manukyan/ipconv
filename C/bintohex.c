char * bintohex(int binary[]){
 char *hex = (char*) malloc(8 * sizeof(char));
 int i, j, num = 0, y[] = {8,4,2,1};

 for(i = 0; i < 8; i++){
  for(j = 0; j < 4; j++){
   num = num + y[j] * binary[4*i+j];
  }
  switch(num){
   case 10 :
    hex[i] = 'A';
    break;
   case 11 :
    hex[i] = 'B';
    break;
   case 12 :
    hex[i] = 'C';
    break;
   case 13 : 
    hex[i] = 'D';
    break;
   case 14 :
    hex[i] = 'E';
    break;
   case 15 : 
    hex[i] = 'F';
    break;
   default :
    hex[i] = num + '0';
  }
  num = 0;
 }

 return hex;
}



