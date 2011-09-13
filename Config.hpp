#include <Windows.h>
#include <string>
class Config
{
public:

    Config(std::string inifile, std::string type):inifile(inifile), type(type){};

    std::string getString(std::string name);

    int getInt(string name);

private:

    std::string inifile;
    std::string type;
}
