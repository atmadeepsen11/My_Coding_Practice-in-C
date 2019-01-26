void recursive(struct TreeNode* root, int* res, int* size){
    if(root==NULL){
        return;
    }
      
			//1. in the case of "leaf nodes"**
    if(root->left==NULL && root->right==NULL){
        res[*size]=root->val;
        (*size)++;
        return;
    }
		
    if(root->left!=NULL){
        recursive(root->left, res, size);
    }
			//2. in the case of "intermediate node"**
    res[*size]=root->val;
    (*size)++;
    
    if(root->right!=NULL){
        recursive(root->right, res, size);
    }
		
    return;
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* traversalResult=(int*)malloc(1000*sizeof(struct TreeNode));
    
    recursive(root, traversalResult, returnSize);
    return traversalResult;
}