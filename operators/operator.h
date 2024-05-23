#pragma once

class Operator {
public:
    virtual double execute(double left, double right) = 0;
    virtual int priority() = 0;
    virtual ~Operator() = default;
};
