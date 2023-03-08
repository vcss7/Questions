#include<stdio.h>
#include<stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* sortedArrayToBST(int* nums, int numsSize);
void printTree(struct TreeNode *root);

int main(int argc, char** argv)
{
    int nums[] = {-10, -3, 0, 5, 9};
    int numsSize = sizeof(nums) / sizeof(int);

    int nums2[] = {1, 3};
    int numsSize2 = sizeof(nums2) / sizeof(int);

    struct TreeNode *root = sortedArrayToBST(nums, numsSize);
    printf("nums: ");
    printTree(root);
    printf("\n");

    struct TreeNode *root2 = sortedArrayToBST(nums2, numsSize2);
    printf("nums2: ");
    printTree(root2);
    printf("\n");

    free(root);
    free(root2);

    return 0;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize)
{
    if (numsSize == 0)
        return NULL;

    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    int mid = numsSize / 2;

    root->val = nums[mid];
    root->left = sortedArrayToBST(nums, mid);
    root->right = sortedArrayToBST(nums + mid + 1, numsSize - mid - 1);

    return root;
}

void printTree(struct TreeNode *root)
{
    if (root == NULL)
        return;

    printTree(root->left);
    printf("%d ", root->val);
    printTree(root->right);
}

