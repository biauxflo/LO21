#ifndef LO21_AUTOMATEEXCEPTION_H
#define LO21_AUTOMATEEXCEPTION_H
#include <exception>
#include <string>
/**
* \class AutomateException
* \brief Classe gérant le déclenchement des différentes exceptions.
*/

namespace AUTOMATE_EXCEPTION_NP {
class AutomateException : public std::exception {
    std::string info;
public:
    AutomateException(const char* s) noexcept: info(s) {}
    const char* what() const noexcept { return info.c_str();}
};
}

#endif //LO21_AUTOMATEEXCEPTION_H
