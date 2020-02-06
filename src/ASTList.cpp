#include "ASTList.h"

#include <string>
#include <Token.h>
#include <ASTNode.h>
#include <list>
using std::string;
using std::list;

ASTList::ASTList(list<ASTNode*> input_list)
{
    //ctor
    children = input_list;
}

ASTList::~ASTList()
{
    //dtor
}

string ASTList::location() {
    for (ASTNode* t: children) {
        string s = t->location();
        if (s.length()!= 0)
            return s;
    }
    return "";
}

string ASTList::toString() {
    string builder;
    builder.append("(");
    string sep = "";
    for (ASTNode* t: children) {
        builder.append(sep);
        sep = " ";
        builder.append(((ASTList*)t)->toString());
    }
    return builder.append(")");
}

ASTNode* ASTList::child(int index) {//return a child
    list<ASTNode*>::iterator iter;
    iter = children.begin();
    for(int i = 0; i < index; ++i) {
        iter++;
    }
    return *iter;
}

int ASTList::numChildren() { return children.size(); }

ReturnType* ASTList::eval(Environment& env){throw "astlist cannot eval";}
