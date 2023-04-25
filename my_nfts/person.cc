#include "person.hh"

Person::Person(const std::string& name, uint money)
    : name_(name)
    , money_(money)
    , nfts_()
{}

std::vector<std::string> Person::enumerate_nfts() const
{
    std::vector<std::string> names;

    for (auto& nft : nfts_)
    {
        names.emplace_back(*nft);
    }

    return names;
}

void Person::add_nft(NFT nft)
{
    nfts_.push_back(std::move(nft));
}

NFT Person::remove_nft(const std::string& name)
{
    // size_t i = 0;
    // bool is_removable = false;

    for (auto nft = nfts_.begin(); nft != nfts_.end(); nft++)
    {
        if (*nft != nullptr && **nft == name)
        {
            auto tmp = std::move(*nft);
            nfts_.erase(nft);
            return tmp;
        }
    }

    return create_empty_nft();
}

void Person::add_money(uint money)
{
    money_ += money;
}

bool Person::remove_money(uint money)
{
    if (money > money_)
        return false;

    money_ -= money;
    return true;
}

uint Person::get_money() const
{
    return money_;
}

std::string Person::get_name() const
{
    return name_;
}

std::ostream& operator<<(std::ostream& os, const Person& p)
{
    os << "Name: " << p.get_name() << "\n";
    os << "Money: " << p.get_money() << "\n";

    os << "NFTs:";

    for (const auto& nft : p.enumerate_nfts())
    {
        os << " " << nft;
    }

    os << "\n";
    return os;
}