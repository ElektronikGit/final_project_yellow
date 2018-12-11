//
// Created by Davydov Ivan on 15/04/2018.
//

#include "test_runner.h"



void Assert(bool b, const std::string& hint) {
    AssertEqual(b, true, hint);
}

TestRunner::~TestRunner() {
    if (fail_count > 0) {
        std::cerr << fail_count << " unit tests failed. Terminate" << std::endl;
        exit(1);
    }
}