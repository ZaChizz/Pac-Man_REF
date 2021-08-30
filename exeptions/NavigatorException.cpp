#include <string>

class NavigatorException
{
private:
    std::string m_error;
 
public:
    NavigatorException(std::string error): m_error(error) {
    }
    
    const char* getError() { 
        return m_error.c_str(); 
    }
};
