//
// Created by student on 1/22/23.
//

#ifndef POLL_SYSTEM_INIT_SPORTSVOTE_H
#define POLL_SYSTEM_INIT_SPORTSVOTE_H
#include "Vote.h"

class SportsVote : public Vote{
private:
    std::string sport;
    std::string sportsperson;
    std::string event;
public:
    SportsVote(long int date,std::string sport,std::string sportsperson, std::string event);
    std::string get_sport();
    std::string get_sportsperson();
    std::string get_event();
    bool is_valid() override;
    std::string vote_to_string() override;
};

#endif //POLL_SYSTEM_INIT_SPORTSVOTE_H
