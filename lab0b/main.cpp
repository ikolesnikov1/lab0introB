#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
#include "csv.h"

int main(int argc, char** argv) {
    Csv text;
    text.openInputFile(argv);
    text.parcer();
    text.openOutputFile(argv);
    text.writeInOutputFile();
    return 0;
}
