#ifndef BASICPARSER_H
#define BASICPARSER_H

#include "lexer.h"

#include <Parser.h>
#include <ParserDerived.h>
#include <map>
#include <set>
#include <string>
#include "NegativeExpr.h"
#include "BinaryExpr.h"
#include "BlockStmnt.h"
#include "IfStmnt.h"
#include "WhileStmnt.h"
#include "NullStmnt.h"
#include "iostream"

using std::string;
using std::cout;
using std::endl;

class BasicParser:public Parser
{
    public:
        BasicParser();
        virtual ~BasicParser();

        Parser expr0;

        ASTNode* beginparse(Lexer* lexer_r);

    public:

    //--------------------primary----------------------//
    ParserDerived<PrimaryExpr>primary;
    Parser primary_sep;
    Parser primary_number;
    Parser primary_identifier;
    Parser primary_str_ing;

    string left_bracket;
    string right_bracket;
    list<string> left_s;

    list<string> right_s;

    list<Parser*>primary_va;

    //--------------------factor---------------------//
    Parser factor;
    list<string> minus_s;
    ParserDerived<NegativeExpr> factor_N;

    list<Parser*> factor_va;

    //---------------------expr------------------------//
    Parser expr;

    //-------------------statement0----------------------//
    Parser statement0;

    //-------------------block----------------------//

    string left_bracket_flower;
    string right_bracket_flower;
    list<string> left_s_flower;
    list<string> right_s_flower;


    ParserDerived<BlockStmnt> block;

    Parser block_repeat_va;

    string simi_c;
    list<string> block_repeat_sep_va;
    //-------------------simple----------------------//
    ParserDerived<PrimaryExpr> simple;

    //-------------------statement----------------------//
    Parser statement;

    ParserDerived<IfStmnt> ifs;

    string ifs_if;
    list<string> ifs_va_if;
    string ifs_else;
    list<string> ifs_va_else;
    string While_while;
    list<string> While_va;

    Parser ifs_opt;

    ParserDerived<WhileStmnt> WhileS;

    list<Parser*> statement_or_va;

    //-------------------program----------------------//
    Parser program;

    list<Parser*>program_or_va;
    ParserDerived<NullStmnt> nulls;

    list<string>program_sep_va;


    public:
        std::set<string> reserved;
        Operators operators;

    public:
        void print_BP_ele(){
            cout<<"primary   "<<&primary<<endl;
            cout<<"expr0   "<<&expr0<<endl;
            cout<<"factor   "<<&factor<<endl;
            cout<<"expr   "<<&expr<<endl;
            cout<<"statement0   "<<&statement0<<endl;
            cout<<"block   "<<&block<<endl;
            cout<<"block_repeat_va   "<<&block_repeat_va<<endl;
            cout<<"simple   "<<&simple<<endl;
            cout<<"statement   "<<&statement<<endl;
            cout<<"ifs   "<<&ifs<<endl;
            cout<<"WhileS   "<<&WhileS<<endl;
            cout<<"program   "<<&program<<endl;
            cout<<"primary_number   "<<&primary_number<<endl;
            cout<<"primary_identifier   "<<&primary_identifier<<endl;
            cout<<"primary_str_ing   "<<&primary_str_ing<<endl;
            cout<<"nulls   "<<&nulls<<endl;
            cout<<"--------------------------------------------------------------------"<<endl;
        }


};

#endif // BASICPARSER_H
