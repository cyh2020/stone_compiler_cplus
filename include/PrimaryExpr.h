#ifndef PRIMARYEXPR_H
#define PRIMARYEXPR_H

#include<ASTNode.h>
#include<ASTList.h>
#include<list>
using std::list;

class PrimaryExpr : public ASTList{
    public:
        PrimaryExpr(list<ASTNode*> c);
        virtual ~PrimaryExpr();

        ASTNode* create(list<ASTNode*> c);

};

#endif // PRIMARYEXPR_H
