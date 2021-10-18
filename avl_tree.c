// AVL tree implementation in C
//includes simple 2D prints

#include <stdio.h>
#include <stdlib.h>
#define COUNT 8

// Create Node
struct Node {
  int key;
  struct Node *left;
  struct Node *right;
  int height;//keeps track of the height from the bottom of the tree
};


// Calculate height
int height(struct Node *N) {
  if (N == NULL){
    return 0;//check for NULL
  }
  return N->height; 
}

//returns the max of two ints
int max(int a, int b) {
  return (a > b) ? a : b;
}//max;

// Create a node
struct Node* newNode(int key) {
  struct Node* node = (struct Node *)malloc(sizeof(struct Node)); //allocate space
  node->key = key; //set value
  node->left = NULL; //initially set to NULL
  node->right = NULL;
  node->height = 1;//leaf nodes are set to height 1
  return (node);
}//newNode;

// Right rotate
struct Node *rightRotate(struct Node *y) {
  struct Node *x = y->left;
  struct Node *T2 = x->right;
//rotate right
  x->right = y;
  y->left = T2;

  y->height = max(height(y->left), height(y->right)) + 1;
  x->height = max(height(x->left), height(x->right)) + 1;

  return x;
}//rightRotate;

// Left rotate
struct Node *leftRotate(struct Node *x) {
  struct Node *y = x->right;
  struct Node *T2 = y->left;
//rotate left
  y->left = x;
  x->right = T2;

  x->height = max(height(x->left), height(x->right)) + 1;
  y->height = max(height(y->left), height(y->right)) + 1;

  return y;
}//leftRotate;

// Get the balance factor
int getBalance(struct Node *N) {
  if (N == NULL){
  return 0;//check NULL
  }
  return height(N->left) - height(N->right);//BF equantion
}//getBalance;

// Insert node
struct Node *insertNode(struct Node *node, int key) {
  // Find the correct position to insertNode the node and insertNode it
  if (node == NULL){
    return (newNode(key));
  }
  if (key < node->key){
    node->left = insertNode(node->left, key);
  }
  else if (key > node->key){
    node->right = insertNode(node->right, key);
  }
  else // equal are not allowed in BST
    return node;

  // Update the balance factor of each node and
  // Balance the tree
  node->height = 1 + max(height(node->left),
               height(node->right));
//check if the node became unbalanced
  int balance = getBalance(node);
  //There are four cases to check when balancing
  //Case 1. Left Left
  if (balance > 1 && key < node->left->key)
    return rightRotate(node);
//Case 2. Right Right case
  if (balance < -1 && key > node->right->key)
    return leftRotate(node);
//Case 3. Left Right
  if (balance > 1 && key > node->left->key) {
    node->left = leftRotate(node->left);
    return rightRotate(node);
  }
//Case 4. Right Left case
  if (balance < -1 && key < node->right->key) {
    node->right = rightRotate(node->right);
    return leftRotate(node);
  }
//return node pointer unchanged
  return node;
}//insertNode;

//finds the optimal node for replacement after deletion or insertion
struct Node *minValueNode(struct Node *node) {
  struct Node *current = node;

  while (current->left != NULL)
    current = current->left;

  return current;
}//minValueNode;

// Delete a nodes
struct Node *deleteNode(struct Node *root, int key) {
  // Find the node and delete it
    if(root ==NULL){
        return root;
    }
    if(key<root->key){
        root->left =deleteNode(root->left, key);
    }
    else if(key>root->key){
        root->right = deleteNode(root->right, key);
    }
    else{
        if((root->left ==NULL)|| (root->right==NULL)){
            struct Node* temp = root->left ? root->left : root->right;
            
            if (temp==NULL){
                temp = root;
                root =NULL;
            } else
                *root = *temp;
                free(temp);
        }
        else{
                struct Node* temp = minValueNode(root->right);
                root->key = temp->key;
                root->right = deleteNode(root->right, temp->key);
            }
        }
        if(root == NULL){
            return root;
        }
        //update the balance factor for each node
      root->height = 1 + max(height(root->left),
               height(root->right));

  int balance = getBalance(root);
  if (balance > 1 && key < root->left->key)
    return rightRotate(root);

  if (balance < -1 && key > root->right->key)
    return leftRotate(root);

  if (balance > 1 && key > root->left->key) {
    root->left = leftRotate(root->left);
    return rightRotate(root);
  }

  if (balance < -1 && key < root->right->key) {
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }
  return root;
        
    }//deleteNode;


// Print the tree
void printPreOrder(struct Node *root) {
  if (root != NULL) {
    printf("%d ", root->key);
    printPreOrder(root->left);
    printPreOrder(root->right);
  }
}//printPreOrder;

void inOrder(struct Node *root) {
  if (root != NULL) {
    printPreOrder(root->left);
        printf("%d ", root->key);
    printPreOrder(root->right);
  }
}//inOrder;

// Function to print binary tree in 2D 
// It does reverse inorder traversal 
void print2DUtil(struct Node *root, int space) 
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
void print2D(struct Node *root) 
{ 
   // Pass initial space count as 0 
   print2DUtil(root, 0); 
} //print2D;

int main() {
    printf("AVL Tree program");
  struct Node *root = NULL;
  
//example tree implementation
  root = insertNode(root, 2);
  root = insertNode(root, 1);
  root = insertNode(root, 7);
  root = insertNode(root, 4);
  root = insertNode(root, 5);
  root = insertNode(root, 3);
  root = insertNode(root, 8);

printf("\nPost Order\n");
  printPreOrder(root);
printf("\nIn Order\n");
  inOrder(root);
  
  print2D(root);
  
  root = deleteNode(root, 4);

  printf("\nAfter deletion: 3");
  printf("\nPost Order\n");
  printPreOrder(root);
printf("\nIn Order\n");
  inOrder(root);
  
  print2D(root);

  return 0;
}
