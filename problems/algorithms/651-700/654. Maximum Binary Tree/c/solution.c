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

void print_tree(struct TreeNode* root, int tree_size) {
    typedef struct TreeNode TreeNode;
    TreeNode **queue = (TreeNode **)malloc(2 * tree_size * sizeof(TreeNode *));
    int bottom = 0, top = 1;
    queue[0] = root;
    while (bottom != top) {
        TreeNode *node = queue[bottom++];
        if (node == NULL) printf("null ");
        else {
            printf("%d ", node->val);
            if (node->left != NULL || node->right != NULL) {
                queue[top++] = node->left;
                queue[top++] = node->right;
            }
        }
    }
    free(queue);
}

int main() {
    int nums[] = { 3, 2, 1, 6, 0, 5 };
    struct TreeNode *root = constructMaximumBinaryTree(nums, 6);
    print_tree(root, 6);
    return 0;
}
