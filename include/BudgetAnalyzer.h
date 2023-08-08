//
// Created by student on 1/23/23.
//

#ifndef POLL_SYSTEM_INIT_BUDGETANALYZER_H
#define POLL_SYSTEM_INIT_BUDGETANALYZER_H
#include "Analyzer.h"
#include "BudgetVote.h"
#include "vector"
#include "memory"

class BudgetAnalyzer : public Analzyer{
private:
    std::vector<std::shared_ptr<BudgetVote>> budget_vect;
    std::string purpose;
public:
    explicit BudgetAnalyzer(std::string p); //added purpose as parameter to constructor
    void add_vote(std::shared_ptr<BudgetVote> new_vote);
    std::string get_winner() override; //return the most voted investment choice as string
    std::string get_vote(int n) override; //returns the vote at position n (never used)
    std::string get_purpose() override; //returns the purpose of the analysis
    int get_no_votes() override; //returns the total number of votes

    //method to output the average distribution of budgets can be added (to use the array of distribution)

};

#endif //POLL_SYSTEM_INIT_BUDGETANALYZER_H
