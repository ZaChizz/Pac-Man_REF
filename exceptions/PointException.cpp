#include <string>

class PointException
{
private:
    std::string m_error;
 
public:
    PointException(std::string error): m_error(error) {
    }
    
    const char* getError() { 
        return m_error.c_str(); 
    }
};
