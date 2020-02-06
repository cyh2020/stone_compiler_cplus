#include "NegativeExpr.h"
using std::string;
using std::list;
#include"ReturnType.h"
#include"ReturnTypeInt.h"

NegativeExpr::NegativeExpr(list<ASTNode*> c):ASTList(c)
{
    //ctor
}

NegativeExpr::~NegativeExpr()
{
    //dtor
}

ASTNode* NegativeExpr::operand() { return child(0); };
string NegativeExpr::toString(){
    ASTNode* op = operand();
    return string("-") + op->toString();
    }


ReturnType* NegativeExpr::eval(Environment& env) {
            ReturnType* v = (operand())->eval(env);
            if ("integer" ==( v->returnValType())){
                ReturnTypeInt* r = (ReturnTypeInt*)new ReturnTypeInt((-1)*( ((ReturnTypeInt*)v) ->returnVal() ));
                return r;
            }
            else
                throw "bad type for - NegativeExpr";
        }


