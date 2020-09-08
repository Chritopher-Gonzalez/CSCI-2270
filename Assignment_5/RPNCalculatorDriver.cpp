/****************************************************************/
/*                  RPN Calculator Driver File                  */
/****************************************************************/
/*      TODO: Implement driver as described in the writeup      */
/****************************************************************/

#include "RPNCalculator.cpp"
#include <iostream>
// you may include more libraries as needed

using namespace std;

/*
 * Purpose: Determine whether some user input string is a
 *          valid floating point number
 * @param none
 * @return true if the string s is a number
 */
bool isNumber(string s)
{
    if(s.size() == 1 && s == "-") return false;
    else if(s.size() > 1 && s[0] == '-') s = s.substr(1);

    bool point = false;
    for(int i = 0; i < s.size(); i++)
    {
      if(!isdigit(s[i]) && s[i] != '.') return false;
      if(s[i]=='.' and !point) point = true;
      else if(s[i]=='.' and point) return false;
    }

    return true;
}

int main()
{
  // TODO - Declare a stack to hold the operands
  RPNCalculator calc;

  cout << "Enter the operators and operands ('+', '*') in a postfix format" << endl;

  /* TODO
     1. Read input (operators and operands) until you encounter a "="
     2. Use the isNumber function to check if the input is an operand
     3. push all operands to the stack
     4. If input is not an operand, call the compute function to evaluate
        the partial expression
  */
  while(true)
  {
    string input;
    cout << "#> ";
    getline(cin,input);

    if(input == "=")
    {
      if(calc.isEmpty())
      {
        cout << "No operands: Nothing to evaluate" << endl;
        return 0;
      }
      else
      {
        float returnValue = calc.peek()->number;
        calc.pop();
        if(calc.isEmpty())
        {
          cout << returnValue << endl;
          return 0;
        }
        else
        {
          cout <<  "Invalid expression" << endl;
          return 0;
        }

      }
    }
    if(isNumber(input))
    {
      calc.push(stof(input));
    }
    else
    {
      calc.compute(input);
    }
  }

  return 0;
}
