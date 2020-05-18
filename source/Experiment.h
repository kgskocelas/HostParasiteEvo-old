/**
 *  @copyright Copyright (C) Katherine Skocelas, MIT Software license; see doc/LICENSE.md
 *  @date 2020.
 *
 *  @file  Experiment.h
 *  @brief Manages host-parasite co-evolution experiment.
 *  @note  Status: BETA
 *
 */

#ifndef EXPERIMENT_H
#define EXPERIMENT_H

#include <iostream>

class Experiment {

    public:
        emp::vector<std::string> args;
        Experiment(emp::vector<std::string> _args);
        void Run();

// run World X number of times

// record results

// results data analysis

};

Experiment::Experiment(emp::vector<std::string> _args) : args(_args) {}; 

void Experiment::Run() {
    std::cout << "Hello, host parasite evolution world!";    
};

#endif //EXPERIMENT_H