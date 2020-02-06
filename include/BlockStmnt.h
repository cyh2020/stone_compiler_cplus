#ifndef BLOCKSTMNT_H
#define BLOCKSTMNT_H

#include<ASTNode.h>
#include<ASTList.h>
#include<ASTLeaf.h>
#include "list"
using std::list;

class BlockStmnt:public ASTList
{
    public:
        BlockStmnt(list<ASTNode*> c);
        virtual ~BlockStmnt();

        ReturnType* eval(Environment& env);

    protected:

    private:
};

#endif // BLOCKSTMNT_H
