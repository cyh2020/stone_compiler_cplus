#include "BlockStmnt.h"
#include <typeinfo>
#include "NullStmnt.h"
using std::list;

BlockStmnt::BlockStmnt(list<ASTNode*> c):ASTList(c)
{
    //ctor
}

BlockStmnt::~BlockStmnt()
{
    //dtor
}

ReturnType* BlockStmnt::eval(Environment& env) {
            ReturnType* result = nullptr;
            for (ASTNode* t: this->children) {//�����������е�eval����
                if (!(typeid(*t) == typeid(NullStmnt)))
                    result = t->eval(env);
            }
            return result;
}
