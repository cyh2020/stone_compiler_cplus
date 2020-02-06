#ifndef PARSERDERIVED_H
#define PARSERDERIVED_H

#include <Factory.h>
#include <FactoryDerived.h>
#include "Parser.h"

template <typename class_clazz=void>
class ParserDerived : public Parser {
public:
    ParserDerived():Parser(){
        factory = new FactoryDerived<class_clazz>();
    }; //factory is added
};


#endif // PARSERDERIVED_H
