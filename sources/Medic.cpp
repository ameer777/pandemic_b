#include "Medic.hpp"

namespace pandemic{

    Medic &Medic::drive(City c){
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

        if(board.getDisL().at(start_city) != 0){
            Color t = board.getColor().at(start_city);
            if(board.getMed().at(t) == 1){
                board.setdisL0(start_city);
            }
        }
        return *this;
    }

    Medic &Medic::fly_direct(City c){
        if(start_city == c){
            throw std::invalid_argument("error currently city = c");
        }

        int flag = 0;
        set<City> cards_copy = cards;
        for (set<City>::iterator i = cards_copy.begin(); i != cards_copy.end(); ++i){
            if((*i) == c){
                cards.erase((*i));
                start_city = c;
                flag = 1;
            }
        }
          if(flag == 0){
             throw std::out_of_range("error (no card of destinition city)");
          }

          if(board.getDisL().at(start_city) != 0){
            Color t = board.getColor().at(start_city);
            if(board.getMed().at(t) == 1){
                board.setdisL0(start_city);
            }
        }
        return *this;

    }

    Medic &Medic::fly_charter(City c){
        int flag = 0;
        set<City> cards_copy = cards;
        for (set<City>::iterator i = cards_copy.begin(); i != cards_copy.end(); ++i){
            if((*i) == start_city){
                cards.erase(c);
                start_city = c;
                flag = 1;
                break;
            }
        }

        if(flag == 0){
            throw std::invalid_argument("error (no card of the current city)");
        }

        if(board.getDisL().at(start_city) != 0){
            Color t = board.getColor().at(start_city);
            if(board.getMed().at(t) == 1){
                board.setdisL0(start_city);
            }
        }
        return *this;
    }

    Medic &Medic::fly_shuttle(City c){
        if(start_city == c){
            throw std::invalid_argument("error (cannot fly from city to it self)");
        }
        
        if(board.getStations().at(c) == 1 && board.getStations().at(start_city) == 1){
            start_city = c;
        }
        else{
            throw std::invalid_argument("error (no research station in dest/src city)");
        }
        if(board.getDisL().at(start_city) != 0){
            Color t = board.getColor().at(start_city);
            if(board.getMed().at(t) == 1){
                board.setdisL0(start_city);
            }
        }
        return *this;
    }

    Medic &Medic::treat(City c){
        
        if(board.getDisL().at(start_city) == 0){
            throw std::invalid_argument("There is no pollution in the city at all!");
        }
        board.setdisL0(start_city);
        return *this;
    }


};