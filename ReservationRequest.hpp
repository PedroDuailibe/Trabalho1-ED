#pragma once
#include <iostream>

class ReservationRequest {

private:
    std::string course_name;
    std::string weekday;
    int start_hour;
    int end_hour;
    int student_count;

public:

    ReservationRequest(std::string course_name, std::string weekday, int start_hour, int end_hour, int student_count);
    ~ReservationRequest();

    std::string getCourseName();
    std::string getWeekday();
    int getStartHour();
    int getEndHour();
    int getStudentCount();
    int MapDayToNumber();
};
