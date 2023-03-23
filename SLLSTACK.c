#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node* link;
}NODE;



NODE *insert_front(int item,NODE *first){
	NODE *new;
	new = malloc(sizeof(NODE));
	if(new == NULL){
		printf("No Space");
	}
	else{
		new -> data = item;
		new -> link = NULL;
	}
	if(first == NULL){
		first = new;
	}
	else{
		new -> link = first;
		first = new;
	}
	return (first);
}


NODE *create(NODE *first){
	int n, item;
	printf("Enter size of stack: ");
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		printf("Enter item: ");
		scanf("%d", &item);
		first =	insert_front(item, first);
	}
	return (first);
}

NODE *delete_front(NODE *first){
	NODE *cur;
	if(first == NULL){
		printf("list is empty");
	}
	else{
		cur = first;
		first = first -> link;
		printf("deleted element: %d", cur -> data);
		free(cur);
	}
	return(first);
}
void display(NODE *first){
	NODE *cur;
	if(first == NULL){
		printf("list is empty");
	}
	else{
		cur = first;
		printf("The elements are \n");
		while(cur!=NULL){
			printf("%d ->", cur->data);
			cur = cur -> link;
		}
	}
}
void search(int key, NODE *first){
	NODE *temp;
	if(first ==NULL){
		printf("list is empty");
	}
	else{
		temp = first;
		while(temp != NULL){
			if(key == temp-> data){
				printf("search successful");
				return;
			}
			temp = temp->link;
		}
		printf("search unsuccessful");
	}
}

NODE *concatenation(NODE *list1, NODE *list2){
	NODE *temp;
	list1 = create(list1);
	list2 = create(list2);
	display(list1);
	display(list2);
	temp = list1;
	while(temp -> link != NULL){
		temp = temp->link;
	}
	temp -> link = list2;
	return(list1);
}

void main(){
	NODE *first = NULL;
	NODE *list1 = NULL;
	NODE *list2 = NULL;
	int ch,key,item;
while(1)
{ printf("\n*******Implementing Stack of integers*****\n");
printf("1.create\n2.insert_front\n3.delete_front\n4.search\n5.display\n6.concatenation\n7.exit\n");
printf("enter your choice");
scanf("%d",&ch);
switch(ch)
{
case 1:first=create(first);
break;
case 2:printf("enter the item\n");
scanf("%d",&item);
first=insert_front(item,first);
break;
case 3:first=delete_front(first);
break;
case 4:printf("enter the item to be searched\n");
scanf("%d",&key);
search(key,first);
break;
case 5:display(first);
break;
case 6:list1=concatenation(list1,list2);
display(list1);
break;
case 7:exit(0);
default :printf("invalid input");
break;
}
}	
}
