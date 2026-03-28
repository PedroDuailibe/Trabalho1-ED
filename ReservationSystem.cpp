#include "ReservationSystem.hpp"

// Construtor Lista
lista::lista() {
    head = nullptr;
    size = 0;
}

// Destrutor Lista
lista::~lista() {
}

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

// Nome do curso
std::string ReserveNode::GetCourseName() { return Request->getCourseName(); }

// Dia em número
int ReserveNode::GetDay() { return Request->MapDayToNumber(); }

// Dia extenso
std::string ReserveNode::GetExtendedDay() { return Request->getWeekday(); }

// Início da aula
int ReserveNode::GetStartHour() { return Request->getStartHour(); }

// Final da aula
int ReserveNode::GetEndHour() { return Request->getEndHour(); }

// Exibir()
void ReserveNode::exibir() {
    int start = GetStartHour();
    int end = GetEndHour();
    std::string name = Request->getCourseName();

    std::cout << start << "h~" << end << "h: " << name << "\n";
}

// Construtor ReservationSystem
ReservationSystem::ReservationSystem(int RoomCount, int* RoomCapacities) {
    room_count = RoomCount;
    room_capacities = new int [RoomCount];
    for (int i = 0; i < RoomCount; i++){
        room_capacities[i] = RoomCapacities[i];
    }

    // Inicializa os rooms com nullptrs
    rooms = new lista[room_count]();
}

// Destrutor ReservationSytem
ReservationSystem::~ReservationSystem() {
    delete[] room_capacities;

    for(int i = 0; i < room_count; i++) {
        ReserveNode* current = rooms[i].head;
        
        while(current != nullptr) {
            ReserveNode* aux = current;
            current = current->Next;
            delete aux;
        }

    }
    delete[] rooms;
}

// Verifica se uma sala atende aquela demanda
bool SalaDisponivel(ReservationRequest& request, lista& reservas) {
    ReserveNode* curr = reservas.head;

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

void AdicionarSala(ReservationRequest& request, lista& reservas) {
    ReserveNode* curr = reservas.head;
    ReserveNode* aux = curr;

    if(curr == nullptr) {
        ReserveNode* n = new ReserveNode();
        
        n->insert(new ReservationRequest(request), nullptr);
        reservas.head = n;
        reservas.size += 1;
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

            reservas.size += 1;
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

            reservas.size += 1;
            return;
        }

        if(end <= curr->GetStartHour()) {
            ReserveNode* n = new ReserveNode();

            n->insert(new ReservationRequest(request), curr);
            aux->Next = n;

            reservas.size += 1;
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
        std::cout << "sala " << i << "\n";
        if (request.getStudentCount() > room_capacities[i]) {
            continue;
        }
        
        if(SalaDisponivel(request, rooms[i])) 
        {
            std::cout << "Sala disponível!\n";
            AdicionarSala(request, rooms[i]);
            std::cout << rooms[i].size << '\n';
            return true;
        }

    }
    // Não encontrou sala disponível
    return false;
}

// Cancelar Curso
bool ReservationSystem::cancel(std::string course_name) {
    for (int i = 0; i < room_count; i++)
    {
        ReserveNode* curr = rooms[i].head;
        ReserveNode* prev = nullptr;

        while (curr != nullptr)
        {
            if (curr->Request->getCourseName() == course_name)
            {
                if (prev == nullptr)
                {
                    rooms[i].head = curr->Next;
                    delete curr;
                    rooms[i].size -= 1;
                    return true;
                }
                else {
                    prev->Next = curr->Next;
                }
                delete curr;
                rooms[i].size -= 1;
                return true;
            }

            prev = curr;
            curr = curr->Next;
        }
    }
    return false;
}

// Número para dia da semana
std::string MapNumberToDay(int dia) {
    if (dia == 1) { return "segunda"; }
    if (dia == 2) { return "terca"; }
    if (dia == 3) { return "quarta"; }
    if (dia == 4) { return "quinta"; }
    if (dia == 5) { return "sexta"; }
}

void printar(lista reservas) {

    ReserveNode* curr = reservas.head;
    int dia = curr->GetDay();

    while(true) {

        dia = curr->GetDay();
        std::string dia_string = MapNumberToDay(dia);
        std::cout << dia_string << "\n";

        while(curr->GetDay() == dia) {
            curr->exibir();
            curr = curr->Next;

            if (curr == nullptr) {
                return;
            }

        }

    }

}

// Printar informações
void ReservationSystem::printSchedule() {

    for(int i = 0; i < room_count; i++) {

        if (rooms[i].head == nullptr) {
            continue;
        }

        std::cout << "Sala " << i + 1 << '\n';
        printar(rooms[i]);
    }
}
