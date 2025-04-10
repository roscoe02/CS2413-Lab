// 144. Binary Tree Preorder Traversal
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    
    if (!root) {
        return NULL;
    }
    
    int capacity = 100;
    int* result = (int*)malloc(capacity * sizeof(int));
    struct TreeNode** stack = (struct TreeNode**)malloc(capacity * sizeof(struct TreeNode*));
    int top = -1;
    
    stack[++top] = root;
    
    while (top >= 0) {
        struct TreeNode* node = stack[top--];
        result[(*returnSize)++] = node->val;
        
        if (*returnSize >= capacity) {
            capacity *= 2;
            result = (int*)realloc(result, capacity * sizeof(int));
            stack = (struct TreeNode**)realloc(stack, capacity * sizeof(struct TreeNode*));
        }
        
        if (node->right) stack[++top] = node->right;
        if (node->left) stack[++top] = node->left;
    }
    
    free(stack);
    return result;
}

// 94. Binary Tree Inorder Traversal
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    
    if (!root) {
        return NULL;
    }
    
    int capacity = 100;
    int* result = (int*)malloc(capacity * sizeof(int));
    struct TreeNode** stack = (struct TreeNode**)malloc(capacity * sizeof(struct TreeNode*));
    int top = -1;
    
    struct TreeNode* node = root;
    
    while (node || top >= 0) {
        while (node) {
            stack[++top] = node;
            node = node->left;
        }
        
        node = stack[top--];
        result[(*returnSize)++] = node->val;
        
        if (*returnSize >= capacity) {
            capacity *= 2;
            result = (int*)realloc(result, capacity * sizeof(int));
            stack = (struct TreeNode**)realloc(stack, capacity * sizeof(struct TreeNode*));
        }
        
        node = node->right;
    }
    
    free(stack);
    return result;
}
