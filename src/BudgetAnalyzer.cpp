//
// Created by Paul on 1/23/23.
//
#include "../include/BudgetAnalyzer.h"
#include <sstream>


BudgetAnalyzer::BudgetAnalyzer(std::string p): purpose(p){
}

void BudgetAnalyzer::add_vote(std::shared_ptr<BudgetVote> new_vote) {
this->budget_vect.push_back(new_vote);
}

std::string BudgetAnalyzer::get_vote(int n) {
    //std::ostringstream outstream;
    //outstream << this->budget_vect.at(n)->get_date() << " " << this->budget_vect.at(n)->get_infrastructure() << " " << this->budget_vect.at(n)->get_medCare() << " " << this->budget_vect.at(n)->get_tourism() << " " << this->budget_vect.at(n)->get_culture();
    return budget_vect.at(n)->vote_to_string();
}

std::string BudgetAnalyzer::get_purpose() {
    return this->purpose;
}

int BudgetAnalyzer::get_no_votes() {
    return this->budget_vect.size();
}

std::string BudgetAnalyzer::get_winner() {
    double cult=0;
    double med=0;
    double tour=0;
    double infra=0;
    for(int i=0;i<this->budget_vect.size();i++){
        cult=cult+this->budget_vect.at(i)->get_culture();
        med=med+this->budget_vect.at(i)->get_medCare();
        tour=tour+this->budget_vect.at(i)->get_tourism();
        infra=infra+this->budget_vect.at(i)->get_infrastructure();
    }
    int arr[4];
    arr[0]=cult;
    arr[1]=med;
    arr[2]=tour;
    arr[3]=infra;
    double max=cult;
    for(int i=0;i<4;i++){
        if(max<=arr[i]){max=arr[i];}
    }
    if(max==cult){return "Culture";}
    if(max==med){return "MedicalCare";}
    if(max==tour){return "Tourism";}
    if(max==infra){return "Infrastructure";}

}
