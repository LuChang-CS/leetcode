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
    print_tree(root, 4);
    return 0;
}
