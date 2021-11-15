//2018203023 Mingeun Park
//this is implementation for evaluator class

#include <iostream>
#include <string>
#include <cstring>
#include <stddef.h>
#include "evaluator.h"

using namespace mystack;
using std::string;
using std::cout;
using std::cin;
using std::endl;

string Evaluator::read_expression(){
  string expression;
  std::getline(std::cin, expression);
  return expression;
}

string Evaluator::convert_to_postfix(string s){
  string postfix; 
  size_t index = 0;
  Stack<char> operators;
  char symbol; // operator
  double number; // operands
  const char DECIMAL = '.';
  const char RIGHT_PARENTHESIS = ')';
  const char LEFT_PARENTHESIS = '(';
  const char* FOUR_OPERATORS = "+-*/";

  while (index<=s.length()){
    // case 1: numbers detected
    if (isdigit(s[index]) || s[index] == DECIMAL){
      while (isdigit(s[index]) || s[index] == DECIMAL){
        postfix=postfix+s[index];
        index++;
      }
      postfix+=" ";
    }
    // case 2: variable detected
    else if(isalpha(s[index])){
      postfix=postfix+s[index]+" ";
      index++;
    }
    // case 3: operators detected
    else if (strchr(FOUR_OPERATORS, s[index]) != NULL){
      // if stack is empty, just push
      if(operators.is_empty())
        operators.push(s[index]);
      // if stack has another operators, compare priority
      else{
        // case 2-1: *, / detected
        if(s[index]=='*'||s[index]=='/') // *, / has a highst priority
          operators.push(s[index]);
        // case 2-2: +,- detected
        else{  // +, - has lower priority
          while(strchr(FOUR_OPERATORS, operators.top())!=NULL){
            postfix=postfix+operators.top()+" ";
            operators.pop();
            if(operators.is_empty())
              break;
          }
          operators.push(s[index]);
        }
      }
      index++;
    }

    //case 4: '(' detected
    else if (s[index] == LEFT_PARENTHESIS){
      operators.push(s[index]);
      index++;
    }

    // case 5: ')' detected
    else if (s[index] == RIGHT_PARENTHESIS){
      index++;
      while(operators.top()!=LEFT_PARENTHESIS){
        postfix=postfix+operators.top()+" ";
        operators.pop();
      }
      operators.pop(); // extract ')'
    }
    else if(s[index] == ' '){
      ++index;
    } // ignore whitespace
  }

  return postfix;
}

double Evaluator::evaluate_postfix(string s){
  Stack<double> operands;
  size_t index = 0;
  double num1, num2;
  const char DECIMAL = '.';

  while(index<s.length()){
    // case 1: number detected
    if (isdigit(s[index])||s[index]==DECIMAL){
      string str;
      while(s[index]!=' '){
        str+=s[index];
        index++;
      }
      operands.push(stod(str));
    }
    if (isalpha(s[index])){
      double var;
      cout<<"value of "<<s[index]<<": ";
      cin>>var;
      operands.push(var);
      index++;
    }
    // case 2: operators detected
    else{
      switch (s[index]){
      case '+':
        num1=operands.top();
        operands.pop();
        num2=operands.top();
        operands.pop();
        operands.push(num2+num1);
        index++;
        break;
      case '-':
        num1=operands.top();
        operands.pop();
        num2=operands.top();
        operands.pop();
        operands.push(num2-num1);
        index++;
        break;
      case '*':
        num1=operands.top();
        operands.pop();
        num2=operands.top();
        operands.pop();
        operands.push(num2*num1);
        index++;
        break;
      case '/':
        num1=operands.top();
        operands.pop();
        num2=operands.top();
        operands.pop();
        operands.push(num2/num1);
        index++;
        break;
      case ' ':
        index++;
        break;
      case '\0':
        index++;
        break;
      }
    }
  }
  return operands.top();
}