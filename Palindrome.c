#include<stdio.h>
#include<string.h>

int main(){
	char s[20];
	gets(s);
	int i, l=strlen(s);
	int j =strlen(s)-1;
	for(i=0;i<l/2;i++,j--){
		 if(s[i]!=s[j]){
		 	printf("not");
		 	return 0;
		 }
	}
	printf("yes");
	return 0;
}