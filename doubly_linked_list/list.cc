#include "list.hh"

#include <iostream>

List::List()
    : nb_elts_(0)
    , first_(nullptr)
    , last_(nullptr)
{}

void List::push_front(int i)
{
    std::shared_ptr<Node> node = std::make_shared<Node>(i);
    if (nb_elts_ == 0)
    {
        first_ = node;
        last_ = node;
        node->next_set(nullptr);
        node->prev_set(nullptr);
    }
    else
    {
        node->prev_set(nullptr);
        node->next_set(first_);
        first_->prev_set(node);
        first_ = node;
    }

    nb_elts_++;
}

void List::push_back(int i)
{
    std::shared_ptr<Node> node = std::make_shared<Node>(i);
    if (nb_elts_ == 0)
    {
        first_ = node;
        last_ = node;
        node->next_set(nullptr);
        node->prev_set(nullptr);
    }
    else
    {
        last_->next_set(node);
        node->prev_set(last_);
        node->next_set(nullptr);
        last_ = node;
    }

    nb_elts_++;
}

std::optional<int> List::pop_front()
{
    if (nb_elts_ == 0)
        return std::nullopt;

    if (nb_elts_ == 1)
    {
        nb_elts_--;
        std::shared_ptr<Node> node = first_;
        first_ = nullptr;
        last_ = nullptr;
        return node->val_get();
    }

    nb_elts_--;
    std::shared_ptr<Node> node = first_;
    first_ = first_->next_get();
    return node->val_get();
}

std::optional<int> List::pop_back()
{
    if (nb_elts_ == 0)
        return std::nullopt;

    if (nb_elts_ == 1)
    {
        nb_elts_--;
        std::shared_ptr<Node> node = first_;
        first_ = nullptr;
        last_ = nullptr;
        return node->val_get();
    }

    nb_elts_--;
    std::shared_ptr<Node> node = last_;
    last_ = last_->prev_get();
    return node->val_get();
}

void List::print(std::ostream& os) const
{
    std::shared_ptr<Node> cur = first_;
    for (int i = 0; i < nb_elts_ - 1; i++ && cur != nullptr)
    {
        os << cur->val_get() << " ";
        cur = cur->next_get();
    }

    if (cur != nullptr)
    {
        os << cur->val_get();
    }
}

int List::length() const
{
    return nb_elts_;
}