#include <stdio.h>
#include <stdlib.h>

//Tree traversal Code

struct node {
    //value of node
    int item;
    //pointer to right
    struct node* right;
    //pointer to left
    struct node* left;
} ;

//Creates a New node to start with
struct node* createNode(value){
    //allocates memory
    struct node* newNode = malloc(sizeof(struct node));
    //sets the new nodes item to value passed
    newNode -> item = value;
    //new node so set the pointers to NULL
    newNode ->right = NULL;
    newNode-> left = NULL;
    
    return newNode;
}//creatNode;

//Insert node right
struct node* insertRight( struct node* root, int value){
    //call to createNode, with the right to the root
    root-> right = createNode(value);
    //return the right
    return root -> right;
}//InsertRight;

//Insert node left
struct node* insertLeft( struct node* root, int value){
    root-> left = createNode(value);
    return root -> left;
}//InsertLeft;


//Traversal Code***
//inorder traversal
void inOrderT(struct node* root){
    //checks if empty
    if (root ==NULL) return;
    //traverses left sub tree
    inOrderT(root->left);
    //prints root
    printf("%d ->", root->item);
    //traverses right
    inOrderT(root->right);
}//inOrderT;

void postOrderT(struct node* root){
    if(root == NULL) return;
    postOrderT(root->left);
    postOrderT(root->right);
    printf("%d ->", root->item);
}//postOrderT;

void preOrderT(struct node* root){
    if(root==NULL) return;
    printf("%d ->", root->item);
    preOrderT(root->left);
    preOrderT(root->right);
}

int main(int argc, char **argv)
{
    //insert 1 to root
struct node* root = createNode(1);

 insertLeft(root, 12);
  insertRight(root, 9);

  insertLeft(root->left, 5);
  insertRight(root->left, 6);
  
 printf("\nIn-order traversal \n");
 inOrderT(root);
 
 printf("\nPost-Order traversal \n");
 postOrderT(root);
 
 printf("\nPre-Order traversal \n");
 preOrderT(root);
 
 printf("\n\n");
	return 0;
}
