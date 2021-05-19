#include "Dispatcher.hpp"

namespace pandemic{

    Dispatcher &Dispatcher::fly_direct(City c){

        if(start_city == c){
            throw std::invalid_argument("error currently city = c");
        }

        if(board.getStations().at(start_city) == 1){
            start_city = c;
            return *this;
        }

        set<City> cards_copy = cards;
        for (set<City>::iterator i = cards_copy.begin(); i != cards_copy.end(); ++i){
            if((*i) == c){
                cards.erase((*i));
                start_city = c;
                return *this;
            }
        }

             throw std::out_of_range("error (no card of destinition city)");
        
    }
};