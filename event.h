#ifndef EVENT_H
#define EVENT_H
#include "time.h"

class event{
    public:
        event();
        virtual ~event();
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

};

#endif // EVENT_H

