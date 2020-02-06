#include "ASTNode.h"
#include "string"
using std::string;
ASTNode::ASTNode()
{
    //ctor
}

ASTNode::~ASTNode()
{
    //dtor
}

ASTNode* ASTNode::child(int i) { throw "ASTNode has no child()!";}
string ASTNode::location() { throw "ASTNode has no location()!"; }
int ASTNode::numChildren(){ throw "ASTNode has no numChildren()!"; }
string ASTNode::toString(){ throw "ASTNode has no toString()!"; }
ReturnType* ASTNode::eval(Environment& env){ throw "ASTNode has no eval()!"; };
