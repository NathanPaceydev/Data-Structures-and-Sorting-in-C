#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define COUNT 8
//Binary Search Tree Implementation in C
//node struct for tree
struct node{
    int key;
    struct node* right;
    struct node* left;
} ;

// Function to print binary tree in 2D 
// It does reverse inorder traversal 
void print2DUtil(struct node *root, int space) 
{ 
    // Base case 
    if (root == NULL) 
        return; 
    // Increase distance between levels 
    space += COUNT; 
    // Process right child first 
    print2DUtil(root->right, space); 
    // Print current node after space 
    // count 
    printf("\n"); 
    for (int i = COUNT; i < space; i++) 
        printf(" "); 
    printf(" %d\n", root->key); 
    // Process left child 
    print2DUtil(root->left, space); 
} 
// Wrapper over print2DUtil() 
void print2D(struct node *root) 
{ 
   // Pass initial space count as 0 
   print2DUtil(root, 0); 
} 


//creating node
struct node* newNode(int item){
    struct node* temp = (struct node* )malloc(sizeof(struct node));
    temp -> key =item;
    temp -> left = NULL;
    temp -> right =NULL;
    return temp;
}//newNode;

//Inorder traversal 
void inOrderT( struct node* root){
     //checks if empty
    if (root ==NULL) return;
    //traverses left sub tree
    inOrderT(root->left);
    //prints root
    printf("%d ->", root->key);
    //traverses right
    inOrderT(root->right);
}//inOrderT;

//PreOrder Traversal
void preOrderT( struct node* root){
     //checks if empty
    if (root ==NULL) return;
    //prints root
    printf("%d ->", root->key);
    //traverses left sub tree
    preOrderT(root->left);
    //traverses right
    preOrderT(root->right);
}//preOrderT;

//Post Order Traversal
void postOrderT( struct node* root){
     //checks if empty
    if (root ==NULL) return;
    //traverses left sub tree
    postOrderT(root->left);
    //traverses right
    postOrderT(root->right);
    //prints root
    printf("%d ->", root->key);
}//postOrderT;

// Insertion**
struct node* insert(struct node* node, int key){
    //return the new node if the tree is empty
    if( node==NULL) return newNode(key);
    
    //traverse to the right place and insert
    if(key<node->key){
        node->left = insert(node->left, key);
    }
    else{
        node->right = insert(node->right, key);
    }
    return node;
}//insert;

//inorder successor**
struct node* minValueNode(struct node* node){
    struct node* current = node;
    
    //find the leftmost leaf
    while(current && current->left !=NULL){
        current = current->left;
    }
    return current;
}

// Deletion **
struct node* deleteNode(struct node* root, int key){
    //check for an empty tree
    if (root==NULL) return root;
    
    //find the node to be deleted
    if (key < root->key){
        root->left = deleteNode(root->left, key);
        }
        else if (key > root->key){
            root->right = deleteNode(root->right, key);
        }
        else{
            //case 1 or 2, the  node has no children or 1
            //if left child is NULL
            if(root->left ==NULL){
                struct node* temp = root->right;
                free(root);
                return temp;
            }
            //if right child is NULL
            else if(root->right ==NULL){
                struct node* temp = root-> left;
                free(root);
                return temp;
            }
            //Case 3 node has 2 children
            struct node* temp = minValueNode(root->right);
            //use inorder successor in pos of the deleted node
            root->key = temp->key;
            //delete inorder succesor's index
            root->right = deleteNode(root->right, temp->key);
        }
        return root;
    }//deleteNode;


int main(int argc, char **argv)
{
    struct node* root=NULL;
 root = insert(root, 8);
  root = insert(root, 3);
  root = insert(root, 1);
  root = insert(root, 6);
  root = insert(root, 7);
  root = insert(root, 10);
  root = insert(root, 14);
  root = insert(root, 4);
//printing the inorder traversal
  printf("Inorder traversal: ");
  inOrderT(root);
  
printf("\nPostorder traversal: ");
  postOrderT(root);
  
  printf("\nPreorder traversal: ");
  preOrderT(root);
  //tree visual
  printf("\n\n2D visual of the tree (sideways)\n");
  print2D(root);
  //deletion
int delete_num = 26;
  printf("\nAfter deleting %d\n", delete_num);
  root = deleteNode(root, delete_num);
  
  printf("Inorder traversal: ");
  inOrderT(root);
  
  printf("\n\n2D visual of the tree (sideways)\n");
  print2D(root);
  
  delete_num =12;
  printf("\nAfter deleting %d\n", delete_num);
  root = deleteNode(root, delete_num);
  
  root = insert(root, 13);
   printf("\n\n2D visual of the tree (sideways)\n");
  print2D(root);
  
  printf("\n\n");
  return 0;
    
}
