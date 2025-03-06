#ifndef EVENT_H
#define EVENT_H
#include "wire.h"

struct Event
{
    uint64_t time;
    Wire* wire;
    char state;
};

typedef struct EventLess {
        //write the operator() required to make this a functor that compares Events by time
        bool operator () (const Event* e1, const Event* e2) const {
            return e2->time > e1->time; // For Min Heap: ealier events have higher priority
        }
} EventLess;
	
#endif
