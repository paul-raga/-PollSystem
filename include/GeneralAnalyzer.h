//
// Created by student on 1/23/23.
//

#ifndef POLL_SYSTEM_INIT_GENERALANALYZER_H
#define POLL_SYSTEM_INIT_GENERALANALYZER_H
#include "Voter.h"
#include "Analyzer.h"
#include "SportsAnalyzer.h"
#include <vector>
#include <memory>
#include <string>

class GeneralAnalyzer{
private:
    std::vector<std::shared_ptr<Voter>> voters_vect;
    std::vector<std::shared_ptr<Analzyer>> analyzer_vect;
public:
    GeneralAnalyzer();
    void add_voter(std::shared_ptr<Voter> new_voter);
    void add_analyzer(std::shared_ptr<Analzyer> new_analyzer);

    double get_sex_percentage(); //operates on Voters

    double get_average_age(); //operates on Voters

    double get_employment_percentage(); //operates on Voters

    void get_winners(); //operates on Analyzers, outputs 2 values: one for sport end one for budgets

    void get_purposes(); //operates on Analyzers, outputs the purpose of each Analyzer

    void get_all_votes();

    void get_no_votes(); //outputs the total number of votes

    void get_all_voters(); //outputs the total number of voters

};


#endif //POLL_SYSTEM_INIT_GENERALANALYZER_H
