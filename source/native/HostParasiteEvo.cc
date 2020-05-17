/**
 *  @copyright Copyright (C) Katherine Skocelas, MIT Software license; see doc/LICENSE.md
 *  @date 2020.
 *
 *  @file  HostParasiteEvo.cc
 *  @brief Examining the co-evolution of host-parasite evolution
 *  @note Status: BETA
 *
 */

#include <iostream>

#include "config/command_line.h"

#include "../HostParasiteEvo.h"

int main(int argc, char* argv[])
{
    emp::vector<std::string> args = emp::cl::args_to_strings(argc, argv);
    std::cout << "Hello host parasite evolution world!";
//   Experiment experiment(args);
//   experiment.Run();
}
