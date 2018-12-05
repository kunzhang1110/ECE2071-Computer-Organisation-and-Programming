#include <stdio.h>
#include <string.h>

/*constant variables*/
const int IDLEN=30;
const int POLARITYLEN=3;
const int MAXSTOCKITEMS=10;

/*define structures*/
struct TransistorRec {
char manufacturersID[IDLEN];
char polarity[POLARITYLEN];
float power;
float gain;
int stock;
};
typedef struct TransistorRec Transistor;

struct StockRec{
int size;
Transistor stocklist[MAXSTOCKITEMS];
};
typedef struct StockRec Stock;

/*function prototypes*/
void inforead(Stock *slist); /*read from keyboard*/
void infoprint(Stock slist); /*printout*/
void infosearch(Stock slist); 

int main(void){
	Stock slist={NULL};

	inforead(&slist);
	infoprint(slist);
	infosearch(slist);
	getchar();
	getchar();
	return 0;
}

/*obtain records from keyboard*/
void inforead(Stock *slist)
{
	int i=0;
	int quit=1;

	while((quit!=0)&&i<=9){
		printf("Manufacture's ID:");
		scanf("%s",&(slist->stocklist[i].manufacturersID));
		printf("Polarity:");
		scanf("%s",&(slist->stocklist[i].polarity));
		printf("Power:");
		scanf("%f",&(slist->stocklist[i].power));
		printf("Gain:");
		scanf("%f",&(slist->stocklist[i].gain));
		printf("Numbers in sotck:");
		scanf("%d",&(slist->stocklist[i].stock));
		i++;
		
		printf("Countinue?(1/0)");
		scanf("%d",&quit);

	}/*end while*/
	slist->size=i; /*size of the list*/
}

/*printout records*/
void infoprint(Stock slist) /*recieves structure as a parameter*/
{	
	int i=0;

	printf("Manufacture ID  Polarity   Power  Gain  Stock\n");
	for(i=0;i<=(slist.size);i++){
		printf("%14s  %8s  %6.1f  %4.0f  %5d\n",slist.stocklist[i].manufacturersID,slist.stocklist[i].polarity,slist.stocklist[i].power,slist.stocklist[i].gain,slist.stocklist[i].stock);
	}
}

void infosearch(Stock slist)
{
	int i=0,found=0;
	char search[IDLEN]={""};
	printf("Find what ID:");
	scanf("%s",search);
	for(i=0;i<=9;i++){
		if(strcmp(search,slist.stocklist[i].manufacturersID)==0){
			found=1;
			break;
		}
	}
	if(found==0){
		printf("No Match found");
	}
	else{
		printf("%-14s  %-3s  %.1f  %.0f  %d\n",slist.stocklist[i].manufacturersID,slist.stocklist[i].polarity,slist.stocklist[i].power,slist.stocklist[i].gain,slist.stocklist[i].stock);
	}
}