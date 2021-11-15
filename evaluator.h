// 2018203023 Mingeun Park
// this is interface for evaluator class
#ifndef EVALUATOR_H_
#define EVALUATOR_H_

#include <string>
#include "myStack.h"

using namespace mystack;
using std::string;

class Evaluator
{
public:
  string read_expression();
  string convert_to_postfix(string s);
  double evaluate_postfix(string s);
};

#endif