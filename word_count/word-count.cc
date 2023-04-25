#include "word-count.hh"

#include <fstream>

ssize_t word_count(const std::string& filename)
{
    ssize_t nb_words = 0;

    std::ifstream file_in;
    std::string token;

    file_in.open(filename);
    if (!file_in.is_open())
    {
        return -1;
    }

    // Read until eof or an error occurs
    while (file_in >> token)
        nb_words++;

    file_in.close();
    // Or we could wait the end of the main's scope, file_in would be closed
    // automatically

    return nb_words;
}
