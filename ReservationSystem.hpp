#pragma once

#include "ReservationRequest.hpp"

struct ReserveNode {
    ReservationRequest* Request;
    ReserveNode* Next;

    ReserveNode();
    ~ReserveNode();

    void insert(ReservationRequest *request, ReserveNode *next);
    void SetNext(ReserveNode* next);
    int GetDay();
    int GetStartHour();
    int GetEndHour();
};

class ReservationSystem {

private:
    int room_count;
    int* room_capacities;

    ReserveNode** rooms;

public:

    ReservationSystem(int room_count, int* room_capacities);
    ~ReservationSystem();

    bool reserve(ReservationRequest request);
    bool cancel(std::string course_name);

    void printSchedule();

};
