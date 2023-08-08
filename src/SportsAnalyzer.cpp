//
// Created by student on 1/22/23.
//

#include "../include/SportsAnalyzer.h"
#include <iostream>
#include <sstream>

SportsAnalyzer::SportsAnalyzer(std::string p): purpose(p){
}

void SportsAnalyzer::add_vote(std::shared_ptr<SportsVote> vote) {
this->vote_vect.push_back(vote);
}

std::string SportsAnalyzer::get_winner() {
    std::ostringstream outstream;
    std::string winners[3];
    int soccer=0;
    int tennis=0;
    int basket=0;
    for(int i=0;i<this->vote_vect.size();i++){
        if(this->vote_vect.at(i)->get_sport()=="soccer"){soccer++;}else{
            if (this->vote_vect.at(i)->get_sport()=="tennis"){tennis++;}else{
                if(this->vote_vect.at(i)->get_sport()=="basket"){basket++;}else{
                    std::cout<<"error, a wrong sport was inserted"<<std::endl;
                }
            }
        }
    }
    if(soccer>tennis && soccer>basket){outstream << "soccer ";}
    if(tennis>soccer && tennis>basket){outstream << "tennis ";}
    if(basket>soccer && basket>tennis){outstream << "basket ";}

    int messiCount = 0;
    int ronaldoCount = 0;
    int neymarCount = 0;
    for (int i=0;i<this->vote_vect.size();i++){
        if(this->vote_vect.at(i)->get_sportsperson()=="messi"){messiCount++;}
        if(this->vote_vect.at(i)->get_sportsperson()=="ronaldo"){ronaldoCount++;}
        if(this->vote_vect.at(i)->get_sportsperson()=="neymar"){neymarCount++;}
    }
    if(messiCount>ronaldoCount && messiCount>neymarCount){outstream << "messi ";}
    if(ronaldoCount>messiCount && ronaldoCount>neymarCount){outstream << "ronaldo ";}
    if(neymarCount>messiCount && neymarCount>ronaldoCount){outstream << "neymar" ;}

    int granCount = 0;
    int worldCount = 0;
    int olyCount = 0;
    for (int i=0;i<this->vote_vect.size();i++){
        if(this->vote_vect.at(i)->get_event()=="world cup"){worldCount++;}
        if(this->vote_vect.at(i)->get_event()=="grand slam"){granCount++;}
        if(this->vote_vect.at(i)->get_event()=="olympics"){olyCount++;}
    }
    if(olyCount>granCount && olyCount>worldCount){outstream << "olympics";}
    if(worldCount>granCount && worldCount>olyCount){outstream << "world cup";}
    if(granCount>worldCount && granCount>olyCount){outstream <<"grand slam";}

    return outstream.str();
}

std::string SportsAnalyzer::get_vote(int n) {
    std::ostringstream outstream;
    outstream<<this->vote_vect.at(n)->vote_to_string();
    return outstream.str();
}

std::string SportsAnalyzer::get_purpose() {
    return this->purpose;
}

int SportsAnalyzer::get_no_votes() {
    return this->vote_vect.size();
}
