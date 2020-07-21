#include <iostream>
#include <conio.h>
#include <process.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct node
{
    int data;
    struct node *left, *right;
};
typedef struct node *NODE;

NODE root = NULL;
NODE insert(int item)
{
    NODE temp;
    temp = new node;
    temp->data = item;
    temp->left = NULL;
    temp->right = NULL;
    if (root == NULL)
    {
        root = temp;
        cout << temp->data << " is inserted as root" << endl;
        return root;
    }
    NODE cur, par;
    cur = root;
    par = NULL;
    while (cur != NULL)
    {
        par = cur;
        if (item < cur->data)
            cur = cur->left;
        else
            cur = cur->right;
    }
    if (item > par->data)
    {
        par->right = temp;
    }
    else
    {
        par->left = temp;
    }
    cout << temp->data << " was inserted" << endl;
    return root;
}
void display(NODE root)
{
    NODE temp;
    temp = root;
    if (root == NULL)
    {
        return;
    }

    display(temp->left);
    cout << temp->data << "->";
    display(temp->right);
}
NODE delete_node()
{
    NODE cur, parent, succ, q;
    int item;
    cout << "Enter the item to be deleted: " << endl;
    cin >> item;

    if (root == NULL)
    {
        cout << "The tree is already empty." << endl;
        return NULL;
    }
    parent = NULL;
    succ = NULL;
    cur = root;
    while (cur != NULL)
    {
        if (item == cur->data)
        {
            break;
        }
        parent = cur;
        if (item > cur->data)
        {
            cur = cur->right;
        }
        else
        {
            cur = cur->left;
        }
    }
    if (cur == NULL)
    {
        cout << "Item not found!" << endl;
        return NULL;
    }
    if (cur->left == NULL)
    {
        q = cur->right;
    }
    else if (cur->right == NULL)
    {
        q = cur->left;
    }
    else
    {
        succ = cur->right;
        while (cur->right != NULL)
        {
            succ = succ->left;
        }
        succ->left = cur->right;
        q = cur->right;
    }
    if (parent == NULL)
    {
        root = q;
    }
    else if (parent->left == cur)
    {
        parent->left = q;
    }
    else
    {
        parent->right = q;
    }
    cout << "The " << cur->data << " element was found and deleted!" << endl;
    delete (cur);
    return root;
}

int main()
{

    int item = 0, ch;
    while (1)
    {
        cout << endl;
        cout << "1.insert\n2.display\n3.delete\n4.exit" << endl
             << "enter your choice:" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "enter the number to be inserted:" << endl;
            cin >> item;
            root = insert(item);
            break;
        case 2:
            display(root);
            break;
        case 3:
            delete_node();
            break;
        case 4:
            exit(0);
        default:
            cout << "choose wisely" << endl;
        }
    }
    return 0;
}
