#include <iostream>
#include "myStack.h"
#include "evaluator.h"

using std::cout;
using std::cin;
using std::endl;

int main(){
  cout<<"press ctrl+c to quit\n";
  while(1){
    cout<<"-----------------------------------------------------------------------\n";
    Evaluator *eval = new Evaluator;
    string *infix_expression = new string;
    string *postfix_expression = new string;
    double *result = (double *)malloc(sizeof(double));
    cout << "infix expression: ";
    *infix_expression = eval->read_expression();
    *postfix_expression = eval->convert_to_postfix(*infix_expression);
    cout << "postfix expression: ";
    cout << *postfix_expression << endl;
    *result = eval->evaluate_postfix(*postfix_expression);
    cout << "result: " << *result << endl;
    fflush(stdin);
    fflush(stdout);

    delete (eval);
    delete(infix_expression);
    delete(postfix_expression);
    delete(result);
  }
  return 0;
}