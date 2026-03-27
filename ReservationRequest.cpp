#include<iostream>

class ReservationRequest {

private:

    std::string course_name;
    std::string weekday;
    int start_hour;
    int end_hour;
    int student_count;

public:

    ReservationRequest(std::string course_name, std::string weekday, int start_hour, int end_hour, int student_count)
      : course_name(course_name)
      , weekday(weekday)
      , start_hour(start_hour)
      , end_hour(end_hour)
      , student_count(student_count)
    {
    }

    ~ReservationRequest()
    {
    }

    int getStartHour();
    int getEndHour();
    std::string getCourseName();
    std::string getWeekday();
    int getStudentCount();
};
