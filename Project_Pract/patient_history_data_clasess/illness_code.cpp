#include "illness_code.h"
#include <iostream>
IllnessCode::IllnessCode()
    : _dictionary(0) {
    setlocale(LC_ALL, "Russian");
    std::ifstream dictionary("Dictionary.txt");
    if (dictionary.is_open()) {
        while (!dictionary.eof()) {
            std::string word, code;
            dictionary >> word;
            dictionary >> code;
            std::pair<std::string, std::string> wordCode(word, code);
            _dictionary.push_back(wordCode);
            std::cout << _dictionary.back().first << " " << _dictionary.back().second << "\n";
        }
    }
    dictionary.close();
}

IllnessCode::~IllnessCode() {}

std::string IllnessCode::Encrypt(std::vector<std::string> &textForChiper) {
    std::string code{""};
    for (auto word : textForChiper) {
//        std::cout << "слово - " << word << "\n";
        for (auto i = _dictionary.begin(); i != _dictionary.end(); ++i) {
//            std::cout << "сравнение с - " << (*i).first << "\n";
            if (word == (*i).first) {
//                std::cout << "замена на - " << (*i).second << "\n";
                code += (*i).second;
//                std::cout << "результат - " << code << "\n";
            }
        }
    }
    return code;
}
