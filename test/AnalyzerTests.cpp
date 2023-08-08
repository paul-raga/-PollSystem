//
// Created by eryk on 1/29/23.
//

#include <boost/test/unit_test.hpp>

#include "../include/Voter.h"
#include "../include/BudgetAnalyzer.h"
#include "../include/SportsAnalyzer.h"
#include "../include/GeneralAnalyzer.h"

BOOST_AUTO_TEST_SUITE(AnalyzerTest)

    BOOST_AUTO_TEST_CASE(testSportsAnalyzer_getPurpose) {
        std::shared_ptr<SportsAnalyzer>analyzer=std::make_shared<SportsAnalyzer>("sports");
        BOOST_REQUIRE_EQUAL(analyzer->get_purpose() , "sports");
    }

    BOOST_AUTO_TEST_CASE(testSportsAnalyzer_addVote_getNoVotes) {
        std::shared_ptr<SportsAnalyzer>analyzer=std::make_shared<SportsAnalyzer>("sports");
        std::shared_ptr<SportsVote> vote= std::make_shared<SportsVote>(20230123,"tennis","messi","grand slam");
        std::shared_ptr<SportsVote> vote2= std::make_shared<SportsVote>(20230123,"tennis","neymar","grand slam");

        analyzer->add_vote(vote);
        BOOST_REQUIRE_EQUAL(analyzer->get_no_votes(),1);
        analyzer->add_vote(vote2);
        BOOST_REQUIRE_EQUAL(analyzer->get_no_votes(),2);
    }

    BOOST_AUTO_TEST_CASE(testSportsAnalyzer_getWinner){
        std::shared_ptr<SportsAnalyzer>analyzer=std::make_shared<SportsAnalyzer>("sports");
        std::shared_ptr<SportsVote> vote= std::make_shared<SportsVote>(20230123,"tennis","messi","grand slam");
        std::shared_ptr<SportsVote> vote2= std::make_shared<SportsVote>(20230123,"tennis","messi","grand slam");
        analyzer->add_vote(vote);
        analyzer->add_vote(vote2);
        std::istringstream iss(analyzer->get_winner());
        std::string sport, sportsperson, event;
        int space1 = iss.str().find(' ');
        int space2 = iss.str().find(' ',space1+1);
        sport = iss.str().substr(0,space1);
        sportsperson = iss.str().substr(space1+1,space2-space1-1);
        event = iss.str().substr(space2+1);
        BOOST_REQUIRE_EQUAL(sport,"tennis");
        BOOST_REQUIRE_EQUAL(sportsperson,"messi");
        BOOST_REQUIRE_EQUAL(event,"grand slam");
    }

    BOOST_AUTO_TEST_CASE(testSportsAnalyzer_getVote){
        std::shared_ptr<SportsAnalyzer>analyzer=std::make_shared<SportsAnalyzer>("sports");
        std::shared_ptr<SportsVote> vote= std::make_shared<SportsVote>(20230123,"tennis","ronaldo","olympics");
        analyzer->add_vote(vote);
        BOOST_REQUIRE_EQUAL(analyzer->get_vote(0),vote->vote_to_string());
    }

    BOOST_AUTO_TEST_CASE(testBudgetAnalyzer_getPurpose) {
        std::shared_ptr<BudgetAnalyzer>analyzer=std::make_shared<BudgetAnalyzer>("budget");
        BOOST_REQUIRE_EQUAL(analyzer->get_purpose() , "budget");
    }

    BOOST_AUTO_TEST_CASE(testBudgetAnalyzer_addVote_getNoVotes) {
        std::shared_ptr<BudgetAnalyzer>analyzer=std::make_shared<BudgetAnalyzer>("budget");
        std::shared_ptr<BudgetVote> vote= std::make_shared<BudgetVote>(20230123,50,25,13,12);
        std::shared_ptr<BudgetVote> vote2= std::make_shared<BudgetVote>(20230123,24,26,49,1);
        analyzer->add_vote(vote);

        BOOST_REQUIRE_EQUAL(analyzer->get_no_votes() ,1);
        analyzer->add_vote(vote2);
        BOOST_REQUIRE_EQUAL(analyzer->get_no_votes() ,2);
    }

    BOOST_AUTO_TEST_CASE(testBudgetAnalyzer_getWinner) {
        std::shared_ptr<BudgetAnalyzer>analyzer=std::make_shared<BudgetAnalyzer>("budget");
        std::shared_ptr<BudgetVote> vote= std::make_shared<BudgetVote>(20230123,50,25,13,12);
        std::shared_ptr<BudgetVote> vote2= std::make_shared<BudgetVote>(20230123,24,26,49,1);
        analyzer->add_vote(vote);
        analyzer->add_vote(vote2);
        BOOST_REQUIRE_EQUAL(analyzer->get_winner() ,"Infrastructure");
    }

    BOOST_AUTO_TEST_CASE(testBudgetAnalyzer_getVote) {
        std::shared_ptr<BudgetAnalyzer>analyzer=std::make_shared<BudgetAnalyzer>("budget");
        std::shared_ptr<BudgetVote> vote= std::make_shared<BudgetVote>(20230123,50,25,13,12);
        analyzer->add_vote(vote);
        BOOST_REQUIRE_EQUAL(analyzer->get_vote(0) ,vote->vote_to_string());
    }

    BOOST_AUTO_TEST_CASE(testGeneralAnalyzer_getSexPercentage) {
        std::shared_ptr<GeneralAnalyzer>analyzer=std::make_shared<GeneralAnalyzer>();
        std::shared_ptr<Voter> voter=std::make_shared<Voter>('F',35,1);
        std::shared_ptr<Voter> voter2=std::make_shared<Voter>('M',25,1);
        analyzer->add_voter(voter);
        analyzer->add_voter(voter2);
        BOOST_REQUIRE_EQUAL(analyzer->get_sex_percentage() ,50);
    }

    BOOST_AUTO_TEST_CASE(testGeneralAnalyzer_getAverageAge) {
        std::shared_ptr<GeneralAnalyzer>analyzer=std::make_shared<GeneralAnalyzer>();
        std::shared_ptr<Voter> voter=std::make_shared<Voter>('F',35,1);
        std::shared_ptr<Voter> voter2=std::make_shared<Voter>('M',25,1);
        analyzer->add_voter(voter);
        analyzer->add_voter(voter2);
        BOOST_REQUIRE_EQUAL(analyzer->get_average_age() ,30);
    }

    BOOST_AUTO_TEST_CASE(testGeneralAnalyzer_getEmploymentPercentage) {
        std::shared_ptr<GeneralAnalyzer>analyzer=std::make_shared<GeneralAnalyzer>();
        std::shared_ptr<Voter> voter=std::make_shared<Voter>('F',35,0);
        std::shared_ptr<Voter> voter2=std::make_shared<Voter>('M',25,0);
        analyzer->add_voter(voter);
        analyzer->add_voter(voter2);
        BOOST_REQUIRE_EQUAL(analyzer->get_employment_percentage() ,0);
    }

BOOST_AUTO_TEST_SUITE_END()

