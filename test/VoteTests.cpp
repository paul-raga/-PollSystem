//
// Created by eryk on 1/29/23.
//

#include <boost/test/unit_test.hpp>

#include "../include/Vote.h"
#include "../include/BudgetVote.h"
#include "../include/SportsVote.h"

BOOST_AUTO_TEST_SUITE(VoteTest)

    BOOST_AUTO_TEST_CASE(testSportsVote_getDate) {
        std::shared_ptr<SportsVote> vote= std::make_shared<SportsVote>(20230123,"soccer","messi","world cup");
        BOOST_REQUIRE_EQUAL(vote->get_date(), 20230123);
    }

    BOOST_AUTO_TEST_CASE(testSportsVote_getSport) {
        std::shared_ptr<SportsVote> vote= std::make_shared<SportsVote>(20230123,"soccer","messi","grand slam");
        BOOST_REQUIRE_EQUAL(vote->get_sport(),"soccer");
    }

    BOOST_AUTO_TEST_CASE(testSportsVote_getSportsPerson) {
        std::shared_ptr<SportsVote> vote= std::make_shared<SportsVote>(20230123,"soccer","ronaldo","olympics");
        BOOST_REQUIRE_EQUAL(vote->get_sportsperson(),"ronaldo");
    }

    BOOST_AUTO_TEST_CASE(testSportsVote_getEvent) {
        std::shared_ptr<SportsVote> vote= std::make_shared<SportsVote>(20230123,"soccer","messi","world cup");
        BOOST_REQUIRE_EQUAL(vote->get_event(),"world cup");
    }

    BOOST_AUTO_TEST_CASE(testSportsVote_isValid_bothCases) {
        std::shared_ptr<SportsVote> vote= std::make_shared<SportsVote>(20230123,"soccer","ronaldo","world cup");
        BOOST_REQUIRE_EQUAL(vote->is_valid(), 1);
        std::shared_ptr<SportsVote> inv_vote= std::make_shared<SportsVote>(20220123,"soccer","ronaldo","test");
        BOOST_REQUIRE_EQUAL(inv_vote->is_valid(), 0);
    }

    BOOST_AUTO_TEST_CASE(testBudgetVote_getDate) {
        std::shared_ptr<BudgetVote> vote= std::make_shared<BudgetVote>(20230123,25,25,25,25);
        BOOST_REQUIRE_EQUAL(vote->get_date(), 20230123);
    }

    BOOST_AUTO_TEST_CASE(testBudgetVote_getInfrastructure) {
        std::shared_ptr<BudgetVote> vote= std::make_shared<BudgetVote>(20230123,50,25,13,12);
        BOOST_REQUIRE_EQUAL(vote->get_infrastructure(),50);
    }

    BOOST_AUTO_TEST_CASE(testBudgetVote_getMedicalCare) {
        std::shared_ptr<BudgetVote> vote= std::make_shared<BudgetVote>(20230123,50,25,13,12);
        BOOST_REQUIRE_EQUAL(vote->get_medCare(),25);
    }

    BOOST_AUTO_TEST_CASE(testBudgetVote_getTourism) {
        std::shared_ptr<BudgetVote> vote= std::make_shared<BudgetVote>(20230123,50,25,13,12);
        BOOST_REQUIRE_EQUAL(vote->get_tourism() ,13);
    }

    BOOST_AUTO_TEST_CASE(testBudgetVote_getCulture) {
        std::shared_ptr<BudgetVote> vote= std::make_shared<BudgetVote>(20230123,50,25,13,12);
        BOOST_REQUIRE_EQUAL(vote->get_culture() ,12);

    }


BOOST_AUTO_TEST_SUITE_END()




