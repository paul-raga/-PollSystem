//
// Created by Paul on 1/22/23.
//
#include "../include/Voter.h"
#include <iostream>


Voter::Voter(char sex, int age, bool is_employed):
sex(sex), age(age), is_employed(is_employed) {
}

char Voter::get_sex() {
    return this->sex;
}

int Voter::get_age() {
    return this->age;
}

bool Voter::get_employed() {
    return this->is_employed;
}

void Voter::add_vote(std::shared_ptr<Vote> new_vote) {
this->votes_vect.push_back(new_vote);
}

std::string Voter::printVotes() {
std::string total="List of votes: ";
for(int i=0;i<this->votes_vect.size();i++){
    total+=this->votes_vect.at(i)->vote_to_string()+"; ";
}
//std::cout<<total<<std::endl;
return total;
}
