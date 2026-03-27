#include <iostream>
#include "ReservationSystem.hpp"

ReservationSystem::ReservationSystem(int room_count, int* room_capacities)
  : room_count(room_count)
  , room_capacities(new int[room_count])
  , head(nullptr)
{
    for (int i = 0; i < room_count; i++)
    {
        this->room_capacities[i] = room_capacities[i];
    }
}

ReservationSystem::~ReservationSystem()
{
    delete [] this->room_capacities;
}

bool ReservationSystem::reserve(ReservationRequest request)
{
    std::string course = request.getCourseName();
    std::string day = request.getWeekday();
    int start = request.getStartHour();
    int end = request.getEndHour();
    int students = request.getStudentCount();

    for (int i = 0; i < room_count; i++)
    {
        if (room_capacities[i] >= students)
        {
            bool available = true;
            ReserveNode* current = head;

            while (current != nullptr)
            {
                if (current->weekday == day && current->room_index == i)
                {
                    if (start < current->end_hour && end > current->start_hour)
                    {
                        available = false;
                        break;
                    }
                }
                current = current->next;
            }

            if (available)
            {
                ReserveNode* new_reservation = new ReserveNode;
                new_reservation->course_name = course;
                new_reservation->weekday = day;
                new_reservation->start_hour = start;
                new_reservation->end_hour = end;
                new_reservation->room_index = i;

                new_reservation->next = head;
                head = new_reservation;

                return true;
            }
        }
    }

    return false;
}
