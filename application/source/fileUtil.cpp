#include <fileUtil.hpp>

#include <switch.h>
#include <stdio.h>
#include <dirent.h>

namespace
{

bool endsWith(const std::string& str, const std::string& suffix)
{
    return str.size() >= suffix.size() && 0 == str.compare(str.size() - suffix.size(), suffix.size(), suffix);
}

} // namespace


namespace FS
{

std::vector<std::string> readFilesFromDirectory(const std::string path)
{
    DIR *dir = opendir(path.c_str());

    if (dir == NULL)
        return {};
    else
    {
        std::vector<std::string> vec;
        struct dirent *ent;

        while ((ent = readdir(dir)))
        {
            vec.push_back(std::string(ent->d_name));
        }
        closedir(dir);

        return vec;
    }

    return {};
}

void filterForExtension(std::vector<std::string> &paths, const std::string extension)
{
    std::vector<std::string>::iterator itr = paths.begin();
    for (;itr != paths.end();)
    {
        if (endsWith(*itr, "." + extension))
            itr++;
        else
            itr = paths.erase(itr);
    }
}

} // namespace FS
