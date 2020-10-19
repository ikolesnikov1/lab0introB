#include "csv.h"

bool comparator(const std::pair<int, std::string>& a, const std::pair<int, std::string>& b) {
    return (a.first > b.first);
}


void Csv::parcer(const std::string &inputFile) {
    std::ifstream fin;
    fin.open(inputFile);
    if (!fin) {
        throw std::logic_error("Unable to open file");
    }

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
}


void Csv::writeInOutputFile(const std::string &outputFile) {
    std::ofstream fout;
    fout.open(outputFile);
    if (!fout) {
        throw std::logic_error("Unable to open file");
    }

    std::vector<std::pair<int, std::string>> sortFreq;

    for (auto i : freq) {
        sortFreq.push_back(std::make_pair(i.second, i.first));
        total += i.second;
    }
    sort(sortFreq.begin(), sortFreq.end(), comparator);

    for (auto i : sortFreq) {
        double freqPercentage = (double)(i.first * 100) / total;
        fout << i.second << ";" << i.first << ";" << freqPercentage << "%" << std::endl;

    }
    fout.close();
}
