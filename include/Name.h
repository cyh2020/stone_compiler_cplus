#ifndef NAME_H
#define NAME_H

#include<ASTNode.h>
#include<ASTList.h>
#include<ASTLeaf.h>
#include<string>
#include"Environment.h"
using std::string;

class Name:public ASTLeaf
{
    public:
        Name(Token* t);
        virtual ~Name();
        string name();
        ReturnType* eval(Environment& env);

    protected:

    private:
};

#endif // NAME_H
