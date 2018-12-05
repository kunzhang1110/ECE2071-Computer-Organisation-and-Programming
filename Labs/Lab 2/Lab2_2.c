#include "Stdio.h"

int main(void)
{
  float r1,r2,i,i1,i2,v,p1,p2,pall=0;
  int n,j=0;

  printf("Enter the values of R1 R2 I1 n seperated with a sapce:");
  scanf("%f %f %f %d",&r1,&r2,&i,&n);
  printf("Number    I1    I2    Power\n");

  for(j=1;j<=n;j++){
    i1=((float)(j-1)/(n-1))*i;
    i2= i-i1;
    p1=i1*i1*r1;
    p2=i2*i2*r2;
    pall=p1+p2;
    printf("%6d%6.2f%6.2f%9.2f",j,i1,i2,pall);
    if(j==1||j==n){
        printf("    MAX");
    }
    else if(((n%2==0)&&(j==n/2||j==n/2+1))||((n%2==1)&&(j==n/2+1))){
        printf("    MIN");
    }
    printf("\n");

  }
  getch();
  return 0;
}
