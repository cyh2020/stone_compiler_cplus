#ifndef DERIVEDTOKENS_H
#define DERIVEDTOKENS_H
#include "Token.h"
#include <string>
#include<sstream>
using std::string;

class NumToken :public Token {
    private:
        int value;
    public:
        NumToken(int line, int v):Token(line){
            value = v;
        }
    public:
        bool isNumber() { return true;}
        string getText() {
            std::stringstream ss;
            ss<<value;
            string s1 = ss.str();
            return s1;}
    public:
        int getNumber() { return value;}
};

class IdToken :public Token {
    private:
        string text;
    public:
        IdToken(int line, string id):Token(line) {
            text = id;
        }
    public:
        bool isIdentifier() { return true;}
    public:
        string getText() { return text;}
};

class StrToken :public Token {
    private:
        string literal;
    public:
        StrToken(int line, string str_info):Token(line) {
            literal = str_info;
        }
    public:
        bool isString() { return true; }
    public:
        string getText() { return literal; }
};

#endif // DERIVEDTOKENS_H
