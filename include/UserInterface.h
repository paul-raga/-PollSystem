//
// Created by eryk on 1/30/23.
//

#ifndef POLL_SYSTEM_INIT_USERINTERFACE_H
#define POLL_SYSTEM_INIT_USERINTERFACE_H

#include <iostream>
#include "GeneralAnalyzer.h"
#include "SportsVote.h"
#include "BudgetVote.h"
#include "SportsAnalyzer.h"
#include "BudgetAnalyzer.h"
#include "functions.h"


class UserInterface{
private:
    GeneralAnalyzer general_analyzer;

public:
    UserInterface();

    void start_interface();

    void create_sports_vote(std::shared_ptr<SportsVote> vote);

    void create_budget_vote(std::shared_ptr<BudgetVote> vote);

    void create_voter(char sex, int age, bool is_employed);

    void display_summary();

    void display_detail(std::string detail);
};

#endif //POLL_SYSTEM_INIT_USERINTERFACE_H
