#pragma once
#include "Board.hpp"

namespace pandemic{
    
    class Player{
        
        City start_city;
        set<City> cards;
        Board& board; 


        public:

        Player(Board &bo ,City st_city) : board(bo) , start_city(st_city){}
        Player(Board &bo ,City st_city , int i) : board(bo) , start_city(st_city){}

        Player &drive(City c);
        Player &fly_direct(City c);
        Player &fly_charter(City c);
        Player &fly_shuttle(City c);
        Player &treat(City c);

        Player &build();
        

        Player &discover_cure(Color c);

        string role();
        Player take_card(City c);
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