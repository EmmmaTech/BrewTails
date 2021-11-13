#pragma once

#include <string>
#include <vector>

namespace FS
{

std::vector<std::string> readFilesFromDirectory(const std::string path);
void filterForExtension(std::vector<std::string> &paths, const std::string extension);

} // namespace FS