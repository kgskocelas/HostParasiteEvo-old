/**
 *  @copyright Copyright (C) Katherine Skocelas, MIT Software license; see doc/LICENSE.md
 *  @date 2020.
 *
 *  @file  Population.h
 *  @brief Manages analysis of a single population.
 *  @note Status: BETA
 *
 *  Populations are either all HOSTS or all PARASITES.
 *  - Hosts collect resources from the world.
 *  - Parasites collect resources from hosts.
 */

#ifndef POPULATION_H
#define POPULATION_H

#include "Organism.h"

#include "base/vector.h"
#include "tools/Random.h"
// #include "tools/stats.h"
#include "tools/TimeQueue.h"

class Population {
  emp::Random & random;

  emp::vector<Organism> organisms;       ///< All organisms in this population
  emp::vector<char> is_full;             ///< Is the local neighborhood full?
  size_t num_organisms = 0;              ///< How many organisms are currently in the population?

  emp::TimeQueue<size_t> organism_queue; ///< Organisms waiting to replicate.

  size_t time_range = 50.0;              ///< Replication takes 100.0 + a random value up to time_range.
  size_t genome_size = 100;              ///< How many bits in genome?
  size_t start_1s = 100;                 ///< How many ones in the starting organism?
  double mutation_probability = 0.0;     ///< Probability of an offspring being mutated.

  Population(emp::Random & _random) : random(_random), organism_queue(100.0) { }
};
#endif ///POPULATION_H