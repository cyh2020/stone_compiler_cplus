#include "IfStmnt.h"

#include "string"
using std::string;
#include "list"
using std::list;
#include "ReturnType.h"
#include "ReturnTypeInt.h"
#include "ReturnTypeString.h"

IfStmnt::IfStmnt(list<ASTNode*> c):ASTList(c)
{
    //ctor
}

IfStmnt::~IfStmnt()
{
    //dtor
}


ASTNode* IfStmnt::condition() { return child(0); }
ASTNode* IfStmnt::thenBlock() { return ASTList::child(1); }
ASTNode* IfStmnt::elseBlock() {
    return numChildren() > 2 ? child(2) : nullptr;
}

string IfStmnt::toString() {
    ASTNode* cond = condition();
    ASTNode* then_B = thenBlock();
    ASTNode* else_B = elseBlock();
    if(else_B != nullptr){//has else block
        return string("(if ") + cond->toString() + " " + then_B->toString() + " else " + else_B->toString() + ")";
    }else{
        return string("(if ") + cond->toString() + " " + then_B->toString() + ")";

    }
//    return string("(if ") + cond->toString() + "{\n" + then_B->toString() + "} else {"  + "( bug )}";

}

ReturnType* IfStmnt::eval(Environment& env) {
            ReturnType* c = (condition())->eval(env);//condition exec
            if (c->returnValType() =="int" && ((ReturnTypeInt*)c)->returnVal() == 1)
                return (thenBlock())->eval(env);
            else {//if not satisfied
                ASTNode* b = elseBlock();
                if (b == nullptr)
                    return nullptr;
                else
                    return b->eval(env);
            }
        }
