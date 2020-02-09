#include "Parser.h"
#include "ParserClass.h"
#include "lexer.h"

Parser::Parser() {
    Parser::reset();
    factory = new FactoryDerived<ordinary>;
};

void Parser::reset() {
        Parser::elements.clear();
    };

bool Parser::match(Lexer* Lexer_r){//if first one match
    if (elements.size() == 0){
        return true;
    }
    else {
        Element* e = elements.front();//if parser head ok with it ，do nothing about other parser
        return e->match(Lexer_r);
    }
};

ASTNode* Parser::parse(Lexer* Lexer_r) {
    list<ASTNode*> results;

//    std::cout<<elements.size()<<this<<std::endl;
//    std::cout<<this<<"          "<<"{"<<std::endl;

    int i = 0;
    for (Element* e: elements){//给element去做
        i++;
        e->parse(Lexer_r, results);

    }

//    std::cout<<this<<"          "<<results.size()<<std::endl;
//    std::cout<<this<<"          "<<"}"<<std::endl;

    return factory->make(results);//回头敲一下再上传
};
