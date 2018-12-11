//
// Created by Davydov Ivan on 17/07/2018.
//

#include "database.h"

void Database::Add(Date date, const std::string& event) {
    auto& v = db_[date];

    if (std::find(v.begin(), v.end(), event) == v.end()) {
        v.push_back(event);
    }
}

void Database::Print(std::ostream& cout) {
    for (const auto& day : db_) {
        for (const auto& event : day.second) {
            cout << day.first << " " << event << std::endl;
        }
    }
}

int Database::RemoveIf(const std::function<bool(Date, std::string&)>& predicate) {
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

std::vector<Event> Database::FindIf(const std::function<bool(Date, const std::string&)>& predicate) {
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

Event Database::Last(const Date& date) {
    for (auto it = db_.rbegin(); it != db_.rend(); it++) {
        if (date >= it->first) return {it->first, it->second.back()};
    }

    throw invalid_argument("");
}
