#ifndef ASTLIST_H
#define ASTLIST_H

#include <string>
#include <Token.h>
#include <ASTNode.h>
#include <list>
#include "ReturnType.h"
using std::string;
using std::list;

class ASTList :public ASTNode {
    public:
        ASTList(list<ASTNode*> input_list);

        virtual ~ASTList();

        ASTNode* child(int i);
        int numChildren();
        string toString();
        string location();

        ReturnType* eval(Environment& env);

    protected:
        list<ASTNode*> children;
    private:
};

#endif // ASTLIST_H
