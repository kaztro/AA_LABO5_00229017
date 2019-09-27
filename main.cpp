#include <iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct node{
    int key;
    struct node *left, *right;
};

// A utility function to create a new BST node
struct node *newNode(int item){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// A utility function to do inorder traversal of BST
void inorder(struct node *root){
    if (root != NULL){
        inorder(root->left);
        printf("%d \n", root->key);
        inorder(root->right);
    }
}

void preorder(struct node *root){
    if (root != NULL){
	printf("%d \n", root->key);
        preorder(root->left);
	preorder(root->right);
    }
}

void postorder(struct node *root){
    if (root != NULL){
        postorder(root->left);
	postorder(root->right);
	printf("%d \n", root->key);
    }
} 

/* A utility function to insert a new node with given key in BST */
struct node* insert(struct node* node, int key){
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key);
    /* Otherwise, recur down the tree */
    if (key < node->key) node->left = insert(node->left, key);
    else if (key > node->key) node->right = insert(node->right, key);
    /* return the (unchanged) node pointer */
    return node;
}

struct node* auxOfFreeN(node* nodeR) {
  while(nodeR->left) nodeR=nodeR->left;	
  return nodeR;
}

struct node* freeN(struct node* node, int key) {
    if (node == NULL) return node;
    if (key < node -> key) node -> left = freeN(node->left, key);
    else if (key > node -> key) node -> right = freeN(node -> right, key);
    else {
	if(key == node->key){ 
		if(node -> left == NULL && node -> right == NULL) free(node);
		if(node -> left != NULL || node -> right != NULL) {
			if(node -> left != NULL && node -> left != NULL) {
 			  struct node* temp = auxOfFreeN(node->right);
			  node->key = temp->key;
                          node->right = freeN(node->right, temp->key);
			  return node;
			}
			if(node -> left != NULL) {
			   struct node* temp = node->left;
			   free(node);
			   return temp;
			}
			if(node -> right != NULL) {
			   struct node* temp = node->right;
			   free(node);
			   return temp;
			}
		}
		return NULL;	
	}
    }
}

// Driver Program to test above functions
int main(){
    /* Let us create following BST50/ \30 70/ \ / \20 40 60 80 */
    struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    inorder(root);
    cout << "///////////////////" << "PREORDER" << "///////////////////" << endl;
    preorder(root);
    cout << "///////////////////" << "FREING SOME NODE" << "///////////////////" << endl;
    freeN(root, 70);
    // print inoder traversal of the BST
    inorder(root);
    return 0;
}

