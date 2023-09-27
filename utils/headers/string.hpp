#ifndef RYO_STRING_HPP
#define RYO_STRING_HPP

#include <string>
#include <vector>

namespace Ryo::Utils {

class String {
public:
    static std::vector<std::string> split(std::string subject, const char &delimiter);
    static std::vector<std::string> split(std::string subject, const std::string &delimiter);
};

}

#endif
