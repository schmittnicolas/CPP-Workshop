#pragma once

#include "unordered-multimap.hh"

template <typename KeyType, typename ValueType>
bool UnorderedMultimap<KeyType, ValueType>::empty() const
{
    return multimap_.empty();
}

template <typename KeyType, typename ValueType>
unsigned UnorderedMultimap<KeyType, ValueType>::size() const
{
    return multimap_.size();
}

template <typename KeyType, typename ValueType>
std::pair<typename UnorderedMultimap<KeyType, ValueType>::iterator,
          typename UnorderedMultimap<KeyType, ValueType>::iterator>
UnorderedMultimap<KeyType, ValueType>::equal_range(const KeyType& key)
{
    iterator first = multimap_.end();
    iterator last = multimap_.end();
    for (iterator it = multimap_.begin(); it != multimap_.end(); it++)
    {
        if (it->first == key)
        {
            if (first == multimap_.end())
            {
                first = it;
            }
            last = it;
        }
    }

    if (first == multimap_.end())
        return std::make_pair(first, first);

    if (last != multimap_.end())
        last++;

    return std::make_pair(first, last);
}

template <typename KeyType, typename ValueType>
void UnorderedMultimap<KeyType, ValueType>::add(const KeyType& key,
                                                const ValueType& value)
{
    multimap_.emplace_back(key, value);
}

template <typename KeyType, typename ValueType>
unsigned UnorderedMultimap<KeyType, ValueType>::count(const KeyType& key) const
{
    unsigned count = 0;

    for (std::pair<KeyType, ValueType> pair : multimap_)
    {
        if (pair.first == key)
            count++;
    }

    return count;
}

template <typename KeyType, typename ValueType>
void UnorderedMultimap<KeyType, ValueType>::clear()
{
    multimap_.clear();
}
