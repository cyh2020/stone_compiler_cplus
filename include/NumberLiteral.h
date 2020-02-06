#ifndef NUMBERLITERAL_H
#define NUMBERLITERAL_H

#include "Environment.h"
#include<ASTLeaf.h>
#include<string>
using std::string;

class NumberLiteral:public ASTLeaf
{
    public:
        NumberLiteral(Token* t);
        virtual ~NumberLiteral();
        ReturnType* eval(Environment& e);

    protected:
        int value();
};

#endif // NUMBERLITERAL_H
