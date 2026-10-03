#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int queue[MAX];
int front=-1;
int rear=-1;

void enqueue(int value){
    if (rear==MAX-1){
        printf("queue overflow\n");
        return;
    }
    if(front==-1){
        front=0;
    }
    queue[++rear]=value;
    printf("inserted %d\n",value);
}

int dequeue(){
    if(front==-1 || front>rear){
        printf("queue is empty\n");
        return -1;
    }
    int val = queue[front];
    if(front==rear){
        front=-1;
        rear=-1;
    } else {
        front++;
    }
    return val;
}

void display(){
    if(front==-1){
        printf("queue is empty\n");
        return;
    }
    printf("queue: ");
    for(int i=front; i<=rear;i++){
        printf("%d ",queue[i]);
    }
    printf("\n");
}

int main(){
    int choice, value;

    while(1){
        printf("\n1.Enqueue 2.Dequeue 3.Display 4.Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);

        if(choice==1){
            printf("Enter value: ");
            scanf("%d",&value);
            enqueue(value);
        }
        else if(choice==2){
            value = dequeue();
            if(value != -1){
                printf("dequeued %d\n", value);
            }
        }
        else if(choice==3){
            display();
        }
        else if(choice==4){
            break;
        }
        else{
            printf("invalid choice\n");
        }
    }
    return 0;
}