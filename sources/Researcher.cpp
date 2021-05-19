#include"Researcher.hpp"

namespace pandemic{

    Researcher &Researcher::discover_cure(Color c){
        const int five = 5;
        if(board.getMed().at(c) == 1){
            throw std::invalid_argument("error (cure dicovered)");
        }
        
        int flag = 0;
        set<City> theFive_city;

        
        int counter = 0;
        set<City> cards_copy = cards;
        for(set<City>::iterator i = cards_copy.begin(); i != cards_copy.end(); ++i){
            if(board.getColor().at(*i) == c){
                counter++;
                theFive_city.insert(*i);
                if(counter == five){
                    board.setMed1(c);
                    for(set<City>::iterator ii = theFive_city.begin(); ii != theFive_city.end(); ++ii){
                    this->cards.erase(*ii);
              }
              return *this;
                }
            }
        }
        if(counter < five){
            throw std::invalid_argument("error less than 5 cities have the same color");
        }

        return *this;

    }

}