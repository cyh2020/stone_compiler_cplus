#ifndef TOKEN_H
#define TOKEN_H
#include <string>
using std::string;

class Token//������public�̳�token���࣬�����������͵�token�����Ǳ�����������
{
    public:

        static string EOL_S;
        static Token* EOF_S;


        virtual bool isIdentifier();//�麯����ά��һ��ָ������ø��Եķ���
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
