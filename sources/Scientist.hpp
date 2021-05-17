#include "Player.hpp"

namespace pandemic{

    class Scientist : public Player
    {
        public:
        Scientist(Board &b , City c , int i):Player(b,c,i){}

    };
}