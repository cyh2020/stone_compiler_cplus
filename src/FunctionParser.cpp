#include "FunctionParser.h"
#include "Parser.h"

FunctionParser::FunctionParser()
{
    BasicParser::reserved.insert(")");

    //!!!!!!!!!!!!!!!!!!!!!!!Parsers must be declared in .h file !!!!!!!!!!!!!!!


    //ctor
    //--------------------param---------------------//
//    Parser param;

    param.identifier<Name>(BasicParser::reserved);


    //--------------------params---------------------//
//    ParserDerived<ParameterList> params;
    params.ast(&param);


//    Parser params_repeat;
    list<string> s_s;
    string comma_s = ",";
    s_s.push_back(comma_s);
    params_repeat.sep(s_s);
    params_repeat.ast(&param);

    params.repeat(&params_repeat);


    //--------------------paramList---------------------//
//    Parser paramList;

     list<string> l_s;
     l_s.push_back(string("("));
     paramList.sep(l_s);

//     paramList.option(&params);
     paramList.maybe(&params);

     list<string> r_s;
     r_s.push_back(string(")"));
     paramList.sep(r_s);


    //--------------------def---------------------//
//    ParserDerived<DefStmnt> def;

    list<string> def_s;
    def_s.push_back(string("def"));
    def.sep(def_s);
    def.identifier<Name>(reserved);
    def.ast(&paramList);
    def.ast(&block);


    //--------------------args---------------------//
//    ParserDerived<Arguments> args;

    args.ast(&expr);
//    Parser args_repeat;

    args_repeat.sep(s_s);
    args_repeat.ast(& (BasicParser::expr));
    args.repeat(&args_repeat);


    //--------------------postfix---------------------//
//    Parser postfix;

    postfix.sep(l_s);
    postfix.maybe(&args);
//    postfix.option(&args);
    postfix.sep(r_s);



    primary.repeat(&postfix);
    simple.option(&args);
    program.insertChoice(&def);
}

FunctionParser::~FunctionParser()
{
    //dtor
}

