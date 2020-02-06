#include <string>
#include <Token.h>
#include <ASTNode.h>
#include <list>
#include "ASTLeaf.h"

using std::string;


ASTLeaf::ASTLeaf(Token* t):token(t)
{
    //ctor
}

ASTLeaf::~ASTLeaf()
{
    //dtor
}

int ASTLeaf::numChildren() { return 0;}
ASTNode* ASTLeaf::child(int i) { throw "ASTLeaf has no child!";}
string ASTLeaf::toString() { return token->getText(); }
string ASTLeaf::location() { return "at line " + token->getLineNumber(); }
Token* ASTLeaf::get_token() { return token; }

ReturnType* ASTLeaf::eval(Environment& env){throw "astleaf cannot eval";}
