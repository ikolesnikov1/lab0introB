#include "csv.h"

bool comparator(const std::pair<int, std::string>& a, const std::pair<int, std::string>& b) {
    return (a.first > b.first);
}

int Csv::openInputFile(char** argv) {
    try {
        fin.open(argv[1]);
        if (!fin) {
            throw "Input file not found";
        }
    }
    catch (const char* exception) {
        std::cout << exception;
        return 1;
    }
}

void Csv::parcer() {
    while (!fin.eof()) {
        std::string line;
        getline(fin, line);
        std::string w;
        for (auto c : line) {
            if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
                w += c;
            }
            else if (w != "") {
                freq[w]++;
                w.clear();
            }
        }
        if (w != "") {
            freq[w]++;
            w.clear();
        }
    }
    fin.close();

    for (auto i : freq) {
        sortFreq.push_back(std::make_pair(i.second, i.first));
        total += i.second;
    }
    sort(sortFreq.begin(), sortFreq.end(), comparator);
}

int Csv::openOutputFile(char** argv) {
    try {
        fout.open(argv[2]);
        if (!fout) {
            throw "Output file not found";
        }
    }
    catch (const char* exception) {
        std::cout << exception;
        return 1;
    }
}

void Csv::writeInOutputFile() {
    for (auto i : sortFreq) {
        double freqPercentage = (double)(i.first * 100) / total;
        fout << i.second << ";" << i.first << ";" << freqPercentage << "%" << std::endl;

    }
    fout.close();
}
