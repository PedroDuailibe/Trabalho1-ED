#include <iostream>
#include "ReservationSystem.hpp"
#include "ReservationRequest.hpp"

int main() {
    int capacities[] = {40, 20};
    ReservationSystem FGV(2, capacities);

    ReservationRequest req1("Medida", "segunda", 8, 10, 25);
    if (FGV.reserve(req1)) {
        std::cout << "SUCESSO!\n";
    } else {
        std::cout << "ERRO!\n";
    }

    ReservationRequest req2("Estrutura de Dados", "terca", 9, 11, 20);
    if (FGV.reserve(req2)) {
        std::cout << "SUCESSO!\n";
    } else {
        std::cout << "ERRO!\n";
    }

    ReservationRequest req3("Análise", "quarta", 15, 17, 10); 
    if (FGV.reserve(req3)) {
        std::cout << "SUCESSO!\n";
    } else {
        std::cout << "ERRO!\n";
    }

    ReservationRequest req4("Probabilidade", "quinta", 15, 17, 20);
    if (FGV.reserve(req4)) {
        std::cout << "SUCESSO!\n";
    } else {
        std::cout << "ERRO!\n";
    }

    ReservationRequest req5("Monitoria", "sexta", 15, 17, 20);
    if (FGV.reserve(req5)) {
        std::cout << "SUCESSO!\n";
    } else {
        std::cout << "ERRO!\n";
    }

    ReservationRequest req6("Fundamentos", "quinta", 16, 17, 30);
    if (FGV.reserve(req6)) {
        std::cout << "SUCESSO!\n";
    } else {
        std::cout << "ERRO!\n";
    }

    if(FGV.cancel("Matemática"))
    {
        std::cout<<"SUCESSO!\n";
    } else {
        std::cout << "ERRO!\n";
    }

    if(FGV.cancel("Probabilidade"))
    {
        std::cout<<"SUCESSO!\n";
    } else {
        std::cout << "ERRO!\n";
    }

    if(FGV.cancel("Probabilidade"))
    {
        std::cout<<"SUCESSO!\n";
    } else {
        std::cout << "ERRO!\n";
    }

    FGV.printSchedule();
    return 0;
}
