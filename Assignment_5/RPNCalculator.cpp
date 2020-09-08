/****************************************************************/
/*                     RPNCalculator Class                      */
/****************************************************************/
/* LEAVE THIS FILE AS IS! DO NOT MODIFY ANYTHING! =]            */
/****************************************************************/
#include "RPNCalculator.hpp"

/*
 * Purpose: set the stackHead pointer to NULL
 * @param none
 * @return none
 */
RPNCalculator::RPNCalculator()
{
  stackHead = nullptr;
}
/*
 * Purpose: pop everything off the stack and set stackHead to NULL.
 * @param none
 * @return none
 */
RPNCalculator::~RPNCalculator()
{
  while(!isEmpty())
  {
    pop();
  }
}
/*
 * Purpose: check if stack is empty
 * @param none
 * @return true if the stack is empty
 */
bool RPNCalculator::isEmpty()
{
  return (stackHead == nullptr);
}
/*
 * Purpose: Insert a new node onto the top of the stack
 * @param number to be inserted
 * @return none
 */
void RPNCalculator::push(float num)
{
  Operand* temp = new Operand;
  temp->number = num;
  temp->next = nullptr;
  temp->next = stackHead;
  stackHead = temp;
}
/*
 * Purpose: delete the top most item from the stack
 * @param none
 * @return none
 */
void RPNCalculator::pop()
{
  // checks if stack is empty
  if(!isEmpty())
  {
      Operand* temp = stackHead;
      stackHead = stackHead->next;
      delete temp;
  }
  else
  {
      cout<<"Stack empty, cannot pop an item."<<endl;
  }
}
/*
 * Purpose: peeks at first element in stack
 * @param none
 * @return return a pointer to the top of the stack
 */
Operand* RPNCalculator::peek()
{
  if(isEmpty())
  {
    cout << "Stack empty, cannot peek." << endl;
    return NULL;
  }
  else
  {
    return stackHead;
  }
}
/*
 * Purpose:  Perform the arithmetic operation symbol, which will be either “+” or “*”, on the top 2 numbers in the stack
 * @param string conatining operation
 * @return return true if calculation was carried out
 */
bool RPNCalculator::compute(std::string symbol)
{
  if(stackHead == nullptr || stackHead->next == nullptr)
  {
    cout << "err: not enough operands" << endl;
    return false;
  }
  else
  {
    if(symbol == "+")
    {
      float first = stackHead->number;
      pop();
      float second = stackHead->number;
      pop();
      push(first + second);
      return true;
    }
    else if(symbol == "*")
    {
      float first = stackHead->number;
      pop();
      float second = stackHead->number;
      pop();
      push(first * second);
      return true;
    }
    else
    {
      cout << "err: invalid operation" << endl;
      return false;
    }
  }
}
