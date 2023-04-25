#include "contact-details.hh"

#include <iostream>

ContactDetails::ContactDetails(const std::string& telephone_number,
                               const std::string& personal_email)
    : number(telephone_number)
    , email(personal_email)
{
    for (auto ch : telephone_number)
    {
        if (ch < '0' || ch > '9')
        {
            throw std::invalid_argument("Incorrect number.");
        }
    }

    if (!(personal_email.find('@') != std::string::npos))
        throw std::invalid_argument("Incorrect email.");
}

std::ostream& operator<<(std::ostream& os, const ContactDetails& cd)
{
    os << cd.number << ", " << cd.email << "\n";
    return os;
}