#include<stdio.h>
#include<stdlib.h>

void main(){
    int *ptr,sum=0;
    ptr=(int*)malloc(10*sizeof(int));
    printf("Enter The Elements: \n");
    for(int i=0;i<10;i++)scanf("%d",&ptr[i]);
    for(int j=0;j<10;j++)sum=sum+ptr[j];
    printf("Your Answer Is:%d\n",sum);
    free(ptr);
}