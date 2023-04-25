#include "address-book.hh"

bool AddressBook::add(const std::string& full_name, const std::string& email,
                      const std::string& number)
{
    if (full_name.empty())
        return false;

    try
    {
        ContactDetails cd(number, email);
        contact_map_.insert(std::make_pair(full_name, cd));
        return true;
    }
    catch (const std::exception& e)
    {
        return false;
    }
}

std::vector<ContactDetails> AddressBook::find(const std::string& full_name)
{
    std::vector<ContactDetails> contacts;

    auto contact_pairs = contact_map_.equal_range(full_name);
    for (auto contact = contact_pairs.first; contact != contact_pairs.second;
         ++contact)
    {
        contacts.push_back(contact->second);
    }

    return contacts;
}

std::size_t AddressBook::count(const std::string& full_name)
{
    return contact_map_.count(full_name);
}

bool AddressBook::remove(const std::string& full_name, std::size_t index)
{
    auto contacts = contact_map_.equal_range(full_name);

    size_t i = 0;
    for (auto contact = contacts.first; contact != contacts.second; contact++)
    {
        if (i == index)
        {
            contact_map_.erase(contact);
            return true;
        }

        i++;
    }

    return false;
}

void AddressBook::remove_all(const std::string& full_name)
{
    contact_map_.erase(full_name);
}

std::ostream& operator<<(std::ostream& os, const AddressBook& b)
{
    os << b.contact_map_.size() << " contact(s) in the address book.\n";

    for (auto contact : b.contact_map_)
    {
        os << "- " << contact.first << ": " << contact.second;
    }

    return os;
}