#ifndef PRIMARYEXPR_H
#define PRIMARYEXPR_H

#include<ASTNode.h>
#include<ASTList.h>
#include<list>
#include "Postfix.h"
#include "ReturnType.h"

#include "ReturnType.h"
#include "Environment.h"
using std::list;

class PrimaryExpr : public ASTList{
    public:
        PrimaryExpr(list<ASTNode*> c);
        virtual ~PrimaryExpr();

        //like func();
        ASTNode* operand();
        Postfix* postfix(int nest);
        bool hasPostfix(int nest);
        ReturnType* eval(Environment &env);
        ReturnType* evalSubExpr(Environment &env, int nest);

};

#endif // PRIMARYEXPR_H
