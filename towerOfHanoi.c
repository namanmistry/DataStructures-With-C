#include<stdio.h>

int disk1;

void main(){
printf("Enter the number of disk on source: \n");
scanf("%d",&disk1);
hanoi(disk1,'A','B','C');
}

void hanoi(int disk,char source,char aux,char dest){
    if(disk==1){
        printf("Disk 1 moved from %c to %c\n",source,dest);
    }
    else{
        hanoi(disk-1,source,dest,aux);
        printf("Disk %d moved from %c to %c\n",disk,source,dest);
        hanoi(disk-1,aux,source,dest);
    }
}

