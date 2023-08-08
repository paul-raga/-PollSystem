//
// Created by Paul on 1/23/23.
//

#include "../include/GeneralAnalyzer.h"
#include <iostream>
#include <sstream>
#include <utility>

GeneralAnalyzer::GeneralAnalyzer() {}

void GeneralAnalyzer::add_voter(std::shared_ptr<Voter> new_voter) {
this->voters_vect.push_back(new_voter);
}

void GeneralAnalyzer::add_analyzer(std::shared_ptr<Analzyer> new_analyzer) {
    if(2 * voters_vect.size() > analyzer_vect.size()){
        this->analyzer_vect.push_back(new_analyzer);
        std::cout<<"Vote successfully added"<<std::endl;
    }
    else{
        std::cout<<"Add a voter to add new votes"<<std::endl;
    }
}

double GeneralAnalyzer::get_sex_percentage() {
    double male=0;
    double female=0;
    for(int i=0;i<this->voters_vect.size();i++){
        if(this->voters_vect.at(i)->get_sex() == 'M'){male++;}else
        {if(this->voters_vect.at(i)->get_sex() == 'F'){female++;}else
            {std::cout<<"sex input error"<<std::endl;}}
    }
    male=(male/this->voters_vect.size())*100;
    female=(female/this->voters_vect.size())*100;

    std::cout<<"Percentage of males: "<<male<<"%"<<std::endl;
    std::cout<<"Percentage of females: "<<female<<"%"<<std::endl;
    if (male>female){return male;}else{
        return female;
    }
}

double GeneralAnalyzer::get_average_age() {
    double average=0;
    for(int i=0;i<this->voters_vect.size();i++){
        average= average + this->voters_vect.at(i)->get_age();
    }
    std::cout<<"Average age of voters: "<<average/this->voters_vect.size()<<std::endl;
    return average/this->voters_vect.size();
}

double GeneralAnalyzer::get_employment_percentage() {
    double count=0;
    for(int i=0;i<this->voters_vect.size();i++){
        if(this->voters_vect.at(i)->get_employed()){count++;}
    }
    std::cout<<"Employed voters: "<<(count/this->voters_vect.size())*100<<"%"
    <<std::endl<<"Unemployed voters: "<<100-((count/this->voters_vect.size())*100)<<"%"<<std::endl;
    return (count/this->voters_vect.size())*100;
}


void GeneralAnalyzer::get_winners() {
int tennisCount=0;
int basketCount=0;
int soccerCount=0;

int messiCount = 0;
int ronaldoCount = 0;
int neymarCount = 0;

int granCount = 0;
int worldCount = 0;
int olyCount = 0;

int cultureCount=0;
int medCount=0;
int infraCount=0;
int tourCount=0;

for(int i=0;i<this->analyzer_vect.size();i++){
    std::istringstream iss(analyzer_vect.at(i)->get_winner());
    std::string sport, sportsperson, event;
    int space1 = iss.str().find(' ');
    int space2 = iss.str().find(' ',space1+1);
    sport = iss.str().substr(0,space1);
    sportsperson = iss.str().substr(space1+1,space2-space1-1);
    event = iss.str().substr(space2+1);
    if(sport == "soccer"){soccerCount++;};
    if(sport == "basket"){basketCount++;};
    if(sport == "tennis"){tennisCount++;};
    if(sportsperson == "messi"){messiCount++;}
    if(sportsperson == "ronaldo"){ronaldoCount++;}
    if(sportsperson == "neymar"){neymarCount++;}
    if(event == "world cup"){worldCount++;}
    if(event == "grand slam"){granCount++;}
    if(event == "olympics"){olyCount++;}
    if(this->analyzer_vect.at(i)->get_winner() == "Culture"){cultureCount++;};
    if(this->analyzer_vect.at(i)->get_winner() == "MedicalCare"){medCount++;};
    if(this->analyzer_vect.at(i)->get_winner() == "Infrastructure"){infraCount++;};
    if(this->analyzer_vect.at(i)->get_winner() == "Tourism"){tourCount++;};
}

if(soccerCount>basketCount && soccerCount>tennisCount){
    std::cout<<"Sports All Time Winner: soccer"<<std::endl;
}
else if(basketCount>soccerCount && basketCount>tennisCount){
        std::cout<<"Sports All Time Winner: basket"<<std::endl;
}
else if(tennisCount>soccerCount && tennisCount>basketCount){
        std::cout<<"Sports All Time Winner: tennis"<<std::endl;
}

if(messiCount>ronaldoCount && messiCount>neymarCount){
    std::cout<<"Sportsperson All Time Winner: messi"<<std::endl;
}
else if(ronaldoCount>messiCount && ronaldoCount>neymarCount){
    std::cout<<"Sportsperson All Time Winner: ronaldo"<<std::endl;
}
else if(neymarCount>messiCount && neymarCount>ronaldoCount){
    std::cout<<"Sportsperson All Time Winner: neymar"<<std::endl;
}

if(worldCount>olyCount && worldCount>granCount){
    std::cout<<"Event All Time Winner: world cup"<<std::endl;
}
else if(olyCount>worldCount && olyCount>granCount){
    std::cout<<"Event All Time Winner: olympic games"<<std::endl;
}
else if(granCount>worldCount && granCount>olyCount){
    std::cout<<"Event All Time Winner: grand slam"<<std::endl;
}

if(cultureCount>medCount && cultureCount>infraCount && cultureCount>tourCount){
    std::cout<<"Budget All Time Winner: culture"<<std::endl;
}
if(medCount>cultureCount && medCount>infraCount && medCount >tourCount){
    std::cout<<"Budget All Time Winner: medical care"<<std::endl;
}
if(infraCount>medCount && infraCount>cultureCount && infraCount>tourCount){
    std::cout<<"Budget All Time Winner: infrastructure"<<std::endl;
}
if(tourCount>infraCount && tourCount>medCount && tourCount>cultureCount){
    std::cout<<"Budget All Time Winner: tourism"<<std::endl;
}
}

void GeneralAnalyzer::get_purposes() {
for(int i=0;i<this->analyzer_vect.size();i++){
    std::cout << this->analyzer_vect.at(i)->get_purpose() << std::endl;
}
}

void GeneralAnalyzer::get_all_votes(){
    for(int i=0;i<this->analyzer_vect.size();i++){
        for(int j=0; j<this->analyzer_vect.at(i)->get_no_votes();j++){
            std::cout <<this->analyzer_vect.at(i)->get_vote(j)<<std::endl;
        }

    }
}

void GeneralAnalyzer::get_no_votes() {
int counter =0;
for(int i=0;i<this->analyzer_vect.size();i++){
    counter=counter + this->analyzer_vect.at(i)->get_no_votes();
}
std::cout<<"Number of votes: "<<counter<<std::endl;
}

void GeneralAnalyzer::get_all_voters() {
std::cout<<"Number of voters: "<<this->voters_vect.size()<<std::endl;
}

