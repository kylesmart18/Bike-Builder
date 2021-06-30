#ifndef Users_H
#define Users_H
#include <iostream>
#include <string>
using namespace std;

class Users
{
    private:
        string user;
        int numbikes;
        string bikes[100];
    public:
        Users();
        Users(string u, int nb, string bikesnum[]);
        void setUser(string u);
        string getUser();
        void setBikes(int nb);
        int getBikes();
        void setBikesAt(string b, int i);
        string getBikesAt(int i);
        void addBikes(string new_bike);
        int getNumBikes();
};
#endif