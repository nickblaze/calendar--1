#include "Soft.h"
#include "string.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

Soft::Soft(){
    //ctor

    location_name = new char*[25];
    set_location_name();
}


Soft::~Soft()
{
    //dtor
}

void Soft::getDuration(vector<Soft>& softEvent,int index){

    bool valid = true;
    int estimatedHours;
    cout<<"How long Do you think it's going to take?\n";
    cout<<"Enter extimated hour no more than 15 hours \n";

    while(valid){
        cin>>estimatedHours;
        if(estimatedHours<1 || cin.fail() ||estimatedHours>15){
            cout<<"+++ invalid input +++\n\n\n";
            continue;
        }
        valid = false;
    }

    softEvent[index].set_duration(estimatedHours);
}

void Soft::getLocation(vector<Soft>& softEvent,int index){
    bool valid = true;
    int pick;
    cout<<"choose location\n";

    for(int i=0;i<25;i++){
        cout<<i+1<<". "<<get_location_name(i)<<endl;
    }

    while(valid){
        cin>>pick;
        if(pick<1 || cin.fail() ||pick>25){
            cout<<"+++ invalid input +++\n\n\n";
            continue;
        }
        valid = false;
    }

    softEvent[index].set_user_location(get_location_name(pick-1));
}

///getter and setter
void Soft::set_location_name(){
    for(int i=0;i<25;i++){
        location_name[i] = new char[25];
        for(int j=0;j<25;j++){
            location_name[i][j] = '\0';
        }
    }

    strcpy(location_name[0],"Library West");
    strcpy(location_name[1],"Library Marston");
    strcpy(location_name[2],"Computer Science Building ");
    ///create more location...
}

char* Soft::get_location_name(int i){
    return location_name[i];
};

int Soft::get_day(){
    return day;
}
void Soft::set_day(int day){
    this->day =day;
}

int Soft::get_month(){
    return  month;
}

void Soft::set_month(int month){
    this->month =month;
}

int Soft::get_hour(){
    return time_hour;
}
void Soft::set_hour(int hour){
    this->time_hour =hour;
}

int Soft::get_min(){
    return  time_min;
}

void Soft::set_min(int time_min){
    this->time_min=time_min;
}

int Soft::get_duration(){
    return  duration;
}

void Soft::set_duration(int duration){
    this->duration = duration;
}
void Soft::set_user_location(char* a){
    this->user_loaction = a;
}
char* Soft::get_user_location(){
    return this->user_loaction;
}

