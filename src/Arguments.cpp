#include "Arguments.h"


Arguments::Arguments(list<ASTNode*> c):Postfix(c)
{
    //ctor
}

Arguments::~Arguments()
{
    //dtor
}

int Arguments::size() { return ASTList::numChildren(); }
