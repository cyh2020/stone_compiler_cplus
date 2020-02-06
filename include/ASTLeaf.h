#ifndef ASTLEAF_H
#define ASTLEAF_H

#include <string>
#include <Token.h>
#include <ASTNode.h>
#include <list>
#include "ReturnType.h"
using std::string;
using std::list;

class ASTLeaf:public ASTNode
{
    public:
        ASTLeaf(Token* t);
        virtual ~ASTLeaf();

        list<ASTNode> empty_list;

        int numChildren();
        string toString();
        string location();
        Token* get_token();
        ASTNode* child(int i);
        ReturnType* eval(Environment& env);

    protected:
        Token* token;
    private:
};

#endif // ASTLEAF_H
