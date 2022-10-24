#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <cctype>

std::map<std::string, int> mark_level = {{"-", 0}, {"+", 0}, {"*", 1}, {"/", 1}, {"(", -1}};

bool is_digit(std::string& str) {
  return std::all_of(str.begin(), str.end(), ::isdigit);
}

std::queue<std::string> parse(std::string& str) {
  int j = 0;
  std::queue<std::string> q;
  std::string s_num = "";

  while (j < str.length()) {
    if (isdigit(str[j])) {
      s_num += str[j];
    } else {
      if (not s_num.empty()) {
        q.push(s_num);
        s_num = "";
      }
      std::string s(1, str[j]);
      q.push(s);
    }
    j++;
  }
  q.push(s_num);

  return q;
}

std::queue<std::string> formatToRPN(std::string& str) {
  std::queue<std::string> q = parse(str);
  std::queue<std::string> ret_queue;;
  std::stack<std::string> notation_stack;
  std::string cur;

  while (not q.empty()) {
    cur = q.front();
    if (is_digit(cur))
      ret_queue.push(cur);
    else if (cur == ")") {
      while (notation_stack.top() != "(") {
        ret_queue.push(notation_stack.top());
        notation_stack.pop();
      }
      notation_stack.pop();
    }
    else if (cur == "(") {
      notation_stack.push(cur);
    } else {
      while (notation_stack.size() && mark_level[cur] <= mark_level[notation_stack.top()]) {
        ret_queue.push(notation_stack.top());
        notation_stack.pop();
      }
      notation_stack.push(cur);
    }
    q.pop();

    if (q.empty()) {
      while (not notation_stack.empty()) {
        ret_queue.push(notation_stack.top());
        notation_stack.pop();
      }
    }
  }

  return ret_queue;
}

// RPN - Reverse Polish Notation
std::string formatRPNtoString(std::queue<std::string>& rpn_queue) {
  std::string ret = "";
  while (!rpn_queue.empty()) {
    ret = ret + " " + rpn_queue.front();
    rpn_queue.pop();
  }

  return ret;
}

int calculate(std::queue<std::string>& rpn_queue) {
  std::string cur;
  std::stack<int> stack;
  while (not rpn_queue.empty()) {
    cur = rpn_queue.front();
    if (is_digit(cur)) {
      stack.push(std::atoi(cur.c_str()));
    } else {
      int value;
      int num1 = stack.top();
      stack.pop();
      int num2 = stack.top();
      stack.pop();
      if (cur == "-") value = num2 - num1;
      else if (cur == "+") value = num2 + num1;
      else if (cur == "*") value = num2 * num1;
      else if (cur == "/") value = num2 / num1;
      
      stack.push(value);
    }
    rpn_queue.pop();
  }

  return stack.top();
}


int main(int argc, char const *argv[])
{
  std::string expression;
  std::cout << "Input a four foundamentaion operations of arithmetic: ";
  std::cin >> expression;
  std::queue<std::string> rpn = formatToRPN(expression);
  std::cout << "The result is: " << calculate(rpn) << std::endl;
  return 0;
}

