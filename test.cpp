#include <iostream>
#include "myStack.h"
#include "evaluator.h"

using std::cout;
using std::cin;
using std::endl;

int main(){
  Evaluator eval;
  string expression;
  string postfix;
  size_t index = 0;
  const char* FOUR_OPERATORS = "+-*/";
  string str = "mingeun";

  expression="100-((3+8*5)+3*(1+2)-.9)";
  // expression="100+(.1*10)";
  postfix=eval.convert_to_postfix(expression);
  cout<<postfix<<endl;
  cout<<eval.evaluate_postfix(postfix)<<endl;
  return 0;
}