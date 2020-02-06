#include "lexer_one_line.h"
#include <string>
#include <list>
#include "Token.h"
#include "derivedTokens.h"

using std::string;

char EMPTY = ' ';
char lastChar = EMPTY;
int token_type = 0;

bool isLetter(char c) {return ((('A' <= c) &&(c <= 'Z')) || (('a' <= c )&& (c <= 'z')));}
bool isDigit(char c) { return '0' <= c && c <= '9'; }
bool isSpace(char c) { return 0 <= c && c <= ' '; }

void ungetChar(char c) { lastChar = c;};

char getChar(string s,int index){
    if (lastChar == EMPTY)//上一个字符空
        return (char)s[index];
    else {//上一个字符非空
        char c = lastChar;//提取上一个字节
        lastChar = EMPTY;
        return c;
    }
}

void lexer_one_line_func(string s,int lineNum,list<Token*>& qlist){
    string sb = "";
    do{
        sb = "";
        int index = 0;
        char c;

        do {
            c = getChar(s,index);
        } while (isSpace(c));//吸收空格

        if (c == '\0')
            sb = "EOL";  // end of text

        else if (isDigit(c)) {
            do {
                sb += c;
                c = getChar(s,index);
            } while (isDigit(c));
        }
        else if (isLetter(c)) {
            do {
                sb += c;
                c = getChar(s,index);
            } while (isLetter(c) || isDigit(c));
        }
        else if (c == '=') {
            c = getChar(s,index);
            if (c == '=')
                sb += "==";
            else {
                ungetChar(c);
                sb = "=";
            }
        }
        else
            throw ("IO  Exception");

        if (c >= 0)
            ungetChar(c);
    }
    while(sb.compare("EOL") != 1);

}


