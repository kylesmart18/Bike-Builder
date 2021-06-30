#ifndef Bikes_H
#define Bikes_H
#include <iostream>
#include <string>
using namespace std;

class Bikes
{
    private:
        string bike_name;
        int bike_weight;
        int bike_price;
        string bike_hub;
        string bike_frame;
        string bike_fork;
        string bike_wheel;
    public:
        Bikes();
        Bikes(string bn, int bw, int bp, string bh, string bfr, string bfo, string bwh);
        void setBikeName(string bn);
        string getBikeName();
        void setBikeWeight(int bw);
        int getBikeWeight();
        void setBikePrice(int bp);
        int getBikePrice();
        void setBikeHub(string bh);
        string getBikeHub();
        void setBikeFrame(string bfr);
        string getBikeFrame();
        void setBikeFork(string bfo);
        string getBikeFork();
        void setBikeWheel(string bwh);
        string getBikeWheel();
};
#endif