#include <iostream>
#include "ReservationSystem.hpp"
#include "ReservationRequest.hpp"

int main() {
    int capacities[] = {30, 50};
    ReservationSystem FGV(2, capacities);

    ReservationRequest req1("Medida", "segunda", 8, 10, 25);
    if (FGV.reserve(req1)) {
        std::cout << "SUCESSO!\n";
    } else {
        std::cout << "ERRO!\n";
    }

    ReservationRequest req2("Estrutura de Dados", "segunda", 9, 11, 20);
    if (FGV.reserve(req2)) {
        std::cout << "SUCESSO!\n";
    } else {
        std::cout << "ERRO!\n";
    }

    ReservationRequest req3("Análise", "terca", 14, 16, 60); 
    if (FGV.reserve(req3)) {
        std::cout << "SUCESSO!\n";
    } else {
        std::cout << "ERRO!\n";
    }

    return 0;
}
