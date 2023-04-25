#include "parse-csv.hh"

#include <fstream>
#include <iostream>
#include <sstream>

std::vector<std::vector<std::string>> parse_csv(const std::string& file_name)
{
    std::ifstream file_in;
    std::string token;

    file_in.open(file_name);
    if (!file_in.is_open())
    {
        throw std::ios_base::failure("Error opening file");
    }

    std::vector<std::vector<std::string>> lines;
    std::string str_line;

    size_t nb_commas = 0;

    size_t nb_lines = 1;
    while (std::getline(file_in, str_line))
    {
        size_t current_nb_commas = 0;
        for (size_t i = 0; i < str_line.size(); i++)
        {
            if (str_line[i] == ',')
                current_nb_commas++;
        }

        if (nb_lines == 1)
        {
            nb_commas = current_nb_commas;
        }
        else
        {
            if (nb_commas != current_nb_commas)
                throw std::ios_base::failure(
                    "Non consistent number of columns at line "
                    + std::to_string(nb_lines));
        }
        std::istringstream input(str_line);

        std::vector<std::string> vector_line;
        std::string current_word;
        size_t nb_words = 0;
        while (std::getline(input, current_word, ','))
        {
            vector_line.push_back(current_word);
            nb_words += 1;
        }

        nb_lines += 1;

        lines.push_back(vector_line);
    }

    return lines;
}