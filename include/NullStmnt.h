#ifndef NULLSTMNT_H
#define NULLSTMNT_H
#include "ASTList.h"
#include "ASTNode.h"
#include "list"
using std::list;

class NullStmnt:public ASTList
{
    public:
        NullStmnt(list<ASTNode*> c);
        virtual ~NullStmnt();

    protected:

    private:
};

#endif // NULLSTMNT_H
