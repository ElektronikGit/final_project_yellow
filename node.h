//
// Created by Davydov Ivan on 17/07/2018.
//

#ifndef FINAL_PROJECT_NODE_H
#define FINAL_PROJECT_NODE_H

#endif //FINAL_PROJECT_NODE_H

#pragma once

#include "token.h"
#include "date.h"
#include "database.h"

class Node {
public:
    virtual bool Evaluate(const Date& date, const std::string& event) = 0;
};

class EventComparisonNode : public Node {
public:
    EventComparisonNode(Comparison cmp, const std::string& event)
    : cmp_(cmp)
    , event_(event)
    {}

    bool Evaluate(const Date& date, const std::string& event) override;
private:
    Comparison cmp_;
    std::string event_;
};

class DateComparisonNode : public Node {
public:
    DateComparisonNode(Comparison cmp, Date date)
    : cmp_(cmp)
    , date_(date) {}

    bool Evaluate(const Date& date, const std::string& event) override;
private:
    Comparison cmp_;
    Date date_;
};

class LogicalOperationNode : public Node {
public:
    LogicalOperationNode(const LogicalOperation& logical_operation, const shared_ptr<Node>& left, const shared_ptr<Node>& right)
    : logical_operation_(logical_operation)
    , left_(left)
    , right_(right) {}

    bool Evaluate(const Date& date, const std::string& event) override;
private:
    LogicalOperation logical_operation_;
    shared_ptr<Node> left_, right_;
};

class EmptyNode : public Node {
    bool Evaluate(const Date& date, const std::string& event) override;
};
