#include "path.hh"

#include <string>

Path& Path::join(const std::string& tail, bool is_file)
{
    if (final_)
        return *this;

    path_.push_back(tail);
    final_ = is_file;
    return *this;
}