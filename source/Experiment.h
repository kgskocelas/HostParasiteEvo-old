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

#include "config/command_line.h"
#include "config/SettingCombos.h"

#include "tools/StreamManager.h"
#include "tools/string_utils.h"
#include "tools/vector_utils.h"

#include "World.h"

class Experiment {

    public:
        emp::vector<std::string> args;

        emp::Random random;
        emp::SettingCombos combos;
        std::string exe_name;      ///< Name of executable used to start this run.
        World world;

        size_t gen_count = 0;             ///< Num generations to evolve (zero for analyze worlds)
        size_t pop_size = 200;            ///< Num organisms in the population.
        size_t sample_size = 100;         ///< Num worlds to sample for each genotype.
        bool reset_cache = false;         ///< Share the cache by default.
        bool print_reps = false;          ///< Should we print results for every replicate?
        bool print_trace = false;         ///< Should we show each step of a world?
        bool verbose = false;             ///< Should we print extra information during the run?
        bool enforce_data_bounds = false;  ///< If we are using pre-gen data and needed missing data, exit?

        emp::StreamManager stream_manager;  ///< Manage files
        std::string evolution_filename;     ///< Output filename for evolution summary data.
        std::string world_filename;     ///< Output filename for world summary data.
        std::string sample_input_directory; ///< Path that contains X.dat files to load in as samples where X is a value for ancestor_1s

        using TreatmentResults = emp::vector<RunResults>;
        using WorldResults = emp::vector<TreatmentResults>;

        WorldResults base_results;

        Experiment(emp::vector<std::string> _args) : args(_args) {
            exe_name = args[0];

            // Setup all command-line options that the system should use.  In general, lower-case
            // letters are used to control model parameters, while capital letters are used to control
            // output.  The one exception is -h for '--help' which is otherwise too standard.
            // The order below sets the order that combinations are tested in. 
            // AVAILABLE OPTION FLAGS: fjklqwxyz ABCDFGHIJKNOQRSUVWXYZ

            // combos.AddSetting("time_range", "Rep time = 100.0 + random(time_range)", 't',
            //                 world.time_range, "TimeUnits...") = { 50 };
            // combos.AddSetting("neighbors",  "Neighborhood size for replication", 'n',
            //                 world.neighbors, "Sizes...") = { 8 };
            // combos.AddSetting("cells_side", "Cells on side of (square) world", 'c',
            //                 world.cells_side, "NumCells...") = { 32 };
            // combos.AddSetting("bit_size",   "Number of bits in genome?", 'b',
            //                 world.genome_size, "NumBits...") = { 100 };
            // combos.AddSetting("restrain",   "Num ones in genome for restraint?", 'r',
            //                 world.restrain, "NumOnes...") = { 50 };
            // combos.AddSetting("ancestor_1s", "How many 1s in starting cell?", 'a',
            //                 world.start_1s, "NumOnes...") = { 50 };
            // combos.AddSetting("mut_prob",   "Probability of mutation in offspring", 'm',
            //                 world.mut_prob, "Probs...") = { 0.0 };
            // combos.AddSetting("unrestrained_cost", "Per-cell cost for unrestrained", 'u',
            //                 world.unrestrained_cost, "Costs...") = { 0.0 };
            combos.AddSetting<size_t>("data_count", "Number of times to replicate each run", 'd') = { 100 };
            // combos.AddAction("one_check", "Make restrained check only one cell to find empty.", 'o',
            //                 [this](){ world.one_check = true; } );

            combos.AddSingleSetting("gen_count",   "Num generations to evolve (0=analyze only)", 'g',
                            gen_count, "NumGens") = { 0 };
            combos.AddSingleSetting("pop_size",    "Number of organisms in the population.", 'p',
                            pop_size, "NumOrgs") = { 200 };
            combos.AddSingleSetting("sample_size", "Num worlds sampled for distributions.", 's',
                            sample_size, "NumSamples") = { 200 };
            combos.AddSingleSetting("load_samples", "Load pre-computer world data from directory", 'L',
                            sample_input_directory, "Path") = {"" };
                            

            combos.AddAction("help", "Print full list of options", 'h',
                            [this](){
                            combos.PrintHelp(exe_name, " -n 0,4,8 -r 0,1 -t 4,8,16,32 -d 100");
                            exit(1);
                            } );
            combos.AddSingleSetting("evolution_filename", "Filename for world data", 'E',
                                    evolution_filename, "Filename") = { "evolution.dat" };
            combos.AddAction("independent_caches", "Use a distinct cache for each run", 'i',
                            [this](){ reset_cache = true; } );
            combos.AddSingleSetting("world_filename", "Filename for world data", 'M',
                                    world_filename, "Filename") = { "world.dat" };
            combos.AddAction("print_reps", "Print data for each replicate", 'P',
                            [this](){ print_reps = true; } );
            combos.AddAction("trace", "Show each step of replicates (world or population)", 'T',
                            [this](){ print_trace = true; } );
            combos.AddAction("verbose", "Print extra information during the run", 'v',
                            [this](){ verbose = true; } );
            combos.AddAction("enforce", "Enforeces population stays within bounds of data loaded with -L. Exits if boudns exceeded", 'e',
                            [this](){ enforce_data_bounds= true; } );

            // Process the command-line options
            args = combos.ProcessOptions(args);

            // Fail if there are any unknown args.
            if (args.size()) {
            std::cerr << "ERROR: Unknown options: " << emp::to_string(args) << "\n";
            exit(2);
            }
        }; 

        emp::vector<Population> populations;

        void Run() {
            
            emp::Random random = emp::Random();

            //1. initilize world
            World world;
        
            //2. initialize populations & add to world
            world.addPopulation("fleas");
            world.addPopulation("cats");
            world.addPopulation("dogs");

            //4. run experiement
            std::cout << "Hello, host parasite evolution world!";    
        }

};

#endif //EXPERIMENT_H