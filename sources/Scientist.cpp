#include "Scientist.hpp"

namespace pandemic{
    

    Scientist &Scientist::discover_cure(Color c){

        if(board.getMed().at(c) == 1){
            throw std::invalid_argument("error (cure dicovered)");
        }
        
        int flag = 0;
        set<City> theFive_city;

        if(n == 0){
            board.setMed1(c);
            return *this;

        }
        if(this->board.getStations().at(start_city) == 1){
        int counter = 0;
        for(set<City>::iterator i = cards.begin(); i != cards.end(); ++i){
            if(board.getColor().at(*i) == c){
                counter++;
                theFive_city.insert(*i);
                if(counter == n){
                    board.getMed().at(c) = 1;
                    for(set<City>::iterator ii = theFive_city.begin(); ii != theFive_city.end(); ++ii){
                    this->cards.erase(*ii);
              }
              return *this;
                }
            }
        }
        if(counter < n){
            throw std::invalid_argument("error less than 5 cities have the same color");
        }

        }
        else{
                throw std::invalid_argument("error the city has not stations");
            }

            return *this;
    }    

    
}