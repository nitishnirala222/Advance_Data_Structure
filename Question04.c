#include<stdio.h>
#include <malloc.h>

struct node {
    int key;
    struct node *parent,*child,*left,*right;
};

struct node* min = NULL;

int n = 0;

void insertion(int val)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->key = val;
    new_node->parent = NULL;
    new_node->child = NULL;
    new_node->left = new_node;
    new_node->right = new_node;
    if (min != NULL) {
        (min->left)->right = new_node;
        new_node->right = min;
        new_node->left = min->left;
        min->left = new_node;
        if (new_node->key < min->key)
            min = new_node;
    }
    else {
        min = new_node;
    }
}

typedef struct node node;
void display(node* min)
{
    node *ptr = min;
    if (ptr == NULL)
        printf("The Heap is Empty");

    else {
        printf("The root nodes of Fibonacci Heap are: ");
        do {
            printf("%d ",ptr->key);
            ptr = ptr->right;
            if (ptr != min) {
                printf("-->");
            }
        } while (ptr != min && ptr->right != NULL);
    }
}

int main()
{

    n = 7;
    insertion(60);
    insertion(39);
    insertion(17);
    insertion(29);
    insertion(12);
    insertion(13);
    insertion(11);

    display(min);

}
