#include "event.h"
#include "string.h"
#include "time.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

///contractor
Event::Event(time_t start, time_t end,char* location){
    location_x = 0;
    location_y = 0;
    duration =0;
    start_time =start;
    end_time =end;
    user_loaction = location;
    //location_name = new char*[25];///name is no more than 25 character
    //set_location_name();
}

Event::Event(){
    location_name = new char*[25];
    set_location_name();
}

Event::~Event()
{
    //dtor
}

void Event::getDate(){
    ///get event date
}//end of getDate

time_t Event::getStartTime(vector<Event>& eventList,int index){
    int* time = new int[24];
    time_t Start;
    bool valid = true;

    std::cout<<"choose statring time: "<<endl;

    ///time frame of 0-24
    for(int i=0;i<24;i++){
        time[i] = i;
        cout<<i+1<<". "<< time[i]<<endl;
    }

    while(valid){
        cin>>Start;
        if(cin.fail() ||Start>23 || Start<1){
            std::cout<<"\n*** Invalid input ***\n";
            std::cout<<"    Enter an Integer\n";
            cin.clear();
            cin.ignore(255, '\n');
            continue;
        }

        eventList[index].set_start_time(time[Start-1]);///initializing
        //start_time = time[Start-1];
        valid = false;
    }

    return Start;
}

void Event::getEndTime(time_t start,vector<Event>& eventList,int index){
    time_t endTime;
    int end;
    bool valid = true;
    int* time = new int[24];
    for(int i=0;i<24;i++)
        time[i] = i;


    cout<<"Pick ending time"<<endl;
    for(int i=0;i<24;i++){
        if(i>start)
            cout<<i+1<<". "<< time[i]<<endl;
    }


    while(valid){
        cin>>end;
        if(cin.fail() ||end>24 || end<1 || end<start+2){
            std::cout<<"\n*** Invalid input ***\n";
            std::cout<<"    Enter an Integer\n";
            cin.clear();
            cin.ignore(255, '\n');
            continue;
        }
        eventList[index].set_end_time(time[end-1]);
        //set_end_time(time[end-1]);
        valid = false;
    }


}//end of getEndTime

int Event::menu(){
    int choice;
    std::cout<<"1. Add Event"<<endl;
    std::cout<<"2. show list"<<endl;
    std::cout<<"3. change an event"<<endl;
    std::cout<<"4. "<<endl;
    std::cout<<"5. Exit"<<endl;
    std::cout<<":";
    std::cin >> choice;

    return choice;
}

void Event::getLocation(vector<Event>& eventList,int index){
    bool valid = true;
    int choice;
    for(int i=0;i<25;i++){
        cout<<i+1<<". "<<location_name[i]<<endl;
    }
    cin>>choice;

    while(valid){
        if(choice<1 || cin.fail() ||choice>26){
            cout<<"+++ invalid input +++\n\n\n";
            continue;
        }
        valid = false;
    }
    ///initializing location by using location setter 
    eventList[index].set_user_loaction(location_name[choice-1]);

}
void Event::getUserinfo(){

    getDate();
   // getLocation();


}//end of getUserinfo


double Event::get_location_x(){
    return location_x;
}
void Event::set_location_x(double location_x){
    this->location_x = location_x;
}

double Event::get_location_y(){
    return location_y;
}

void Event::set_location_y(double location_y){
    this->location_y = location_y;
}

unsigned int Event::get_duration(){
    return duration;
}
unsigned int Event::set_duration(unsigned int duration){
    this->duration = duration;
}
time_t Event::get_start_time(){
    return start_time;
}
void Event::set_start_time(time_t start_time){
    this->start_time = start_time;
}

int Event::get_end_time(){
    return end_time;
}
void Event::set_end_time(int end_time){
    this->end_time = end_time;
}
char* Event::get_location_name(int i){
    return location_name[i];
}

void Event::set_sleep_time_begin(time_t slee_time_begin){
    this->sleep_time_begin = slee_time_begin;
}
time_t Event::get_sleep_time_begin(){
    return sleep_time_begin;
}

void Event::set_sleep_time_end(time_t slee_time_end){
    this->sleep_time_end = slee_time_end;
}
time_t Event::get_sleep_time_end(){
    return sleep_time_end;
}

void Event::set_user_loaction(char* input){
    user_loaction = input;
}

char* Event::get_user_loaction(){
    return user_loaction;
}
void Event::set_location_name(){

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


///this function has not been used 
vector<Event> Event::fillVector(vector<Event>& eventList){
    vector<Event> newEvnetLists;
    return newEvnetLists;
}

void Event::makeChange(vector<Event>& evetList){

   int index;
   bool valid = true;

   if(evetList.size() ==0){
        cout<<"No items to show\n\n";
        return;
   }
   for(int i=0;i<evetList.size();i++){
        cout<<i+1 <<evetList[i].get_user_loaction()<<endl;
   }

   while(valid){
        cin>>index;
        if(index<1 || cin.fail() ||index>evetList.size()){
            cout<<"+++ invalid input +++\n\n\n";
            cin.clear();
            cin.ignore(255, '\n');
            continue;
        }
        valid = false;
   }

    int field = pickChangeField(evetList,index);///which field to edit
    changeField(evetList,index-1,field);
}

void Event::changeField(vector<Event>& evetList, int index,int field){

    switch(field){
        case 1:
            getStartTime(evetList,index);
            break;
        case 2:
            getEndTime(evetList[index].get_start_time(),evetList,index);
            break;
        case 3:
            getLocation(evetList,index);
            break;
    }
}

int Event::pickChangeField(vector<Event>& evetList, int choice){
    int num;
    bool valid = true;

    cout<<"which field do you want to make a change\n";
    cout<<"1 "<<"Event start"<<evetList[choice-1].get_start_time()<<endl;
    cout<<"2 "<<"Event End "<<evetList[choice-1].get_end_time()<<endl;
    cout<<"3 "<<"Location : "<<evetList[choice-1].get_user_loaction()<<endl<<endl;


    while(valid){
        cin>>num;
        if(num<0 || cin.fail() ||num>3){
            cout<<"+++ invalid input +++\n\n\n";
            cin.clear();
            cin.ignore(255, '\n');
            continue;
        }
        valid = false;
    }

    return num;
}
void showVector(vector<Event>& evetList);

int main(){

    Event* event = new Event();
    int choice = event->menu();

    vector<Event> evetList;

    while(choice!= 5){

        switch(choice){
            case 1:{
                ///create new object for an event
                Event* newEvent = new Event();
                ///add new event to evetlist
                evetList.push_back(*newEvent);

                int index = evetList.size()-1;
                time_t start = event->getStartTime(evetList,index);
                event->getEndTime(start,evetList,index);
                event->getLocation(evetList,index);

                break;
                }
            case 2:{
                showVector(evetList);
                break;
                }
            case 3:{
                event->makeChange(evetList);
            }

        }//end of switch
        //cout<<"size : "<<evetList.size()<<endl;

        choice = event->menu();
    }//ebd of while
    return 0;
}

void showVector(vector<Event>& evetList){

    if(evetList.size() == 0 ){
        cout<<"No items to show\n\n";
        return;
    }

   for(int i=0;i<evetList.size();i++){
            cout<<i+1<<"\n";
            cout<<"Event start"<<evetList[i].get_start_time()<<endl;
            cout<<"Event End "<<evetList[i].get_end_time()<<endl;
            cout<<"Location : "<<evetList[i].get_user_loaction()<<endl<<endl;
    }
}
