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
        map<City,int> dis_level; // dis level in city
        map<Color,int> medicines; // medicines descovered in city
        map<City,int> stations; // reasearch stations in city
        static map<City,Color> city_color; // city color


        public:
        Board(){
            // disease levels :
           dis_level = {{City::Algiers,0},
                        {City::Atlanta,0},
                        {City::Baghdad,0},
                        {City::Bangkok,0},
                        {City::Beijing,0},
                        {City::Bogota,0},
                        {City::BuenosAires,0},
                        {City::Cairo,0},
                        {City::Chennai,0},
                        {City::Chicago,0},
                        {City::Delhi,0},
                        {City::Essen,0},
                        {City::HoChiMinhCity,0},
                        {City::HongKong,0},
                        {City::Istanbul,0},
                        {City::Jakarta,0},
                        {City::Johannesburg,0},
                        {City::Karachi,0},
                        {City::Khartoum,0},
                        {City::Kinshasa,0},
                        {City::Kolkata,0},
                        {City::Lagos,0},
                        {City::Lima,0},
                        {City::London,0},
                        {City::LosAngeles,0},
                        {City::Madrid,0},
                        {City::Manila,0},
                        {City::MexicoCity,0},
                        {City::Miami,0},
                        {City::Milan,0},
                        {City::Montreal,0},
                        {City::Moscow,0},
                        {City::Mumbai,0},
                        {City::NewYork,0},
                        {City::Osaka,0},
                        {City::Paris,0},
                        {City::Riyadh,0},
                        {City::SanFrancisco,0},
                        {City::Santiago,0},
                        {City::SaoPaulo,0},
                        {City::Seoul,0},
                        {City::Shanghai,0},
                        {City::StPetersburg,0},
                        {City::Sydney,0},
                        {City::Taipei,0},
                        {City::Tehran,0},
                        {City::Tokyo,0},
                        {City::Washington,0},
                        
                        };

           medicines = {{Color::Blue,0},
                        {Color::Black,0},
                        {Color::Yellow,0},
                        {Color::Red,0}};
                    
                        
            stations = {{City::Algiers,0},
                        {City::Atlanta,0},
                        {City::Baghdad,0},
                        {City::Bangkok,0},
                        {City::Beijing,0},
                        {City::Bogota,0},
                        {City::BuenosAires,0},
                        {City::Cairo,0},
                        {City::Chennai,0},
                        {City::Chicago,0},
                        {City::Delhi,0},
                        {City::Essen,0},
                        {City::HoChiMinhCity,0},
                        {City::HongKong,0},
                        {City::Istanbul,0},
                        {City::Jakarta,0},
                        {City::Johannesburg,0},
                        {City::Karachi,0},
                        {City::Khartoum,0},
                        {City::Kinshasa,0},
                        {City::Kolkata,0},
                        {City::Lagos,0},
                        {City::Lima,0},
                        {City::London,0},
                        {City::LosAngeles,0},
                        {City::Madrid,0},
                        {City::Manila,0},
                        {City::MexicoCity,0},
                        {City::Miami,0},
                        {City::Milan,0},
                        {City::Montreal,0},
                        {City::Moscow,0},
                        {City::Mumbai,0},
                        {City::NewYork,0},
                        {City::Osaka,0},
                        {City::Paris,0},
                        {City::Riyadh,0},
                        {City::SanFrancisco,0},
                        {City::Santiago,0},
                        {City::SaoPaulo,0},
                        {City::Seoul,0},
                        {City::Shanghai,0},
                        {City::StPetersburg,0},
                        {City::Sydney,0},
                        {City::Taipei,0},
                        {City::Tehran,0},
                        {City::Tokyo,0},
                        {City::Washington,0},
                        
                        };

        };
        int &operator[](City city);
        int operator[](City city) const;
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

        map<Color,int> getMed(){

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

        void setMed1(Color c){

            medicines.at(c) = 1;
        }

        void setMed0(Color c){

            medicines.at(c) = 0;
        }

        void setdisL_1(City c){

            dis_level.at(c) -= 1;
        }

        void setdisL0(City c){

            dis_level.at(c) = 0;
        }
        //des
        ~Board(){};

    };



}