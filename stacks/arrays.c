#include<stdio.h>
#include<stdlib.h>
struct stack{
    int size;
    int top;
    int *arr;
};
int isEmpty(struct stack *ptr){
    if(ptr->top==-1){return 1;}
    else{return 0;}
}
int isFull(struct stack *ptr){
    if(ptr->top==ptr->size-1){return 1;}
    else{return 0;}
}
void push(struct stack *ptr,int val){
    if(isFull(ptr)){printf("stack overflow\n");}
    else{
        ptr->top++;
        ptr->arr[ptr->top]=val;
    }
}
int pop(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("stack underflow\n");
        return -1;}
    else{
       int val=ptr->arr[ptr->top];
       ptr->top=ptr->top-1;
       return val;
    }
}
int peek(struct stack *sp,int i){
    if(sp->top-i<0){printf("invalid position\n");
                     return -1;}
    else{
        return sp->arr[sp->top-i];
    }
}
int stackTop(struct stack *sp){
    return sp->arr[sp->top];
}
int stackBottom(struct stack *sp){
    return sp->arr[0];
}
int main(){
    struct stack *sp=malloc(sizeof(struct stack));
    sp->size=100;
    sp->top=-1;
    sp->arr=(int *)malloc(sp->size*sizeof(int));
    printf("%d\n",isFull(sp));
    printf("%d\n",isEmpty(sp));
    push(sp,10);
    push(sp,20);
    push(sp,30);
    push(sp,40);
    push(sp,50);
    push(sp,60);
    push(sp,70);
    printf("%d\n",isFull(sp));
    printf("%d\n",isEmpty(sp));
    
    for(int j=0;j<sp->top+1;j++){
        printf("the value at position %d is %d\n",j,peek(sp,j));
    }
    return 0;
}