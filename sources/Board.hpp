#pragma once
#include <iostream>
#include<map>
#include <set>
#include "City.hpp"
#include "Color.hpp"
using namespace std;




namespace pandemic{


    class Board
    {

        static map<City,set<City>> myMap; // cities map
        static map<City,int> dis_level; // dis level in city
        static map<City,int> medicines; // medicines descovered in city
        static map<City,int> stations; // reasearch stations in city
        static map<City,Color> city_color; // city color


        public:
        Board();
        int &operator[](City city);
        const int operator[](City city) const;
        friend ostream& operator << (ostream& os , const Board& bd);

        bool is_clean();
        void remove_cures();
        void remove_stations();

        map<City,set<City>> getMap(){
            return myMap;
        }

        map<City,int> getDisL(){

            return dis_level;
        }

        map<City,int> getStations(){

            return stations;
        }

        map<City,int> getMed(){

            return medicines;
        }

        map<City,Color> getColor(){

            return city_color;
        }

        void setStations0(City c){

            stations.at(c) = 0;
        }

        void setStations1(City c){

            stations.at(c) = 1;
        }

        void setMed1(City c){

            medicines.at(c) = 1;
        }

        void setMed0(City c){

            medicines.at(c) = 0;
        }

        void setdisL_1(City c){

            dis_level.at(c) -= 1;
        }

        void setdisL1(City c){

            dis_level.at(c) += 1;
        }

        void setdisL0(City c){

            dis_level.at(c) = 0;
        }
        //des
        ~Board(){};

    };



}