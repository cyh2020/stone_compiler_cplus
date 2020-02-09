#ifndef PARAMETERLIST_H
#define PARAMETERLIST_H
#include "ASTList.h"
#include "ASTNode.h"
#include <list>
#include <string>

using std::list;
using std::string;
#include "ReturnType.h"
#include "Environment.h"

class ParameterList:public ASTList
{
    public:
        ParameterList(list<ASTNode*> c);
        virtual ~ParameterList();

        string name(int i);
        int size();
        void eval(Environment &env, int index, ReturnType* value);

    protected:

    private:
};

#endif // PARAMETERLIST_H
