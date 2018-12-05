#include "stdio.h"
#include "math.h"

int main(int argc,char*argv[])
{
    const double q=1.6*pow(10,-19);
    const double k=1.38*pow(10,-23);
    const double eta=1.5;
    const double Is=pow(10,-12);

    double T,R,Vb, Vd,Vdold=0;

    printf("Enther the diode temperature in Kelvin:");
    while(scanf("%lf",&T)&&(T<200)){
        printf("Don't forget dgrees Kelvin. Try again\n");
    }

    printf("Enther the series resistance in Ohms:");
    scanf("%lf",&R);
    if(R<=0){
        printf("Incorrect resistor value. Try again:");
        scanf("%lf",&R);
    }

    do{
        printf("Enter the batter voltage:");
        scanf("%lf",&Vb);
    }while(Vb<=0);

    printf("Enter an initial guess for the diode voltage:");
    scanf("%lf",&Vd);

    printf("Diode Voltage is:%-10.7lf\n",Vd);

    do{
        Vdold=Vd;
        Vd=((eta*k*T)/q)*log(((Vb-Vdold)/R)/Is+1);
        printf("Diode Voltage is:%-10.7lf\n",Vd);
    } while(sqrt((Vdold-Vd)*(Vdold-Vd))<0.0000001);

    printf("Diode voltage is:%-10.7lf\n",Vd);
    printf("\n");





    getch();
    return 0;
 }
