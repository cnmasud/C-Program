#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
	char str[50];
	gets(str);
	int uppercase=0, lowercase=0, digits=0, others=0;
	int len= strlen(str);
	for(int i=0;i<len-1;i++){
		char c= str[i];
		if(isupper(c))
			uppercase++;
		else if(islower(c))
			lowercase++;
		else if(isdigit(c))
			digits++;
		else
			others++;
	}
	printf("total uppercase %d \n", uppercase);
	printf("total lowercase %d \n", lowercase);
	printf("total digits %d \n", digits);
	printf("total others %d \n", others);
	return 0;
}