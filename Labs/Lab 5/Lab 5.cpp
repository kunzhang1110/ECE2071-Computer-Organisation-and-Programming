/* ECE2071, Computer Organisation and Programming*/
/* TRC2400 Computer Programmimg */
/*Lab5 Linked List  Skeleton C code  */

#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define NAME_LEN 30
#define LINE_LEN 80

struct record {
	char *firstname;
	char *lastname;
	long int idnumber;
	int ccode;
	long int phonenum;
	struct record *next;
};
typedef struct record STUDENT;


STUDENT *header;  /* pointer to the start of linked list */

char fname[NAME_LEN], lname[NAME_LEN];
char filename[LINE_LEN];
long int id, phone;
int course;

FILE *fptr;

STUDENT *makenode(long int stud_id, int c_code, long int phone, char *fname, char *lname);
void insert_node(STUDENT **header);
void delete_node(STUDENT **header);
void search_node(STUDENT** header);
void print_list();
void output_list();
STUDENT *name_finder(STUDENT *header,char name[]);

int main()
{
	int choice;
	STUDENT *p, *q;
	q = NULL;
	printf(" Enter the input file name: ");
	gets(filename);
	fptr= fopen(filename, "r");
	if (fptr == NULL)
		printf("Error, can't open the input file %s \n", filename);
	else
	{
		
		while (!feof(fptr))
		{
			
			fscanf(fptr," %s %s %ld %d %ld", fname, lname, &id, &course, &phone);
			/* printf("%s  %s  %ld %d %ld \n",fname, lname,id,course,phone);*/
			p=makenode(id,course, phone, fname, lname);
			p->next= q;
			q=p;
			
		}
		printf("Created the Linked List\n");
		header = q;
		fclose(fptr);

		do {
			printf("\n\n MENU \n\n");
			printf("1. Insert\n");
			printf("2. Delete\n");
			printf("3. Search\n");
			printf("4. List\n");
			printf("5. Save\n");
			printf("6. Quit\n");
			printf("\n");

			printf("Enter your choice: "); /*Prompt user*/
			scanf("%d", &choice);

			switch(choice)
			{
			case 1:
				insert_node(&header);
				break;
			case 2:
				delete_node(&header);
				break;
			case 3:
				search_node(&header);
				break;
			case 4:
				print_list();
				break;
			case 5:
				output_list();
				break;
			}
		}while (choice !=6);
		return 0;
	}
	getchar();
	getchar();
}

/***************************************************************/
STUDENT *makenode(long int stud_id, int c_id, long int phone, char *fname, char *lname)
{
	STUDENT *ptr;

	ptr = (STUDENT *) malloc(sizeof(STUDENT));
	if (ptr != NULL)
	{
		ptr->next = NULL;
		ptr->firstname = (char *)malloc(strlen(fname)+1);/*adddtional 1 for \0*/
		strcpy(ptr->firstname, fname);
		ptr->lastname = (char *)malloc(strlen(lname)+1);
		strcpy(ptr->lastname, lname);
		ptr->idnumber = stud_id;
		ptr->ccode = c_id;
		ptr->phonenum = phone;
		return(ptr);
	}
	else
	{
		printf("Memory not allocated\n");
	}
		
}
/************************************************************/
void insert_node(STUDENT** header)
{
	char fname[NAME_LEN], lname[NAME_LEN];  
    long int id, phone;
	int course;
	STUDENT *p;

	printf("Please enter:");
    scanf("%s %s %ld %d %ld", fname, lname, &id, &course, &phone);
	p=makenode(id,course, phone, fname, lname);
    p->next= *header;
    *header=p;
}
/************************************************************/
void delete_node(STUDENT** header)
{
	char selName[NAME_LEN];
	STUDENT *p=NULL,*q=NULL,*prev=NULL;
	
	printf("Please enter last name:");
	scanf("%s",&selName);
	p=*header;
	while(strcmp(selName,(p->lastname))!=0){
		prev=p;
		p=p->next;
	}	
	//p=name_finder(*header,selName);
	/*delete begins*/
	q=p;
	prev->next=p->next;
	free(q);		
}
/***********************************************************/
void search_node(STUDENT** header)
{
	char selName[NAME_LEN];
	STUDENT *p,*q;
	
	printf("Please enter last name:");
	scanf("%s",&selName);
	p=name_finder(*header,selName);
	printf("The record is:");
    printf("%s %s %ld %d %ld\n",p->firstname,p->lastname,p->idnumber,p->ccode,p->phonenum);	
}
/**********************************************************/
void output_list()
{	
	FILE *fnew;
	STUDENT *p;
	
	fnew=fopen("student.dat","w");
	p=header;
	while(p!='\0'){
		fprintf(fnew,"%s %s %ld %d %ld",p->firstname,p->lastname,p->idnumber,p->ccode,p->phonenum);
		printf("%s %s %ld %d %ld",p->firstname,p->lastname,p->idnumber,p->ccode,p->phonenum);
		p=p->next;
	}						
}
/********************************************************/
void print_list()
{
	STUDENT *p1;
	p1=header;/*header is global~*/
	while(p1 != NULL)
	{
		printf("%s %s %ld %d %ld\n",p1->firstname,
       p1->lastname,p1->idnumber,p1->ccode,p1->phonenum);
		p1=p1->next;
	}
	
}
/********************************************************/
STUDENT *name_finder(STUDENT *header,char name[])
{
	STUDENT *p;

	p=header;
	while(strcmp(name,(p->lastname))!=0){
		p=p->next;
	}

	return p;
}
