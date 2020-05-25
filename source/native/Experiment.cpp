/**
 *  @copyright Copyright (C) Katherine Skocelas, MIT Software license; see doc/LICENSE.md
 *  @date 2020.
 *
 *  @file  Experiment.cpp
 *  @brief Examining the co-evolution of host-parasite evolution
 *  @note Status: BETA
 *
 */

#include "../Experiment.h"
#include "../Organism.h"
#include "../Population.h"
#include "../World.h"

#include "tools/Random.h"
#include "config/command_line.h"

int main(int argc, char* argv[])
{
    emp::vector<std::string> args = emp::cl::args_to_strings(argc, argv);
    Experiment experiment(args);  
    experiment.Run();    
}
