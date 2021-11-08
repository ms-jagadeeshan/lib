#include <iostream>
#include <exception>
#include <dirent.h>
#include <libgen.h>
// #include <errno.h>
#include <string.h>
// #include <cstdlib>
#include <sys/stat.h> //for struct stat
#include <unistd.h>   //for access()
#include <sys/types.h>
#define CMD_NAME "backup_sync"
const char *getEnv(const char *key, const char *def = nullptr)
{
    if (key == nullptr)
    {
        throw std::invalid_argument("Null pointer passed as environment variable name");
    }
    if (*key == '\0')
    {
        throw std::invalid_argument("Value requested for the empty-name environment variable");
    }
    const char *ret = getenv(key);
    return ret ? ret : def;
}

bool isExist(const std::string &name)
{
    return (access(name.c_str(), F_OK) != -1);
}

int isFile(const std::string &name) noexcept
{
    struct stat st_buf;
    int status = stat(name.c_str(), &st_buf);
    if (status != 0)
    {
        return -1;
    }
    if (S_ISREG(st_buf.st_mode))
    {
        return 0;
    }
    if (S_ISDIR(st_buf.st_mode))
    {
        return 1;
    }
    return -1;
}
// int main()
// {
//     std::cout << getEnv("HOME");
// }