//
// Created by student on 1/30/23.
//

#include <UserInterface.h>

#include <utility>



UserInterface::UserInterface() {
    general_analyzer = GeneralAnalyzer();
}

void UserInterface::start_interface() {
    std::string answer;

    do{
        display_menu();
        std::cin>>answer;
        if(answer == "1"){
            char sex;
            int age;
            bool is_employed;
            std::cout<<"Enter sex (M/F): ";
            std::cin>>sex;
            std::cout<<"Enter age: ";
            std::cin>>age;
            std::cout<<"Enter employment (0/1): ";
            std::cin>>is_employed;
            create_voter(sex,age,is_employed);
            std::cout<<"Voter successfully added"<<std::endl;
        }
        else if(answer == "2"){
            int choice;
            std::cout<<"1. Create a sports vote"<<std::endl<<"2. Create a budget vote"<<std::endl;
            std::cin>>choice;
            if(choice == 1){
                long int date;
                std::string sport, sportsperson, event;
                std::cout<<"Enter date (YYYYMMDD): ";
                std::cin>>date;
                std::cout<<"Enter sport (tennis/basket/soccer): ";
                std::cin>>sport;
                std::cout<<"Enter sportsperson (messi/ronaldo/neymar): ";
                std::cin.ignore();
                std::getline(std::cin, sportsperson, '\n');
                std::cout<<"Enter event (world cup/grand slam/olympics): ";
                //std::cin.ignore();
                std::getline(std::cin, event, '\n');
                std::shared_ptr<SportsVote> new_vote = std::make_shared<SportsVote>(date, sport, sportsperson, event);
                if(new_vote->is_valid()){
                    create_sports_vote(new_vote);
                }
                else{
                    std::cout<<"Invalid vote, try again"<<std::endl;
                }
            }
            else if(choice == 2){
                std::cout<<"All sectors have to add up to 100%"<<std::endl;
                long int date;
                double infra, med_care, tourism, culture;
                std::cout<<"Enter (YYYYMMDD): ";
                std::cin>>date;
                std::cout<<"Enter infrastructure %: ";
                std::cin>>infra;
                std::cout<<"Enter medical care %: ";
                std::cin>>med_care;
                std::cout<<"Enter tourism %: ";
                std::cin>>tourism;
                std::cout<<"Enter culture %: ";
                std::cin>>culture;
                std::shared_ptr<BudgetVote> new_vote = std::make_shared<BudgetVote>(date, infra, med_care, tourism, culture);
                if(new_vote->is_valid()){
                    create_budget_vote(new_vote);
                }
                else{
                    std::cout<<"Invalid vote, try again"<<std::endl;
                }
            }
            else{
                std::cout<<"Wrong input, try again"<<std::endl;
            }
        }
        else if(answer == "3"){
            this->display_summary();
        }
        else if(answer == "4"){
            display_detailed_menu();
            int choice;
            std::cin>>choice;
            switch (choice) {
                case 1:
                    this->display_detail("average_age");
                    break;
                case 2:
                    this->display_detail("sex_percentage");
                    break;
                case 3:
                    this->display_detail("employment_percentage");
                    break;
                case 4:
                    this->display_detail("winner");
                    break;
                case 5:
                    this->display_detail("purpose");
                    break;
                case 6:
                    this->display_detail("no_votes");
                    break;
                case 7:
                    this->display_detail("no_voters");
                    break;
                case 8:
                    this->display_detail("all_votes");
                    break;
            }
        }


    }while(answer != "5");
}

void UserInterface::create_sports_vote(std::shared_ptr<SportsVote> vote) {
    std::shared_ptr<SportsAnalyzer> analyzer = std::make_shared<SportsAnalyzer>("Sports");
    analyzer->add_vote(std::move(vote));
    general_analyzer.add_analyzer(analyzer);

}

void UserInterface::create_budget_vote(std::shared_ptr<BudgetVote> vote) {
    std::shared_ptr<BudgetAnalyzer> analyzer = std::make_shared<BudgetAnalyzer>("Budget");
    analyzer->add_vote(std::move(vote));
    general_analyzer.add_analyzer(analyzer);

}

void UserInterface::create_voter(char sex, int age, bool is_employed) {
    std::shared_ptr<Voter> new_voter = std::make_shared<Voter>(sex, age, is_employed);
    this->general_analyzer.add_voter(new_voter);
}

void UserInterface::display_summary() {
    std::cout<<"Summary and current results: "<<std::endl;
    this->display_detail("average_age");
    this->display_detail("sex_percentage");
    this->display_detail("employment_percentage");
    this->display_detail("winner");
    this->display_detail("no_votes");
    this->display_detail("no_voters");
}

void UserInterface::display_detail(std::string detail) {
    if(detail == "average_age"){
        general_analyzer.get_average_age();
    }
    else if(detail == "sex_percentage"){
        general_analyzer.get_sex_percentage();
    }
    else if(detail == "employment_percentage"){
        general_analyzer.get_employment_percentage();
    }
    else if(detail == "winner"){
        general_analyzer.get_winners();
    }
    else if(detail == "purpose"){
        general_analyzer.get_purposes();
    }
    else if(detail == "all_votes"){
        general_analyzer.get_all_votes();
    }
    else if(detail == "no_votes"){
        general_analyzer.get_no_votes();
    }
    else if(detail == "no_voters"){
        general_analyzer.get_all_voters();
    }
}


