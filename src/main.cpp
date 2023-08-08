#include <iostream>
#include "../include/Analyzer.h"
#include "../include/BudgetAnalyzer.h"
#include "../include/SportsAnalyzer.h"
#include "../include/Voter.h"
#include "../include/Vote.h"
#include "../include/BudgetVote.h"
#include "../include/SportsVote.h"
#include "../include/GeneralAnalyzer.h"
#include "../include/UserInterface.h"


int main() {
    //std::cout << "Option for sports: soccer, basket, tennis"<< std::endl;
    //std::cout << "Order for Budget: infrastructure, medical care, tourism, culture"<< std::endl;
/*
try {
    std::shared_ptr<SportsVote> vote1 = std::make_shared<SportsVote>(20230123, "soccer", "no", "none");
    std::shared_ptr<SportsVote> vote2 = std::make_shared<SportsVote>(20230124, "soccer", "no", "none");


    std::shared_ptr<SportsVote> vote3 = std::make_shared<SportsVote>(20230125, "basket", "no", "none");
    std::shared_ptr<SportsVote> vote4 = std::make_shared<SportsVote>(20230125, "basket", "no", "none");
    std::shared_ptr<SportsVote> vote5 = std::make_shared<SportsVote>(20230125, "basket", "no", "none");


    std::cout << vote1->vote_to_string() << std::endl;

    std::shared_ptr<SportsAnalyzer> analyzer1 = std::make_shared<SportsAnalyzer>("test");
    analyzer1.get()->add_vote(vote1);
    analyzer1.get()->add_vote(vote2);
    analyzer1.get()->add_vote(vote3);
    analyzer1.get()->add_vote(vote4);
    analyzer1.get()->add_vote(vote5);

    std::shared_ptr<SportsVote> vote6 = std::make_shared<SportsVote>(20230123, "tennis", "no", "none");
    std::shared_ptr<SportsVote> vote7 = std::make_shared<SportsVote>(20230124, "tennis", "no", "none");

    std::shared_ptr<SportsVote> vote8 = std::make_shared<SportsVote>(20230125, "tennis", "no", "none");
    std::shared_ptr<SportsVote> vote9 = std::make_shared<SportsVote>(20230125, "tennis", "no", "none");
    std::shared_ptr<SportsVote> vote10 = std::make_shared<SportsVote>(20230125, "tennis", "no", "none");

    std::shared_ptr<BudgetVote> vote11 = std::make_shared<BudgetVote>(20230125, 50, 25, 12, 13);
    std::cout << vote11->get_distribution();

    std::shared_ptr<SportsAnalyzer> analyzer2 = std::make_shared<SportsAnalyzer>("test");
    analyzer2.get()->add_vote(vote6);
    analyzer2.get()->add_vote(vote7);

    std::shared_ptr<SportsAnalyzer> analyzer3 = analyzer2;
    analyzer3.get()->add_vote(vote8);
    std::cout<<"TEST: "<<analyzer3->get_no_votes();
    //analyzer3.get()->add_vote(vote9);
    //analyzer3.get()->add_vote(vote10);



    GeneralAnalyzer general;
    general.add_analyzer(analyzer1);
    general.add_analyzer(analyzer2);
    general.add_analyzer(analyzer3);
    general.get_no_votes(); //WORKS
    general.get_winners();


    std::shared_ptr<Voter> voter1 = std::make_shared<Voter>('M', 59, true);
    std::shared_ptr<Voter> voter2 = std::make_shared<Voter>('M', 20, true);
    std::shared_ptr<Voter> voter3 = std::make_shared<Voter>('F', 104, false);

    voter1.get()->add_vote(vote1);
    voter1.get()->add_vote(vote2);
    voter1.get()->add_vote(vote11);
    std::cout << voter1.get()->printVotes();

    general.add_voter(voter1);
    general.add_voter(voter2);
    general.add_voter(voter3);
    general.get_sex_percentage(); //WORKS
    general.get_average_age(); //WORKS




    std::cout<<"1. Add Voter"<<std::endl<<"2. Add vote"<<std::endl;

<<<<<<< HEAD
    } catch (int x) {if(x==1)std::cout<<"wrong sport input"<<std::endl;
    if(x==2)std::cout<<"wrong budget input"<<std::endl;
    if(x==3)std::cout<<"wrong budget distribution"<<std::endl;
    if(x==5)std::cout<<"wrong sportperson"<<std::endl;
    if(x==6)std::cout<<"wrong event"<<std::endl;
     }
=======
} catch (int x) {if(x==1)std::cout<<"wrong sport input"<<std::endl;
if(x==2)std::cout<<"wrong budget input"<<std::endl;
if(x==3)std::cout<<"wrong budget distribution"<<std::endl;
if(x==5)std::cout<<"wrong sportperson"<<std::endl;
if(x==6)std::cout<<"wrong event"<<std::endl;
 }




    interface.create_voter('F', 53, 1);
    interface.create_voter('M', 47, 1);
    interface.display_detail("average_age");

    GeneralAnalyzer gen;
    std::shared_ptr<Voter> voter1 = std::make_shared<Voter>('M', 59, true);
    std::shared_ptr<Voter> voter2 = std::make_shared<Voter>('F', 59, true);
    std::shared_ptr<SportsVote> vote8 = std::make_shared<SportsVote>(20230125, "tennis", "messi", "world cup");
    std::shared_ptr<BudgetVote> vote9 = std::make_shared<BudgetVote>(20230224,50,23,22,5);
    std::shared_ptr<SportsAnalyzer> analyzer2 = std::make_shared<SportsAnalyzer>("Sports");
    gen.add_voter(voter1);
    gen.add_voter(voter2);

    gen.add_analyzer(analyzer2);*/




    UserInterface interface;
    interface.start_interface();





}
