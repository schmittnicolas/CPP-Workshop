#pragma once

#include <fstream>
#include <iomanip>
#include <iostream>
#include <istream>
#include <sstream>
#include <string>

#include "directory-info.hh"

bool read_info(std::istream& file, DirectoryInfo& dir_info);
