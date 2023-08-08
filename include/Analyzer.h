//
// Created by student on 1/22/23.
//

#ifndef POLL_SYSTEM_INIT_ANALYZER_H
#define POLL_SYSTEM_INIT_ANALYZER_H
#include "Vote.h"
#include "memory"
#include <string>

class Analzyer{
public:
    virtual void add_vote(std::shared_ptr<Vote> vote);
    virtual std::string get_winner() = 0;
    virtual std::string get_vote(int n) = 0;
    virtual std::string get_purpose() = 0;
    virtual int get_no_votes() = 0;

};

#endif //POLL_SYSTEM_INIT_ANALYZER_H
