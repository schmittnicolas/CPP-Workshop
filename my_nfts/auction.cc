#include "auction.hh"

Auction::Auction(Person& organizer, NFT nft, uint initial_bid)
    : organizer_(organizer)
    , nft_(std::move(nft))
    , highest_bidder_(nullptr)
    , highest_bid_(initial_bid)
{
    if (nft_ == nullptr)
    {
        throw std::invalid_argument("nft cannot be null");
    }
}

Auction::~Auction()
{
    if (highest_bidder_ == nullptr)
    {
        organizer_.add_nft(std::move(nft_));
    }
    else
    {
        NFT nft = organizer_.remove_nft(*nft_);
        highest_bidder_->add_nft(std::move(nft_));
        organizer_.add_money(highest_bid_);
    }
}

bool Auction::bid(Person& person, uint money)
{
    if (money <= highest_bid_ || !person.remove_money(money))
        return false;

    if (highest_bidder_ != nullptr)
    {
        highest_bidder_->add_money(highest_bid_);
    }

    highest_bidder_ = &person;
    highest_bid_ = money;

    return true;
}

std::string Auction::get_nft_name() const
{
    if (nft_ == nullptr)
        return "";
    return *nft_;
}

uint Auction::get_highest_bid() const
{
    return highest_bid_;
}
