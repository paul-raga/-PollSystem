//
// Created by student on 1/22/23.
//

#ifndef POLL_SYSTEM_INIT_BUDGETVOTE_H
#define POLL_SYSTEM_INIT_BUDGETVOTE_H
#include "Vote.h"

class BudgetVote : public Vote{
private:
    double infrastructure;
    double medical_care;
    double tourism;
    double culture;
    double distribution[4]; //distrib [0]=infra, [1]=med_care, [2]=tourism, [3]=culture
public:

    BudgetVote(long int date, double infra, double med_care, double tourism, double culture);
    bool is_valid() override;
    std::string vote_to_string() override;
    double get_infrastructure();
    double get_medCare();
    double get_tourism();
    double get_culture();
    std::string get_distribution();

};

#endif //POLL_SYSTEM_INIT_BUDGETVOTE_H
