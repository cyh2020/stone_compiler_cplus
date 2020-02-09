#ifndef PARSER_H
#define PARSER_H

#include <map>
#include <string>
#include <set>
#include <list>
#include <lexer.h>
#include <Token.h>
#include <ASTNode.h>
#include <ASTLeaf.h>
#include <ASTList.h>
#include <Factory.h>
#include <FactoryDerived.h>
#include <typeinfo>
#include "ParserClass.h"
#include "BinaryExpr.h"
using std::map;
using std::set;
using std::list;
using std::string;
using std::cout;
using std::endl;


//!!!!!!!!!!!!!!!!!!!!!!!Parsers must be declared in .h file !!!!!!!!!!!!!!!

class Parser {
public:
    void printMyself(){
//        cout<<"{"<<endl;

        if (this == (void*)(0x96fdbc)){//block address avoid repeat print
            cout<<this<<" block  ("<<elements.size()<<")";
        }else{
            cout<<this<<"  ("<<elements.size()<<")";
            cout<<"{"<<endl;
            for(Element* e : elements){
                e->printMyself();
                cout<<";"<<endl;
            }
            cout<<"}"<<endl;
        }
    }

    class Element {
    public:
        virtual void parse(Lexer* le, list<ASTNode*> &res) {
            throw "Element has no function called parse";
        }
        virtual bool match(Lexer* le) {
            throw "Element has no function called match";
        }

        virtual void printMyself(){
            throw "Element has no function called printMyself()";
        }
    };

    class Tree :public Parser::Element {
    protected:
        Parser* Tree_parser;
    public:
        Tree(Parser* p) {
            Tree_parser = p;
        }

        void parse(Lexer* lexer_r, list<ASTNode*> &res) {
            res.push_back(Tree::Tree_parser->parse(lexer_r));
        }
        bool match(Lexer* lexer_r) {
            return Tree::Tree_parser->match(lexer_r);
        }

        void printMyself(){
            cout<<this<<"  "<<"TREE"<<endl;
                Tree_parser->printMyself();
        }
    };

    class OrTree:public Parser::Element {
    protected:
        list<Parser*> parsers;
    public:
        OrTree(list<Parser*> p) {
            parsers = p;
        }
        void parse(Lexer*  lexer_r, list<ASTNode*> &res) {
//            std::cout<<"this is the ortree func"<<std::endl;
            Parser* p = choose(lexer_r);
//            std::cout<<"p is the chossen"<<std::endl;
            ASTNode* get_p = p->parse(lexer_r);
            res.push_back(get_p);
        }
        bool match(Lexer*  lexer_r) {
            return choose(lexer_r) != nullptr;
        }
        Parser* choose(Lexer* lexer_r) {
//            std::cout<<"p is the chosing"<<std::endl;
            for (Parser* p: OrTree::parsers)
                if (p->Parser::match(lexer_r)){
//                    std::cout<<"p is the ok"<<p<<std::endl;
                    return p;
                }

            return nullptr;
        }
        void insert(Parser* p) {
            parsers.push_front(p);
        }

        void printMyself(){
            cout<<this<<"  "<<"ORTREE"<<"  "<<parsers.size()<<endl;
            cout<<"{"<<endl;
            for(Parser*p : parsers){
                p->printMyself();
                cout<<";"<<endl;
            }
            cout<<"}"<<endl;
        }
    };

    class Repeat :public Parser::Element {
    protected:
        Parser* rparser;
        bool onlyOnce;
    public:
        Repeat(Parser* p, bool once) {//option'once is true
            rparser = p;
            onlyOnce = once;
        }
        void parse(Lexer*  lexer_r, list<ASTNode*>& res) {
            while (rparser->match(lexer_r)) {
                ASTNode* t = rparser->parse(lexer_r);
                //is a Name Terminal or has children
                if (typeid(*t) != typeid(ASTList) || (t->numChildren() > 0))
                    res.push_back(t);
                if (onlyOnce)
                    break;
            }
        }
        bool match(Lexer*  lexer_r) {
            return rparser->match(lexer_r);
        }

        void printMyself(){
            cout<<this<<"  "<<"RepeatTREE"<<endl;
                rparser->printMyself();
        }
    };


    template <typename type = ASTLeaf>
    class AToken :public Parser::Element {
    protected:
        FactoryDerived<type> factory;
    public:
        AToken() {
            FactoryDerived<type> factory;
        }

        void parse(Lexer* lexer_r, list<ASTNode*>& res) {
//            std::cout<<"the A token parse is running"<<std::endl;
            //实现parse
            Token* t = lexer_r->read();
            if (test(t)) {
                ASTNode* leaf = AToken::factory.make_atoken(t);
                res.push_back(leaf);
            } else
                throw "ParseException";
        }

        bool match(Lexer*  lexer_r) { //实现match
            return test(lexer_r->peek(0));
        }
        virtual bool test(Token* t) {
            return false;
        }

        void printMyself(){
            cout<<this<<"  "<<"AToken"<<endl;
        }
    };

    template <typename type>
    class IdToken : public AToken<type> {//IdToken_Lexer
    protected:
        set<string> reserved;
    public:
        IdToken(set<string> &r):AToken<type>() {
            if (!r.empty()) {
                reserved = r;
            }
        }

        void printMyself(){
            cout<<this<<"  "<<"IdToken"<<endl;
        }
    protected:
        bool test(Token* t) {
//            cout<<"------------"<<t->getText()<<(reserved.count( t->getText() ) == 0)<<endl;
            return ((t->isIdentifier()) && (reserved.count( t->getText() ) == 0));
        }
    };

    template <typename type>
    class NumToken :public AToken<type> {//NumToken_Lexer
    public:
        void printMyself(){
            cout<<this<<"  "<<"NumToken"<<endl;
        }
        NumToken():AToken<type>() {

        }
        bool test(Token* t) {
            return t->isNumber();
        }
    };

    template <typename type>
    class StrToken:public AToken<type> {//StrToken_Lexer
    public:
        void printMyself(){
            cout<<this<<"  "<<"StrToken"<<endl;
        }
        StrToken():AToken<type>() { };
        bool test(Token* t) {
            return t->isString();
        }
    };


    class Leaf :public Parser::Element {//something not very important
    protected:
        list<string> tokens;
    public:
        void printMyself(){
            cout<<this<<"  "<<"Leaf"<<endl;
        }

        Leaf(list<string> pat) {
            tokens = pat;
        }
        void parse(Lexer*  lexer_r, list<ASTNode*>& res) {
            Token* t = lexer_r->read();
//            cout<<this<<"  "<<t->getText()<<t->getLineNumber()<<endl;

            if (t->isIdentifier())
                for (string token: tokens)
                    if (token == (t->getText())) {
                        find(res, t);
                    }
        }
        void virtual find(list<ASTNode*>& res, Token* t) {
//            cout<<"---i am in lEAF find----"<<endl;
            res.push_back(new ASTLeaf(t));//隐藏掉换行的做法
        }
        bool match(Lexer*  lexer_r) {
            Token* t = lexer_r->peek(0);
            if (t->isIdentifier())
                for (string token: tokens)
                    if (token == (t->getText()))
                        return true;

            return false;
        }
    };

    class Skip:public Leaf {
    public:
        void printMyself(){
            cout<<this<<"  "<<"Skip"<<endl;
        }
        Skip(list<string> t):Leaf(t) {}
        void find(list<ASTNode*>& res, Token* t) {

        }//is ignored
    };

// for expression
    class Precedence {//结合顺序
    public:
        int value;
        bool leftAssoc; // left associative

        Precedence():value(20),leftAssoc(true){};//default
        Precedence(int v, bool a):value(v),leftAssoc(a) {
        }

        bool operator==(const Precedence& rhs){
          if(this->value == rhs.value){
            return true;
          }else{
            return false;
          }
        }
        bool operator!=(const Precedence& rhs){
          if(this->value != rhs.value){
            return true;
          }else{
            return false;
          }
        }
    };

    class Operators {
    public:
        void add(string name, int prec, bool leftAssoc) {//优先级 ，是否左结合
            Precedence p(prec, leftAssoc);
            std::pair<string,Precedence> value(name,p);
            smp.insert(value);
        }

        Precedence get(string t) {
            Precedence p = smp.at(t);
            return p;
        }

    private:
        std::map<string,Parser::Precedence> smp;
    };

    template <typename clazz>
    class Expr :public Element {
    protected:
        FactoryDerived<clazz> factory;
        Operators ops;
        Parser* factor;
    public:
        void printMyself(){
            cout<<this<<"  "<<"Expr"<<endl;
//            Expr::factor->printMyself();
        }

        const Precedence prec_null;//the prec when no matching one returned

        Expr(Parser* exp,Operators Opmap) {
            FactoryDerived<clazz> factory;
            ops = Opmap;
            factor = exp;
            Precedence prec_null;
        }

        void parse(Lexer*lexer_r, list<ASTNode*>& res) {
            ASTNode* right = factor->parse(lexer_r);
            Precedence prec;
            //if input is more than one,output will be BinaryExpr,else it will be Name
            while ((prec = Expr::nextOperator(lexer_r))!= Expr::prec_null){
//                cout<<"___________________{___________________"<<endl;
                right = doShift(lexer_r, right, prec.value);
            }

            res.push_back(right);

//            //some is Name
//            cout<<"right in Expr parse "<< (typeid(*right) == typeid(Name)) <<endl;
//            //some is Binary
//            cout<<"right in Expr parse "<< (typeid(*right) == typeid(BinaryExpr)) <<endl;
//            cout<<"right in Expr parse "<<right->toString() <<endl;
        };

        ASTNode* doShift(Lexer*lexer_r, ASTNode* left, int prec) {
            list<ASTNode*> innerlist;
            innerlist.push_back(left);
            innerlist.push_back(new ASTLeaf(lexer_r->read()));
            ASTNode* right = factor->parse(lexer_r);
//            cout<<"____________________}___________________"<<endl;
            Precedence next;
            while (((next = nextOperator(lexer_r)) != Expr::prec_null)  && rightIsExpr(prec, next)){
//                cout<<"before doShift"<<endl;
                right = doShift(lexer_r, right, next.value);
//                cout<<"after doShift"<<endl;
            }


            innerlist.push_back(right);
//            cout<<"before innerlist expr"<<innerlist.size()<<endl;

            //this factory means binary factory
            return factory.make(innerlist);
        }

        Precedence nextOperator(Lexer*  lexer_r) {
            Token* t = lexer_r->peek(0);
            if (t->isIdentifier()){
                    string cp = t->getText();
//                    cout<<"-------->"<<cp<<endl;
                if( cp.compare("\\n")== 0 ){//is end of line
                    return Expr::prec_null;
                }
                else if( cp.compare("{")== 0 ){
                    return Expr::prec_null;
                }
                else if( cp.compare(")")== 0 ){
                    return Expr::prec_null;
                }
                else return Expr::ops.get(t->getText());
            }
            else
                return Expr::prec_null;
        }
        bool rightIsExpr(int prec, Precedence nextPrec) {
            if (nextPrec.leftAssoc)
                return prec < nextPrec.value;
            else
                return prec <= nextPrec.value;
        }
        bool match(Lexer*  lexer_r) {
            return factor->match(lexer_r);
        }
    };


//data owned by itself
public:
    list<Element*> elements;//实例各个元素
    Factory* factory;//实例化工厂

//functions
public:
    Parser();//construction function

    Parser(Parser* p){
        factory = p->factory;
        elements = p->elements;
    }

    ASTNode* parse(Lexer* lexer_r);

    bool match(Lexer* lexer_r);

    void reset();

    //add terminals//add the nodes above
public:
    template <typename clazz>
    void number() {
        elements.push_back(new Parser::NumToken<clazz>);
    };


//    void identifier(set<string> &reserved) {//some bug here
//        elements.push_back(new Parser::IdToken<AST>(reserved));
//    }

    template <typename clazz>
    void identifier(set<string> &reserved) {
        elements.push_back(new Parser::IdToken<clazz>(reserved));
    };


    template <typename clazz>
    void str_ing() {
        elements.push_back(new Parser::StrToken<clazz>);
    };

    void token(list<string> pat) {//可变长度string数组
        elements.push_back(new Leaf(pat));
    }


    //add non terminals
public:
    void sep(list<string> pat) {//some thing that can be ignored
        elements.push_back(new Skip(pat));
    }
    void ast(Parser* p) {//abstract syntax tree
        elements.push_back(new Tree(p));
    }
    void or_add(list<Parser*> p) {
        elements.push_back(new OrTree(p));
    }

    void maybe(Parser* p) {
        Parser* p2 = new Parser(p);

        list<Element*> null_list;
        p2->elements = null_list;

        list<Parser*> to_add;
        to_add.push_back(p);
        to_add.push_back(p2);
        elements.push_back(new OrTree(to_add));
    }

    void option(Parser* p) {//some thing can be run only once
        elements.push_back(new Repeat(p, true));
    }
    void repeat(Parser* p) {//some thing can be run 1 to infinite times
        elements.push_back(new Repeat(p, false));
    }

    template <typename clazz>
    void expression(Parser* subexp,Operators operators) {
        elements.push_back(new Expr<clazz>(subexp, operators));
    };

    void insertChoice(Parser* p) {
        Element* e = elements.front();

        if (typeid(*e) == typeid(OrTree))
            ((OrTree*)e)->insert(p);
//        else {
//            Parser otherwise = new Parser(this);
//            reset(null);
//            or(p, otherwise);
//        }
    }

};

//
#endif // PARSER_H
