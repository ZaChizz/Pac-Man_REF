#include <string>

class UnitException
{
private:
    std::string m_error;
 
public:
    UnitException(std::string error): m_error(error) {
    }
    
    const char* getError() { 
        return m_error.c_str(); 
    }
};
