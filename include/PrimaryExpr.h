#ifndef PRIMARYEXPR_H
#define PRIMARYEXPR_H

#include<ASTNode.h>
#include<ASTList.h>
#include<list>

#include "ReturnType.h"
#include "Environment.h"
using std::list;

class PrimaryExpr : public ASTList{
    public:
        PrimaryExpr(list<ASTNode*> c);
        virtual ~PrimaryExpr();

//        ASTNode* create(list<ASTNode*> c);
        ReturnType* eval(Environment& env);

};

#endif // PRIMARYEXPR_H
