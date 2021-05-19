#include "OperationsExpert.hpp"

namespace pandemic{

    OperationsExpert &OperationsExpert::build(){

        if(board.getStations().at(start_city) == 1){
                    return *this;

        }
        board.setStations1(start_city);
        return *this;
    }
    
}