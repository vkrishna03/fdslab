#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newnode(int key)
{
    struct node *p;
    p = malloc(sizeof(struct node));
    p->data = key;
    p->left = NULL;
    p->right = NULL;

    return p;
}

struct node *insert(struct node *root, int key)
{
    if (root == NULL)
        root = newnode(key);
    else if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    return root;
}

void inorder(struct node *t)
{
    if (t != NULL)
    {
        inorder(t->left);
        printf("%d\t", t->data);
        inorder(t->right);
    }
}

void preorder(struct node *t)
{
    if (t != NULL)
    {
        printf("%d\t", t->data);
        preorder(t->right);
        preorder(t->left);
    }
}

void postorder(struct node *t)
{
    if (t != NULL)
    {
        printf("%d\t", t->data);
        postorder(t->left);
        postorder(t->right);
    }
}

struct node *search(struct node *root, int key)
{
    struct node *p = root;

    while (p != NULL)
    {
        if (key == p->data)
            return p;
        else if (key < p->data)
            p = p->left;
        else if (key > p->data)
            p = p->right;
    }
    return NULL;
}

void main()
{

    struct node *root = NULL;

    int ch;
    int x, y;

    printf("\n * * * BST ADT * * *\n");
    printf("\n1.Insert\n2.Inorder\n3.Postorder\n4.Preorder\n5.Search\n6.Exit\n");

    while (1)
    {

        printf("\nEnter your choice:\t");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter data:\t");
            scanf("%d", &x);
            root = insert(root, x);
            break;
        case 2:
            inorder(root);
            break;
        case 3:
            postorder(root);
            break;
        case 4:
            preorder(root);
            break;
        case 5:
            printf("Enter data:\t");
            scanf("%d", &x);
            search(root, x);
            break;
        case 6:
            exit(0);
        default:
            printf("\nEnter valid choice!\n");
        }
    }
}
