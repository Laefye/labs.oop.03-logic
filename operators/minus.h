#include "operator.h"

class Minus : public Operator {
public:
    double execute(double left, double right) override;
    int priority() override;
};
