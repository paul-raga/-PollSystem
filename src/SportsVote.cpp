//
// Created by Paul on 1/22/23.
//

#include "../include/SportsVote.h"
#include <sstream>


SportsVote::SportsVote(long date, std::string sport, std::string sportsperson, std::string event)
: Vote(date), sport(sport), sportsperson(sportsperson), event(event){
    //option for sportperson:messi, ronaldo, neymar
    //option for event:grand slam, world cup, olympics
    const char* list[3]={"soccer","basket","tennis"};
    int k=0;
    int check=0;
    for (int i=0;i<=2;i++){
        if (sport==list[k]){check++;}
            k++;
    }
    if(check<1 ){throw 1;}

    const char* list2[3]={"messi","ronaldo","neymar"};
    int t=0;
    int check2=0;
    for (int i=0;i<=2;i++){
        if (sportsperson==list2[t]){check2++;}
        t++;
    }
    if(check2<1 ){throw 5;}

    const char* list3[3]={"world cup","olympics","grand slam"};
    int p=0;
    int check3=0;
    for (int i=0;i<=2;i++){
        if (event==list3[p]){check3++;}
        p++;
    }
    //if(check3<1 ){throw 6;}
}



std::string SportsVote::get_sport() {
    return this->sport;
}

std::string SportsVote::get_sportsperson() {
    return this->sportsperson;
}

std::string SportsVote::get_event() {
    return this->event;
}

bool SportsVote::is_valid() {
    if(this->get_date() > TODAY && !this->sport.empty() && !this->sportsperson.empty() && !this->event.empty()){
        return true;
    }else{return false;}
}

std::string SportsVote::vote_to_string() {
    std::ostringstream  outstream;
    outstream << "Date of vote: " << this->get_date() << ", Chosen sport: " <<
              this->get_sport() << ", Chosen event: "<<this->get_event()
    <<", Chosen sportsperson: "<<this->get_sportsperson();
    return outstream.str();
}
