#include "stdin-to-file.hh"

void stdin_to_file()
{
    std::string token;
    std::ofstream output_file;

    output_file.open("file.out");

    while (std::cin >> token)
        output_file << token << std::endl;
}
