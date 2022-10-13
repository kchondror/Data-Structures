#include <iostream>
#include "BinaryTree.h"

 BinaryTree:: BinaryTree()
{
    //initializing the childs to null and the number of inserts to 0
    Lchild=Rchild=nullptr;
    numberOfInserts=0;
}

void BinaryTree::init()
{
    //initializing the root to null
    root=nullptr;
}

bool BinaryTree::insert_root(string &word)
{
    //creates a new object of Binary tree and sets it as the root of the tree
    BinaryTree *newnode;
    if(root!=nullptr)
        return false;

    newnode=new(nothrow) BinaryTree;
    if(newnode==nullptr)
    {
        cout<<"not enough memory"<<endl;
        return false;
    }
    newnode->data=word;
    newnode->Lchild=nullptr;
    newnode->Rchild=nullptr;
    newnode->numberOfInserts++;
    root=newnode;
    return true;

}

bool BinaryTree::insert_node(string &word)
{
    //checks where to put the word
    if(root ==nullptr)//checks if the root is empty
    {
        insert_root(word);
        return true;
    }
    BinaryTree *current;
    current=root;
    while(current)//a loop that goes on until it finds some place to insert the current word
    {
        if(word==current->data)
        {
            current->numberOfInserts++;//if it already exists
            return false;
        }
        else if(word<current->data)
        {
            if(current->Lchild==nullptr)//checks if current node has already a left child
            {
                insert_left(current,word);//if not then the word inserts as left child of the current node
                return true;
            }
            current=current->Lchild;//else moves deeper in the left of the node
        }

        else if (word>current->data)
        {
            if(current->Rchild==nullptr)//checks if current node has already a right child
            {
                insert_right(current,word);//if not then the word inserts as right child of the current node
                return true;
            }
           current=current->Rchild;//else moves deeper in the right of the node
        }
    }
    return false;
}

bool BinaryTree::insert_right(BinaryTree *current,string &word)
{
    //creates a new node
    BinaryTree *newnode;
    if(current->Rchild!=nullptr)
        return false;

    newnode=new(nothrow) BinaryTree;
    if(newnode==nullptr)
    {
        cout<<"not enough memory"<<endl;
        return false;
    }
    newnode->data=word;
    newnode->Lchild=nullptr;
    newnode->Rchild=nullptr;
    newnode->numberOfInserts++;
    current->Rchild=newnode;//transports the new nodes data to the currents one right child
    return true;
}

bool BinaryTree::insert_left(BinaryTree *current,string &word)
{
    //creates a new node
    BinaryTree *newnode;
    if(current->Lchild!=nullptr)
        return false;

    newnode=new (nothrow)BinaryTree;
    if(newnode==nullptr)
    {
        cout<<"not enough memory"<<endl;
        return false;
    }
    newnode->data=word;
    newnode->Lchild=nullptr;
    newnode->Rchild=nullptr;
    newnode->numberOfInserts++;
    current->Lchild=newnode;//transports the new nodes data to the currents one left child
    return true;
}

void BinaryTree::preorder(BinaryTree *node)
{
    //executes a preorder and prints the tree nodes
    if(node!=nullptr)
    {
        cout<<node->data<<endl;
        preorder(node->Lchild);
        preorder(node->Rchild);
    }
}

void BinaryTree::inorder(BinaryTree *node)
{
    //executes a inorder and prints the tree nodes
    if(node!=nullptr)
    {
        inorder(node->Lchild);
        cout<<node->data<<endl;
        inorder(node->Rchild);
    }
}

void BinaryTree::postorder(BinaryTree *node)
{
    //executes a postorder and prints the tree nodes
    if(node!=nullptr)
    {
        postorder(node->Lchild);
        postorder(node->Rchild);
        cout<<node->data<<endl;
    }
}

bool BinaryTree::Search(string &word)
{
    //searches if a word exists in the tree and how many times
    BinaryTree *p=root;
    while(p)//a loop that goes through the tree until the word is found or ends if not
    {
        if(word<p->data)
            p=p->Lchild;
        else if(word>p->data)
            p=p->Rchild;
        else
        {
            cout<<"The word '"<<word<<"' has appeared "<<p->numberOfInserts<< " times " <<endl;
            return true;//returns true if the word exists
        }
    }
return false;//returns false if the tree reaches the bottom and the word is not found
}


bool BinaryTree::Delete(const string word)
{
    BinaryTree *p=root,*pp=nullptr;
    while(p!=nullptr && p->data !=word)//search to find the word
    {
        pp=p;
        if(word<p->data)
            p=p->Lchild;
        else
            p=p->Rchild;
    }
    if(p==nullptr)//if the word dont found in the tree
        return false;
    if(p->Lchild!=nullptr && p->Rchild!=nullptr)//if the node has a 2 childs
    {
        BinaryTree *s=p->Lchild,*ps=p;
        while(s->Rchild!=nullptr)
        {
            ps=s;
            s=s->Rchild;
        }
        p->data=s->data;
        p=s;
        pp=ps;
    }
    BinaryTree *current;
    if(p->Lchild!=nullptr)//if the node has 1 child
        current=p->Lchild;
    else
        current=p->Rchild;
    if(p==root)//if the node that we want to delete is the only node in the tree
        root=current;
    else//if the node has no childs
    {
        if(p==pp->Lchild)
            pp->Lchild=current;
        else
            pp->Rchild=current;
    }
    delete p;
    return true;

}








