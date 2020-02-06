#include "Lexer.h"
#include <string>
#include <list>
#include "Token.h"
#include "LineNumberReader.h"
#include "lexer_one_line.h"
#include "derivedTokens.h"
#include<regex>

#include <exception>
using std::string;


Lexer::Lexer(){
    hasMore = true;
    list<Token*> qlist;
    LineNumberReader reader;
}

Lexer::~Lexer(){
}



void Lexer::readLine(){
    string line_string;
    line_string = Lexer::reader.getstr();//read one line

    int lineNo = Lexer::reader.getLineNumber();//got line_Number

    //文本数据
//    line_string = "int a = 5";
    //正则表达式
    string regexPat= "\\s*((//.*)|([0-9]+)|(\"(\\\\\"|\\\\\\\\|\\\\n|[^\"])*\")|[A-Za-z][A-Za-z0-9]*|==|<=|>=|\\|\\||&&|[[:punct:]])+";
    std::regex pattern1(regexPat,std::regex::icase);

    //迭代器声明
    string::const_iterator iter = line_string.begin();
    string::const_iterator iterEnd= line_string.end();
    string temp;
    //储存结果
    std::smatch result;
    //正则查找并加入token
    while (std::regex_search(iter,iterEnd,result,pattern1))
    {
        temp=result[0];
//        std::cout<<temp<<std::endl;
//        std::cout<<result[0]<<'^'<<result[1]<<'^'<<result[2] <<'^'<<result[3]<<'^'<<result[4]<<std::endl;
        //addToken;

            string m = result[1];//string found
            string m2 = result[2];
            string m3 = result[3];
            string m4 = result[4];
            if (m2.length() == 0) { // if not a comment
                Token* token;
                if (m3.length() != 0){//interger
                     int n = atoi(m.c_str());
                    token = new NumToken(lineNo,n);
                }
                else if (m4.length() != 0){//str
                    token = new StrToken(lineNo, m);
                }
                else//id
                    token = new IdToken(lineNo, m);
                Lexer::qlist.push_back(token);
            }


        iter = result[0].second; //更新搜索起始位置
    }

    IdToken* idtk = new IdToken(lineNo,Token::EOL_S);
    Token* tk = idtk;
    Lexer::qlist.push_back(tk);//EOL

    if (reader.is_open != 1) {//EOF
            hasMore = false;
        }
}

Token* Lexer::read() {//读取加预读
        if (fillQueue(0)){
            Token*tk = qlist.front();
            qlist.pop_front();
            return tk;
        }
        else
            return Token::EOF_S;
    }

Token* Lexer::peek(int index){//提前看一下
    if (fillQueue(index)){
            list<Token*>::iterator iter;
            iter = qlist.begin();
            for(int i = 0; i < index; ++i) {
                iter++;
            }
            return *iter;
    }
    else
        return Token::EOF_S;
}

bool Lexer::fillQueue(int i){
        while (i >= (int)Lexer::qlist.size()){
            if (hasMore)
                Lexer::readLine();
            else
                return false;
        }
        return true;
    }
