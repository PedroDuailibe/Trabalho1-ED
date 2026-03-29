#include <iostream>
#include "ReservationSystem.hpp"
#include "ReservationRequest.hpp"

int main() {

    int capacities[] = {40, 20};
    std::cout << "Criamos um sistema de reservas com duas salas\n";
    std::cout << "Com capacidades 40 e 20, respectivamente\n";
    ReservationSystem FGV(2, capacities);

    std::cout << "\n___ Testando requests ___\n"; 

    std::cout << "ReservationRequest medida(\"Medida\", \"segunda\", 8, 10, 25)\n";
    ReservationRequest medida("Medida", "segunda", 8, 10, 25);
    if (FGV.reserve(medida)) {
        std::cout << "SUCESSO!\n\n";
    } else {
        std::cout << "ERRO!\n\n";
    }
    std::cout << "ReservationRequest ed(\"Estrutura de Dados\", \"segunda\", 9, 11, 20)\n";
    ReservationRequest ed("Estrutura de Dados", "segunda", 9, 11, 20);
    if (FGV.reserve(ed)) {
        std::cout << "SUCESSO!\n\n";
    } else {
        std::cout << "ERRO!\n\n";
    }
    std::cout << "ReservationRequest analise(\"Análise\", \"quarta\", 15, 17, 50)\n";
    std::cout << "Deve dar erro, pois nenhuma sala comporta todos os alunos\n";
    ReservationRequest analise("Análise", "quarta", 15, 17, 50); 
    if (FGV.reserve(analise)) {
        std::cout << "SUCESSO!\n\n";
    } else {
        std::cout << "ERRO!\n\n";
    }
    std::cout << "ReservationRequest probabilidade(\"Probabilidade\", \"terca\", 15, 17, 20);\n";
    ReservationRequest probabilidade("Probabilidade", "terca", 15, 17, 20);
    if (FGV.reserve(probabilidade)) {
        std::cout << "SUCESSO!\n\n";
    } else {
        std::cout << "ERRO!\n\n";
    }
    std::cout << "ReservationRequest vetorial(\"Calculo vetorial\", \"terca\", 14, 16, 30);\n";
    std::cout << "Deve dar erro, pois a primeira sala não tem tal horário disponível,\n";
    std::cout << "E a segunda não comporta o total de alunos\n";
    ReservationRequest vetorial("Calculo vetorial", "terca", 14, 16, 30);
    if (FGV.reserve(vetorial)) {
        std::cout << "SUCESSO!\n\n";
    } else {
        std::cout << "ERRO!\n\n";
    }
    std::cout << "ReservationRequest calculo(\"calculo\", \"segunda\", 12, 13, 25)\n";
    ReservationRequest calculo("calculo", "segunda", 12, 13, 25);
    if (FGV.reserve(calculo)) {
        std::cout << "SUCESSO!\n\n";
    } else {
        std::cout << "ERRO!\n\n";
    }
    std::cout << "ReservationRequest algebra(\"algebra\", \"sexta\", 19, 21, 15)\n";
    ReservationRequest algebra("algebra", "sexta", 19, 21, 15);
    if (FGV.reserve(algebra)) {
        std::cout << "SUCESSO!\n\n";
    } else {
        std::cout << "ERRO!\n\n";
    }

    std::cout << "\n___ Testando cancelamentos ___\n";

    std::cout << "FGV.cancel(\"Matemática\")\nDeve dar erro pois não há disciplina Matemática\n";
    if(FGV.cancel("Matemática"))
    {
        std::cout<<"SUCESSO!\n\n";
    } else {
        std::cout << "ERRO!\n\n";
    }
    std::cout << "FGV.cancel(\"Probabilidade\")\n";
    if(FGV.cancel("Probabilidade"))
    {
        std::cout<<"SUCESSO!\n\n";
    } else {
        std::cout << "ERRO!\n\n";
    }
    std::cout << "FGV.cancel(\"Probabilidade\")\nDeve dar erro, pois probabilidade já foi excluída\n";
    if(FGV.cancel("Probabilidade"))
    {
        std::cout<<"SUCESSO!\n\n";
    } else {
        std::cout << "ERRO!\n\n";
    }

    std::cout << "----Testando schedule-----\n";
    FGV.printSchedule();
    return 0;
}
