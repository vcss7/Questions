#include<stdio.h>
#include<stdlib.h>


// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void preorder(struct TreeNode* root, int* result, int* index);
int* preorderTraversal(struct TreeNode* root, int* returnSize);

int main(int argc, char** argv)
{
    struct TreeNode* root = malloc(sizeof(struct TreeNode));
    root->val = 1;
    root->left = NULL;
    root->right = malloc(sizeof(struct TreeNode));
    root->right->val = 2;
    root->right->left = malloc(sizeof(struct TreeNode));
    root->right->left->val = 3;
    root->right->left->left = NULL;
    root->right->left->right = NULL;
    root->right->right = NULL;

    int returnSize = 0;
    int* result = preorderTraversal(root, &returnSize);

    printf("returnSize: %d\n", returnSize);
    printf("result: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}

void preorder(struct TreeNode* root, int* result, int* index) {
    if (root == NULL) return;

    // append
    result[*index] = root->val;
    (*index)++;

    preorder(root->left, result, index);
    preorder(root->right, result, index);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = malloc(100 * sizeof(int));
    int index = 0;

    preorder(root, result, &index);
    *returnSize = index;

    return result;
}
