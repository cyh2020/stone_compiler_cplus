#include "PrimaryExpr.h"

using std::list;
PrimaryExpr::PrimaryExpr(list<ASTNode*> c):ASTList(c)
{
    //ctor
}

PrimaryExpr::~PrimaryExpr()
{
    //dtor
}


ASTNode* PrimaryExpr::create(list<ASTNode*> c) {
        return (c.size() == 1) ? c.front() : new PrimaryExpr(c);
    }
