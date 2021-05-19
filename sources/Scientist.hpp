#include "Player.hpp"

namespace pandemic{

    class Scientist : public Player
    {
        public:
        int n;
        Scientist(Board &b , City c , int i):Player(b,c,i,"Scientist"){}
        Scientist &discover_cure(Color C);

    };
}