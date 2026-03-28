#pragma once

#include "ReservationRequest.hpp"

struct ReserveNode {
    ReservationRequest* Request;
    ReserveNode* Next;

    ReserveNode();
    ~ReserveNode();

    std::string GetExtendedDay();
    std::string GetCourseName();
    void exibir();
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

std::string MapNumberToDay(int dia);
void AdicionarSala(ReservationRequest& request, lista& reservas);
bool SalaDisponivel(ReservationRequest& request, lista& reservas);
void printar(lista reservas);