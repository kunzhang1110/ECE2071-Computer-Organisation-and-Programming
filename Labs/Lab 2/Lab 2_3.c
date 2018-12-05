#include "stdio.h"

const double THE=0.22;
const double PHO=0.15;
const double ADC=2.5;
const double LED=0.15;

int main(void) 
{ 
  char key;
  int items = 0;
  int done = 0;
  float total = 0.00;
    
/* Output information: */ 
  puts("ELECTRONIC DEVICES MENU SYSTEM"); 
  puts("===============================\n"); 
  puts(" [T]hermistor - press T (then Enter)"); 
  puts(" [P]hoto diode - press P (then Enter)");
  puts(" [A]DC - press A (then Enter)");
  puts(" [L]ED - press L (then Enter)");
  puts(" E[X]it -press X(then Enter) when ordering is complete\n");

/* Handle key presses: */ 
  do { 
    fflush(stdin);
    key = getchar();
    switch (key) 
        { 
        case 'T': case 't': 
            printf(" Thermistor $%4.2f\n", THE); 
            items++; 
            total += THE; 
            break; 
        case 'P': case 'p': 
            printf(" Photo diode $%4.2f\n", PHO); 
            items++; 
            total += PHO; 
            break; 
        case 'A': case 'a':
            printf(" ADC $%4.2f\n", ADC);
            items++; 
            total += ADC;
            break;
        case 'L': case 'l':
            printf(" LED $%4.2f\n", LED);
            items++; 
            total += LED;
            break;              
        case 'X': case 'x': 
            printf("\nOrder complete - "); 
            printf("%i items - total $%4.2f\n", items, total); 
            done = 1; 
            break; 
        default: 
            puts(" Invalid key! Try again."); 
            break; 
        } 
  } while (!done); 

/* Output information: */ 
  printf("\n\"Thank you! Total amount will be $%4.2f\"\n", total); 
  puts("\"Thanks for shopping! Come again!\"");
  getch();
  return 0;
} 


