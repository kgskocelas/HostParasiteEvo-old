/**
 *  @copyright Copyright (C) Katherine Skocelas, MIT Software license; see doc/LICENSE.md
 *  @date 2020.
 *
 *  @file  HostParasiteEvo.cc
 *  @brief Examining the co-evolution of host-parasite evolution
 *  @note Status: BETA
 *
 */

#include "config/command_line.h"

#include "../HostParasiteEvo.h"

int main(int argc, char* argv[])
{
    emp::vector<std::string> args = emp::cl::args_to_strings(argc, argv);
    Experiment experiment(args);
    experiment.Run();  
}
