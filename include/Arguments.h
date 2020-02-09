#ifndef ARGUMENTS_H
#define ARGUMENTS_H

#include <Postfix.h>
#include <ASTList.h>
#include <ASTNode.h>
#include <string>
#include <typeinfo>
#include "ReturnType.h"
#include "Function.h"
#include "ParameterList.h"
using std::string;

class Arguments : public Postfix
{
    public:
        Arguments(list<ASTNode*> c);
        virtual ~Arguments();

        int size();

        ReturnType* eval(Environment &callerEnv, ReturnType* value);

    protected:

    private:
};



#endif // ARGUMENTS_H
