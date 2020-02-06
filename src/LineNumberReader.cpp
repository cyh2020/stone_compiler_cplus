#include "LineNumberReader.h"
#include <fstream>
#include <string>

LineNumberReader::LineNumberReader()
{
    line_no = 0;
    is_open = true;
    OpenFile.open("./Lexertest.txt");
}

LineNumberReader::~LineNumberReader()
{
    //dtor
}

std::string LineNumberReader::getstr(){
    OpenFile.getline(chr_out,20);
    str_out = chr_out;
    line_no ++;

    if (OpenFile.eof()){
        OpenFile.close();
        is_open = false;
        return str_out;
    }

    return str_out;
};

int LineNumberReader::getLineNumber(){
    return this->line_no;

};

