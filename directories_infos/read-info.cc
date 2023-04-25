#include "read-info.hh"

bool read_info(std::istream& file, DirectoryInfo& dir_info)
{
    if (!file)
        return false;

    std::string line;

    if (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string name;
        unsigned int size;
        unsigned int rights;
        std::string owner;

        if (iss >> name >> size >> std::oct >> rights >> owner)
        {
            if (!iss.eof())
                return false;

            dir_info.name_ = name;
            dir_info.size_ = size;
            dir_info.rights_ = rights;
            dir_info.owner_ = owner;
            return true;
        }
    }

    return false;
}
