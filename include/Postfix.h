#ifndef POSTFIX_H
#define POSTFIX_H

#include <ASTList.h>
#include <ASTNode.h>
#include <string>
#include "ReturnType.h"

using std::string;


class Postfix : public ASTList
{
    public:
        Postfix(list<ASTNode*> c);
        virtual ~Postfix();

        virtual ReturnType* eval(Environment &env, ReturnType* value){
            throw "no eval function in postfix";
        };

    protected:

    private:
};

#endif // POSTFIX_H
