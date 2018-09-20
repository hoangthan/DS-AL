#include "conio.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

	typedef struct
	{
		int id;
		char name[30];
		char group[10];
		char email[30];
	}info;


	typedef struct Node
	{
		info data;
		struct Node *pnext;
	}* node;


	node CreateNode()
	{
		return (node)malloc(sizeof(struct Node));
	}


	int IsEmpty(node phead)
	{
		if(phead==NULL) return 1;
		return 0;
	}


	void GetData(info* data)
	{
		printf("\n\tID : "); scanf("%d",&(*data).id);
		printf("\n\tName: "); fflush(stdin); gets((*data).name);
		printf("\n\tGroup: "); fflush(stdin); gets((*data).group);
		printf("\n\tEmail: "); fflush(stdin); gets((*data).email);
	}


	void Add(node *phead, int *n)
	{
		printf("Number of students : ");
		int t;
		scanf("%d",&t);
		*n = *n + t;
		info data;
		node temp;
		for(int i=0;i<t;i++)
		{
			printf("\n  Student[%d] : ",i+1);
			if(*phead==NULL)
			{
				*phead = CreateNode();
				GetData(&data);
				(*phead)->data = data;
				(*phead)->pnext = NULL;
			}
			else
			{
				temp = CreateNode();
				GetData(&data);
				temp->pnext = *phead;
				temp->data = data;
				*phead = temp;
			}
		}
	}


	void Display(node p,int i)
	{
		printf("\n\t [%d] ID : %d   || Name : %s    || Group: %s    || Email: %s",i,p->data.id,p->data.name,p->data.group,p->data.email);
	}


	void ShowList(node phead)
	{
		if(phead==NULL)
		{
			printf("\n\t THE LIST IS EMPTY!!!");
			getch();
			return;
		}
		else
		{
			int i = 1;
			node p = phead;
			while(p!=NULL)
			{
				Display(p,i);
				p = p->pnext;
				i++;
			}
		}
		getch();
	}

	void Insert(node *phead, int *n)
	{
		int pos;
		printf("\n\t Range [1-%d]",*n+1);
		printf("\n\t Position to insert into : ");
		scanf("%d",&pos);
		
		while(pos<=0 || pos > *n+1)
		{
			printf("\n\t Position is invalid. Position to insert into : ");
			scanf("%d",&pos);
		}
		
		if(IsEmpty(*phead))
		{
			*phead = CreateNode();
			info data;
			GetData(&data);
			(*phead)->data = data;
			(*phead)->pnext = NULL;
			*n = *n+1;
		}
		else
		{
			node p = CreateNode();
			info data;
			GetData(&data);
			p->data = data;
			
			if(pos==1)
			{
				p->pnext = *phead;
				*phead = p;
			}
			else if(pos==*n+1)
			{
				p->pnext = NULL;
				node temp = *phead;
				while(temp->pnext!=NULL) temp = temp->pnext;
				temp->pnext = p;
			}

			else
			{
				int i = 1;
				node temp = *phead;
				for(i;i<pos-1;i++) temp = temp->pnext;
				p->pnext = temp->pnext;
				temp->pnext = p;
			}
			*n = *n+1;
		}
		
	}

	void Delete(node *phead)
	{
		if(*phead==NULL)
		{
			printf("EMPTY LIST\n");
			getch();
			return;
		}
		int id;
		printf("\n ID of sudent need to delete : ");
		scanf("%d",&id);
		node p = *phead;
		if((*phead)->data.id==id)
		{
			*phead = NULL;
			free(p);
			printf("Deleted!!!\n");
			getch();
			return;
		}
		else
		{
			node p = *phead;
			while(p->pnext!=NULL)
			{
				if(p->pnext->data.id==id)
				{
					node temp = p->pnext;
					p->pnext = temp->pnext;
					free(temp);
					printf("Deleted!!!\n");
					getch();
					return;
				}
				p = p->pnext;
			}
		}
		printf("ID: %d is not exist in the list\n",id );
		getch();
	}

	void Search(node phead)
	{
		if(phead==NULL)
		{
			printf("\n\t EMPTY LIST!!!");
			getch();
			return;
		}
		int id;
		printf("\n\t ID of the student : ");
		scanf("%d",&id);
		node p = phead;
		while(p!=NULL)
		{
			if(p->data.id==id) 
				{
					Display(p,1);
					getch();
					return;
				}
			p = p->pnext;
		}
		printf("\n\tID: %d is not exist in the list.\n",id );
		getch();
	}


	void Menu()
	{
		printf("1. Creating list.\n");
		printf("2. Show the list of students.\n");
		printf("3. Inserting student..\n");
		printf("4. Deleting.\n");
		printf("5. Searching.\n");
		printf("6. Exit.\n");
		printf("\n\t\t >> Choose functionality:  : ");
	}


	void main()
	{	
		node phead = NULL;
		int choose;
		int n=0;
		while(1)
		{
			system("cls");
			Menu();
			scanf("%d",&choose);
			if(choose==1) Add(&phead,&n);
			if(choose==2) ShowList(phead);
			if(choose==3) Insert(&phead,&n);
			if(choose==4) Delete(&phead);
			if(choose==5) Search(phead);
			if(choose==6)
			{
				printf("The program has been terminated .!");
				break;
			}
		}
	}