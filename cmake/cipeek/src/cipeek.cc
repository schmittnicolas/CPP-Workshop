#include <ciutils/ciutils.hh>
#include <iostream>

int main(int argc, char *argv[])
{
    if (argc != 2)
        return 1;

    // Parsing the file
    std::string filename = argv[1];
    CIUtils::CIData data = CIUtils::parse_ci_file(filename);


    // Printing the content
    std::cout << "stages(" << data.stages.size() << "):\n";
    for (const auto& stage : data.stages)
        std::cout << "  "<< stage << '\n';

    std::cout << "\n";
    std::cout << "jobs(" << data.jobs.size() << "):\n";
    for (const auto& job : data.jobs)
        std::cout << "  " << job.name << " (" << job.stage << ")\n";

    std::cout << "\n";
    std::cout << "commands(" << data.commands.size() << "):\n";
    for (const auto& command : data.commands)
        std::cout << "  " << command << '\n';

    return 0;
}
