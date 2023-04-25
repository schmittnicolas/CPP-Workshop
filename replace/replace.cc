#include "replace.hh"

void replace(const std::string& input_filename,
             const std::string& output_filename, const std::string& src_token,
             const std::string& dst_token)
{
    std::ofstream file_out;
    std::ifstream file_in;

    file_out.open(output_filename);
    file_in.open(input_filename);

    if (!file_in.is_open())
    {
        std::cerr << "Cannot open input file\n";
        return;
    }

    if (!file_out.is_open())
    {
        std::cerr << "Cannot write output file\n";
        return;
    }

    size_t src_length = src_token.length();
    size_t dst_length = dst_token.length();

    std::string line;
    while (std::getline(file_in, line))
    {
        size_t current_position = line.find(src_token);
        while (current_position != std::string::npos)
        {
            line.replace(current_position, src_length, dst_token);
            current_position += dst_length;
            current_position = line.find(src_token, current_position);
        }

        file_out << line << '\n';
    }

    file_out.close();
    file_in.close();
}
