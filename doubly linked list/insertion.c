
#include <stdio.h>
#include<stdlib.h>
struct node{
  struct node *previous;
  int data;
  struct node *next;};
struct node *insertempty(struct node *head,int data){
  struct node *temp=malloc(sizeof(struct node));
  temp->previous=NULL;
  temp->data=data;
  temp->next=NULL;
  head=temp;
  return head;}
struct node* addatbeg(struct node **head,int data){
  struct node *temp=malloc(sizeof(struct node));
  temp->previous=NULL;
  temp->data=data;
  temp->next=NULL;
  temp->next=*head;
  (*head)->previous=temp;
  *head=temp;
  return *head;}
void addatend(struct node **head,int data){
  struct node *tp=*head;
  struct node *temp=malloc(sizeof(struct node));
  temp->previous=NULL;
  temp->data=data;
  temp->next=NULL;
  while(tp->next!=NULL){
    tp=tp->next;}
  tp->next=temp;
  temp->previous=tp;}
void insertatposition(struct node **head,int data,int position){
  struct node *temp=malloc(sizeof(struct node));
  struct node *tp2=*head;
  temp->previous=NULL;
  temp->data=data;
  temp->next=NULL;
  struct node *tp=*head;
  while(position!=1){
    tp=tp2;
    tp2=tp2->next;
    position--;}
  tp->next=temp;
  temp->previous=tp;
  temp->next=tp2;
  tp2->previous=temp;}
void printlist(struct node *head){
  struct node *ptr=head;
  while(ptr!=NULL){
    printf("%d",ptr->data);
    ptr=ptr->next;
    printf("\n");}}

int main() {
  struct node *head=malloc(sizeof(struct node));
  head=insertempty(head,10);
  addatbeg(&head,20);
  addatend(&head,30);
  insertatposition(&head,40,2);
  addatend(&head,50);
  printlist(head);
  return 0;
}