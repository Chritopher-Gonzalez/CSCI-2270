/****************************************************************/
/*                    ProducerConsumer Class                    */
/****************************************************************/
/* LEAVE THIS FILE AS IS! DO NOT MODIFY ANYTHING! =]            */
/****************************************************************/
#include "ProducerConsumer.hpp"

/*
 * Purpose: Set queueFront and queueEnd to 0
 * @param none
 * @return none
 */
ProducerConsumer::ProducerConsumer()
{
  queueFront = 0;
  queueEnd = 0;
}
/*
 * Purpose: check if queue is empty
 * @param none
 * @return true if queue is empty
 */
bool ProducerConsumer::isEmpty()
{
  return (counter == 0);
}
/*
 * Purpose: check if queue is full
 * @param none
 * @return true if queue is full
 */
bool ProducerConsumer::isFull()
{
  return (counter == SIZE);
}
/*
 * Purpose: add item to end of queue
 * @param item to be added
 * @return none
 */
void ProducerConsumer::enqueue(string item)
{
  if(isFull())
  {
    cout << "Queue full, cannot add new item" << endl;
  }
  else
  {
    queue[queueEnd] = item;
    counter ++;

    if(queueEnd ==  SIZE - 1)
    {
      queueEnd = 0;
    }
    else
    {
      queueEnd++;
    }
  }
}
/*
 * Purpose: remove item from front of queue
 * @param none
 * @return none
*/
void ProducerConsumer::dequeue()
{
  if(isEmpty())
  {
    cout << "Queue empty, cannot dequeue an item" << endl;
  }
  else
  {
    queue[queueFront] = "";
    counter--;

    if(queueFront == SIZE - 1)
    {
      queueFront = 0;
    }
    else
    {
      queueFront++;
    }
  }
}
/*
 * Purpose: peeks at first element in queue
 * @param none
 * @return return a string
 */
string ProducerConsumer::peek()
{
  if(isEmpty())
  {
     cout << "Queue empty, cannot peek" << endl;
     return "";
  }
  else
  {
    return queue[queueFront];
  }
}
/*
 * Purpose: size of queue
 * @param none
 * @return return number of elements in queue
 */
int ProducerConsumer::queueSize()
{
  return counter;
}
