#include "WhileStmnt.h"
#include "string"
#include "list"
using std::list;
using std::string;
#include "ReturnType.h"
#include "ReturnTypeInt.h"

WhileStmnt::WhileStmnt(list<ASTNode*> c):ASTList(c)
{
    //ctor
}

WhileStmnt::~WhileStmnt()
{
    //dtor
}


ASTNode* WhileStmnt::condition() { return child(0); }
ASTNode* WhileStmnt::body() { return child(1); }
string WhileStmnt::toString() {
        ASTNode* con = condition();
        ASTNode* body_s = body();
        return string("(while ") + con->toString() + " " + body_s->toString() + ")";
    }

ReturnType* WhileStmnt::eval(Environment& env) {
            ReturnType* result = nullptr;
            for (;;) {//return last line result
                ReturnType* c = (condition())->eval(env);
                if (c->returnValType() =="int" && ((ReturnTypeInt*)c)->returnVal() == 0)
                    return result;//when condition turn false
                else
                    result = (body())->eval(env);
            }
        }
