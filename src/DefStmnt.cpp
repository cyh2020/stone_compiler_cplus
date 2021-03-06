#include "DefStmnt.h"

DefStmnt::DefStmnt(list<ASTNode*> c):ASTList(c)
{
    //ctor
}

DefStmnt::~DefStmnt()
{
    //dtor
}



string DefStmnt::name() {
    ASTLeaf* l = (ASTLeaf*)(this->child(0));
    Token* t = l->get_token();
    return t->getText();
}

ParameterList* DefStmnt::parameters() {
    ParameterList* p = (ParameterList*)(this->child(1));
    return  p;
}
BlockStmnt* DefStmnt::body() {
    BlockStmnt* b = (BlockStmnt*)(this->child(2));
    return b;
    }

string DefStmnt::toString() {
//    return "(def " + name() + " " + parameters() + " " + body() + ")";
    return "(def " + name() + ")";

}

ReturnType* DefStmnt::eval(Environment &env) {//add function to env and return its name
        env.putNew(this->name(), new Function(*(parameters()), *(body()), env));

        ReturnTypeString* a = new ReturnTypeString(this->name());
        return a;
    }
