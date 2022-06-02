#include "doctest.h"
#include "sources/Leauge.hpp"
using namespace ariel;
TEST_CASE("TEAM"){
    std::vector<Team*> allTeams;
    CHECK_THROWS(allTeams.push_back(new Team("",0)));
    CHECK_THROWS(allTeams.push_back(new Team("\r",0)));
    CHECK_THROWS(allTeams.push_back(new Team("\n",0)));
    CHECK_THROWS(allTeams.push_back(new Team("\t",0)));
    CHECK_THROWS(allTeams.push_back(new Team("\r",0)));
    CHECK_THROWS(allTeams.push_back(new Team(" ",0)));
    CHECK_NOTHROW(allTeams.push_back(new Team("Renana",0.9)));
    CHECK_NOTHROW(allTeams.push_back(new Team("Talya",0.1)));
    CHECK_NOTHROW(allTeams.push_back(new Team("Arik",0.2)));
    CHECK_NOTHROW(allTeams.push_back(new Team("Roee",0.3)));
    CHECK_NOTHROW(allTeams.push_back(new Team("Tahel",0.005)));
    CHECK_NOTHROW(allTeams.push_back(new Team("shahar",1)));
    CHECK_NOTHROW(allTeams.push_back(new Team("dvir",0.4)));
    CHECK_NOTHROW(allTeams.push_back(new Team("tavor",0.8)));
    CHECK_NOTHROW(allTeams.push_back(new Team("gil",0.77)));
    CHECK_NOTHROW(allTeams.push_back(new Team("tal",0.123456)));
    CHECK_THROWS(allTeams.push_back(new Team("shai",-1)));
    CHECK_THROWS(allTeams.push_back(new Team("dan",1.1)));

}
TEST_CASE("LEAUGE"){
    std::vector<Team*> allTeams;
    CHECK_NOTHROW(allTeams.push_back(new Team("Renana",0.9)));
    CHECK_NOTHROW(allTeams.push_back(new Team("Talya",0.1)));
    CHECK_NOTHROW(allTeams.push_back(new Team("Arik",0.2)));
    CHECK_NOTHROW(allTeams.push_back(new Team("Roee",0.3)));
    CHECK_NOTHROW(allTeams.push_back(new Team("Tahel",0.005)));
    CHECK_NOTHROW(allTeams.push_back(new Team("shahar",1)));
    CHECK_NOTHROW(allTeams.push_back(new Team("dvir",0.4)));
    CHECK_NOTHROW(allTeams.push_back(new Team("tavor",0.8)));
    CHECK_NOTHROW(allTeams.push_back(new Team("gil",0.77)));
    CHECK_NOTHROW(allTeams.push_back(new Team("tal",0.123456)));
    Leauge* l = new Leauge(allTeams);
    CHECK_EQ(l->_teams.size(), 20);
    CHECK_THROWS(l->printLeauge(5)); // Leauge not started
    l->startLeauge();
    CHECK_NOTHROW(l->printLeauge(5));
}