#include <string>

class CompassException
{
private:
    std::string m_error;
 
public:
    CompassException(std::string error): m_error(error) {
    }
    
    const char* getError() { 
        return m_error.c_str(); 
    }
};
