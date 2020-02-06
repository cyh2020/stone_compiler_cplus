#ifndef NEGATIVEEXPR_H
#define NEGATIVEEXPR_H
#include <ASTList.h>
#include "string"
#include "list"
#include <ASTNode.h>
using std::string;
using std::list;


class NegativeExpr:public ASTList
{
    public:
        NegativeExpr(list<ASTNode*> c);
        virtual ~NegativeExpr();
        ASTNode* operand();
        string toString();

        ReturnType* eval(Environment& env);

};

#endif // NEGATIVEEXPR_H
