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
        //resources?
    
    World(emp::vector<Population> _populations) : populations(_populations) {};

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