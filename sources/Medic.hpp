#include "Player.hpp"

namespace pandemic {

    class Medic : public Player
    {
        public:
        Medic(Board &b,City c):Player(b,c,"Medic"){}
        Medic &drive(City c);
        Medic &fly_direct(City c);
        Medic &fly_charter(City c);
        Medic &fly_shuttle(City c);
        Medic &treat(City c);
    };
}