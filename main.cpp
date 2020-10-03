#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>


class Csv {
private:
    std::ifstream fin;
    std::map <std::string, int> freq;
    std::vector<std::pair<int, std::string>> sortFreq;
    std::ofstream fout;
    int total = 0;

public:
    static bool comparator(const std::pair<int, std::string>& a, const std::pair<int, std::string>& b) {
        return (a.first > b.first);
    }

    int openInputFile(char** argv) {
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

    void parcer() {
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

    int openOutputFile(char** argv) {
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

    void writeInOutputFile() {
        for (auto i : sortFreq) {
            double freqPercentage = (double)(i.first * 100) / total;
            fout << i.second << " " << i.first << "," << freqPercentage << "%" << std::endl;

        }
        fout.close();
    }
};

int main(int argc, char** argv) {
    Csv text;
    text.openInputFile(argv);
    text.parcer();
    text.openOutputFile(argv);
    text.writeInOutputFile();
    return 0;
}
