
/*

    4/10/2016
    -user input for event (not all fields)
    -user is able to make a chnage for the event 
    -show the events 






*/
#endif // EVENT_H


#ifndef EVENT_H
#define EVENT_H
#include "time.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

class Event{
    public:
        Event(time_t start, time_t end,char* location);
        Event();
        virtual ~Event();
        int menu();
        vector<Event> fillVector(vector<Event>& eventList);
        void getLocation(vector<Event>& eventList,int index);
        void getUserinfo();
        time_t getStartTime(vector<Event>& eventList,int index);
        void getEndTime(time_t start,vector<Event>& eventList,int index);
        void getDate();
        void makeChange(vector<Event>& evetList);
        int pickChangeField(vector<Event>& evetList, int choice);
        void changeField(vector<Event>& evetList, int index,int field);

        double get_location_x();
        void set_location_x(double a);
        double get_location_y();
        void set_location_y(double a);
        unsigned int get_duration();
        unsigned int set_duration(unsigned int a);
        time_t get_start_time();
        void set_start_time(time_t a);
        int get_end_time();
        void set_end_time(int a);
        char* get_location_name(int i);
        void set_location_name();
        void set_user_loaction(char* i);
        char* get_user_loaction();
        void set_sleep_time_begin(time_t slee_time_begin);
        time_t get_sleep_time_begin();
        void set_sleep_time_end(time_t slee_time_end);
        time_t get_sleep_time_end();
    protected:

    private:
        double location_x;
        double location_y;
        unsigned int duration;
        time_t start_time;
        time_t end_time;
        char** location_name;///name of the location that event happends
        char* subject_name;///class or go to gym
        time_t sleep_time_begin;
        time_t sleep_time_end;
        char* user_loaction;

};



#endif // EVENT_H
