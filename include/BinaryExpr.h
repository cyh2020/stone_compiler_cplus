#ifndef BINARYEXPR_H
#define BINARYEXPR_H

#include<ASTNode.h>
#include<ASTList.h>
#include<ASTLeaf.h>
#include<string>
#include "ReturnType.h"
using std::string;

class BinaryExpr:public ASTList
{
    public:
        BinaryExpr(list<ASTNode*> c);
        virtual ~BinaryExpr();

        ASTNode* left();
        string operator_func();
        ASTNode* right();

        ReturnType* eval(Environment& env);

    protected:

        ReturnType* computeAssign(Environment& env, ReturnType* rvalue);
        ReturnType* computeOp(ReturnType* left, string op, ReturnType* right);
        int computeNumber(int left, string op, int right);


    private:
};

#endif // BINARYEXPR_H
