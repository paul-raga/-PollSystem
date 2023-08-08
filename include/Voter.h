//
// Created by Paul on 1/22/23.
//

#ifndef POLL_SYSTEM_INIT_VOTER_H
#define POLL_SYSTEM_INIT_VOTER_H
#include <string>
#include <vector>
#include <memory>
#include "Vote.h"

class Voter{
private:
    char sex;
    int age;
    std::vector <std::shared_ptr<Vote>> votes_vect;
    bool is_employed;
public:
    Voter(char sex,int age, bool is_employed);
    char get_sex();
    int get_age();
    bool get_employed();
    void add_vote(std::shared_ptr<Vote>);

    std::string printVotes();

};

#endif //POLL_SYSTEM_INIT_VOTER_H
