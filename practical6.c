#include <stdio.h>
#include<stdlib.h>
 struct node{
     int data;
     struct node* next;
 };
struct node *top;
struct node *push(int val){
    struct node *newnode=(struct node *)malloc(sizeof(struct node *));
    
    newnode->data=val;
    newnode->next=top;
    top=newnode;
    
}
struct node *display(struct node * top){
    if(top==NULL){
        printf("stack is empty");
    }
     struct node *node=(struct node *)malloc(sizeof(struct node *));
    node=top;
    while(node->next!=NULL){
        printf("%d",node->data);
        printf("\n");
        node=node->next;
    }
     printf("%d",node->data);
        printf("\n");
    
}
struct node* peak(){
    printf(" top is  %d ",top->data);
}
struct node *pop(){
    top=top->next;
}
int main(){
    push (10);
    push (30);
    push (20);
    display(top);
    pop();
    display(top);
    peak();
    
    return 0;
} 
