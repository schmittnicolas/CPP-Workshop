#pragma once

#include <string>

struct ContactDetails
{
    ContactDetails(const std::string& telephone_number,
                   const std::string& personal_email);
    std::string number;
    std::string email;
};

std::ostream& operator<<(std::ostream& os, const ContactDetails& cd);
