#ifndef AVL_H
#define AVL_H


using namespace std;
class AVL
{
    public:
        AVL();
        AVL* newnodeAVL(string &);
        AVL* insert_nodeAVL(AVL *,string &);
        int height(AVL *);
        AVL *deleteAVL(AVL * ,string &);
        AVL* Min(AVL* );
        AVL *balance(AVL *,string );

        AVL* R(AVL* );
        AVL* L(AVL* );
        AVL* LR(AVL* );
        AVL* RL(AVL* );

        void preOrder(AVL *);
        void postOrder(AVL *);
        void inOrder(AVL *);
        bool Search(AVL *,string &word);

    private:
        string dataAVL;
        AVL *LchildAVL,*RchildAVL;
        int h;
        int numberOfInsertsAVL;
};

#endif // AVL_H
