#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENT 100

typedef struct TreeNode
{

    char ch;

    int weight;

    struct TreeNode *left_child;

    struct TreeNode *right_child;

} TreeNode;

typedef struct
{

    TreeNode *ptree;

    int key;

} element;

typedef struct
{

    element heap[MAX_ELEMENT];

    int heap_size;

} HeapType;

// initialization function

void init(HeapType *h)

{

    h->heap_size = 0;
}

// insertion function

void insert_min_heap(HeapType *h, element item)

{ //Complete the following
}

// Delete function

element delete_min_heap(HeapType *h)

{ //Complete the following
}

// binary tree generation function

TreeNode *make_tree(TreeNode *left, TreeNode *right)

{

    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));

    if (node == NULL)
    {

        fprintf(stderr, "memory error\n");

        exit(1);
    }

    node->left_child = left;

    node->right_child = right;

    return node;
}

// binary tree removal function

void destroy_tree(TreeNode *root)

{

    if (root == NULL)
        return;

    destroy_tree(root->left_child);

    destroy_tree(root->right_child);

    free(root);
}

// Huffman code generation function

TreeNode *huffman_tree(char ch_arr[], int freq[], int n)

{

    int i;

    TreeNode *node, *x;

    HeapType heap;

    element e, e1, e2;

    init(&heap);

for(i=0;i

node = make_tree(NULL, NULL);

node->ch= ch_arr[i];

e.key = node->weight = freq[i];

e.ptree = node;

insert_min_heap(&heap, e);
}

while (heap.heap_size > 1)
{ //for(i=1;i

    e1 = delete_min_heap(&heap); // Delete two nodes with minimum value

    e2 = delete_min_heap(&heap);

    x = make_tree(e1.ptree, e2.ptree); // Combine the two nodes.

    x->ch = 0;

    e.key = x->weight = e1.key + e2.key;

    e.ptree = x;

    insert_min_heap(&heap, e);
}

e = delete_min_heap(&heap); // final tree

return e.ptree;
}

void traverse(TreeNode *p, char code[], int level)
{

    int i;

    if (p != NULL)
    {

        if (p->ch > 0)
        {

            printf("%c : ", p->ch);

for (i=0; i

printf("%c", code[i]);

printf("\n");
        }

        else
        {

            code[level] = '0';

            traverse(p->left_child, code, level + 1);

            code[level] = '1';

            traverse(p->right_child, code, level + 1);
        }
    }
}

// main function

void main()

{

    char ch_arr[] = {'A', 'B', 'C', 'D', 'E'};

    int freq[] = {15, 12, 8, 6, 4};

    TreeNode *node = huffman_tree(ch_arr, freq, 5);

    char h_code[100];

    traverse(node, h_code, 0);

    destroy_tree(node);

    getchar();
}

/* Results
C : 00
E : 010
D : 011
B : 10
A : 11
*/