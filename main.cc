#include <iostream>

#include "interface.hh"

struct ICalculator {
  virtual int compute(int input) const = 0;
  virtual void log(int input, int output) const = 0;
  virtual ~ICalculator(){};
};

struct BigCalculator : ICalculator {
  int compute(int input) const override { return input * 5; }

  void log(int input, int output) const override {
    std::cout << "BigCalculator took an input of " << input << " and produced an output of "
              << output << '\n';
  }
};

struct SmallCalculator : ICalculator {
  int compute(int input) const override { return input + 2; }

  void log(int input, int output) const override {
    std::cout << "SmallCalculator took an input of " << input << " and produced an output of "
              << output << '\n';
  }
};

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