#ifndef WHILESTMNT_H
#define WHILESTMNT_H

#include "ASTNode.h"
#include "ASTList.h"
#include "string"
#include "list"
using std::list;
using std::string;

class WhileStmnt:public ASTList
{
    public:
        WhileStmnt(list<ASTNode*> c);
        virtual ~WhileStmnt();

        ASTNode* condition();
        ASTNode* body();
        string toString();

        ReturnType* eval(Environment& env);

    protected:

    private:
};

#endif // WHILESTMNT_H
