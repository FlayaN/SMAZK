#include <Windows.h>
#include <string>
std::string Config::getString(std::string name)
{
    return GetPrivateProfileString(type, name, "error", inifile);
}

int Config::getInt(std::string name)
{
    return GetPrivateProfileInt(type, name, 10, inifile);
}
