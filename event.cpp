#include "event.h"
#include "string.h"
#include "time.h"

///contractor
event::event(){
    location_x = 0;
    location_y = 0;
    duration =0;
    start_time =0;
    end_time =0;
    location_name = new char*[25];///name is no more than 25 character
    set_location_name();
}

event::~event()
{
    //dtor
}

double event::get_location_x(){
    return location_x;
}
void event::set_location_x(double location_x){
    this->location_x = location_x;
}

double event::get_location_y(){
    return location_y;
}

void event::set_location_y(double location_y){
    this->location_y = location_y;
}

unsigned int event::get_duration(){
    return duration;
}
unsigned int event::set_duration(unsigned int duration){
    this->duration = duration;
}
time_t event::get_start_time(){
    return start_time;
}
void event::set_start_time(time_t start_time){
    this->start_time = start_time;
}

int event::get_end_time(){
    return end_time;
}
void event::set_end_time(int end_time){
    this->end_time = end_time;
}
char* event::get_location_name(int i){
    return location_name[i];
}

void event::set_sleep_time_begin(time_t slee_time_begin){
    this->sleep_time_begin = slee_time_begin;
}
time_t event::get_sleep_time_begin(){
    return sleep_time_begin;
}

void event::set_sleep_time_end(time_t slee_time_end){
    this->sleep_time_end = slee_time_end;
}
time_t event::get_sleep_time_end(){
    return sleep_time_end;
}
void event::set_location_name(){
    strcpy(location_name[0],"Library West");
    strcpy(location_name[1],"Library Marston");
    strcpy(location_name[2],"Computer Science Building ");
    ///create more location...
}

