//
// Created by Paul on 1/22/23.
//
#include "../include/Vote.h"
#include <sstream>


Vote::Vote(long int date) : date_of_vote(date) {
}

long int Vote::get_date() {
    return this->date_of_vote;
}

bool Vote::is_valid() {
    if(this->date_of_vote>TODAY){
        return true;
    }else{return false;}
}
