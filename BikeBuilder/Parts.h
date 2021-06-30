#ifndef Parts_H
#define Parts_H
#include <iostream>
#include <string>
using namespace std;

class Parts
{
    private:
        string component;
        int component_weight;
        int price;
    public:
        Parts();
        Parts(string c, int cw, int p);
        void setComponent(string c);
        string getComponent();
        void setComponentWeight(int cw);
        int getComponentWeight();
        void setPrice(int p);
        int getPrice();
};
#endif