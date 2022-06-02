#include "Leauge.hpp"

namespace ariel{
    void Leauge::startLeauge(){
        Schedule* schedule = new Schedule(this->_teams);
        for (auto iter = schedule->_games.begin(); iter < schedule->_games.end(); iter++) {
            (*iter)->startGame();
        }
        this->_end_of_leauge = true;
        fixLeauge();

    }

    void Leauge::fixLeauge(){
        if (!this->_end_of_leauge){
            throw std::invalid_argument("leauge not started yet\n");
        }
        for(auto iter = this->_teams.begin(); iter < this->_teams.end(); iter++){
            (*iter)->_score = (*iter)->_wins + EPS*((*iter)->_scorePts - (*iter)->_sufferedPts);
        }

        for (size_t i = 0; i < this->_teams.size() - 1; ++i) {
            for (size_t j = 0; j < this->_teams.size() - i - 1; ++j) {
                if (this->_teams.at(j)->_score < this->_teams.at(j + 1)->_score)
                    std::swap(this->_teams.at(j), this->_teams.at(j + 1));
            }
        }
    }
    void Leauge::printLeauge(int limit){
        if (!this->_end_of_leauge){
            throw std::invalid_argument("leauge not started yet\n");
        }
        std::cout << "---------Leauge Rank---------" << std::endl;
        for (unsigned int i = 0; i < limit; ++i) {
            std::cout << i+1 << ") " << this->_teams.at(i)->_name << " Wins-Loses: " << this->_teams.at(i)->_wins
                      << "-" << this->_teams.at(i)->_losses << ". Score-Suffer: " << this->_teams.at(i)->_scorePts << "-"
                      << this->_teams.at(i)->_sufferedPts << ". TOTAL SCORE: " << this->_teams.at(i)->_score << std::endl;
        }
        int maxWINS = 0;
        Team* maxWin;
        int maxLOSES = 0;
        Team* maxLose;
        for (auto iter = this->_teams.begin(); iter < this->_teams.end(); iter++){
            if((*iter)->_winSpree_max > maxWINS){
                maxWINS = (*iter)->_winSpree_max;
                maxWin = *iter;
            }
            if((*iter)->_loseSpree_max > maxLOSES){
                maxLOSES = (*iter)->_loseSpree_max;
                maxLose = *iter;
            }
        }
        std::cout << "Most wins spree by " << maxWin->_name << " with: " << maxWINS << " spree wins!" << std::endl;
        std::cout << "Most loses spree by " << maxLose->_name << " with: " << maxLOSES << " spree loses!" << std::endl;
        std::cout << "Teams that scored more than they suffered:" << std::endl;
        for (auto iter = this->_teams.begin(); iter < this->_teams.end(); iter++) {
            if((*iter)->_scorePts - (*iter)->_sufferedPts > 0){
                std::cout << (*iter)->_name << " with: " <<(*iter)->_scorePts << ":" <<(*iter)->_sufferedPts << std::endl;
            }
        }
    }

}