//
// Created by Davydov Ivan on 17/07/2018.
//

#include "node.h"



bool EventComparisonNode::Evaluate(const Date& date, const std::string& event) {
    switch (cmp_) {
        case Comparison::Equal:
            return event_ == event;
        case Comparison::NotEqual:
            return event_ != event; // default case??
        default:
            throw logic_error("impossible event comparison");
    }
}

bool DateComparisonNode::Evaluate(const Date& date, const std::string& event) {
    switch (cmp_) {
        case Comparison::Less:
            return date < date_;
        case Comparison::LessOrEqual:
            return date <= date_;
        case Comparison::Greater:
            return date > date_;
        case Comparison::GreaterOrEqual:
            return date >= date_;
        case Comparison::Equal:
            return date == date_;
        case Comparison::NotEqual:
            return date != date_;
    }
}

bool LogicalOperationNode::Evaluate(const Date& date, const std::string& event) {
    switch (logical_operation_) {
        case LogicalOperation::Or:
            return left_->Evaluate(date, event) || right_->Evaluate(date, event);
        case LogicalOperation::And:
            return left_->Evaluate(date, event) && right_->Evaluate(date, event);
    }
}

bool EmptyNode::Evaluate(const Date& date, const std::string& event) {
    return true;
}
