#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// use a linked list to store path temporarily
struct Path {
    int *path;
    int path_len;
    struct Path *next;
};
typedef struct Path Path;

int** allPathsSourceTarget(int** graph, int graphRowSize, int *graphColSizes, int** columnSizes, int* returnSize) {
    Path *paths_list = (Path *)malloc(sizeof(Path));
    paths_list->next = NULL;
    Path *paths_list_tail = paths_list;
    int path_number = 0;

    // BFS in a stack manner
    int node_stack[225], top = 0;
    node_stack[0] = 0;
    // this stack is to store the path length in each layer
    // the successive nodes of one node form a layer
    int path_len_stack[225], len_top = 0;
    path_len_stack[0] = 1;

    // a path
    int *current_path = (int *)malloc(15 * sizeof(int));
    int current_path_len;
    while (top >= 0) {
        // fetch next node
        int current_node = node_stack[top--];
        // fetch the coresponding path length for this node
        current_path_len = path_len_stack[len_top--];
        // add this node to current path
        current_path[current_path_len - 1] = current_node;
        if (current_node == graphRowSize - 1) {  // if path exists
            // add path to linked list
            Path *p = (Path *)malloc(sizeof(Path));
            p->path = current_path;
            p->path_len = current_path_len;
            p->next = NULL;
            paths_list_tail->next = p;
            paths_list_tail = p;

            // get a new path based on current path
            current_path = (int *)malloc(15 * sizeof(int));
            memcpy(current_path, p->path, (current_path_len - 1) * sizeof(int));
            ++path_number;
        } else {
            int *current_row = graph[current_node];
            int current_row_size = graphColSizes[current_node];
            // add successive nodes and path lengths to the stack
            for (int i = 0; i < current_row_size; ++i) {
                node_stack[++top] = current_row[i];
                path_len_stack[++len_top] = current_path_len + 1;
            }
            // move to next layer
            if (current_row_size > 0) ++current_path_len;
        }
    }

    *returnSize = path_number;
    int **paths = (int **)malloc(path_number * (sizeof(int *)));
    *columnSizes = (int *)malloc(path_number * (sizeof(int *)));
    Path *p = paths_list->next;
    // transform linked list to 2d array
    for (int i = 0; p != NULL; ++i) {
        paths[i] = p->path;
        (*columnSizes)[i] = p->path_len;
        p = p->next;
    }
    return paths;
}

int main() {
    int row1[] = { 1, 2};
    int row2[] = { 3 };
    int row3[] = { 3 };
    int **graph = (int **)malloc(4 * sizeof(int *));
    graph[0] = row1;
    graph[1] = row2;
    graph[2] = row3;
    graph[3] = NULL;
    int graphRowSize = 4;
    int graphColSizes[] = { 2, 1, 1, 0 };
    int *columnSizes;
    int returnSize;
    int **paths = allPathsSourceTarget(graph, graphRowSize, graphColSizes, &columnSizes, &returnSize);
    for (int i = 0; i < returnSize; ++i) {
        int path_len = columnSizes[i];
        int *path = paths[i];
        for (int j = 0; j < path_len; ++j) {
            printf("%d ", path[j]);
        }
        printf("\n");
    }
    return 0;
}
