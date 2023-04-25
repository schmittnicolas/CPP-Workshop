#include "unix-path.hh"

std::string UnixPath::to_string() const
{
    std::string output = "/";

    for (const std::string& str : path_)
    {
        output += str + "/";
    }

    if (final_)
        output.pop_back();
    return output;
}