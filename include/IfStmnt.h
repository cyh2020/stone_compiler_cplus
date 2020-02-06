#ifndef IFSTMNT_H
#define IFSTMNT_H
#include "ASTNode.h"
#include "ASTList.h"
#include "string"
#include "list"
using std::list;
using std::string;


class IfStmnt:public ASTList
{
    public:
        IfStmnt(list<ASTNode*> c);
        virtual ~IfStmnt();

        ASTNode* condition();
        ASTNode* thenBlock();
        ASTNode* elseBlock();
        string toString();

        ReturnType* eval(Environment& env);

    protected:

    private:
};

#endif // IFSTMNT_H
