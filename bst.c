#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

struct Node *maxV(struct Node *n);
struct Node *minV(struct Node *n);


struct Node{
	struct Node *left, *right;
	int val;
};


struct Node *newNode(int data){
	struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
	temp->val = data;
	temp->left = temp->right = NULL;
	return temp;
}

//inorder traversal
void printInorder(struct Node *root)
{0.0
	if(root != NULL)
	{
		printInorder(root->left);
		printf(" %d \n", root->val);
		printInorder(root->right);
	}
}

//insert a node
struct Node *insert(struct Node *root, int data){
	
	if(root == NULL)
	{
		return newNode(data);
	}
	if(root->val > data)
	{
		root->left = insert(root->left, data);
	}
	else if(root->val < data) 
	{
		root->right = insert(root->right, data);
	}
	return root;
}

//search if an element exists using recursion
int contains(struct Node *root, int data)
{
	if(root->val == data)
	{
		return 1;
	}
	if(root->val > data)
	{
		if(root->left == NULL)
			return 0;
		else
			return contains(root->left, data);
	}
	else if(root->val < data)
	{
		if(root->right == NULL)
            return 0;
        else
            return contains(root->right, data);
	}
}

//search if an element exists using iteration
int iterativeSearch(struct Node *root, int data)
{
	while(root != NULL)
	{
		if(root->val > data)
			root = root->left;
		else if(root->val < data)
			root = root->right;
		else
			return true;
	}
	return false;
}

int findSmallest(struct Node* root){
    if(root == NULL)
        return 0;
    struct Node* curr = root;
    while(curr->left != NULL){
        curr = curr->left;
    }
    return curr->val;
}

//fid the next successor node 

struct Node *findSucc(struct Node *root, struct Node *n)
{
	if(n->right != NULL)
		return minV(n->right);
	struct Node *succ = NULL;
	while(root != NULL)
	{
		if(n->val < root->val)
		{
			succ = root;
			root = root->left;
		}
		else if(n->val > root->val){
			root = root->right;
		}
		else
			break;
	}
	return succ;
}

struct Node *findPred(struct Node *root, struct Node *n)
{
	if(n->left != NULL)
		return maxV(n->left);
	struct Node *pre = NULL;
	while(root != NULL)
	{
		if(n->val > root->val)
		{
			pre = root;
			root = root->right;
		}
		else if(n->val < root->val){
			root = root->left;
		}
		else
			break;
	}
	return pre;
}


struct Node *maxV(struct Node *n)
{
	struct Node *curr = n;
	while(curr->right != NULL){
		curr = curr->right;
	}
	return curr;
}


//finding the minimum element which is obviously a left node
struct Node *minV(struct Node *n)
{
	struct Node *curr = n;
	while(curr->left != NULL){
		curr = curr->left;
	}
	return curr;
}
		
struct node* deleteNode(struct node* root, int key) 
{ 
    if (root == NULL) return root; 
	if (key < root->val) 
        root->left = deleteNode(root->left, key); 
	else if (key > root->val) 
        root->right = deleteNode(root->right, key); 
  
    // if key is same as root's key, then This is the node 
    // to be deleted 
    else
    { 
        // node with only one child or no child 
        if (root->left == NULL) 
        { 
            struct node *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            struct node *temp = root->left; 
            free(root); 
            return temp; 
        }   
        // node with two children: Get the inorder successor (smallest 
        // in the right subtree) 
        struct node* temp = minV(root->right); 
  
        // Copy the inorder successor's content to this node 
        root->val = temp->val; 
  
        // Delete the inorder successor 
        root->right = deleteNode(root->right, temp->val); 
    } 
    return root; 
} 

int main(){

	struct Node *root = NULL;
	struct Node *temp, *succ;
	root = insert(root, 50);
	insert(root, 20);
	insert(root, 40);
	insert(root, 60);
	insert(root, 80);
	insert(root, 100);
	insert(root, 120);
	insert(root, 140);
    
    int min = findSmallest(root);	
//	temp = root->left->right;
//	succ = findPred(root, temp);

//	printInorder(root);
//	int res = contains(root, 40);   
    printf("%d \n", min);
//	printf("%d ---> %d\n", temp->val, succ->val);

	return 0;
}
			
			
		
