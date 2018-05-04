#include <stdio.h>
#include <stdlib.h>


/**
* Definition for a binary tree node.
*/
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize) {
    typedef struct TreeNode TreeNode;
    // we need a root pointer to the real root
    TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
    root->right = NULL;
    for (int i = 0; i < numsSize; ++i) {
        int v = nums[i];
        TreeNode *p = root;
        // move to right and find a node's right child less than current value
        while (p->right != NULL && v < p->right->val) {
            p = p->right;
        }
        TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
        node->val = v;
        node->left = p->right;  // null or less than current value should be node's left child
        node->right = NULL;
        p->right = node;  // replace previous right child
    }
    return root->right;  // return real root
}

void print_tree(struct TreeNode* subnodes[], int top, int bottom) {
    if (top == bottom) return;
    int new_top = top, new_bottom = bottom;
    for (int i = top; i < bottom; ++i) {
        if (subnodes[i] == NULL) printf("%s", "null ");
        else {
            printf("%d ", subnodes[i]->val);
            if (subnodes[i]->left != NULL || subnodes[i]->right != NULL) {
                subnodes[new_bottom++] = subnodes[i]->left;
                subnodes[new_bottom++] = subnodes[i]->right;
            }
        }
        ++new_top;
    }
    print_tree(subnodes, new_top, new_bottom);
}

int main() {
    int nums[] = { 3, 2, 1, 6, 0, 5 };
    struct TreeNode *root = constructMaximumBinaryTree(nums, 6);
    struct TreeNode* subnodes[1000];
    subnodes[0] = root;
    print_tree(subnodes, 0, 1);
    return 0;
}
