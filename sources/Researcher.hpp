#include "Player.hpp"

namespace pandemic{

    class Researcher : public Player
    {
        public:
        Researcher(Board & b,City c) : Player(b, c){}
    };
}