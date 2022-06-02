#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "sources/Leauge.hpp"
int const MAXTEAM = 20;
using namespace ariel;

int main() {
    vector<Team*> myTeams;
    myTeams.push_back(new Team("renena", 1));
    myTeams.push_back(new Team("talya", 0.4));
    myTeams.push_back(new Team("arik", 0.5));
    myTeams.push_back(new Team("dan", 0.3));
    myTeams.push_back(new Team("roee", 0.4));
    myTeams.push_back(new Team("shai", 0.5));
    myTeams.push_back(new Team("ron", 0.3));
    myTeams.push_back(new Team("yossi", 0.2));
    myTeams.push_back(new Team("shir", 0.5));
    myTeams.push_back(new Team("david", 1));
    myTeams.push_back(new Team("4", 0.7));
    myTeams.push_back(new Team("5", 0.3));
    myTeams.push_back(new Team("7", 0.2));
    myTeams.push_back(new Team("1", 0.6));
    myTeams.push_back(new Team("2", 0.8));
    myTeams.push_back(new Team("3", 0.6));
    myTeams.push_back(new Team("234", 0.5));
    myTeams.push_back(new Team("6453", 0.3));
    myTeams.push_back(new Team("454", 0));
    myTeams.push_back(new Team("86756", 0.1));
    Leauge* l = new Leauge(myTeams);
    l->start();
    l->print(20);
    l->print(5);
    for (int i = MAXTEAM -1; i >= 0; --i) {
        delete myTeams.at((unsigned int)i);
    }

}