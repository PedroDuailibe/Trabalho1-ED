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

struct lista{
    ReserveNode* head;
    int size;

    lista();
    ~lista();
};

class ReservationSystem {

private:
    int room_count;
    int* room_capacities;

    lista* rooms;

public:

    ReservationSystem(int room_count, int* room_capacities);
    ~ReservationSystem();

    bool reserve(ReservationRequest request);
    bool cancel(std::string course_name);

    void printSchedule();

};
