#include<stdio.h>
#include<stdlib.h>
void toh(int n,char from,char to,char aux){
    if(n==0) return;
    toh(n-1,from,aux,to);
    printf("Move disc  %d from rod %c to rod %c\n",n,from,to);
    toh(n-1,aux,to,from);
}
int main(){
    int num;
    printf("ENter number of discs : ");
    scanf("%d",&num);
    char A='A',B='B',C='C';
    toh(num,A,B,C);
    return 0;
}