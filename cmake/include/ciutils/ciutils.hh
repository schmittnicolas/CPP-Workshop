#pragma once

#include <set>
#include <string>
#include <vector>

namespace CIUtils
{
    struct Job
    {
        std::string name;
        std::string stage;
    };

    struct CIData
    {
        std::vector<Job> jobs;
        std::vector<std::string> stages;
        std::set<std::string> commands;
    };

    CIData parse_ci_file(const std::string& path);
} // namespace CIUtils
