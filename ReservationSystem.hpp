#include <iostream>
#include "ReservationRequest.hpp"

class ReservationSystem {

private:
    int room_count;
    int* room_capacities;

    // Estruturas internas escolhidas pelos alunos
    // para armazenar e gerenciar as reservas, os horários, ...
    struct ReserveNode {
        std::string course_name;
        std::string weekday;
        int start_hour;
        int end_hour;
        int room_index;
        ReserveNode* next;
    };

    ReserveNode* head;

public:

    ReservationSystem(int room_count, int* room_capacities);
    ~ReservationSystem();

    bool reserve(ReservationRequest request);
    bool cancel(std::string course_name);

    void printSchedule();

    // Outros métodos utilitários necessários
    // para auxiliar nas funções requisitadas
};
