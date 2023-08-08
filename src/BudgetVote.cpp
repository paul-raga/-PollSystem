//
// Created by student on 1/22/23.
//
#include "../include/BudgetVote.h"
#include <sstream>


BudgetVote::BudgetVote(long int date, double infra, double med_care, double tourism, double culture)
: Vote(date), infrastructure(infra), medical_care(med_care), tourism(tourism), culture(culture) {
this->distribution[0]=infra;
this->distribution[1]=med_care;
this->distribution[2]=tourism;
this->distribution[3]=culture;
}



bool BudgetVote::is_valid() {
    if(this->get_date() > TODAY && (this->get_culture() + this->get_infrastructure() + this->get_medCare() + this->get_tourism()) == 100){
        return true;
    }else{return false;}
}

double BudgetVote::get_infrastructure() {
    return this->infrastructure;
}

double BudgetVote::get_medCare() {
    return this->medical_care;
}

double BudgetVote::get_tourism() {
    return this->tourism;
}

double BudgetVote::get_culture() {
    return this->culture;
}

std::string BudgetVote::vote_to_string() {
    std::ostringstream outstream;
    outstream <<"Date of vote: "<< this->get_date() <<
    ", Infrastructure %: " << this->get_infrastructure() <<
    ", Medical care %: " << this->get_medCare() <<
    ", Tourism %: " << this->get_tourism() <<
    ", Culture %: " << this->get_culture() << std::endl;
    return outstream.str();
}

std::string BudgetVote::get_distribution() {
    std::ostringstream outstream;
    outstream<<"Budget distribution: "<<std::endl<<this->get_infrastructure()<<"% infrastructure"<<std::endl<<
    this->get_medCare()<<"% medical care"<<std::endl<<this->get_culture()<<"% culture"<<std::endl<<
    this->get_tourism()<<"% tourism"<<std::endl;
    return outstream.str();
}




