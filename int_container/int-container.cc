#include "int-container.hh"

MyIntContainer::MyIntContainer(size_t size)
{
    elems_ = std::make_unique<int[]>(size);
    max_size_ = size;
    current_size_ = 0;
}

void MyIntContainer::print() const
{
    if (current_size_ == 0)
        return;

    std::cout << elems_[0];

    for (size_t i = 1; i < current_size_; i++)
    {
        std::cout << " | " << elems_[i];
    }

    std::cout << "\n";
}

size_t MyIntContainer::get_len() const
{
    return current_size_;
}

bool MyIntContainer::add(int elem)
{
    if (current_size_ >= max_size_)
        return false;

    elems_[current_size_] = elem;
    current_size_++;
    return true;
}

std::optional<int> MyIntContainer::pop()
{
    if (current_size_ == 0)
        return std::nullopt;

    current_size_--;
    return elems_[current_size_];
}

std::optional<int> MyIntContainer::get(size_t position) const
{
    if (position >= current_size_)
        return std::nullopt;

    return elems_[position];
}

std::optional<size_t> MyIntContainer::find(int elem) const
{
    for (size_t i = 0; i < current_size_; i++)
    {
        if (elem == elems_[i])
            return i;
    }

    return std::nullopt;
}

void MyIntContainer::sort()
{
    for (size_t i = current_size_ - 1; i > 0; i--)
    {
        for (size_t j = 0; j < i; j++)
        {
            if (elems_[j + 1] < elems_[j])
            {
                int tmp = elems_[j + 1];
                elems_[j + 1] = elems_[j];
                elems_[j] = tmp;
            }
        }
    }
}

bool MyIntContainer::is_sorted() const
{
    for (size_t i = 1; i < current_size_; i++)
    {
        if (!(elems_[i - 1] <= elems_[i]))
        {
            return false;
        }
    }

    return true;
}