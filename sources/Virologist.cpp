#include"Virologist.hpp"

namespace pandemic{

    Virologist &Virologist::treat(City c){
        if(board.getDisL().at(start_city) == 0 &&board.getDisL().at(c) == 0){
            throw std::invalid_argument("There is no pollution in the city at all!");
        }

        if(start_city == c){
            Player::treat(c);
            return *this;
        }

        int flag = 0;
        for(set<City>::iterator i = cards.begin(); i != cards.end(); ++i){
            if((*i) == c){
                flag = 1;
            }
        }
         if(flag == 1){
             Color t = board.getColor().at(c);
             if(board.getMed().at(t) == 1){
                 board.setdisL0(c);
             }
             else{
                 board.setdisL_1(c);
             }
             cards.erase(c);
             return *this;
        }
        throw std::invalid_argument("you didnt have the city card");
    }

   

}