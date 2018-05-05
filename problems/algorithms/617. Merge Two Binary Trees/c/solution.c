#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2) {
    if (t1 == NULL) return t2;
    if (t2 == NULL) return t1;
    t1->val += t2->val;
    if (t1->left == NULL && t2->left != NULL) {
        t1->left = t2->left;  // move t2's left to t1, no malloc
    } else if (t1->left != NULL && t2->left != NULL) {
        mergeTrees(t1->left, t2->left);  // go to child node
    }
    if (t1->right == NULL && t2->right != NULL) {
        t1->right = t2->right;
    } else if (t1->right != NULL && t2->right != NULL) {
        mergeTrees(t1->right, t2->right);
    }
    return t1;
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
    typedef struct TreeNode TreeNode;
    TreeNode root1, m1, m2, m3;
    TreeNode root2, n1, n2, n3, n4;
    root1.val = 1, root1.left = &m1, root1.right = &m2;
    m1.val = 3, m1.left = &m3, m1.right = NULL;
    m2.val = 2, m2.left = NULL, m2.right = NULL;
    m3.val = 5, m3.left = NULL, m3.right = NULL;
    root2.val = 2, root2.left = &n1, root2.right = &n2;
    n1.val = 1, n1.left = NULL, n1.right = &n3;
    n2.val = 3, n2.left = NULL, n2.right = &n4;
    n3.val = 4, n3.left = NULL, n3.right = NULL;
    n4.val = 7, n4.left = NULL, n4.right = NULL;
    mergeTrees(&root1, &root2);
    print_tree(&root1, 9);
    return 0;
}
