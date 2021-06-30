#include "Parts.h"

Parts::Parts()
{
    component="NONE";
    component_weight=0;
    price=0;
}

Parts::Parts(string c, int cw, int p)
{
    component=c;
    component_weight=cw;
    price=p;
}

void Parts::setComponent(string c)
{
    component=c;
}

string Parts::getComponent()
{
    return component;
}

void Parts::setComponentWeight(int cw)
{
    component_weight=cw;
}

int Parts::getComponentWeight()
{
    return component_weight;
}

void Parts::setPrice(int p)
{
    price=p;
}

int Parts::getPrice()
{
    return price;
}