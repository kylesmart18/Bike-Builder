#include "Builder.cpp"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    Builder d;
    d.loadPartsFile("parts.txt"); //loads files
    d.loadBikesfile("bikes.txt");
    d.loadUserFile("users.txt");
    string name;
    cout<<"Thank you for using the bike builder! Please enter your name: "<<endl;
    getline(cin, name);
    while(name.length()==0 || name=="")
    {
        cout<<"Please enter a valid name: "<<endl;
        getline(cin, name);
        if(name.length()>0 && name!="")
        {
            break;
        }
    }
    int x=d.findName(name); //see's if user exists
    if(x!=-1)
    {
        cout<<"Hello again, "<<name<<endl;
    }
    if(x==-1)
    {
        cout<<"Hello, "<<name<<endl;
        d.addNewUser(name);
    }
    cout<<"Option a: build a bike."<<endl;
    cout<<"Option b: see current bikes and components."<<endl;
    cout<<"Option c: change a component on a bike."<<endl;
    cout<<"Option d: get a bike recommendation."<<endl;
    cout<<"Option e: quit the program."<<endl;
    cout<<"Select the letter for the option you want: "<<endl;
    string choice;
    getline(cin, choice);
    while(choice!="a" && choice!="A" && choice!="b" && choice!="B" && choice!="c" && choice!="C" && choice!="d" && choice!="D" && choice!="e" && choice!="E")
    {
        cout<<"Please pick a valid choice: "<<endl;
        getline(cin, choice);
        if(choice=="a" || choice=="A" || choice=="b" || choice=="B" || choice=="c" || choice=="C" || choice=="d" || choice=="D" || choice=="e" || choice=="E")
        {
            break;
        }
    }
    while(choice!="1") //different options of the program
    {
        if(choice=="a" || choice=="A")
        {
            string h;
            string f;
            string w;
            string fr;
            string n;
            cout<<"What hub do you want?: "<<endl;
            d.outputComponent("hub");
            getline(cin, h);
            cout<<"What fork do you want?: "<<endl;
            d.outputComponent("fork");
            getline(cin, f);
            cout<<"What wheelset do you want?: "<<endl;
            d.outputComponent("wheel");
            getline(cin, w);
            cout<<"What frame do you want?: "<<endl;
            d.outputComponent("frame");
            getline(cin, fr);
            cout<<"What do you want to name your bike?: "<<endl;
            getline(cin, n);
            int check=d.findBike(n);
            while(check!=-1)
            {
                cout<<"This bike name already exists.Please pick a new one: "<<endl;
                getline(cin, n);
                int check1=d.findBike(n);
                if(check1==-1)
                {
                    break;
                }
            }
            d.buildBike(h,f,w,fr,n);
            d.addUserBike(n,name);
        }
        if(choice=="b" || choice=="B")
        {
            cout<<"Your Bikes: "<<endl;
            d.outputUserBikes(name);
            string bike_choice;
            cout<<"Choose the bike would you like to see parts for: "<<endl;
            getline(cin, bike_choice);
            d.outputBikeParts(bike_choice);
        }
        if(choice=="c" || choice=="C")
        {
            d.outputUserBikes(name);
            cout<<"Which bike would you like to change?: "<<endl;
            string bchoice;
            getline(cin, bchoice);
            if(bchoice=="santacruzblur" || bchoice=="santacruznomad" || bchoice=="ibisripmo" || bchoice=="specializestumpjumper" || bchoice=="evilcalling" || bchoice=="transitionscout")
            {
                cout<<"You can not edit complete bike options."<<endl;
            }
            else
            {
                d.outputBikeParts(bchoice);
                cout<<"Would you like to change your hub, wheel, fork, or frame?: "<<endl;
                string component_choice;
                getline(cin, component_choice);
                cout<<"What alternative would you like?: "<<endl;
                d.outputComponent(component_choice);
                string a_choice;
                getline(cin, a_choice);
                d.changeBikeComponent(bchoice,a_choice,component_choice);
            }
        }
        if(choice=="d" || choice=="D")
        {
            cout<<"What type of bike are you looking for?"<<endl;
            cout<<"Bike types: xc, trail, and enduro."<<endl;
            string type_choice;
            getline(cin, type_choice);
            string s=d.recommendBike(type_choice);
            cout<<s<<endl;
            d.outputBikeParts(s);
        }
        if(choice=="e" || choice=="E")
        {
            cout<<"Your data is saved. Goodbye!"<<endl;
            d.saveUserData("users.txt");
            d.saveBikeData("bikes.txt");
            break;
        }
        cout<<"Option a: build a bike."<<endl;
        cout<<"Option b: see current bikes and their components, weights, and prices."<<endl;
        cout<<"Option c: change a component on a bike."<<endl;
        cout<<"Option d: get a bike recommendation."<<endl;
        cout<<"Option e: quit the program."<<endl;
        cout<<"Select the letter for the option you want: "<<endl;
        getline(cin, choice);
        while(choice!="a" && choice!="A" && choice!="b" && choice!="B" && choice!="c" && choice!="C" && choice!="d" && choice!="D" && choice!="e" && choice!="E")
        {
            cout<<"Please pick a valid choice: "<<endl;
            getline(cin, choice);
            if(choice=="a" || choice=="A" || choice=="b" || choice=="B" || choice=="c" || choice=="C" || choice=="d" || choice=="D" || choice=="e" || choice=="E")
            {
                break;
            }
        }
    }
    /*
    -Load file containing parts.
    -Load file containing complete bikes.
    -Load file containing users and bikes.
    -Ask the user whether they want to build a bike, see their current bikes and components of each bike, change a bike component, get a bike reomemended to them, or quit the program.
    -If the user wants to see their bikes, output each bike name and the components of that bike.
    -If the user wants to build a bike, they will pick their components and name the bike.
    -The user can choose to change a component of an existing bike.
    -The user can ask for a bike recommendation for a certain type of bike.
    -If the user quits the program, any new data is written to the user and bike files is saved.
    */
}