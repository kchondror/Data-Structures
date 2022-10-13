#ifndef  BINARYTREE_H
#define  BINARYTREE_H


using namespace std;


class  BinaryTree
{
    public:
        BinaryTree();
        void init();
        bool insert_root(string &);
        bool insert_node(string &);
        bool insert_right(BinaryTree *,string &);
        bool insert_left(BinaryTree *,string &);
        bool Delete(const string );
        bool Search(string &);

        void preorder(BinaryTree*);
        void inorder(BinaryTree*);
        void postorder(BinaryTree*);


        BinaryTree *root;
    private:
        int numberOfInserts;
        string data;
        BinaryTree *Lchild,*Rchild;





};

#endif //  BINARYTREE_H
