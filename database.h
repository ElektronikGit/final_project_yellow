//
// Created by Davydov Ivan on 17/07/2018.
//

#ifndef FINAL_PROJECT_DATABASE_H
#define FINAL_PROJECT_DATABASE_H

#endif //FINAL_PROJECT_DATABASE_H

#pragma once

#include "date.h"
#include "node.h"

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

class Database {
public:
    void Add(Date date, const std::string& event);
    void Print(std::ostream& cout);
    int RemoveIf(const std::function<bool(Date, std::string&)>& predicate);
    std::vector<Event> FindIf(const std::function<bool(Date, const std::string&)>& predicate);
    Event Last(const Date& date);
private:
    std::map<Date, std::vector<std::string>> db_;
};
