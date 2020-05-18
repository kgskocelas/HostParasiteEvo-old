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

class Population {
  // references
  emp::Random & random;
  World & world; 

  //organism variables
  emp::vector<Organism> organisms;       ///< All organisms in this population
  const organism_type;                   ///< What type of organisms make up the population
  bool are_parasites;                    ///< Are the organisms in the population parasites?
  size_t num_organisms = 0;              ///< How many organisms are currently in the population?

  //replication variables
  emp::TimeQueue<size_t> organism_queue; ///< Organisms waiting to replicate.
  size_t time_range = 50.0;              ///< Replication takes 100.0 + a random value up to time_range.
  size_t genome_size = 100;              ///< How many bits in genome?
  double mutation_probability = 0.0;     ///< Probability of an offspring being mutated.

  // constructor
  Population(size_t initial_pop_size, const organism_type, bool are_parasites, emp::Random & _random, World & _world) : random(_random), world(_world), organism_queue(initial_pop_size) { 
    
    this.organism_type = organism_type;
    this.are_parasites = are_parasites;

    // create starting organisms & add to population
    for (int org_count = 0; orgCount <= initial_pop_size; org_count) {
      // 1. create organism 
      // 2. add to population
      // 3. place in world 
    }

  }

};

#endif ///POPULATION_H