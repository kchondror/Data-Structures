#include <iostream>
#include "AVL.h"

AVL::AVL()
{
    //initializing the childs to null and the number of inserts ,the height to 0
    LchildAVL=RchildAVL=nullptr;
    numberOfInsertsAVL=h=0;
}
AVL* AVL::newnodeAVL(string &word)
{
    AVL *newnode;//creates a new node
    newnode=new(nothrow) AVL();
    if(newnode==nullptr)
    {
        cout<<"not enough memory"<<endl;
        return 0;
    }
    newnode->dataAVL=word;//inserts the word to the new node
    newnode->LchildAVL=nullptr;
    newnode->RchildAVL=nullptr;
    newnode->numberOfInsertsAVL++;
    newnode->h=1;
    return newnode;
}
int AVL::height(AVL *current)
{
    //returns the height of the current node
    return (current==nullptr ? 0 :current->h);
}

AVL *AVL::balance(AVL * current,string word)
{
    //updating the height of the tree
    if(height(current->LchildAVL)>height(current->RchildAVL))
        current->h=height(current->LchildAVL)+1;
    else
        current->h=height(current->RchildAVL)+1;

    //checks if the tree is unbalanced
    int k=height(current->LchildAVL)-height(current->RchildAVL);

    //if it is ,makes the right rotations depending on the occasion
    if (k ==2 && word<current->LchildAVL->dataAVL)
        return R(current);

    if( k==-2 && word>current->RchildAVL->dataAVL)
        return L(current);

    if(k==2 && word>current->LchildAVL->dataAVL)
        return LR(current);
    if(k==-2 && word <current->RchildAVL->dataAVL)
        return RL(current);

    return current;
}

AVL* AVL::insert_nodeAVL(AVL *node,string &word)
{
    //inserts a word in the tree with recursion
    if(node==nullptr)//whenever it finds an empty node calls the newnodeAVL function to insert that word in the tree
        return newnodeAVL(word);
    else if(word<node->dataAVL)//searching for an empty node through the tree
    {
        node->LchildAVL=insert_nodeAVL(node->LchildAVL,word);
        node=balance(node,word);//calling the balance function to update the heights and make the necessary rotations
    }
    else if(word>node->dataAVL)
    {
        node->RchildAVL=insert_nodeAVL(node->RchildAVL,word);
        node=balance(node,word);
    }
    else
        node->numberOfInsertsAVL++;//if the word already exists in the tree

    return node;
}
AVL* AVL::R(AVL* parent)
{
    //right rotation
    AVL *l=parent->LchildAVL;
    parent->LchildAVL=l->RchildAVL;
    l->RchildAVL=parent;
    //updates the height of the nodes
    if(height(parent->LchildAVL)>height(parent->RchildAVL))
        parent->h=height(parent->LchildAVL)+1;
    else
        parent->h=height(parent->RchildAVL)+1;

    if(height(l->LchildAVL)>height(l->RchildAVL))
        l->h=height(l->LchildAVL)+1;
    else
        l->h=height(l->RchildAVL)+1;
    return l;//returns the node l to take the position of the parent and maintain the correct layout
}
AVL* AVL::L(AVL* parent)
{
    //left rotation
    //in the same way works for the left rotation as well
    AVL *r=parent->RchildAVL;
    parent->RchildAVL=r->LchildAVL;
    r->LchildAVL=parent;
    if(height(parent->LchildAVL)>height(parent->RchildAVL))
        parent->h=height(parent->LchildAVL)+1;
    else
        parent->h=height(parent->RchildAVL)+1;

    if(height(r->LchildAVL)>height(r->RchildAVL))
        r->h=height(r->LchildAVL)+1;
    else
        r->h=height(r->RchildAVL)+1;
    return r;
}

AVL* AVL::RL(AVL *current)
{
    //right left rotation
    current->RchildAVL=R(current->RchildAVL);//does a right rotation to the rightchild of the current node
    return L(current);//and after a left rotation to the current node
}
AVL *AVL::LR(AVL *current)
{
    //left right rotations
    current->LchildAVL=L(current->LchildAVL);//does a left rotation to the leftchild of the current node
    return R(current);//and after a right rotation to the current node
}


void AVL::preOrder(AVL *node)
{
    //executes a preorder and prints the tree nodes
    if(node != nullptr)
    {
        cout << node->dataAVL <<endl;
        preOrder(node->LchildAVL);
        preOrder(node->RchildAVL);
    }
}
void AVL::postOrder(AVL *node)
{
    //executes a postorder and prints the tree nodes
    if(node != nullptr)
    {
        preOrder(node->LchildAVL);
        preOrder(node->RchildAVL);
        cout << node->dataAVL <<endl;
    }
}
void AVL::inOrder(AVL *node)
{
    //executes a inorder and prints the tree nodes
    if(node != nullptr)
    {
        preOrder(node->LchildAVL);
        cout << node->dataAVL <<endl;
        preOrder(node->RchildAVL);
    }
}

bool AVL::Search(AVL * p,string &word)
{
    //searches if a word exists in the tree and how many times
    while(p!=nullptr)//if the node is not null continue the search
    {
        if(word<p->dataAVL)
            p=p->LchildAVL;
        else if(word>p->dataAVL)
            p=p->RchildAVL;
        else
        {
            cout<<"The word '"<<word<<"' has appeared "<<p->numberOfInsertsAVL<< " times " <<endl;
            return true;
        }
    }
return false;//returns false if the word is not found
}
AVL* AVL::Min(AVL* current)
{
    //it returns smallest node of the current subtree
    if(current==nullptr)
        return nullptr;
    else if(current->LchildAVL==nullptr)
        return current;
    else
        return Min(current->LchildAVL);
}
AVL* AVL::deleteAVL(AVL *node ,string &word)
{
    AVL *current;
    //first it searches for the word in the tree
    if(node==nullptr)//if the word do not exists
    {
        cout<<"no word like "<<word<<" in the tree"<<endl;
        return nullptr;
    }

    else if(word<node->dataAVL)
        node->LchildAVL=deleteAVL(node->LchildAVL,word);//using recursion for the search
    else if(word>node->dataAVL)
        node->RchildAVL=deleteAVL(node->RchildAVL,word);

    else if(node->LchildAVL && node->RchildAVL)//if the node with the word that we want to delete have 2 childs
    {
        current=Min(node->RchildAVL);
        node->dataAVL=current->dataAVL;
        node->RchildAVL=deleteAVL(node->RchildAVL,node->dataAVL);
    }
    else//if the node has 1 or no childs at all
    {
        current=node;
        if(node->LchildAVL==nullptr)//if it has only right child
            node=node->RchildAVL;
        else if(node->RchildAVL==nullptr)//if it has only left child
            node=node->LchildAVL;
        //if has no childs
        cout<<"the word is deleted"<<endl;
        delete current;//deletes the node
    }
    if(node==nullptr)//in case that the word that we want to delete is in the only node of the tree
        return node;

    //updates the height of the node
    if(height(node->LchildAVL)>height(node->RchildAVL))
        node->h=height(node->LchildAVL)+1;
    else
        node->h=height(node->RchildAVL)+1;
    //checks if the node thats deleted made the tree unbalanced and makes the necessary rotations
    if(height(node->LchildAVL)-height(node->RchildAVL)==2)
    {
        if(height(node->LchildAVL->LchildAVL)-height(node->LchildAVL->RchildAVL)==1)
            return L(node);
        else
            return RL(node);
    }
    else if(height(node->LchildAVL)-height(node->RchildAVL)==-2)
    {
        if(height(node->RchildAVL->RchildAVL)-height(node->LchildAVL->LchildAVL)==1)
            return R(node);
        else
            return LR(node);
    }
    return node;


}




