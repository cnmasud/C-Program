#include<stdio.h>
int main(){
	int arra[]={1,2,3,4,5};
	int size = sizeof(arra)/sizeof(arra[0]);
	
	printf("original array: ");
	for(int i=0;i<size;i++){
		printf("%d ",arra[i]);
	}
	printf("\n");
	printf("reverse array: ");
	for(int i=0, j=size-1;i<j;i++,j--){
		int temp = arra[i];
		arra[i]= arra[j];
		arra[j]=temp;
	}
	for(int i=0;i<size;i++){
		printf("%d ",arra[i]);
	}
	
	
	return 0;
}