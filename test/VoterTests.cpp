//
// Created by eryk on 1/29/23.
//

#include <boost/test/unit_test.hpp>

#include "../include/Voter.h"
#include "../include/SportsVote.h"

BOOST_AUTO_TEST_SUITE(VoterTest)

    BOOST_AUTO_TEST_CASE(testVoter_getSex) {
        std::shared_ptr<Voter> voter=std::make_shared<Voter>('F',35,1);
        BOOST_REQUIRE_EQUAL(voter->get_sex(), 'F');
    }

    BOOST_AUTO_TEST_CASE(testVoter_getAge) {
        std::shared_ptr<Voter> voter=std::make_shared<Voter>('F',35,1);
        BOOST_REQUIRE_EQUAL(voter->get_age(), 35);
    }

    BOOST_AUTO_TEST_CASE(testVoter_getEmployed) {
        std::shared_ptr<Voter> voter=std::make_shared<Voter>('F',35,1);
        BOOST_REQUIRE_EQUAL(voter->get_employed(), 1);
    }

    BOOST_AUTO_TEST_CASE(testVoter_addTwoVotes_printVotes) {
        std::shared_ptr<Voter> voter=std::make_shared<Voter>('F',35,1);
        std::shared_ptr<SportsVote> sports_vote = std::make_shared<SportsVote>(20230123,"soccer","messi","world cup");
        voter->add_vote(sports_vote);
        BOOST_TEST(voter->printVotes().size() > 0);
    }

BOOST_AUTO_TEST_SUITE_END()