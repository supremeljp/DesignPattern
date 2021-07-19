#include <map>
#include <string>

class Font
{
public:
    Font(const std::string& key)
    {

    }
private:
    std::string str;
};

class Factory
{
public:
    Font* GetFont(const std::string& key)
    {
        if(fontPool.find(key) != fontPool.end())
        {
            return fontPool[key];
        }
        else
        {
            Font* font = new Font(key);
            fontPool[key] = font;
            return font;
        }
    }
private:
    std::map<std::string, Font*> fontPool;
};