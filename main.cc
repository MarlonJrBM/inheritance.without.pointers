#include <iostream>

#include "interface.hh"


// This is the base (interface) class.
struct ICalculator {
  virtual int compute(int input) const = 0;
  virtual void log(int input, int output) const = 0;
  virtual ~ICalculator(){};
};

// Concrete class #1 : Big Calculator
struct BigCalculator : ICalculator {
  int compute(int input) const override { return input * 5; }

  void log(int input, int output) const override {
    std::cout << "BigCalculator took an input of " << input << " and produced an output of "
              << output << '\n';
  }
};

// Concrete class #2 : Small Calculator
struct SmallCalculator : ICalculator {
  int compute(int input) const override { return input + 2; }

  void log(int input, int output) const override {
    std::cout << "SmallCalculator took an input of " << input << " and produced an output of "
              << output << '\n';
  }
};

// Now the magic begins: instead of using ICalculator* to refer to Big and SmallCalculators,
// we will use the magic wrapper Implementation<ICalculator> (refer to interface.hh header).
// This new type is a way of avoiding the whole runtime/vtable lookup mechanism, as well
// as allocations on the heap (thanks to std::any's internals).
using Calculator = Implementation<ICalculator>;

Calculator getBigCalculator() { return BigCalculator{}; }

Calculator getSmallCalculator() { return SmallCalculator{}; }

int main() {
  Calculator bigCalculator = getBigCalculator();
  Calculator smallCalculator = getSmallCalculator();

  bigCalculator->log(2, bigCalculator->compute(2));
  smallCalculator->log(2, smallCalculator->compute(2));

  return 0;
}