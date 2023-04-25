#include "merge-sort.hh"

#include <algorithm>

void merge_sort(iterator_type begin, iterator_type end)
{
    if (std::distance(begin, end) < 2)
        return;

    size_t const half_size = std::distance(begin, end) / 2;
    const auto half = std::next(begin, half_size);

    merge_sort(begin, half);
    merge_sort(half, end);

    std::inplace_merge(begin, half, end);
}