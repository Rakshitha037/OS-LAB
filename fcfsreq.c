#include<stdio.h>
#include<stdlib.h>
int main()
{
    int RQ[100],i,n,TotalHeadMoment=0,initial;
    printf("Enter the number of request:\n");
    scanf("%d",&n);
    printf("Enter the request sequences:\n");
    for(i=0;i<n;i++)
    scanf("%d",&RQ[i]);
    printf("Enter the initial head position:\n");
    scanf("%d",&initial);
    printf("sequence of request access:\n");
    for(i=0;i<n;i++)
    {
        printf("%d",RQ[i]);
        TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
        initial=RQ[i];
       
       
    }
    printf("\n Total head mment is %d",TotalHeadMoment);
   
}
//output:
// Enter the number of request:
// 7
// Enter the request sequences:
// 82
// 170
// 43
// 140
// 24
// 16
// 190
// Enter the initial head position:
// 50
// sequence of request access:
// 82170431402416190
//  Total head mment is 642