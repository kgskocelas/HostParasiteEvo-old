
/**
 *  @copyright Copyright (C) Katherine Skocelas, MIT Software license; see doc/LICENSE.md
 *  @date 2020.
 *
 *  @file  HostParasiteEvo.h
 *  @brief Manages analysis of host-parasite co-evolution.
 *  @note  Status: BETA
 *
 */

#include "Population.h"
#include "World.h"
#include "Experiment.h"

#include "base/vector.h"
#include "tools/Random.h"

#ifndef HOST_PARASITE_EVO_H
#define HOST_PARASITE_EVO_H

class HostParasiteEvo {

    emp::Random & random;

    /// variables
    World & world;
    emp::vector<Population> populations;

    HostParasiteEvo(emp::Random & _random, World & _world) : random(_random), world(_world) {
        //1. initilize world
        //2. initialize populations
        //3. add populations to world
        //4. run experiement
    }

};
#endif ///HOST_PARASITE_EVO_H