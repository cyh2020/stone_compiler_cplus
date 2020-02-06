#ifndef TOKEN_H
#define TOKEN_H
#include <string>
using std::string;

class Token//其他都public继承token的类，可以向上造型到token，但是保留自有数据
{
    public:

        static string EOL_S;
        static Token* EOF_S;


        virtual bool isIdentifier();//虚函数，维持一张指向表，调用各自的方法
        virtual bool isNumber();
        virtual bool isString();
        virtual int getNumber();
        virtual string getText();
        int getLineNumber();

    public:
        Token(int line);
        virtual ~Token();

    protected:
//        int value;
//        string literal;
        int lineNumber;
};


#endif // TOKEN_H
