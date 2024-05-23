#include "operator.h"

class Add : public Operator {
public:
    double execute(double left, double right) override;
    int priority() override;
};
