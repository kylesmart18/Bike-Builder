#include "Builder.h"

int Split(string s, char c, string array[], int size) //parsing algorithm
{
    int i=0;
    int counter = 0;
    int length=0;
    string new_string;
    int count = 0;
    if(s.length()<=0) 
    {
        return 0;
    }
    s=s+c; 
    for(i=0;i<s.length();i++) 
    {
        if(s[i]==c) 
        {
            new_string=s.substr(i-counter, counter); 
            counter=0;
            array[length]=new_string; 
            length++; 
            count++; 
        }
        else
        {
            counter++;
        }
    }
    return count; 
}

Builder::Builder() //deconsturcter
{
    num_hubs=0;
    num_forks=0;
    num_wheels=0;
    num_fframes=0;
    num_hframes=0;
    num_xcbikes=0;
    num_trailbikes=0;
    num_endurobikes=0;
    num_users=0;
}

void Builder::loadPartsFile(string filename) //loads the file with parts
{
    ifstream mfs;
    mfs.open(filename);
    if(mfs.fail())
    {
        return;
    }
    string line="\n";
    while(getline(mfs, line))
    {
        string tempArray[3];
        Split(line,',',tempArray,3);
        string name=tempArray[0];
        int weight=stoi(tempArray[1]);
        int price=stoi(tempArray[2]);
        Parts p1(name,weight,price);
        string substring;
        string tempArray1[2];
        Split(name, '_', tempArray1, 2);
        substring=tempArray1[1];
        if(substring=="hu")
        {
            hubs[num_hubs]=p1;
            num_hubs++;
        }
        if(substring=="fk")
        {
            forks[num_forks]=p1;
            num_forks++;
        }
        if(substring=="wh")
        {
            wheels[num_wheels]=p1;
            num_wheels++;
        }
        if(substring=="ff")
        {
            frame_fullsuspension[num_fframes]=p1;
            num_fframes++;
        }
        if(substring=="fh")
        {
            frame_hardtail[num_hframes]=p1;
            num_hframes++;
        }
    }
}

void Builder::loadBikesfile(string filename) //loads the file with bikes
{
    ifstream mfs;
    mfs.open(filename);
    if(mfs.fail())
    {
        return;
    }
    string line="\n";
    while(getline(mfs, line))
    {
        string tempArray[7];
        Split(line, ',', tempArray, 7);
        string name=tempArray[0];
        int weight=stoi(tempArray[1]);
        int price=stoi(tempArray[2]);
        string hub=tempArray[3];
        string frame=tempArray[6];
        string fork=tempArray[4];
        string wheel=tempArray[5];
        Bikes b1(name,weight,price,hub,frame,fork,wheel);
        if(weight<5500)
        {
            xc[num_xcbikes]=b1;
            num_xcbikes++;
        }
        if(weight>=5500 && weight<=6300)
        {
            trail[num_trailbikes]=b1;
            num_trailbikes++;
        }
        if(weight>6300)
        {
            enduro[num_endurobikes]=b1;
            num_endurobikes++;
        }
    }
}

void Builder::loadUserFile(string filename) //loads the file with users and bike names
{
    ifstream mfs;
    mfs.open(filename);
    if(mfs.fail())
    {
        return;
    }
    string line="\n";
    while(getline(mfs, line))
    {
        string tempArray[2];
        Split(line, ':', tempArray, 2);
        string user_name=tempArray[0];
        string bike_names=tempArray[1];
        string bnames[100];
        int x=Split(bike_names, ',', bnames, 100);
        Users u1(user_name,100,bnames);
        people[num_users]=u1;
        num_users++;
    }
}

string Builder::convertol(string str) //converts strings to lowercase
{
    for(int i=0;i<str.length();i++)
    {
        str[i]=tolower(str[i]);
    }
    return str;
}

int Builder::findName(string name) //the findFunctions go through their respective arrays of objects to find the index where a certain object occurs
{
    name=convertol(name);
    for(int i=0;i<num_users;i++)
    {
        if(name==people[i].getUser())
        {
            return i;
        }
    }
    return -1;
}

int Builder::findBike(string name)
{
    name=convertol(name);
    for(int i=0;i<num_xcbikes;i++)
    {
        if(name==xc[i].getBikeName())
        {
            return i;
        }
    }
    for(int i=0;i<num_trailbikes;i++)
    {
        if(name==trail[i].getBikeName())
        {
            return i;
        }
    }
    for(int i=0;i<num_endurobikes;i++)
    {
        if(name==enduro[i].getBikeName())
        {
            return i;
        }
    }
    return -1;
}

void Builder::outputUserBikes(string name)
{
    name=convertol(name);
    int x=findName(name);
    for(int i=0;i<100;i++)
    {
        cout<<people[x].getBikesAt(i)<<endl;
        if(people[x].getBikesAt(i)=="")
        {
            break;
        }
    }
}

int Builder::outputBikeParts(string bike_name) //outputs parts of a certain bike based on category
{
    bike_name=convertol(bike_name);
    for(int i=0;i<100;i++)
    {
        if(bike_name==xc[i].getBikeName())
        {
            cout<<"Hub: "<<xc[i].getBikeHub()<<endl;
            cout<<"Fork: "<<xc[i].getBikeFork()<<endl;
            cout<<"Wheels: "<<xc[i].getBikeWheel()<<endl;
            cout<<"Frame: "<<xc[i].getBikeFrame()<<endl;
            cout<<"Weight: "<<xc[i].getBikeWeight()<<endl;
            cout<<"Price: "<<xc[i].getBikePrice()<<endl;
            return 1;
            break;
        }
        if(bike_name==trail[i].getBikeName())
        {
            cout<<"Hub: "<<trail[i].getBikeHub()<<endl;
            cout<<"Fork: "<<trail[i].getBikeFork()<<endl;
            cout<<"Wheels: "<<trail[i].getBikeWheel()<<endl;
            cout<<"Frame: "<<trail[i].getBikeFrame()<<endl;
            cout<<"Weight: "<<trail[i].getBikeWeight()<<endl;
            cout<<"Price: "<<trail[i].getBikePrice()<<endl;
            return 2;
            break;
        }
        if(bike_name==enduro[i].getBikeName())
        {
            cout<<"Hub: "<<enduro[i].getBikeHub()<<endl;
            cout<<"Fork: "<<enduro[i].getBikeFork()<<endl;
            cout<<"Wheels: "<<enduro[i].getBikeWheel()<<endl;
            cout<<"Frame: "<<enduro[i].getBikeFrame()<<endl;
            cout<<"Weight: "<<enduro[i].getBikeWeight()<<endl;
            cout<<"Price: "<<enduro[i].getBikePrice()<<endl;
            return 3;
            break;
        }
    }
}

int Builder::getHub(string hub) 
{
    hub=convertol(hub);
    for(int i=0;i<num_hubs;i++)
    {
        if(hub==hubs[i].getComponent())
        {
            return i;
        }
    }
    return -1;
}

int Builder::getFork(string fork)
{
    fork=convertol(fork);
    for(int i=0;i<num_hubs;i++)
    {
        if(fork==forks[i].getComponent())
        {
            return i;
        }
    }
    return -1;
}

int Builder::getWheels(string wheel)
{
    for(int i=0;i<num_hubs;i++)
    {
        if(wheel==wheels[i].getComponent())
        {
            return i;
        }
    }
    return -1;
}    

int Builder::getHardtailFrame(string hf)
{
    hf=convertol(hf);
    for(int i=0;i<num_hubs;i++)
    {
        if(hf==frame_hardtail[i].getComponent())
        {
            return i;
        }
    }
    return -1;
}

int Builder::getFullSuspensionFrame(string ff)
{
    ff=convertol(ff);
    for(int i=0;i<num_hubs;i++)
    {
        if(ff==frame_fullsuspension[i].getComponent())
        {
            return i;
        }
    }
    return -1;
}

void Builder::outputComponent(string type) //outputs all the existing specific components within a type
{
    type=convertol(type);
    if(type=="hub")
    {
        for(int i=0;i<num_hubs;i++)
        {
            string temp[2];
            string h=hubs[i].getComponent();
            Split(h,'_',temp,2);
            string hu=temp[0];
            cout<<hu<<endl;
        }
    }
    if(type=="fork")
    {
        for(int i=0;i<num_forks;i++)
        {
            string temp[2];
            string f=forks[i].getComponent();
            Split(f,'_',temp,2);
            string fo=temp[0];
            cout<<fo<<endl;
        }
    }
    if(type=="wheel")
    {
        for(int i=0;i<num_wheels;i++)
        {
            string temp[2];
            string w=wheels[i].getComponent();
            Split(w,'_',temp,2);
            string wh=temp[0];
            cout<<wh<<endl;
        }
    }
    if(type=="frame")
    {
        cout<<"Hardtail frames: "<<endl;
        for(int i=0;i<num_hframes;i++)
        {
            string temp[2];
            string fh=frame_hardtail[i].getComponent();
            Split(fh,'_',temp,2);
            string fhu=temp[0];
            cout<<fhu<<endl;
        }
        cout<<"Full suspension frames: "<<endl;
        for(int i=0;i<num_fframes;i++)
        {
            string temp[2];
            string ff=frame_fullsuspension[i].getComponent();
            Split(ff,'_',temp,2);
            string ffu=temp[0];
            cout<<ffu<<endl;
        }
    }
}

void Builder::buildBike(string hub, string fork, string wheel, string frame, string name) //builds a bike based on component parameters
{
    hub=convertol(hub);
    fork=convertol(fork);
    frame=convertol(frame);
    name=convertol(name);
    string hub1=hub+"_hu";
    string fork1=fork+"_fk";
    string wheel1=wheel+"_wh";
    string frame1=frame+"_ff";
    string frame2=frame+"_fh";
    int a=getHub(hub1);
    int b=getFork(fork1);
    int c=getWheels(wheel1);
    int ff=getFullSuspensionFrame(frame1);
    int price=(hubs[a].getPrice())+(forks[b].getPrice())+(wheels[c].getPrice())+(frame_fullsuspension[ff].getPrice());
    int weight=(hubs[a].getComponentWeight())+(forks[b].getComponentWeight())+(wheels[c].getComponentWeight())+(frame_fullsuspension[ff].getComponentWeight());
    Bikes b1;
    b1.setBikeName(name);
    b1.setBikeWeight(weight);
    b1.setBikePrice(price);
    b1.setBikeHub(hub);
    b1.setBikeFork(fork);
    b1.setBikeFrame(frame);
    b1.setBikeWheel(wheel);
    if(weight<5500)
    {
        xc[num_xcbikes]=b1;
        num_xcbikes++;
    }
    if(weight>=5500 && weight<=6300)
    {
        trail[num_trailbikes]=b1;
        num_trailbikes++;
    }
    if(weight>6300)
    {
        enduro[num_endurobikes]=b1;
        num_endurobikes++;
    }
}

void Builder::changeBikeComponent(string bike, string c, string c_type) //changes the component of a bike and adjusts the weight and price accordingly 
{
    bike=convertol(bike);
    c_type=convertol(c_type);
    for(int i=0;i<num_xcbikes;i++)
    {
        if(bike==xc[i].getBikeName())
        {
            if(c_type=="hub")
            {
                string nc=c+"_hu";
                string nc1=xc[i].getBikeHub()+"_hu";
                int h=getHub(nc);
                int j=getHub(nc1);
                int nw=(xc[i].getBikeWeight()-hubs[j].getComponentWeight())+hubs[h].getComponentWeight();
                int np=(xc[i].getBikePrice()-hubs[j].getPrice())+hubs[h].getPrice();
                xc[i].setBikeHub(c);
                xc[i].setBikeWeight(nw);
                xc[i].setBikePrice(np);
            }
            if(c_type=="fork")
            {
                string nc=c+"_fk";
                string nc1=xc[i].getBikeFork()+"_fk";
                int h=getFork(nc);
                int j=getFork(nc1);
                int nw=(xc[i].getBikeWeight()-forks[j].getComponentWeight())+forks[h].getComponentWeight();
                int np=(xc[i].getBikePrice()-forks[j].getPrice())+forks[h].getPrice();
                xc[i].setBikeFork(c);
                xc[i].setBikeWeight(nw);
                xc[i].setBikePrice(np);
            }
            if(c_type=="wheel")
            {
                string nc=c+"_wh";
                string nc1=xc[i].getBikeWheel()+"_wh";
                int h=getWheels(nc);
                int j=getWheels(nc1);
                int nw=(xc[i].getBikeWeight()-wheels[j].getComponentWeight())+wheels[h].getComponentWeight();
                int np=(xc[i].getBikePrice()-wheels[j].getPrice())+wheels[h].getPrice();
                xc[i].setBikeWheel(c);
                xc[i].setBikeWeight(nw);
                xc[i].setBikePrice(np);
            }
            if(c_type=="frame")
            {
                string nc=c+"_ff";
                string nc1=xc[i].getBikeFrame()+"_ff";
                int h=getFullSuspensionFrame(nc);
                int j=getFullSuspensionFrame(nc1);
                int nw=(xc[i].getBikeWeight()-frame_fullsuspension[j].getComponentWeight())+frame_fullsuspension[h].getComponentWeight();
                int np=(xc[i].getBikePrice()-frame_fullsuspension[j].getPrice())+frame_fullsuspension[h].getPrice();
                xc[i].setBikeFrame(c);
                xc[i].setBikeWeight(nw);
                xc[i].setBikePrice(np);
            }
        }
    }
    for(int i=0;i<num_trailbikes;i++)
    {
        if(bike==trail[i].getBikeName())
        {
            if(c_type=="hub")
            {
                string nc=c+"_hu";
                string nc1=trail[i].getBikeHub()+"_hu";
                int h=getHub(nc);
                int j=getHub(nc1);
                int nw=(trail[i].getBikeWeight()-hubs[j].getComponentWeight())+hubs[h].getComponentWeight();
                int np=(trail[i].getBikePrice()-hubs[j].getPrice())+hubs[h].getPrice();
                trail[i].setBikeHub(c);
                trail[i].setBikeWeight(nw);
                trail[i].setBikePrice(np);
            }
            if(c_type=="fork")
            {
                string nc=c+"_fk";
                string nc1=trail[i].getBikeFork()+"_fk";
                int h=getFork(nc);
                int j=getFork(nc1);
                int nw=(trail[i].getBikeWeight()-forks[j].getComponentWeight())+forks[h].getComponentWeight();
                int np=(trail[i].getBikePrice()-forks[j].getPrice())+forks[h].getPrice();
                trail[i].setBikeFork(c);
                trail[i].setBikeWeight(nw);
                trail[i].setBikePrice(np);
            }
            if(c_type=="wheel")
            {
                string nc=c+"_wh";
                string nc1=trail[i].getBikeWheel()+"_wh";
                int h=getWheels(nc);
                int j=getWheels(nc1);
                int nw=(trail[i].getBikeWeight()-wheels[j].getComponentWeight())+wheels[h].getComponentWeight();
                int np=(trail[i].getBikePrice()-wheels[j].getPrice())+wheels[h].getPrice();
                trail[i].setBikeWheel(c);
                trail[i].setBikeWeight(nw);
                trail[i].setBikePrice(np);
            }
            if(c_type=="frame")
            {
                string nc=c+"_ff";
                string nc1=trail[i].getBikeFrame()+"_ff";
                int h=getFullSuspensionFrame(nc);
                int j=getFullSuspensionFrame(nc1);
                int nw=(trail[i].getBikeWeight()-frame_fullsuspension[j].getComponentWeight())+frame_fullsuspension[h].getComponentWeight();
                int np=(trail[i].getBikePrice()-frame_fullsuspension[j].getPrice())+frame_fullsuspension[h].getPrice();
                trail[i].setBikeFrame(c);
                trail[i].setBikeWeight(nw);
                trail[i].setBikePrice(np);
            }
        }
    }
    for(int i=0;i<num_endurobikes;i++)
    {
        if(bike==enduro[i].getBikeName())
        {
            if(c_type=="hub")
            {
                string nc=c+"_hu";
                string nc1=enduro[i].getBikeHub()+"_hu";
                int h=getHub(nc);
                int j=getHub(nc1);
                int nw=(enduro[i].getBikeWeight()-hubs[j].getComponentWeight())+hubs[h].getComponentWeight();
                int np=(enduro[i].getBikePrice()-hubs[j].getPrice())+hubs[h].getPrice();
                enduro[i].setBikeHub(c);
                enduro[i].setBikeWeight(nw);
                enduro[i].setBikePrice(np);
            }
            if(c_type=="fork")
            {
                string nc=c+"_fk";
                string nc1=enduro[i].getBikeFork()+"_fk";
                int h=getFork(nc);
                int j=getFork(nc1);
                int nw=(enduro[i].getBikeWeight()-forks[j].getComponentWeight())+forks[h].getComponentWeight();
                int np=(enduro[i].getBikePrice()-forks[j].getPrice())+forks[h].getPrice();
                enduro[i].setBikeFork(c);
                enduro[i].setBikeWeight(nw);
                enduro[i].setBikePrice(np);
            }
            if(c_type=="wheel")
            {
                string nc=c+"_wh";
                string nc1=enduro[i].getBikeWheel()+"_wh";
                int h=getWheels(nc);
                int j=getWheels(nc1);
                int nw=(enduro[i].getBikeWeight()-wheels[j].getComponentWeight())+wheels[h].getComponentWeight();
                int np=(enduro[i].getBikePrice()-wheels[j].getPrice())+wheels[h].getPrice();
                enduro[i].setBikeWheel(c);
                enduro[i].setBikeWeight(nw);
                enduro[i].setBikePrice(np);
            }
            if(c_type=="frame")
            {
                string nc=c+"_ff";
                string nc1=enduro[i].getBikeFrame()+"_ff";
                int h=getFullSuspensionFrame(nc);
                int j=getFullSuspensionFrame(nc1);
                int nw=(enduro[i].getBikeWeight()-frame_fullsuspension[j].getComponentWeight())+frame_fullsuspension[h].getComponentWeight();
                int np=(enduro[i].getBikePrice()-frame_fullsuspension[j].getPrice())+frame_fullsuspension[h].getPrice();
                enduro[i].setBikeFrame(c);
                enduro[i].setBikeWeight(nw);
                enduro[i].setBikePrice(np);
            }
        }
    }
}

string Builder::recommendBike(string bike_type) //reccomends a random bike out of a specified category
{
    bike_type=convertol(bike_type);
    if(bike_type=="xc")
    {
        string random_xcbike=xc[rand()%num_xcbikes].getBikeName();
        return random_xcbike;
    }
    if(bike_type=="trail")
    {
        string random_trailbike=trail[rand()%num_trailbikes].getBikeName();
        return random_trailbike;
    }
    if(bike_type=="enduro")
    {
        string random_endurobike=enduro[rand()%num_endurobikes].getBikeName();
        return random_endurobike;
    }
}

void Builder::addUserBike(string bike_name, string u_name) //adds a new bike to its user
{
    int n=findName(u_name);
    people[n].addBikes(bike_name);
}

void Builder::addNewUser(string name) //adds a new user
{
    Users u;
    u.setUser(name);
    people[num_users]=u;
    num_users++;
}

void Builder::saveUserData(string filename) //saves any new data about a user
{
    ofstream mfs;
    mfs.open(filename);
    for(int i=0;i<num_users;i++)
    {
        int c=people[i].getNumBikes()-1;
        mfs<<people[i].getUser()<<":";
        for(int j=0;j<5;j++)
        {
            if(j<c)
            {
                mfs<<people[i].getBikesAt(j)<<",";
            }
            if(j==c)
            {
                mfs<<people[i].getBikesAt(j);
            }
        }
        mfs<<endl;
    }
}

void Builder::saveBikeData(string filename) //saves any new data about a bike
{
    ofstream mfs;
    mfs.open(filename);
    for(int i=0;i<num_xcbikes;i++)
    {
        mfs<<xc[i].getBikeName()<<","<<xc[i].getBikeWeight()<<","<<xc[i].getBikePrice()<<","<<xc[i].getBikeHub()<<","<<xc[i].getBikeFork()<<","<<xc[i].getBikeWheel()<<","<<xc[i].getBikeFrame()<<endl;
    }
    for(int i=0;i<num_trailbikes;i++)
    {
        mfs<<trail[i].getBikeName()<<","<<trail[i].getBikeWeight()<<","<<trail[i].getBikePrice()<<","<<trail[i].getBikeHub()<<","<<trail[i].getBikeFork()<<","<<trail[i].getBikeWheel()<<","<<trail[i].getBikeFrame()<<endl;
    }
    for(int i=0;i<num_endurobikes;i++)
    {
        mfs<<enduro[i].getBikeName()<<","<<enduro[i].getBikeWeight()<<","<<enduro[i].getBikePrice()<<","<<enduro[i].getBikeHub()<<","<<enduro[i].getBikeFork()<<","<<enduro[i].getBikeWheel()<<","<<enduro[i].getBikeFrame()<<endl;
    }
}




