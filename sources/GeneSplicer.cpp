#include "GeneSplicer.hpp"

namespace pandemic{

GeneSplicer &GeneSplicer::discover_cure(Color c){
    const int five = 5;
    if(this->board.getStations().at(start_city) != 1){
             throw std::invalid_argument("error (there is no reasearch stat)");
         }
    if(board.getMed().at(c) == 1){
            throw std::invalid_argument("error (cure dicovered)");
        }
        
        int flag = 0;
        set<City> theFive_city;

        if(this->board.getStations().at(start_city) == 1){
           if(cards.size() >= five){
              board.getMed().at(c) = 1;
                 for(set<City>::iterator i = cards.begin(); i != cards.end(); ++i){
                    theFive_city.insert(*i);   
                    }
              for(set<City>::iterator ii = theFive_city.begin(); ii != theFive_city.end(); ++ii){
                        this->cards.erase(*ii);
                }
            }
        }
        
    
        return *this;
}
}