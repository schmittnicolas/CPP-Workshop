#include "ciutils/ciutils.hh"

#include <iostream>
#include <string>
#include <vector>
#include <yaml-cpp/yaml.h>

namespace CIUtils
{

    CIData parse_ci_file(const std::string& filename)
    {
        CIData data;

        YAML::Node config = YAML::LoadFile(filename);
        data.stages = config["stages"].as<std::vector<std::string>>();

        for (const auto& node : config)
        {
            // For each node in config, parse the stage and scripts using the
            // job name as first key.
            auto job = node.first.as<std::string>();

            // Skip the "stages" job as it is a special gitlab yaml node that we
            // have previously parsed.
            if (job == "stages")
                continue;

            // Retrieves the stage field of the job key.
            auto stage = config[job]["stage"];

            // Create the job struct and set the name, stage, and scripts
            // variables accordingly
            Job job_to_add;
            job_to_add.name = job;
            job_to_add.stage = stage.as<std::string>();
            data.jobs.push_back(job_to_add);

            auto script = config[job]["script"];
            for (const auto& command : script)
            {
                std::string str_cmd = command.as<std::string>();
                std::string str_cmd_first_cmd = str_cmd.substr(0, str_cmd.find(" "));
                data.commands.insert(str_cmd_first_cmd);
            }
            
        }

        return data;
    }
} // namespace CIUtils
