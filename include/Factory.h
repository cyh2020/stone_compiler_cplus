#ifndef FACTORY_H
#define FACTORY_H


#include <string>

#include <lexer.h>
#include <Token.h>
#include <ASTNode.h>
#include <ASTLeaf.h>
#include <ASTList.h>
#include <list>

#include "PrimaryExpr.h"
using std::list;

class Factory{
    public:
//        virtual ASTNode* make(ASTNode* c){
//            throw "Factory has no make()!";
//        }

        virtual ASTNode* make(list<ASTNode*> &c){
            throw "Factory has no make()!";
        }

        virtual ASTNode* make_atoken(Token* &c){
            throw "Factory has no make()!";
        }
};
//
#endif // FACTORY_H
