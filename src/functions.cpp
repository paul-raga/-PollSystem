//
// Created by eryk on 1/30/23.
//
#include <iostream>
#include "Voter.h"

void display_menu(){
    std::cout
    <<"    Menu:   "<<std::endl
    <<"1. Create a voter"<<std::endl
    <<"2. Create a vote"<<std::endl
    <<"3. Display summary"<<std::endl
    <<"4. Get detailed info"<<std::endl
    <<"5. Exit"<<std::endl;
}

void display_detailed_menu(){
    std::cout
    <<"Choose a statistic you want to see:"<<std::endl
    <<"1. Display average age"<<std::endl
    <<"2. Display sex percentages"<<std::endl
    <<"3. Display employment percentages"<<std::endl
    <<"4. Display polls' winners"<<std::endl
    <<"5. Display polls' purposes"<<std::endl
    <<"6. Display number of votes"<<std::endl
    <<"7. Display number of voters"<<std::endl
    <<"8. Display all votes"<<std::endl;
}
