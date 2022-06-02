#pragma once
#include<iostream>
#include "Team.hpp"
namespace ariel{
    class Game
    {
    private:
        Team* _home;
        Team* _out;
    public:
        Game(Team* home, Team* out)
        : _home(home), _out(out) {}
        ~Game(){}

        Team* startGame(){
            int homeRand = (rand()%(100-55)) + 55;
            int awayRand = (rand()%(100-50)) + 50;
            homeRand += (int)(this->_home->_talent_level * 10);
            awayRand += (int)(this->_out->_talent_level * 10);
            this->_home->_scorePts+=(homeRand);
            this->_home->_sufferedPts+=(awayRand);
            this->_out->_scorePts+=(awayRand);
            this->_out->_sufferedPts+=(homeRand);
            if(homeRand>=awayRand){
                this->_home->_teamStatus = true;
                this->_home->_loseSpree_curr = 0;
                this->_home->_winSpree_curr+=1;
                this->_home->_wins+=1;
                if (this->_home->_winSpree_curr > this->_home->_winSpree_max){
                    this->_home->_winSpree_max = this->_home->_winSpree_curr;
                }
                this->_out->_teamStatus = false;
                this->_out->_winSpree_curr = 0;
                this->_out->_loseSpree_curr+=1;
                this->_out->_losses+=1;
                if (this->_out->_loseSpree_curr > this->_out->_loseSpree_max){
                    this->_out->_loseSpree_max = this->_out->_loseSpree_curr;
                }
                return this->_home;
            }
            this->_out->_teamStatus = true;
            this->_out->_loseSpree_curr = 0;
            this->_out->_winSpree_curr+=1;
            this->_out->_wins+=1;
            if (this->_out->_winSpree_curr > this->_out->_winSpree_max){
                this->_out->_winSpree_max = this->_out->_winSpree_curr;
            }
            this->_home->_teamStatus = false;
            this->_home->_winSpree_curr = 0;
            this->_home->_loseSpree_curr+=1;
            this->_home->_losses+=1;
            if (this->_home->_loseSpree_curr > this->_home->_loseSpree_max){
                this->_home->_loseSpree_max = this->_home->_loseSpree_curr;
            }
            return this->_out;
        }
    };
    
}