#include <Windows.h>
#include <string>
class Config
{
public:

    Config(string inifile, string type)
    {
        this.inifile = inifile;
        this.type = type;
    }

    string getString(string name)
    {
        return GetPrivateProfileString(type, name, "error", inifile);
    }

    int getHP(string name)
    {
        return GetPrivateProfileInt(type, name, 10, inifile);
    }

private:

    string inifile;
    string type;
}
