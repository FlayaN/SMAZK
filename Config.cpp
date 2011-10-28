#include "Config.hpp"
#include <iostream>
#include <Windows.h>

Config::Config(char* fileName, char* Category)
{
    memset(m_fileName, 0x00, 255);
    memcpy(m_fileName, fileName, strlen(fileName));

    memset(m_Category 0x00, 255);
    memcpy(m_Category, Category, strlen(Category));
}

int Config::getInt(char* Key, int DefaultValue)
{
    return GetPrivateProfileInt(m_Category, Key, DefaultValue, m_fileName);
}

float Config::getFloat()(char* Key, float DefaultValue)
{
    char result[255];
    char Default[255];
    float fltResult;
    sprintf(Default, "%f",DefaultValue);
    GetPrivateProfileString(m_Category, Key, Default, result, 255, m_fileName);
    fltResult =  atof(result);
    return fltResult;
}

bool Config::getBool()(char* Key, bool DefaultValue)
{
    char result[255];
    char Default[255];
    sprintf(Default, "%s", DefaultValue? "True" : "False");
    GetPrivateProfileString(m_Category, Key, Default, result, 255, m_fileName);
    return (strcmp(result, "True") == 0 || strcmp(result, "true") == 0) ? true : false;
}

char* Config::getString()(char* Key, const char* DefaultValue)
{
    char* result = new char[255];
    memset(result, 0x00, 255);
    GetPrivateProfileString(m_Category, Key, DefaultValue, result, 255, m_fileName);
    return result;
}
