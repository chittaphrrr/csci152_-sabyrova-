//HERE OUR IMPLEMENTATION OF ALL FUNCTIONS

//INCLUDE IOSTREAM, QUEUE.H
#include <iostream>
#include "queue.h"

//COPY NAMES OF ALL FUNCTIONS FROM QUEUE.H


// Copy constructor
	queue::queue(const queue& q):
queue_size(q.queue_size),
front(nullptr),
back(nullptr)
    {
        node* temp_node = q.front;
        while (temp_node!=nullptr)
        {
          node* new_node= new node(temp_node->value);

          if (front==nullptr){
            front=new_node ;
            back = new_node ;
          } else {
            back->next= new_node ;
            back= new_node ;
          }
          temp_node=temp_node->next;
        }
        
    };
    

	// Initializer list constructor
	queue::queue(std::initializer_list<int> ilist):
front(nullptr),
back(nullptr),
queue_size(ilist.size())
{
   for (auto element:ilist){
          node* new_node= new node(element) ;

          if (front==nullptr){
            front=new_node ;
            back = new_node ;
          } else {
            back->next= new_node ;
            back= new_node ;
          }
        }
}

	// Copy assignment
	queue& queue::operator=(const queue& q)
{
  node *cur_node=front;
  while (cur_node!=nullptr)
  {
    node *del_node=cur_node;
    cur_node=cur_node->next;
    delete del_node;
  }
  queue_size=0;
  front=nullptr;
  back=nullptr;

node *temp_node=q.front;
while (temp_node!=nullptr)
  {
     node *new_node=new node(temp_node->value);
    if (front==nullptr)
    {
      front=new_node;
      back=new_node;
    } 
    else
    {
      back->next=new_node; //temp
      back=new_node; //?
    }
    temp_node=temp_node->next;
    queue_size++;
  }
  return *this;
}

	// Insert an item at the back of the queue
	void queue :: push(int val)
{
  node *temp_node=new node(val);
    if (front==nullptr)
    {
      front=temp_node;
      back=temp_node;
    } 
    else
    {
      back->next=temp_node; //temp
      back=back->next; //?
    }
    queue_size++;
}

	// Returns the value of the front-most item of the queue;
	// throws an exception if the queue is empty
	int queue:: peek() const
{
  if (front==nullptr)
  {
    throw std:: invalid_argument("Queue is empty");
  }
  else
  {
    return front->value;
  }
}
  

	// Remove the front-most item from the queue
	// throws an exception if the queue is empty
	void queue:: pop()
{
  if (front==nullptr)
  {
        throw std:: invalid_argument("Queue is empty");
  }
  else
  {
    auto temp=front->next;
    delete front;
    front= temp;
    queue_size--;
    if (front==nullptr)
    {
      back=nullptr;
    }
  }
}

	// Remove everything from the queue
	void queue:: clear()
{
  node *temp_node=front;
  while (temp_node!=nullptr)
    {
      node *del_node= temp_node;
      temp_node=temp_node->next;
      delete del_node;
    }
    queue_size=0;
    front=nullptr;
    back=nullptr;
}

	// Returns the number of items on the queue
	size_t queue:: size() const
{
  return queue_size;
}

	// Returns whether or not the queue is currently empty
	bool queue:: empty() const
{
  if (queue_size==0)
  {
    return true;
  }
  else{
    return false;
  }
}

	// Destructor
	queue :: ~queue()
{
  clear();
}