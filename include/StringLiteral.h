#ifndef STRINGLITERAL_H
#define STRINGLITERAL_H
#include "ASTLeaf.h"
#include "Environment.h"
#include "string"
using std::string;


class StringLiteral:public ASTLeaf
{
    public:
        StringLiteral(Token* t);
        virtual ~StringLiteral();

        ReturnType* eval(Environment& e);
    protected:
        string value();
    private:
};

#endif // STRINGLITERAL_H
