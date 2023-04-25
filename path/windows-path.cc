#include "windows-path.hh"

#include <string>
#include <vector>

std::string WindowsPath::to_string() const
{
    std::string output = "";

    for (const std::string& str : path_)
    {
        output += str + "\\";
    }

    if (final_)
        output.pop_back();
    return output;
}

WindowsPath::WindowsPath(char drive)
{
    std::string prefix(1, drive);
    prefix += ":";

    path_.push_back(prefix);
}

Path& WindowsPath::join(const std::string& tail, bool is_file)
{
    if (final_)
        return *this;

    for (char c : tail)
    {
        if (c == ',' || c == '\"' || c == '|' || c == '?' || c == '*'
            || c == ':')
            return *this;
    }

    path_.push_back(tail);
    final_ = is_file;
    return *this;
}