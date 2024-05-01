typedef struct Node
	{
	s8 ahmed[10];
	struct Node* next;
	}Node;
	
void addtoend(Node* Head,s8* arr)
{
	Node* omar=(Node*)malloc(sizeof(Node));
	for(s16 i=0 ; i<10; i++)
	{
		omar->ahmed[i]=arr[i]; 
	}
	omar-> next=NULL;
	while(Head->next!=NULL)
	{
		Head=Head->next;
	}
	Head->next=omar;
}

s32 size(Node* Head)
{
	s32 t=1;
	while(Head->next!=NULL)
		{
			Head=Head->next;
			t++;
		}
	return t;
}

void printing(Node* Head)
{
	u16 element=1;
	Node* ptr=Head;
	for(s16 i=0 ; i<size(Head) ; i++)
	{
		printf("elements in Node(%d): ",element);
		for(int i=0 ; i<10 ; i++)
		{
			printf("%d ",ptr->ahmed[i]);
		}
		printf("\n");
		ptr=ptr->next;
		element++;
	}
}

void removefromend(Node* Head)
{
	Node* ptr=Head;
	Node* ptr2;
	if (size(Head)==1)
		printf("The Least length is acheived");
	else
	{	
	while(ptr->next->next!=NULL)
	{
		ptr=ptr->next;
	}
	ptr2=ptr->next;
	free(ptr2);
	ptr->next=NULL;
	}
}