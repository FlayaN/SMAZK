#ifndef CONFIG_H
#define CONFIG_H
class Config
{
public:

    Config(char* fileName, char* Category);

    int getInt(char* Key, int DefaultValue);
    float getFloat(char* Key, float DefaultValue);
    bool getBool(char* Key, bool DefaultValue);
    char* getString(char* Key, const char* DefaultValue);

private:

    char m_fileName[255];
    char m_Category[255];
}
#endif
