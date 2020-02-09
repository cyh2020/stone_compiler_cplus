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


//ASTNode* PrimaryExpr::create(list<ASTNode*> c) {
//        return (c.size() == 1) ? c.front() : new PrimaryExpr(c);
//    }


ASTNode* PrimaryExpr::operand() { return child(0); }
Postfix* PrimaryExpr::postfix(int nest) {
        return (Postfix*)child(numChildren() - nest - 1);
    }

bool PrimaryExpr::hasPostfix(int nest) { return numChildren() - nest > 1; }
ReturnType* PrimaryExpr::eval(Environment &env) {
    return evalSubExpr(env, 0);
}

ReturnType* PrimaryExpr::evalSubExpr(Environment &env, int nest) {
    if (hasPostfix(nest)) {//like func(10)
        ReturnType* target = evalSubExpr(env, nest + 1);
        return (postfix(nest))->eval(env, target);
    }
    else
        return (operand())->eval(env);//like func()
}
