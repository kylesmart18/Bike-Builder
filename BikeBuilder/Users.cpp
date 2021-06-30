#include "Users.h"

Users::Users()
{
    user="NONE";
    numbikes=0;
}

Users::Users(string u, int nb, string bikesnum[])
{
    user=u;
    numbikes=nb;
    for(int i=0;i<nb;i++)
    {
        bikes[i]=bikesnum[i];
    }
}

void Users::setUser(string u)
{
    user=u;
}

string Users::getUser()
{
    return user;
}

void Users::setBikes(int nb)
{
    numbikes=nb;
}

int Users::getBikes()
{
    return numbikes;
}

void Users::setBikesAt(string b, int i)
{
    bikes[i]=b;
}

string Users::getBikesAt(int i)
{
    return bikes[i];
}

void Users::addBikes(string new_bike)
{
    for(int i=0;i<100;i++)
    {
        if(bikes[i]=="")
        {
            setBikesAt(new_bike,i);
            break;
        }
    }
}

int Users::getNumBikes()
{
    int count=0;
    for(int i=0;i<100;i++)
    {
        if(bikes[i]!="" && bikes[i]!=",")
        {
            count++;
        }
    }
    return count;
}
