#include <iostream>
#include "ReservationRequest.hpp"

// Construtor ReservationRequest
ReservationRequest::ReservationRequest(
    std::string course_name,
    std::string weekday,
    int start_hour,
    int end_hour,
    int student_count)
{
    if (start_hour < 7 || end_hour > 21 || start_hour >= end_hour) {
        std::cerr << "Horário inválido\n";
    }

    course_name = course_name;
    weekday = weekday;
    start_hour = start_hour;
    end_hour = end_hour;
    student_count = student_count;
}

// Método destrutor
ReservationRequest::~ReservationRequest() {
}

// Horário de início do curso
int ReservationRequest::getStartHour() {
    return start_hour;
}

// Horário de término do curso
int ReservationRequest::getEndHour() {
    return end_hour;
}

// Nome do curso
std::string ReservationRequest::getCourseName() {
    return course_name;
}

// Dia da semana do curso
std::string ReservationRequest::getWeekday() {
    return weekday;
}

// Quantidade de alunos
int ReservationRequest::getStudentCount() {
    return student_count;
}

// Dia da semana para número
int ReservationRequest::MapDayToNumber() {

    if (weekday == "segunda") {
        return 1;
    }
    
    if (weekday == "terca") {
        return 2;
    }

    if (weekday == "quarta") {
        return 3;
    }
    
    if (weekday == "quinta") {
        return 4;
    }
    
    if (weekday == "sexta") {
        return 5;
    }

    return 0;
}