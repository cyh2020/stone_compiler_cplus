#ifndef DEFSTMNT_H
#define DEFSTMNT_H

#include "ASTList.h"
#include "ASTNode.h"
#include "list"
#include "ParameterList.h"
#include "BlockStmnt.h"

#include "ReturnType.h"
#include "ReturnTypeString.h"
#include "Function.h"
#include "Environment.h"


using std::list;

class DefStmnt:public ASTList
{
    public:
        DefStmnt(list<ASTNode*> c);
        virtual ~DefStmnt();


        string name();
        ParameterList* parameters();
        BlockStmnt* body();
        string toString();

        ReturnType* eval(Environment &env);


    protected:

    private:
};

#endif // DEFSTMNT_H
