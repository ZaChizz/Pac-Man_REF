#include <string>

class MooverException
{
private:
    std::string m_error;
 
public:
    MooverException(std::string error): m_error(error) {
    }
    
    const char* getError() { 
        return m_error.c_str(); 
    }
};
