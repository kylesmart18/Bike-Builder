#include "Bikes.h"

Bikes::Bikes()
{
    bike_name="NONE";
    bike_weight=0;
    bike_price=0;
}

Bikes::Bikes(string bn, int bw, int bp, string bh, string bfr, string bfo, string bwh)
{
    bike_name=bn;
    bike_weight=bw;
    bike_price=bp;
    bike_hub=bh;
    bike_frame=bfr;
    bike_fork=bfo;
    bike_wheel=bwh;
}

void Bikes::setBikeName(string bn)
{
    bike_name=bn;
}

string Bikes::getBikeName()
{
    return bike_name;
}

void Bikes::setBikeWeight(int bw)
{
    bike_weight=bw;
}

int Bikes::getBikeWeight()
{
    return bike_weight;
}

void Bikes::setBikePrice(int bp)
{
    bike_price=bp;
}

int Bikes::getBikePrice()
{
    return bike_price;
}

void Bikes::setBikeHub(string bh)
{
    bike_hub=bh;
}

string Bikes::getBikeHub()
{
    return bike_hub;
}

void Bikes::setBikeFrame(string bfr)
{
    bike_frame=bfr;
}

string Bikes::getBikeFrame()
{
    return bike_frame;
}

void Bikes::setBikeFork(string bfo)
{
    bike_fork=bfo;
}

string Bikes::getBikeFork()
{
    return bike_fork;
}

void Bikes::setBikeWheel(string bwh)
{
    bike_wheel=bwh;
}

string Bikes::getBikeWheel()
{
    return bike_wheel;
}