//
// Created by Paul on 1/22/23.
//

#ifndef POLL_SYSTEM_INIT_VOTE_H
#define POLL_SYSTEM_INIT_VOTE_H
#include <string>
#define TODAY 20230122

class Vote{
protected:
    long int date_of_vote;
public:
    explicit Vote(long int);
    long int get_date();
    virtual bool is_valid();
    virtual std::string vote_to_string() = 0;
 };

#endif //POLL_SYSTEM_INIT_VOTE_H
