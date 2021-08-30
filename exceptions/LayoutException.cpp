#include <string>

class LayoutException
{
private:
    std::string m_error;
 
public:
    LayoutException(std::string error): m_error(error) {
    }
    
    const char* getError() { 
        return m_error.c_str(); 
    }
};
