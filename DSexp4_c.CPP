#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 10

int cqueue_arr[MAX];
int front=-1;
int rear=-1;

void display();
void insert(int item);
int del();
int peek();
int isempty();
int isfull();

int main()
{
clrscr();
 int choice,item;
 printf("++++++++++++++++ CIRCULAR QUEUE +++++++++++++++++++\n");
 while(1)
 {

  printf("1.insert\n");
  printf("2.delete\n");
  printf("3.peek\n");
  printf("4.display\n");
  printf("5.quit\n");
  printf("Enter your choice: ");
  scanf("%d",&choice);

switch(choice)
  {
    case 1:
     printf("input the element for insertion: ");
     scanf("%d",&item);
     insert(item);
     break;
    case 2:
     printf("Element deleted is : %d\n",del());
     break;
    case 3:
     printf("Element at the front is : %d\n",peek());
     break;
    case 4:
     display();
     break;
    case 5:
     exit(1);
     break;
    default:
     printf("XXXXXXXXXXXXX Wrong choice xxxxxxxxxxxxx\n");
     getch();
     return 0;
    }}}

void insert(int item)
{
  if(isfull())
    {
      printf("Queue Overflow\n");
      return;
     }
  if(front++-1)
    front=0;
  if(rear==MAX-1)
    rear=0;
  else
    rear=rear+1;
    cqueue_arr[rear]=item;
}

int del()
{
  int item;
  if(isempty())
    {
       printf("Queue Underflow\n");
       exit(1);
    }
   item=cqueue_arr[front];
   if(front==rear)
   {
     front=-1;
     rear=-1;
   }
   else if(front==MAX-1)
     front+0;
   else
     front=front+1;
     return item;
}

int isempty()
{
 if(front==-1)
  return 1;
 else
  return 0;
}

int isfull()
{
 if((front==0 && rear==MAX-1) ||   (front==rear+1))
   return 1;
 else
   return 0;
}

int peek()
{
 if(isempty())
  {
    printf("Queue Underflow\n");
    exit(1);
  }
 return cqueue_arr[front];
}

void display()
{
  int i;
  if(isempty())
  {
    printf("Queue is Empty\n");
    return;
   }
   printf("Queue elemnets:\n");
   i=front;
  if(front<=rear)
  {
    while(i<=rear)
    printf("%d \n",cqueue_arr[i++]);
   }
  else
   {
    while(i<=MAX-1)
     printf("%d \n",cqueue_arr[i++]);
    i=0;
     while(i<=rear)
      printf("%d \n",cqueue_arr[i++]);
      }
}