#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <Token.h>
#include <derivedTokens.h>
#include "lexer.h"
#include "LineNumberReader.h"
#include <regex>
#include "Parser.h"
#include "BasicParser.h"
#include"ReturnType.h"
#include"ReturnTypeInt.h"
#include"ReturnTypeString.h"
#include "FunctionParser.h"
#include "BasicEnv.h"

using namespace std;

string Token::EOL_S = "\\n";//在main 外部定义
Token* Token::EOF_S = new Token(-1);

//template <class clazz>
//Parser::Precedence Expr<clazz>::prec_static(8,false);

int main()
{
//    string str_out;
//    int n;
//    LineNumberReader ler;
//    for(;ler.is_open != false;){
//        str_out = ler.getstr();
//        n = ler.getLineNumber();
//        cout<<n<<' '<<str_out<<endl;
//    }


////Lexer
//    Lexer le("./test/Lexertest.txt");
//    le.readLine();
//
//    for (Token* t; (t = le.read()) != Token::EOF_S; ){
//        cout<<"=> "<<t->getText()<<endl;
//    }



////BP
//	BasicParser bp;
//    Lexer le("./test/Lexertest.txt");
//
//    bp.print_BP_ele();
////    bp.program.printMyself();
//
//    while (le.peek(0) != Token::EOF_S) {
//        ASTNode* ast = bp.beginparse(&le);
//        cout<<string("=> ") + ast->toString()<<endl;
//    }


////BP
//	BasicParser bp;
//    Lexer le("./test/Lexer.txt");
//
//    bp.print_BP_ele();
//    BasicEnv env;
//
//    while (le.peek(0) != Token::EOF_S) {
//        ASTNode* ast = bp.beginparse(&le);
//        if (!(typeid(*ast) == typeid(NullStmnt))) {
//                ReturnType* r = ast->eval(env);
//                if(!r){
//                    cout << "=> nullptr" << endl;
//                }else if (r->returnValType() == "int"){
//                    cout << "=> " << ((ReturnTypeInt*)r)->returnVal() << endl;
//                }else if (r->returnValType() == "string"){
//                    cout << "=> " << ((ReturnTypeString*)r)->returnVal() << endl;
//                }else{
//                    cout << "=> other" << endl;
//                }
//            }
//    }


//Function Parser
	FunctionParser fp;
    Lexer le("./test/Lexertest.txt");

    fp.print_BP_ele();
//    fp.simple.printMyself();

    //change the address before you print,confirm twice to avoid death loop
//    fp.expr.printMyself();
//    fp.program.printMyself();
    BasicEnv env;
    while (le.peek(0) != Token::EOF_S) {
        ASTNode* ast = fp.beginparse(&le);
            if (!(typeid(*ast) == typeid(NullStmnt))) {
                ReturnType* r = ast->eval(env);
                if(!r){
                    cout << "=> nullptr" << endl;
                }else if (r->returnValType() == "int"){
                    cout << "=> " << ((ReturnTypeInt*)r)->returnVal() << endl;
                }else if (r->returnValType() == "string"){
                    cout << "=> " << ((ReturnTypeString*)r)->returnVal() << endl;
                }else{
                    cout << "=> other" << endl;
                }
            }
    }


}
