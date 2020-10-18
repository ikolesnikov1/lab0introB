#include "csv.h"

int main(int argc, char** argv) {
    Csv text;
    std::string inputFile = argv[1], outputFile = argv[2];
    text.parcer(inputFile);
    text.writeInOutputFile(outputFile);
    return 0;
}
