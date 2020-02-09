#include "ParameterList.h"
#include "ASTLeaf.h"

ParameterList::ParameterList(list<ASTNode*> c):ASTList(c)
{
    //ctor
}

ParameterList::~ParameterList()
{
    //dtor
}


string ParameterList::name(int i) { return ((Token*) ((ASTLeaf*) child(i))->get_token())->getText(); }
int ParameterList::size() { return ASTList::numChildren(); }

void ParameterList::eval(Environment &env, int index, ReturnType* value) {
            env.putNew(ParameterList::name(index), value);//add value to env
        }
