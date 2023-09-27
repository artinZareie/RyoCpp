#include  "../headers/string.hpp"

using namespace Ryo::Utils;

std::vector<std::string> String::split(std::string subject, const char &delimiter) {
    size_t find_poisition = 0;
    std::vector<std::string> tokens; 

    while ((find_poisition = subject.find(delimiter)) != std::string::npos) {
        std::string token = subject.substr(0, find_poisition);
        tokens.push_back(token);
        subject.erase(0, find_poisition + 1);
    }
    tokens.push_back(subject);

    return tokens;
}

std::vector<std::string> String::split(std::string subject, const std::string &delimiter) {
    size_t find_poisition = 0;
    std::vector<std::string> tokens; 

    while ((find_poisition = subject.find(delimiter)) != std::string::npos) {
        std::string token = subject.substr(0, find_poisition);
        tokens.push_back(token);
        subject.erase(0, find_poisition + delimiter.length());
    }
    tokens.push_back(subject);

    return tokens;
}
