#pragma once
#include <iostream>
#include <vector>

namespace ariel
{
    class Team
    {
    private:
    public:
        std::string _name;
        double _talent_level;
        int _wins;
        int _losses;
        int _winSpree_curr;
        int _winSpree_max;
        int _loseSpree_curr;
        int _loseSpree_max;
        bool _teamStatus;
        double _score;
        int _scorePts;
        int _sufferedPts;


        Team(std::string name, double talent_level)
        : _name(name), _talent_level(talent_level), _wins(0), _losses(0),
            _winSpree_curr(0), _winSpree_max(0), _loseSpree_curr(0), _loseSpree_max(0), 
            _score(0), _scorePts(0), _sufferedPts(0), _teamStatus(false)
        {
            if(name == "" || name == " "){
                throw std::invalid_argument("data contains not printable char");
            }
            for (size_t i = 0; i < name.length(); i++)
            {
                if (isprint(name.at(i)) == 0)
                {
                    throw std::invalid_argument("data contains not printable char");
                }
            }
            if(talent_level <0 || talent_level>1){
                throw std::invalid_argument("talent must be [0,1]");
            }
        }

        ~Team(){}

        bool operator==(const Team& other) const{
            return this->_name == other._name;
        }

        bool operator!=(const Team& other) const{
            return this->_name != other._name;
        }
    };

}
