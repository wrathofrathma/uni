#include <stdio.h>
#include <stdlib.h>

int ch_to_int(char c){
	int zero='0';
	int num=c-zero;
	if(num<0 || num>9){
		printf("NaN\n");
		exit(-1);
	}
	return num;
}

int st_to_int(char *str){
	int total=0;
	int index=0;
	while(str[index]!='\0'){
		total+=ch_to_int(str[index]);
		total*=10;
		index++;
	}
	total/=10;
	return total;
}

int main(int argc, char**argv){
	if(argc<2){
		printf("Please input some numbers\n");
		return -1;
	}
	int sum=0;
	for(int i=1; i<argc; i++){
		sum+=st_to_int(argv[i]);
	}
	printf("sum %d\n", sum);
	return 0;
}
