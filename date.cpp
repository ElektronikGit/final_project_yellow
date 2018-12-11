//
// Created by Davydov Ivan on 02/07/2018.
//

#include "date.h"

bool operator < (const Date& lhs, const Date& rhs) {
    return lhs.FormattedDate() < rhs.FormattedDate();
}

bool operator == (const Date& lhs, const Date& rhs) {
    return lhs.FormattedDate() == rhs.FormattedDate();
}

bool operator > (const Date& lhs, const Date& rhs) {
    return lhs.FormattedDate() > rhs.FormattedDate();
}

bool operator <= (const Date& lhs, const Date& rhs) {
    return !(lhs > rhs);
}

bool operator >= (const Date& lhs, const Date& rhs) {
    return !(lhs < rhs);
}

bool operator != (const Date& lhs, const Date& rhs) {
    return !(lhs == rhs);
}

std::ostream& operator << (std::ostream& os, const Date& date) {
    os << std::setfill('0');
    os << std::setw(4);
    os << date.GetYear();
    os << std::setw(1) << "-";
    os << std::setw(2) << date.GetMonth();
    os << std::setw(1) << "-";
    os << std::setw(2) << date.GetDay();
    return os;
}

Date ParseDate(std::istringstream& is) {
    int year, month, day;

    is >> year;
    is.ignore(1);
    is >> month;
    is.ignore(1);
    is >> day;

    return {year, month, day};
}

typedef std::pair<Date, std::string> Event;

std::ostream& operator << (std::ostream& os, const Event& event) {
    os << event.first << " " << event.second;
    return os;
}
