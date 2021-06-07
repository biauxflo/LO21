#ifndef LO21_AUTOMATEEXCEPTION_H
#define LO21_AUTOMATEEXCEPTION_H
#include <exception>
#include <string>

namespace AUTOMATE_EXCEPTION_NP {
class AutomateException : public std::exception {
    std::string info;
public:
    AutomateException(const char* s) throw() : info(s) {}
    const char* what() const noexcept { return info.c_str();}
};
}

#endif //LO21_AUTOMATEEXCEPTION_H
