#ifndef UTILS_HPP
#define UTILS_HPP

#include <filesystem>

namespace fs = std::filesystem;

void pressAnyKey();
void throwError(const std::string& error);
std::string formatPath(std::string path);
std::vector<std::string> splitString(std::string stringToSplit, const char delimiter);
int mkpath(const fs::path& filePath, size_t startPos);

#endif
