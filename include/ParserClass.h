//#ifndef PARSERCLASS_H
//#define PARSERCLASS_H
//
//#include <lexer.h>
//#include <Token.h>
//#include <ASTNode.h>
//#include "Parser.h"
//using std::list;
//
//class Element {
//    virtual void parse(Lexer le, list<ASTNode*> res) {
//        throw "Element has no function called parse";
//    }
//    virtual bool match(Lexer le) {
//        throw "Element has no function called match";
//    }
//};
//
//class Tree :public Element {
//protected:
//    Parser parser;
//
//    Tree(Parser p) {
//        parser = p;
//    }
//
//    void parse(Lexer Lexer, list<ASTNode*> res) {
//        res.push_back(parser.parse(Lexer));
//    }
//    bool match(Lexer Lexer) {
//        return parser.match(Lexer);
//    }
//};
//
//class OrTree:public Element {
//protected:
//    list<Parser> parsers;
//    OrTree(list<Parser> p) {
//        parsers = p;
//    }
//    void parse(Lexer Lexer, list<ASTNode*> res) {
//        Parser p = choose(Lexer);
//        res.push_back(p.parse(Lexer));
//    }
//    bool match(Lexer Lexer) {
//        return choose(Lexer) != nullptr;
//    }
//    Parser choose(Lexer Lexer) {
//        for (Parser p: parsers)
//            if (p.match(Lexer))
//                return p;
//        return nullptr;
//    }
//    void insert(Parser p) {
//        parsers.push_front(p);
//    }
//};
//
//class Repeat :public Element {
//protected:
//    Parser parser;
//    bool onlyOnce;
//    Repeat(Parser p, bool once) {
//        parser = p;
//        onlyOnce = once;
//    }
//    void parse(Lexer Lexer, list<ASTNode*> res) {
//        while (parser.match(Lexer)) {
//            ASTNode* t = parser.parse(Lexer);
//            if (t->numChildren() > 0)
//                res.push_back(t);
//            if (onlyOnce)
//                break;
//        }
//    }
//    bool match(Lexer Lexer) {
//        return parser.match(Lexer);
//    }
//};
//
//
//template <typename type = ASTLeaf>
//class AToken :public Element {
//protected:
//    FactoryDerived<type> factory;
//
//    AToken() {
//        FactoryDerived<type> factory;
//    }
//
//protected:
//    void parse(Lexer Lexer, list<ASTNode*> res) {
//        //实现parse
//        Token t = Lexer.read();
//        if (test(t)) {
//            ASTNode* leaf = this.factory.make(t);
//            res.push_back(leaf);
//        } else
//            throw "ParseException";
//    }
//
//    bool match(Lexer Lexer) { //实现match
//        return test(Lexer.peek(0));
//    }
//    virtual bool test(Token* t) {
//        return false;
//    }
//};
//
//template <typename type>
//class IdToken : public AToken<type> {//IdToken_Lexer
//public:
//    set<string> reserved;
//
//protected:
//    IdToken(set<string> r):AToken<type>() {
//        if (r.empty()) {
//            reserved = new set<string>;
//        } else {
//            reserved = r;
//        }
//    }
//
//protected:
//    bool test(Token* t) {
//        return ((t->isIdentifier()) && (reserved.count( t->getText() ) != 0));
//    }
//};
//
//template <typename type>
//class NumToken :public AToken<type> {//NumToken_Lexer
//    NumToken():AToken<type>() {
//
//    }
//    bool test(Token* t) {
//        return t->isNumber();
//    }
//};
//
//template <typename type>
//class StrToken:public AToken<type> {//StrToken_Lexer
//protected:
//    StrToken():AToken<type>() { };
//    bool test(Token* t) {
//        return t->isString();
//    }
//};
//
//
//class Leaf :public Element {
//protected:
//    list<string> tokens;
//    Leaf(list<string> pat) {
//        tokens = pat;
//    }
//    void parse(Lexer Lexer, list<ASTNode*> res) {
//        Token* t = Lexer.read();
//        if (t->isIdentifier())
//            for (string token: tokens)
//                if (token == (t->getText())) {
//                    find(res, t);
//                }
//    }
//    void find(list<ASTNode*> res, Token* t) {
//        res.push_back(new ASTLeaf(t));
//    }
//    bool match(Lexer Lexer) {
//        Token* t = Lexer.peek(0);
//        if (t->isIdentifier())
//            for (string token: tokens)
//                if (token == (t->getText()))
//                    return true;
//
//        return false;
//    }
//};
//
//class Skip:public Leaf {
//protected:
//    Skip(list<string> t):Leaf(t) {}
//    void find(list<ASTNode*> res, Token* t) {}
//};
//
//// for expression
//class Precedence {//结合顺序
//public:
//    int value;
//    bool leftAssoc; // left associative
//
//    Precedence(int v, bool a):value(v),leftAssoc(a) {
//    }
//};
//
//class Operators {
//public:
//    void add(string name, int prec, bool leftAssoc) {//优先级 ，是否左结合
//        Precedence p(prec, leftAssoc);
//        std::pair<string,Precedence> value(name,p);
//        smp.insert(value);
//    }
//
//private:
//    std::map<string,Parser::Precedence> smp;
//};
//
//
//template <typename clazz>
//class Expr :public Element {
//protected:
//    FactoryDerived<clazz> factory;
//    Operators ops;
//    Parser factor;
//    Expr(Parser exp,Operators map) {
//        factory = new FactoryDerived<clazz>();
//        ops = map;
//        factor = exp;
//    }
//public:
//    void parse(Lexer Lexer, list<ASTNode*> res) {
//        ASTNode* right = factor.parse(Lexer);
//        Precedence prec;
//        while (prec = nextOperator(Lexer))
//            right = doShift(Lexer, right, prec.value);
//        res.push_back(right);
//    };
//
//private:
//    ASTNode* doShift(Lexer Lexer, ASTNode* left, int prec) {
//        list<ASTNode*> innerlist;
//        innerlist.push_back(left);
//        innerlist.push_back(new ASTLeaf(Lexer.read()));
//        ASTNode* right = factor.parse(Lexer);
//        Precedence next;
//        while ((next = nextOperator(Lexer)) != nullptr  && rightIsExpr(prec, next))
//            right = doShift(Lexer, right, next.value);
//
//        innerlist.push_back(right);
//        return factory.make(innerlist);
//    }
//    Precedence nextOperator(Lexer Lexer) {
//        Token* t = Lexer.peek(0);
//        if (t->isIdentifier())
//            return ops.get(t->getText());
//        else
//            return nullptr;
//    }
//    bool rightIsExpr(int prec, Precedence nextPrec) {
//        if (nextPrec.leftAssoc)
//            return prec < nextPrec.value;
//        else
//            return prec <= nextPrec.value;
//    }
//    bool match(Lexer Lexer) {
//        return factor.match(Lexer);
//    }
//};
//
//#endif // PARSERCLASS_H
