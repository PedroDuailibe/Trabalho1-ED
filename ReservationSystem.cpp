#include <iostream>
#include "ReservationRequest.hpp"

class ReservationSystem {

private:
    int room_count;
    int* room_capacities;

    // Estruturas internas escolhidas pelos alunos
    // para armazenar e gerenciar as reservas, os horários, ...

public:

    ReservationSystem(int room_count, int* room_capacities)
      : room_count(room_count)
      , room_capacities(new int[room_count])
    {
        for (int i = 0; i < room_count; i++)
        {
            this->room_capacities[i] = room_capacities[i];
        }
    }
    
    ~ReservationSystem()
    {
        delete[] room_capacities;
    }

    bool reserve(ReservationRequest request);
    bool cancel(std::string course_name);

    void printSchedule();

    // Outros métodos utilitários necessários
    // para auxiliar nas funções requisitadas
};
