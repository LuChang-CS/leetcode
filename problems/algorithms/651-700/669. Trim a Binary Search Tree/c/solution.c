#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct TreeNode TreeNode;

TreeNode *trim(TreeNode *node, int L, int R) {
    if (node == NULL) return NULL;
    // replace node with left child
    if (node->val > R) return trim(node->left, L, R);
    // replace node with right child
    if (node->val < L) return trim(node->right, L, R);
    // move to child
    node->left = trim(node->left, L, R);
    node->right = trim(node->right, L, R);
    return node;
}

struct TreeNode* trimBST(struct TreeNode* root, int L, int R) {
    return trim(root, L, R);
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
    TreeNode root, left, right;
    root.val = 1;
    root.left = &left;
    root.right = &right;
    left.val = 0;
    left.left = left.right = NULL;
    right.val = 2;
    right.left = right.right = NULL;
    trimBST(&root, 1, 2);
    print_tree(&root, 3);
    return 0;
}
