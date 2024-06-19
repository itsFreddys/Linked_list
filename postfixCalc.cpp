#include "postfixCalc.hpp"
#include "LLStack.hpp"
#include <stdexcept>
#include <string>
#include <cctype>
#include <iostream>
#include <vector>



unsigned postfixCalculator(const std::vector<std::string> & entries)
{
  if (entries.size() == 0) {throw CannotEvaluateException("Vector is empty.");}
	LLStack<int> cal;
	filter_vector(cal, entries);
  if (cal.top() < 0) {throw CannotEvaluateException("Answer cannot be negative.");}
	return cal.top();
}

void filter_vector(LLStack<int> &st, const std::vector<std::string> &entries)
{
  for (size_t i = 0; i < entries.size(); i++){
    if (check_for_num(entries[i]))
    {
      st.push(std::stoi(entries[i]));
    }
    else
    {
      if (st.size() < 2) throw CannotEvaluateException("Operation on Stack not possible.");
      perform_op(st, entries[i]);
    }
  }
  if (st.size() > 1){ throw CannotEvaluateException("Calculation not possible.");}
}

bool check_for_num(const std::string &s){
  if (std::isdigit(s[0])){
    return true;
  }
  else return false;
}

void perform_op(LLStack<int> &st, const std::string &s){
  int res;
  int var1 = st.top();
  st.pop();
  int var2 = st.top();
  st.pop();


  switch (s[0]){
    case '+':
      res = var2 + var1;
      break;
    case '-':
      res = var2 - var1;
      break;
    case '*':
      res = var2 * var1;
      break;
    case '/':
      if (var1 == 0){ throw CannotEvaluateException("Division of 0 is not possible");}
      res = var2/var1;
      break;
  }
  st.push(res);
}