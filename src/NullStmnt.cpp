#include "NullStmnt.h"
#include "list"
using std::list;

NullStmnt::NullStmnt(list<ASTNode*> c):ASTList(c)
{
    //ctor
}

NullStmnt::~NullStmnt()
{
    //dtor
}
