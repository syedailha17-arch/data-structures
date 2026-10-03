#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *left;
    struct node *right;
    int data;
};
struct node* createNode(int data){
    struct node* n =(struct node*)malloc(sizeof(struct node));
    n->data=data;
    n->right=n->left=NULL;
    return n;
}
struct node* minValue(struct node *root){
    root=root->right;
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}
struct node* insertNode(struct node* root,int data){
    if(root==NULL){
        return createNode(data);
    }
    else if(data<root->data){
        root->left=insertNode(root->left,data);
    }
    else if(data>root->data){
        root->right=insertNode(root->right,data);
    }
    return root;
}
void inorder(struct node* root){
    if(root==NULL)return;
    else{
        inorder(root->left);
        printf("%d\n",root->data);
        inorder(root->right);

    }
}
void preorder(struct node* root){
    if(root==NULL)return;
    else{
        printf("%d\n",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node* root){
    if(root==NULL)return;
    else{
        postorder(root->left);
        postorder(root->right);
        printf("%d\n",root->data);
    }
}
struct node* delete(struct node* root,int data){
    if(root==NULL){
        printf("There is nothing to delete");
        return NULL;
    }
    else if(data<root->data){
        root->left=delete(root->left,data);
    }
    else if(data>root->data){
        root->right=delete(root->right,data);
    }
    else{
        if(root->left==NULL && root->right==NULL){
            free(root);
            return NULL;
        }
        else if(root->left==NULL && root->right!=NULL){
            struct node* temp=root->right;
            free(root);
            return temp;

        }
        else if(root->right==NULL && root->left!=NULL){
            struct node* temp=root->left;
            free(root);
            return temp;
        }
        else{
            struct node* temp=minValue(root);
            root->data=temp->data;
            root->right=delete(root->right,temp->data);        
        }
    }
    return root;
        
}
int main(){
    struct node *root=NULL;
    root=insertNode(root,10);
    root=insertNode(root,20);
    root=insertNode(root,5);
    root=insertNode(root,15);
    root=insertNode(root,5);
    root=insertNode(root,7);
    root=insertNode(root,2);
    root=delete(root,7);
    int a;
    printf("select 1 for inorder,2 for pre and 3 for post\n");
    scanf("%d",&a);
    if(a==1){
        inorder(root);
    }
    else if(a==2){
        preorder(root);
    }
    else if(a==3){
         postorder(root);
    }
    else{
        printf("invalid choice");
    }
}