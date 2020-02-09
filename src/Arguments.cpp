#include "Arguments.h"
#include "ReturnTypeInt.h"
#include <iostream>
using std::cout;
using std::endl;


Arguments::Arguments(list<ASTNode*> c):Postfix(c)
{
    //ctor
}

Arguments::~Arguments()
{
    //dtor
}

int Arguments::size() { return ASTList::numChildren(); }

ReturnType* Arguments::eval(Environment &callerEnv, ReturnType* value) {
            if (!(typeid(*value)== typeid(Function)))
                throw "bad function";

            Function* func = (Function*)value;//function
            ParameterList* params = func->get_parameters();//parameters

            if (Arguments::size() != params->size())
                throw "bad number of arguments";

            Environment* newEnv = func->get_Env();//prepare env and exec the func
            int num = 0;
            for (ASTNode* a: this->children){
                params->eval(*newEnv, num++, a->eval(callerEnv));
            }


            ReturnType* r = (func->get_body())->eval(*newEnv);

            cout<<((ReturnTypeInt*)r)->returnVal()<<endl;
            return r;
        }
