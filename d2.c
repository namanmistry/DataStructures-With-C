#include<stdio.h>
#include<stdlib.h>

void main(){
    float *ptr,mul=1;
    ptr=(float*)calloc(10,sizeof(float));
    printf("Enter The 10 Elements\n");
    for(int i=0;i<10;i++)scanf("%f",&ptr[i]);
    for(int j=0;j<10;j++)mul=mul*ptr[j];
    printf("Your Answer Is:%f",mul);
    free(ptr);
}