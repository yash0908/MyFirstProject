#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};


void append(Node **root, int x)
{
    Node *new_node = new Node(x);

    if(*root == NULL)
        *root = new_node;
    else
    {
        Node *temp = *root;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = new_node;
    }
}


void display(Node *root)
{
    while(root != NULL)
    {
        cout<<root->data<<" ";
        root =  root->next;
    }
    cout<<"\n";
}

void reverse_list(Node **root, Node* prev, Node* cur)
{
    if(cur == NULL)
        return;
    /*if(cur->next == NULL)
    {
        *root = cur;
        cur->next = prev;
        return;
    }*/
    Node *p = cur->next;
    cur->next = prev;
    prev = cur;
    cur = p;
    *root = prev;
    reverse_list(root, prev, cur);

}


int main()
{
    int t;
    cout<<"\nenter the no of nodes \n";
    cin>>t;
    Node *root = NULL;
    while(t--)
    {
        int temp;
        cin>>temp;
        append(&root, temp);
    }
    display(root);

    reverse_list(&root, NULL, root);
    display(root);
}
