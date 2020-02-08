#ifndef LEXER_H
#define LEXER_H

#include "lexer_one_line.h"
#include "Token.h"
#include "LineNumberReader.h"
#include <list>
#include <string>

using std::string;

class Lexer{
    public:
        Lexer(string file_location);
        virtual ~Lexer();
        void readLine();
        list<Token*> qlist;//��tokenָ���ԭ������ΪҪ��������
        Token* read();
        Token* peek(int i);


    private:
        bool hasMore;

        LineNumberReader reader;

        bool fillQueue(int i);
};


#endif // LEXER_H
