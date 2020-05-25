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
#include "../Organism.h"
#include "../Population.h"
#include "../World.h"
// #include "../Experiment.h"

#include "tools/Random.h"

int main(int argc, char* argv[])
{
    emp::vector<std::string> args = emp::cl::args_to_strings(argc, argv);
    Experiment experiment(args);
    experiment.Run();  

    //test objects
    emp::Random random = emp::Random();
    Organism org = Organism(true, 1, random);
    World world;
    world.addPopulation("fleas");
    world.addPopulation("cats");
    world.addPopulation("dogs");
    
}
