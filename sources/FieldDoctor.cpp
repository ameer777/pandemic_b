#include"FieldDoctor.hpp"

namespace pandemic{

    FieldDoctor &FieldDoctor::treat(City c){

        if(board.getDisL().at(c) == 0){
             throw std::invalid_argument("There is no pollution in the city at all!");
        }
        
        if(board.getMap().at(start_city).find(c) != board.getMap().at(start_city).end() || start_city == c){

            Color t = board.getColor().at(c);
            if(board.getMed().at(t) == 1){
                board.setdisL0(c);
            }
            else{
               board.setdisL_1(c);
            }
        }
        else{
             throw std::invalid_argument("not neightboor");
        }

        return *this;
    }

    string FieldDoctor::role(){
        return "FieldDoctor";
    }
}