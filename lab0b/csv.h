#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>

class Csv {
    std::ifstream fin;
    std::map <std::string, int> freq;
    std::vector<std::pair<int, std::string>> sortFreq;
    std::ofstream fout;
    int total = 0;

public:
    int openInputFile(char** argv);
    void parcer();
    int openOutputFile(char** argv);
    void writeInOutputFile();
};

