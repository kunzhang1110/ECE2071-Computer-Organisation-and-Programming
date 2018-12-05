#include "Stdio.h"

double simp(double a,double b,double c,double h);
double simpsq(double a,double b,double c,double h);

int main(void)
{
    double h=0,slope=0,isquare=0,isum=0;
    double integ[10]={NULL},line[21]={NULL},integsq[10]={NULL};
    int i;

    h=0.002/2;
    slope=(0.7-0.3)/(0.02);

    for(i=0;i<=20;i++){
        line[i]=0.3+slope*i*h;
    }

    for(i=0;i<=9;i++){
        integ[i]=simp(line[2*i],line[2*i+1],line[2*i+2],h);
        integsq[i]=simpsq(line[2*i],line[2*i+1],line[2*i+2],h);
    }
    for(i=0;i<=9;i++){
        isquare+=integsq[i];
        isum+=integ[i];

    }
    printf("%f   %f   adfafa",isquare,isum);
    printf("Diode Power:%f\nFet Power:%f",0.7*isum/0.04,1.25*isquare/0.04);

    getch();
    return 0;
}
/*Simpson 1/3 Rule*/
double simp(double a,double b,double c,double h)
{
    double intp;
    intp=(h/3)*(a+4*b+c);
    return intp;
}

double simpsq(double a,double b,double c,double h)
{
    double intp;
    intp=(h/3)*(a*a+4*b*b+c*c);
    return intp;
}
        
