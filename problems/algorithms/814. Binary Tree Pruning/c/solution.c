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

// solution begin
int count_one(struct TreeNode* r) {
    if (r == NULL) return 0;
    int left_count = count_one(r->left);
    int right_count = count_one(r->right);
    /**
    * I write this comment just to say I remember to free the memory,
    * but in this test, forget it.
    */
    if (left_count == 0) r->left = NULL;
    if (right_count == 0) r->right = NULL;
    return r->val + left_count + right_count;  // consider the value for this node itself.
}

struct TreeNode* pruneTree(struct TreeNode* root) {
    count_one(root);
    return root;
}
// solution end

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
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *level1_right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *level2_left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *level2_right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = 1;
    level1_right->val = 0;
    level2_left->val = 0;
    level2_right->val = 1;
    root->left = NULL;
    root->right = level1_right;
    level1_right->left = level2_left;
    level1_right->right = level2_right;
    level2_left->left = level2_left->right = NULL;
    level2_right->left = level2_right->right = NULL;
    root = pruneTree(root);
    struct TreeNode* subnodes[200];
    subnodes[0] = root;
    print_tree(subnodes, 0, 1);
    getchar();
    return 0;
}
