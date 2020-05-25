/**
 *  @copyright Copyright (C) Katherine Skocelas, MIT Software license; see doc/LICENSE.md
 *  @date 2020.
 *
 *  @file  Population.h
 *  @brief Manages analysis of a single population.
 *  @note  Status: BETA
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

class World;
class Population {
  // references
  emp::Random & random;
  World & world; 
  const std::string name;

  //organism variables
  emp::vector<Organism> organisms;       ///< All organisms in this population
  bool are_parasites;                    ///< Are the organisms in the population parasites?
  size_t num_organisms = 0;              ///< How many organisms are currently in the population?

  //replication variables
  emp::TimeQueue<size_t> organism_queue; ///< Organisms waiting to replicate.
  size_t time_range = 50.0;              ///< Replication takes 100.0 + a random value up to time_range.
  size_t genome_size = 100;              ///< How many bits in genome?
  double mutation_probability = 0.0;     ///< Probability of an offspring being mutated.

  public:
    // constructor
    Population(const std::string & _name, emp::Random & _random, World & _world, size_t _initial_pop_size = 0, bool _are_parasites = false) 
    : random(_random), world(_world), name(_name), organism_queue(_initial_pop_size) 
    { 

      size_t initial_pop_size = _initial_pop_size;
      are_parasites = _are_parasites;

      // create starting organisms & add to population
      for (int org_count = 0; org_count <= initial_pop_size; org_count++) {
        // 1. create organism 
        // 2. add to population
        // 3. place in world 
      }

  }

};

#endif ///POPULATION_H