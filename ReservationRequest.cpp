#include <iostream>
#include "ReservationRequest.hpp"

ReservationRequest::ReservationRequest(std::string course_name, std::string weekday, int start_hour, int end_hour, int student_count)
  : course_name(course_name)
  , weekday(weekday)
  , start_hour(start_hour)
  , end_hour(end_hour)
  , student_count(student_count)
{
    if (start_hour < 7 || end_hour > 21 || start_hour >= end_hour)
    {
        std::cerr << "Horário inválido." << "\n"; 
    }

}

ReservationRequest::~ReservationRequest()
{
}

int ReservationRequest::getStartHour() { return start_hour; }
int ReservationRequest::getEndHour() { return end_hour; }
std::string ReservationRequest::getCourseName() { return course_name; }
std::string ReservationRequest::getWeekday() { return weekday; }
int ReservationRequest::getStudentCount() { return student_count; }
