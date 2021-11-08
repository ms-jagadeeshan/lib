#include <iostream>
#include <cstddef>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
//#include <exception>
// #include <cstdlib>
// #include <sys/stat.h>
// #include <unistd.h>

//function to detect and change special characters
void sanitize(std::string &stringValue)
{
    // Add backslashes.
    for (auto i = stringValue.begin();;)
    {
        auto const pos = std::find_if(
            i, stringValue.end(),
            [](char const c)
            { return '\\' == c || '\'' == c || '"' == c; });
        if (pos == stringValue.end())
        {
            break;
        }
        i = std::next(stringValue.insert(pos, '\\'), 2);
    }

    // Removes others.
    stringValue.erase(
        std::remove_if(
            stringValue.begin(), stringValue.end(), [](char const c)
            { return '\n' == c || '\r' == c || '\0' == c || '\x1A' == c; }),
        stringValue.end());
}
//function to get environment variable
std::string getEnvVar(std::string const &key)
{
    char *val = getenv(key.c_str());
    return val == NULL ? std::string("") : std::string(val);
}

inline std::string get_env(const char *key)
{
    if (key == nullptr)
    {
        throw std::invalid_argument("Null pointer passed as environment variable name");
    }
    if (*key == '\0')
    {
        throw std::invalid_argument("Value requested for the empty-name environment variable");
    }
    const char *ev_val = getenv(key);
    if (ev_val == nullptr)
    {
        throw std::runtime_error("Environment variable not defined");
    }
    return std::string(ev_val);
}
const char *GetEnv(const char *tag, const char *def = nullptr) noexcept
{
    const char *ret = std::getenv(tag);
    return ret ? ret : def;
}
int main()
{
    std::cout << GetEnv("");
  //  std::string str = get_env("sdkl");
}