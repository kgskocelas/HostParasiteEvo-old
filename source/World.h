/**
 *  @copyright Copyright (C) Katherine Skocelas, MIT Software license; see doc/LICENSE.md
 *  @date 2020.
 *
 *  @file  World.h
 *  @brief Manages analysis of a single run in a host-parasite co-evolution world.
 *  @note  Status: BETA
 *
 */

#ifndef WORLD_H
#define WORLD_H

#include "Population.h"

#include "base/vector.h"
#include "tools/Random.h"
#include "tools/stats.h"
#include "tools/TimeQueue.h"

class World {

    //world variables

    //world contents 
    emp::vector<Population> populations;
    emp::Random random;
        //resources?
public:
    World() {}
    void addPopulation(const std::string & population_name, size_t init_size = 0, bool is_parasite = false) {
        populations.emplace_back(population_name, random, *this, init_size, is_parasite);
    }

    /// spatial map of world
    struct WorldMap {

        //map variables

    };

    /// Results from a single run.
    struct RunResults {

        //result variables

    };

};

#endif /// WORLD_H