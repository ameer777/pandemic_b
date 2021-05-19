#include "Player.hpp"


namespace pandemic{

    class GeneSplicer : public Player
    {
        public:
        GeneSplicer(Board &b,City c):Player(b,c,"GeneSplicer"){}
        GeneSplicer &discover_cure(Color c);
    };
}