

#include "Stdio.h"

double median(double h,double b,double c);

int main(void)
{
    int i=0,j=0;
  /*  double orgData[20]={NULL}; */
    double orgData[20]={0.00, -0.07, 0.08, -0.01, 1.44, 0.00, 0.00, 0.07, -0.01, 0.00, 0.97,0.96, 1.02, 0.93, 0.9, 0.24, 1.01, 1.04, 1.01, 1.02};
    double medData[20]={NULL};
 /* printf("Enter array (MAX.20):");
    while(i<20){
        scanf("%f",&orgData[i]);
        i++;
    }
  */
    for(j=0;j<20;j++){
        if(j<=1||j>=18){
            medData[j]=orgData[j];
        }
        else{
            medData[j]=median(orgData[j-2],orgData[j-1],orgData[j]);
        }
    }
    printf("The filtered array is:\n");
    for(j=0;j<20;j++){
        printf("%5.2f  ",medData[j]);
        if((j+1)%5==0){
            printf("\n");
        }
    }
    getch();
    return 0;
}

double median(double h,double b,double c)
{
    double a[3]={NULL};
    double temp;
    int i,j=0;

    a[0]=h;
    a[1]=b;
    a[2]=c;

    for(i=1;i<3;i++){
        for(j=0;j<2;j++){
            if(*(a+j)>*(a+j+1)){
                temp=*(a+j);
                *(a+j)=*(a+j+1);
                *(a+j+1)=temp;
            }
         }
     }
     return a[1];
}

