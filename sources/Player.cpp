#include "Player.hpp"
#include <string>

namespace pandemic{

    City &start_city(City);
    set<City> cards;
    Board &board(Board);

    Player &Player::drive(City c){

        int flag = 0;
        map<City,set<City>> m = board.getMap();
        for(map<City,set<City>>::iterator i = m.begin(); i != m.end(); ++i){
            if((*i).first == start_city){
                set<City> cc = (*i).second;
                for(set<City>::iterator ii = cc.begin(); ii != cc.end();++ii){
                    if((*ii) == c){
                        flag = 1;
                        start_city = c;
                    } 
                } 
                if(flag == 0){
                    throw std::invalid_argument("error (non-neighboring cities!)");
                    }
            }
        }
        return *this;
    }

    Player &Player::fly_direct(City c){

        if(start_city == c){
            throw std::invalid_argument("error currently city = c");
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

    Player &Player::fly_charter(City c){

        int flag = 0;
        set<City> cards_copy = cards;
        for (set<City>::iterator i = cards_copy.begin(); i != cards_copy.end(); ++i){
            if((*i) == start_city){
                cards.erase(start_city);
                start_city = c;
                flag = 1;
                break;
            }
        }

        if(flag == 0){
            throw std::invalid_argument("error (no card of the current city)");
        }
        
        return *this;
    }
    
    Player &Player::fly_shuttle(City c){

        if(start_city == c){
            throw std::invalid_argument("error (cannot fly from city to it self)");
        }
        
        if(board.getStations().at(c) == 1 && board.getStations().at(start_city) == 1){
            start_city = c;
        }
        else{
            throw std::invalid_argument("error (no research station in dest/src city)");
        }
        return *this;
    }

    Player &Player::treat(City c){

        if(board.getDisL().at(start_city) == 0){
              throw std::invalid_argument("There is no pollution in the city at all!");
        }
       
        Color t = board.getColor().at(start_city);

        if(board.getMed().at(t) == 1){
           
            board.setdisL0(start_city);
               
        }
        else{
        
             board.setdisL_1(start_city);
               
        }

        return *this;
    }

    Player &Player::build(){

        int flag = 0;
        for(set<City>::iterator i = cards.begin(); i != cards.end(); ++i){
            if((*i) == start_city){
                flag = 1;
            }
        }

        if (flag == 0){
            throw std::invalid_argument("error (no card)");
        }

         if(board.getStations().at(start_city) == 0){
            board.setStations1(start_city);
            this->cards.erase(start_city);
         }
         else{
             throw std::invalid_argument("error (there are reasearch center in the city)");
         }
        return *this;
    }

    Player &Player::discover_cure(Color c){

        const int five = 5;
        if(board.getMed().at(c) == 1){
            throw std::invalid_argument("error (cure dicovered)");
        }
        
        int flag = 0;
        set<City> theFive_city;

        if(this->board.getStations().at(start_city) == 1){
        int counter = 0;
        for(set<City>::iterator i = cards.begin(); i != cards.end(); ++i){
            if(board.getColor().at(*i) == c){
                counter++;
                theFive_city.insert(*i);
                if(counter == five){
                    board.getMed().at(c) = 1;
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

        }
        else{
                throw std::invalid_argument("error the city has not stations");
            }

        return *this;
    }

    Player &Player::take_card(City c){

            cards.insert(c);
            return *this;
    }

    string Player::role(){
        return role();
    }
}