//
// Created by Davydov Ivan on 15/04/2018.
//

#ifndef BUILD_PROJECT_TEST_RUNNER_H
#define BUILD_PROJECT_TEST_RUNNER_H

#endif //BUILD_PROJECT_TEST_RUNNER_H

#pragma once

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <sstream>



template <class T>
std::ostream& operator << (std::ostream& os, const std::vector<T>& s) {
    os << "{";

    bool first = true;
    for (const auto& i : s) {
        if (!first) {
            os << ", ";
        }

        first = false;

        os << i;
    }

    return os << "}";
}

template <class T>
std::ostream& operator << (std::ostream& os, const std::set<T>& s) {
    os << "{";

    bool first = true;
    for (const auto& i : s) {
        if (!first) {
            os << ", ";
        }

        first = false;

        os << i;
    }

    return os << "}";
}

template <class K, class V>
std::ostream& operator << (std::ostream & os, const std::map<K, V>& m) {
    os << "{";

    bool first = true;
    for (const auto& i : m) {
        if (!first) {
            os << ", ";
        }

        first = false;

        os << i.first << ": " << i.second;
    }

    return os << "}";
}

template <class T, class U>
void AssertEqual(const T& t, const U& u, const std::string& hint) {
    if (t != u) {
        std::ostringstream os;
        os << "Assertion failed: " << t << " != " << u;

        if (!hint.empty()) {
            os << " hint: " << hint;
        }


        throw std::runtime_error(os.str());
    }
}

void Assert(bool b, const std::string& hint);

class TestRunner {
public:
    template <class TestFunc>
    void RunTest(TestFunc func, const std::string &test_name) {
        try {
            func();
            std::cerr << test_name << " OK" << std::endl;
        } catch (std::exception& ex) {
            std::cerr << test_name << "failed: " << ex.what() << std::endl;
            ++fail_count;
        }
    }

    ~TestRunner();
private:
    int fail_count = 0;
};