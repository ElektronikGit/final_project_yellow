//
// Created by Davydov Ivan on 02/07/2018.
//

#ifndef FINAL_PROJECT_DATE_H
#define FINAL_PROJECT_DATE_H

#endif //FINAL_PROJECT_DATE_H

#pragma once

#include <iostream>
#include <sstream>
#include <iomanip>

class Date {
public:
    Date(int year, int month, int day)
    : year_(year)
    , month_(month)
    , day_(day)
    , formatted_date_((year * 100 + month) * 100 + day)
    {}

    int FormattedDate() const { return formatted_date_; }

    int GetYear() const { return year_; }
    int GetMonth() const { return month_; }
    int GetDay() const { return day_; }
private:
    int day_, month_, year_;
    int formatted_date_;
};

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
