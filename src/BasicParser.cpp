#include "BasicParser.h"
#include "Token.h"
#include "Parser.h"
#include "ParserDerived.h"
#include <set>
#include <string>
#include "PrimaryExpr.h"
#include "NumberLiteral.h"
#include "Name.h"
#include "StringLiteral.h"
#include "NegativeExpr.h"
#include "BinaryExpr.h"
#include "BlockStmnt.h"
#include "IfStmnt.h"
#include "WhileStmnt.h"
#include "NullStmnt.h"
#include "lexer.h"


#include "list"
using std::list;
using std::string;


BasicParser::BasicParser()
{
    reserved.insert(";");
    reserved.insert("}");
    reserved.insert("\\n");


//    trueAssoc bool LEFT = true;bool RIGHT = false;
    operators.add("=", 1, false);
    operators.add("==", 2, true);
    operators.add(">", 2, true);
    operators.add("<", 2, true);
    operators.add("+", 3, true);
    operators.add("-", 3, true);
    operators.add("*", 4, true);
    operators.add("/", 4, true);
    operators.add("%", 4, true);


    //--------------------expr0------------------------//
//    Parser expr0;

    //--------------------primary----------------------//
//    ParserDerived<PrimaryExpr>primary;
//    Parser primary_sep;
//    Parser primary_number;
//    Parser primary_identifier;
//    Parser primary_str_ing;

    left_bracket = "(";
    right_bracket = ")";
//    list<string> left_s;
    left_s.push_back(left_bracket);
//    list<string> right_s;
    right_s.push_back(right_bracket);

    primary_sep.sep(left_s);
    primary_sep.ast(&expr);
    primary_sep.sep(right_s);
    primary_number.number<NumberLiteral>();
    primary_identifier.identifier<Name>(reserved);
    primary_str_ing.str_ing<StringLiteral>();

//    list<Parser*>primary_va;
    primary_va.push_back(&primary_sep);
    primary_va.push_back(&primary_number);
    primary_va.push_back(&primary_identifier);
    primary_va.push_back(&primary_str_ing);
    primary.or_add(primary_va);

    //--------------------factor---------------------//
//    Parser factor;

//    ParserDerived<NegativeExpr> factor_N;
//    list<string> minus_s;
    minus_s.push_back(string("-"));
    factor_N.sep(minus_s);
    factor_N.ast(&primary);

//    list<Parser*> factor_va;
    factor_va.push_back(&factor_N);
    factor_va.push_back(&primary);

    factor.or_add(factor_va);

    //---------------------expr------------------------//
//    Parser expr;
    expr.expression<BinaryExpr>(&factor, operators);


    //-------------------statement0----------------------//
//    Parser statement0;

    //-------------------block----------------------//
//    ParserDerived<BlockStmnt> block;

    left_bracket_flower = "{";
    right_bracket_flower = "}";
//    list<string> left_s_flower;
    left_s_flower.push_back(left_bracket_flower);
//    list<string> right_s_flower;
    right_s_flower.push_back(right_bracket_flower);
    block.sep(left_s_flower);
//    block.option(&statement);

//    Parser block_repeat_va;

    simi_c = ";";
//    list<string> block_repeat_sep_va;
    block_repeat_sep_va.push_back(simi_c);
    block_repeat_sep_va.push_back(Token::EOL_S);

    block_repeat_va.sep(block_repeat_sep_va);
    block_repeat_va.option(&statement);

    block.repeat(&block_repeat_va);
    block.sep(right_s_flower);

    //-------------------simple----------------------//
//    ParserDerived<PrimaryExpr> simple;
    simple.ast(&expr);


    //-------------------statement----------------------//
//    Parser statement;

//    ParserDerived<IfStmnt> ifs;

    ifs_if = "if";
//    list<string> ifs_va_if;
    ifs_va_if.push_back(ifs_if);
    ifs_else = "else";
//    list<string> ifs_va_else;
    ifs_va_else.push_back(ifs_else);
    While_while = "while";
//    list<string> While_va;
    While_va.push_back(While_while);

    ifs.sep(ifs_va_if);
    ifs.ast(&expr);
    ifs.ast(&block);

//    Parser ifs_opt;
    ifs_opt.sep(ifs_va_else);
    ifs_opt.ast(&block);

    ifs.option(&ifs_opt);//ifstmnt is over

//    ParserDerived<WhileStmnt> WhileS;
    WhileS.sep(While_va);
    WhileS.ast(&expr);
    WhileS.ast(&block);

//    list<Parser*> statement_or_va;
    statement_or_va.push_back(&ifs);
    statement_or_va.push_back(&WhileS);
    statement_or_va.push_back(&simple);

    statement.or_add(statement_or_va);

    //-------------------program----------------------//
//    Parser program;

//    list<Parser*>program_or_va;
    program_or_va.push_back(&statement);
//    ParserDerived<NullStmnt> nulls;
    program_or_va.push_back(&nulls);
    program.or_add(program_or_va);

//    list<string>program_sep_va;
    program_sep_va.push_back(simi_c);
    program_sep_va.push_back(Token::EOL_S);
    program.sep(program_sep_va);

    //test
//    std::cout<<program.elements.size()<<std::endl;

}

BasicParser::~BasicParser()
{
    //dtor
}

ASTNode* BasicParser::beginparse(Lexer* lexer_r){
        ASTNode* k = program.parse(lexer_r);
        return k;
}
