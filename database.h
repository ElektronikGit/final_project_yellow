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
    void Add(Date date, const std::string& event) {
        auto& v = db_[date];

        if (std::find(v.begin(), v.end(), event) == v.end()) {
            v.push_back(event);
        }
    }

    void Print(std::ostream& cout) {
        for (const auto& day : db_) {
            for (const auto& event : day.second) {
                cout << day.first << " " << event << std::endl;
            }
        }
    }

    int RemoveIf(const std::function<bool(Date, std::string&)>& predicate) {
        int n = 0;

        auto itm = db_.begin();
        while (itm != db_.end()) {
            auto itv = itm->second.begin();
            while (itv != itm->second.end()) {
                if (predicate(itm->first, *itv)) {
                    itv = itm->second.erase(itv);
                    n++;
                } else {
                    itv++;
                }
            }

            if (itm->second.empty()) {
                itm = db_.erase(itm);
            } else {
                itm++;
            }
        }

        return n;
    }

    std::vector<Event> FindIf(const std::function<bool(Date, const std::string&)>& predicate) {
        std::vector<Event> events;

        for (const auto& day : db_) {
            for (const auto& event : day.second) {
                if (predicate(day.first, event)) {
                    events.emplace_back(day.first, event);
                }
            }
        }

        return events;
    }

    Event Last(const Date& date) {
        for (auto it = db_.rbegin(); it != db_.rend(); it++) {
            if (date >= it->first) return {it->first, it->second.back()};
        }

        throw invalid_argument("");
    }
private:
    std::map<Date, std::vector<std::string>> db_;
};
