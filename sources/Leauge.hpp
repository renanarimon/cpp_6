#pragma once
#include "Team.hpp"
#include "Schedule.hpp"
#include<vector>
#include<iterator>
#include<algorithm>
double const EPS = 0.0001;
namespace ariel{
    class Leauge
    {
    private:
        
    public:
        std::vector<Team*> _teams;
        bool _end_of_leauge;

        Leauge(){
            this->_end_of_leauge = false;
            for(int i =0; i<20; i++){
                this->_teams.push_back(new Team(std::to_string(i), 0.5));
            }
        }

        Leauge(std::vector<Team*> teams){
            this->_end_of_leauge = false;
            if(teams.size() == 20){
                this->_teams = teams;
            }
            else if (teams.size() < 20)
            {
                for(auto iter = teams.begin(); iter < teams.end(); iter++){
                    this->_teams.push_back(*iter);
                }
                for (int i = 0; i < 20-teams.size(); i++)
                {
                    this->_teams.push_back(new Team(std::to_string(i), 0.5));
                } 
            }
            else{
                throw std::invalid_argument("only 0-20 teams in leauge!");
            }
            
        }
        ~Leauge(){}


        void start();

        void update();

        void print(int limit);


    };

    
}