#ifndef ILLNESSCODE_H
#define ILLNESSCODE_H

#include <string>
#include <vector>
#include <utility>
#include <fstream>

class IllnessCode {
public:
    IllnessCode();
    ~IllnessCode();

    std::string Encrypt(std::vector<std::string> &textForChiper);
    std::vector<std::string> Decrypt(std::string textForDecrypt);

private:
    std::vector<std::pair<std::string, std::string>> _dictionary;
};

#endif // ILLNESSCODE_H
