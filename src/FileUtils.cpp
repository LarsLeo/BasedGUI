#include "FileUtils.h"

#include <fstream>
#include <sstream>

std::string FileUtils::readFile(const std::string& filePath)
{
    std::ifstream ifStream(filePath.c_str());
    std::stringstream buffer;

    buffer << ifStream.rdbuf();

    return buffer.str();
}
