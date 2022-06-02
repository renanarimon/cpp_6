#pragma once
#include "Game.hpp"
#include "Team.hpp"
#include "Leauge.hpp"
#include<iterator>

int const MAX_TEAMS = 20;

namespace ariel{
    class Schedule
    {
    private:
        
    public:
        std::vector<Game*> _games;
        Schedule(std::vector<Team*> teams){
            if(teams.size() != MAX_TEAMS){
                throw std::invalid_argument("leauge must be with 20 teams");
            }
            for(auto iter1 = teams.begin(); iter1 < teams.end(); iter1++){
                for(auto iter2 = teams.begin(); iter2 < teams.end(); iter2++){
                    if (*iter1 != *iter2)
                    {
                        this->_games.push_back(new Game(*iter1, *iter2));
                        this->_games.push_back(new Game(*iter2, *iter1));
                    }
                }
            }
        }
        ~Schedule(){}
    };

    
}