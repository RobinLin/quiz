/* FIXME: Implement! */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>


typedef struct TreeNode {
    int value;
    struct TreeNode *left;
    struct TreeNode *right;
} Node;


void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree)) {
        temp = (Node *)malloc(sizeof(Node));
        temp->left = temp->right = NULL;
        temp->value = val;
        *tree = temp;
        return;
    }
    if(val < (*tree)->value) {
        insert(&(*tree)->left, val);
    } else if(val > (*tree)->value) {
        insert(&(*tree)->right, val);
    }
}

void print_preorder(Node * tree)
{
    if (tree) {
        printf("%d\n",tree->value);
        print_preorder(tree->left);
        print_preorder(tree->right);
    }
}

void print_inorder(Node * tree)
{
    if (tree) {
        print_inorder(tree->left);
        printf("%d\n",tree->value);
        print_inorder(tree->right);
    }
}

void print_postorder(Node * tree)
{
    if (tree) {
        print_postorder(tree->left);
        print_postorder(tree->right);
        printf("%d\n",tree->value);
    }
}

static double diff_in_second(struct timespec t1, struct timespec t2)
{
    struct timespec diff;
    if (t2.tv_nsec-t1.tv_nsec < 0) {
        diff.tv_sec  = t2.tv_sec - t1.tv_sec - 1;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec + 1000000000;
    } else {
        diff.tv_sec  = t2.tv_sec - t1.tv_sec;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec;
    }
    return (diff.tv_sec + diff.tv_nsec / 1000000000.0);
}

void flatten(TreeNode *root)
{
	
    while (root) {
        if (root->left) {
            TreeNode* pre=root->left;
            while (pre->right) {
                pre = pre->right;
            }
            pre->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
        root=root->right;
    }
}

int main()
{
    struct timespec start, end;
    double cpu_time;

    clock_gettime(CLOCK_REALTIME, &start);

    clock_gettime(CLOCK_REALTIME, &end);
    cpu_time = diff_in_second(start, end);

    printf("execution time of iterative : %lf sec\n", cpu_time);
    return 0;
}

