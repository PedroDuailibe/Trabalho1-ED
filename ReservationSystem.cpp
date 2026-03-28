#include "ReservationSystem.hpp"

// Construtor ReserveNode
ReserveNode::ReserveNode() {
    Request = nullptr;
    Next = nullptr;
}

// Destrutor ReserveNode
ReserveNode::~ReserveNode() {
    delete Request;
}

// Atualizar o next
void ReserveNode::SetNext(ReserveNode* next) {
    Next = next;
}

// Inserir informações
void ReserveNode::insert(ReservationRequest* request, ReserveNode* next) {
    SetNext(next);
    Request = request;
}

// Pega o dia em número
int ReserveNode::GetDay() {
    return Request->MapDayToNumber();
}

int ReserveNode::GetStartHour() {
    return Request->getStartHour();
}

int ReserveNode::GetEndHour() {
    return Request->getEndHour();
}

// Construtor ReservationSystem
ReservationSystem::ReservationSystem(int RoomCount, int* RoomCapacities) {
    room_count = RoomCount;
    room_capacities = new int [RoomCount];
    for (int i = 0; i < RoomCount; i++){
        room_capacities[i] = RoomCapacities[i];
    }

    // Inicializa os rooms com nullptrs
    rooms = new ReserveNode*[RoomCount]();
}

// Destrutor ReservationSytem
ReservationSystem::~ReservationSystem() {
    delete[] room_capacities;

    for(int i = 0; i < room_count; i++) {
        ReserveNode* current = rooms[i];
        
        while(current != nullptr) {
            ReserveNode* aux = current;
            current = current->Next;
            delete aux;
        }
    }
    delete[] rooms;
}

// Verifica se uma sala atende aquela demanda
bool SalaDisponivel(ReservationRequest request, ReserveNode* reservas) {
    ReserveNode* curr = reservas;

    if(curr == nullptr) {
        return true;
    }

    int day = request.MapDayToNumber();
    int start = request.getStartHour();
    int end = request.getEndHour();

    while(curr != nullptr) {

        int curr_day = curr->GetDay();

        if(day > curr_day) {
            curr = curr->Next;
            continue;
        }

        if(day < curr_day) {
            return true;
        }

        int curr_start = curr->GetStartHour();
        int curr_end = curr->GetEndHour();

        if (start < curr_end && curr_start < end) {
            return false;
        }

        curr = curr->Next;
    }

    return true;
}

void AdicionarSala(ReservationRequest request, ReserveNode*& reservas) {
    ReserveNode* curr = reservas;
    ReserveNode* aux = curr;

    if(curr == nullptr) {
        ReserveNode* n = new ReserveNode();
        
        n->insert(new ReservationRequest(request), nullptr);
        return;
    }

    int day = request.MapDayToNumber();
    int start = request.getStartHour();
    int end = request.getEndHour();

    while(curr != nullptr) {
        curr = curr->Next;

        // aux é o último da lista
        if(curr == nullptr) {
            ReserveNode* n = new ReserveNode();

            n->insert(new ReservationRequest(request), nullptr);
            aux->Next = n;

            return;
        }

        if (day > curr->GetDay()) {
            aux = curr;
            continue;
        }

        if (day < curr->GetDay()) {
            ReserveNode* n = new ReserveNode();

            n->insert(new ReservationRequest(request), curr);
            aux->Next = n;
            return;
        }

        if(end <= curr->GetStartHour()) {
            ReserveNode* n = new ReserveNode();

            n->insert(new ReservationRequest(request), curr);
            aux->Next = n;
            return;
        }

        aux = curr;
    }

}

// Reservar Curso
bool ReservationSystem::reserve(ReservationRequest request) {

    int day = request.MapDayToNumber();

    // Procura por uma sala disponível para a request
    for(int i = 0; i < room_count; i++) 
    {
        if (request.getStudentCount() <= room_capacities[i])
        {
            if(SalaDisponivel(request, rooms[i])) 
            {
                AdicionarSala(request, rooms[i]);
                return true;
            }
        }
    }
    // Não encontrou sala disponível
    return false;
}

// Cancelar Curso
bool ReservationSystem::cancel(std::string course_name) {
    return 0;
}

// Printar informações
void ReservationSystem::printSchedule() {

}
