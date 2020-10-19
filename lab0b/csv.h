#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>

class Csv {
    std::map <std::string, int> freq;
    int total = 0;

public:
    void parcer(const std::string &inputFile);
    void writeInOutputFile(const std::string &outputFile);
};
