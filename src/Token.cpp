#include "Token.h"
#include "exception"
#include "string"

using std::string;

Token::Token(int line):lineNumber(line) {

}

Token::~Token() {
    //dtor
}

bool Token::isIdentifier() {
    return false;
}
bool Token::isNumber() {
    return false;
}
bool Token::isString() {
    return false;
}
int Token::getNumber() {
    throw ("not number token");
}
string Token::getText() {
    return "";
}
int Token::getLineNumber() {
    return lineNumber;
};


