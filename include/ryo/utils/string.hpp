#pragma once

#include <string>
#include <vector>

namespace Ryo::Utils {

class String {
public:
    static std::vector<std::string> split(std::string subject, const char &delimiter);
    static std::vector<std::string> split(std::string subject, const std::string &delimiter);
};

}
