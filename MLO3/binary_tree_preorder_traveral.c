#include<stdio.h>
#include<stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* create_node(int val);
int* preorderTraversal(struct TreeNode* root, int* returnSize);

int main(int argc, char** argv)
{
    return 0;
}

struct TreeNode* create_node(int val)
{
    struct TreeNode *node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
    int *result = (int*)malloc(sizeof(int) * 100);
    int i = 0;
    if(root == NULL)
    {
        *returnSize = 0;
        return result;
    }
    result[i++] = root->val;
    int *left = preorderTraversal(root->left, returnSize);
    int *right = preorderTraversal(root->right, returnSize);
    for(int j = 0; j < *returnSize; j++)
    {
        result[i++] = left[j];
    }
    for(int j = 0; j < *returnSize; j++)
    {
        result[i++] = right[j];
    }
    *returnSize = i;
    return result;
}
