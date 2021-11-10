//2018203023 Mingeun Park
//this is implementation for evaluator class

#include <iostream>
#include <string>
#include <cstring>
#include <stddef.h>
#include "evaluator.h"

using namespace mystack;
using std::string;
using std::istream;

string Evaluator::read_expression(){
  string expression;
  std::getline(std::cin, expression);
  return expression;
}

string Evaluator::convert_to_postfix(string s)
{
  string postfix;
  size_t index = 0;
  Stack<char> operators;
  char symbol; // operator
  double number;
  const char DECIMAL = '.';
  const char RIGHT_PARENTHESIS = ')';
  const char LEFT_PARENTHESIS = '(';

  while (s[index] != '\n')
  {
    if (isdigit(s[index]) || s[index] == DECIMAL) // operands
    {
      while(isdigit(s[index]))
        postfix=postfix+" "+s[index];
    }
    else if (strchr("+-*/", s[index]) != NULL) // comparing priorities of operators 
    {
      if(s[index]=='*'||s[index]=='/') // * / has a highst priority
        operators.push(s[index]);
      else{  // + - has lower priority
        while(strchr("+-*/", operators.top())!=NULL){
          postfix=postfix+" "+operators.top();
          operators.pop();
          operators.push(s[index]);
        }
      }
    }
    else if (s[index] == LEFT_PARENTHESIS)
      operators.push(s[index]);
    else if (s[index] == RIGHT_PARENTHESIS){
      while(operators.top()!=LEFT_PARENTHESIS){
        postfix=postfix+" "+operators.top();
        operators.pop();
      }
      operators.pop(); // extract ')'
    }
    else if(s[index] == ' '){;} // ignore whitespace
    index++;
  }

  return postfix;
}