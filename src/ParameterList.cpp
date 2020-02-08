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
