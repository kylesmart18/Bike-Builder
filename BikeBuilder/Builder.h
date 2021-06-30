#ifndef Builder_H
#define Builder_H
#include "Parts.cpp"
#include "Bikes.cpp"
#include "Users.cpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <math.h>
#include <random>
#include <time.h>
using namespace std;
;
class Builder
{
    private:
        Parts hubs[100];
        Parts forks[100];
        Parts wheels[100];
        Parts frame_fullsuspension[100];
        Parts frame_hardtail[100];
        int num_hubs;
        int num_forks;
        int num_wheels;
        int num_fframes;
        int num_hframes;
        Bikes xc[100];
        Bikes trail[100];
        Bikes enduro[100];
        int num_xcbikes;
        int num_trailbikes;
        int num_endurobikes;
        Users people[100];
        int num_users;
    public:
        Builder();
        void loadPartsFile(string filename);
        void loadBikesfile(string filename);
        void loadUserFile(string filename);
        string convertol(string str);
        int findName(string name);
        int findBike(string name);
        void outputUserBikes(string name);
        int outputBikeParts(string bike_name);
        int getHub(string hub);
        int getFork(string fork);
        int getWheels(string wheel);
        int getHardtailFrame(string hf);
        int getFullSuspensionFrame(string ff);
        void outputComponent(string type);
        void buildBike(string hub, string fork, string wheel, string frame, string name);
        void addUserBike(string bike_name, string u_name);
        void changeBikeComponent(string bike, string c, string c_type);
        string recommendBike(string bike_type);
        void addNewUser(string name);
        void saveUserData(string filename);
        void saveBikeData(string filename);
};
#endif