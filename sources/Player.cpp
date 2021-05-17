#include "Player.hpp"
#include <string>

namespace pandemic{


    City &start_city(City);
    Board::Board() {}


    Player &Player::drive(City c){

        int flag = 0;
        map<City,set<City>> m = board.getMap();
        for(map<City,set<City>>::iterator i = m.begin(); i != m.end(); ++i){
            if((*i).first == start_city){
                set<City> cc = (*i).second;
                for(set<City>::iterator ii = cc.begin(); ii != cc.end();++ii){
                    if((*ii) == c){
                        flag = 1;
                        Player p = Player(board,c);
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

        

        for (set<City>::iterator i = cards.begin(); i != cards.end(); ++i){
            if((*i) == c){
                cards.erase((*i));
                board.setStations0(c);
                Player p = Player(board,c);
            }
        }
        return *this;
    }

    Player &Player::fly_charter(City c){

        board.setStations0(start_city);
        cards.erase(start_city);
        Player p = Player(board,c);
        return *this;
    }
    
    Player &Player::fly_shuttle(City c){

        if(start_city == c){
            throw std::invalid_argument("error (cannot fly from city to it self)");
        }
        int flag = 0;
        map<City,int> st = board.getStations();

        for(map<City,int>::iterator i = st.begin(); i != st.end(); ++i){
            if((*i).first == c){
                if((*i).second == 1){
                    flag = 1;
                    break;
                }
            }
        }

        if(flag == 1){
        for(map<City,int>::iterator j = st.begin(); j != st.end(); ++j){
            if((*j).first == start_city){
                if((*j).second == 1){
                    Player p = Player(board,c);
                }
                else {
                    throw std::invalid_argument("error (no research station in src city)");
                }
             }
           }
        }
        else{
                throw std::invalid_argument("error (no research station in dest city)");
              }
        return *this;
    }

    Player &Player::treat(City c){

        int flag1 = 0;
        map<City,int> m = board.getMed();
        map<City,int> dis = board.getDisL();

        for(map<City,int>::iterator i = m.begin(); i != m.end(); ++i){
            if((*i).first == c){
                if((*i).second == 0){
                    flag1 = 1;
                }
            }
        }

        if(flag1 == 0){
            for(map<City,int>::iterator i = dis.begin(); i != dis.end(); ++i){
            if((*i).first == c){
                board.setdisL0(c);
               }
            }
        }
        else{
        for(map<City,int>::iterator i = dis.begin(); i != dis.end(); ++i){
            if((*i).first == c){
                if((*i).second > 0){
                    board.setdisL_1(c);
                }
                else{
                    throw std::invalid_argument("There is no pollution in the city at all!");
                }
            }
          }
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

        map<City,int> st = board.getStations();
        for(map<City,int>::iterator i = st.begin(); i != st.end(); ++i){
            if((*i).first == start_city){
                if((*i).second == 0){
                    // (*i).second = 1;
                    board.setStations1(start_city);
                    this->cards.erase(start_city);
                }
            }
        }
        return *this;
    }

    Player &Player::discover_cure(Color c){

        int flag = 0;
        map<City,int> st = board.getStations();
        for(map<City,int>::iterator i = st.begin(); i != st.end() ; ++i){
            if((*i).first == start_city){
                if((*i).second == 1){
                    flag = 1;
                }
            }
        }

        if(flag == 1){
        int counter = 0;
        map<City,Color> cc = board.getColor();
        for(map<City,Color>::iterator i = cc.begin(); i != cc.end(); ++i){
            if((*i).second == c){
                counter++;
            }
        }

        if(counter >= 5){
            board.setdisL0(start_city);
            
            for(map<City,Color>::iterator i = cc.begin(); i != cc.end(); ++i){
               if((*i).second == c){
                   this->cards.erase((*i).first);
                   board.setStations0((*i).first);
                 }
            }
         }
        }
        return *this;
    }

    Player Player::take_card(City c){

        int flag = 1;
        for(set<City>::iterator i = cards.begin(); i != cards.end(); ++i){
            if((*i) == c){
                flag = 0;
            }
        }

        if(flag == 1){
            this->cards.insert(c);
        }
        return *this;
    }

    string Player::role(){
        return "reasearch";
    }
}