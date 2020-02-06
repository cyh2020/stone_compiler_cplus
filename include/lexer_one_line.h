#ifndef LEXER_ONE_LINE_H
#define LEXER_ONE_LINE_H

#include <string>
#include <list>
#include "Token.h"
#include "derivedTokens.h"
using std::list;

void lexer_one_line_func(string s,int num,list<Token*>& qlist);
bool isLetter(int c);
bool isDigit(int c);
bool isSpace(int c);
void ungetChar(int c);
char getChar();


#endif // LEXER_ONE_LINE_H
