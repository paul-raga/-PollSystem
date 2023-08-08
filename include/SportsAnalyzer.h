//
// Created by student on 1/22/23.
//

#ifndef POLL_SYSTEM_INIT_SPORTSANALYZER_H
#define POLL_SYSTEM_INIT_SPORTSANALYZER_H
#include "Analyzer.h"
#include "SportsVote.h"
#include <vector>
#include <memory>

class SportsAnalyzer : public Analzyer{
private:
    std::vector<std::shared_ptr<SportsVote>> vote_vect;
    std::string purpose;
public:
    explicit SportsAnalyzer(std::string p); //added string purpose as parameter to constructor
    void add_vote(std::shared_ptr<SportsVote> vote);
    std::string get_winner() override; //returns the most voted sport as string
    std::string get_vote(int n) override; //return the vote at position n in the vector (never used)
    std::string get_purpose() override; //returns the purpose of the poll
    int get_no_votes() override; //return the total number of votes
};



#endif //POLL_SYSTEM_INIT_SPORTSANALYZER_H
