#include <stdio.h>
#include <math.h>

int main()
{
	float r,vout,temp;
	const float b=2500,k=0.34094;
	
	printf("Vout is:");
	scanf("%f",&vout);
	r=vout/((5-vout)/(10000));
	temp=1/(log(r/k)/b);
	printf("The temperature is:%f",temp);

	getchar();
	getchar();

	





	return 0;
}