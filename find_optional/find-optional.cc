#include "find-optional.hh"

std::optional<std::size_t> find_optional(const std::vector<int>& vect,
                                         int value)
{
    size_t pos = 0;
    for (int i : vect)
    {
        if (i == value)
            return pos;
        pos++;
    }

    return std::nullopt;
}