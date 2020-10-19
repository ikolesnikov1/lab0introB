#include "csv.h"

int main(int argc, char** argv) {
    Csv text;
    if (argc == 3) {
        const std::string inputFile = argv[1], outputFile = argv[2];
        try {
            text.parcer(inputFile);
            text.writeInOutputFile(outputFile);
        }
        catch(std::exception& ex) {
            std::cerr << ex.what();
        }
    }
    else {
        std::cerr << "Incorrect count of files";
    }
    return 0;
}
