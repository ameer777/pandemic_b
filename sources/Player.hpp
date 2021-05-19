#pragma once
#include "Board.hpp"
using namespace std;

namespace pandemic{
    
    class Player{
        
        

        public:
        
        City start_city;
        set<City> cards;
        Board& board; 
        std::string p_role;
        Player(Board &bo ,City st_city ,std::string r) : board(bo) , start_city(st_city) , p_role(r){}
        Player(Board &bo ,City st_city , int i , std::string rr) : board(bo) , start_city(st_city) , p_role(rr){}

        virtual Player &drive(City c);
        virtual Player &fly_direct(City c);
        virtual Player &fly_charter(City c);
        virtual Player &fly_shuttle(City c);
        virtual Player &treat(City c);

        virtual Player &build();
        

        virtual Player &discover_cure(Color c);

        virtual string role();
        virtual Player &take_card(City c);
        void remove_cards(){

         for(set<City>::iterator i = cards.begin(); i != cards.end(); ++i){
             cards.erase(i);
         }

        map<City,int> st = board.getStations();
        for(map<City,int>::iterator i = st.begin(); i != st.end(); ++i){
         board.setStations0((*i).first);
        }

    }
    };
}