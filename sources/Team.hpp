#pragma once
#include <iostream>
#include <vector>

namespace ariel
{
    class Team
    {
    private:
        std::string _name;
        double _talent_level;

    public:
        Team(std::string name, double talent_level)
        : _name(name), _talent_level(talent_level)
        {
            for (size_t i = 0; i < name.length(); i++)
            {
                if (isprint(name.at(i)) == 0)
                {
                    throw std::invalid_argument("data contains not printable char");
                }
            }
        }

        ~Team();
    };

}
