/**
 *  @copyright Copyright (C) Katherine Skocelas, MIT Software license; see doc/LICENSE.md
 *  @date 2020.
 *
 *  @file  Organism.h
 *  @brief Manages analysis of a single organism.
 *  @note  Status: BETA
 *
 *  Organisms are either HOSTS or PARASITES.
 *  - Hosts collect resources from the world.
 *  - Parasites collect resources from hosts.
 */

#ifndef ORGANISM_H
#define ORGANISM_H

// #include "base/vector.h"
#include "tools/Random.h"
// #include "tools/stats.h"
// #include "tools/TimeQueue.h"

/// Information about a single organism
class Organism {

  public:
    Organism(bool _is_parasite, const size_t _organism_type, emp::Random & _random);
    size_t GetId();
    std::bitset<100> GetGenome();
    bool IsParasite();
    double GetReproTime();

  private:
    emp::Random & random;

    /// class variables
    size_t id;
    std::bitset<100> genome;
    const size_t organism_type;
    bool is_parasite = false;
    double repro_time = 0.0;  ///< When will this organism replicate?n 

  /// operators
  bool operator==(const Organism & _in) const { return id == _in.id; } ///< When using == on Organisms, compare their id's
  bool operator!=(const Organism & _in) const { return id != _in.id; } ///< When using != on Organisms, compare their id's
  bool operator<(const Organism & _in) const {                         ///< When using < on Organisms, compare their repro_time's
    if (repro_time == _in.repro_time) return (id < _in.id);
    return (repro_time < _in.repro_time);
  }
  
};

/// constructor
Organism::Organism(bool _is_parasite, const size_t _organism_type, emp::Random & _random) : random(_random),  organism_type(_organism_type), is_parasite(_is_parasite)  {

  switch(organism_type) {
    case (1) :
      /// setup random genome
      break;
    case (2) :
      /// setup random genome
      break;
    default : 
      /// throw an exception
      ;
  }
  
  if (is_parasite) {
    /// parasite-specific setup
    
   }
  else {
      /// host-specific setup
  }

}

/// getters & setters
size_t Organism::GetId() { return id; }
std::bitset<100> Organism::GetGenome() {return genome; }
bool Organism::IsParasite() { return is_parasite; }
double Organism::GetReproTime() { return repro_time; }

#endif ///ORGANSIM_H