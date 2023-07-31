#include <ostream>
#include "stack.h"

stack::stack(const stack& stk):
	values(new int[stk.array_capacity]),
	stack_size(stk.stack_size),
	array_capacity(stk.array_capacity)
	{
		for (size_t count = 0; count < stack_size; count++)
		{
			values[count] = stk.values[count];
		}
	}

stack::stack(std::initializer_list<int> ilist) :
	stack_size(ilist.size()),
	array_capacity(stack_size),
	values(new int[ilist.size()])
{
	int count = 0;
	for (size_t element : ilist)
	{
		values[count] = element;
		count++;
	}
}

stack& stack::operator=(const stack& stk)
{
	if (array_capacity < stk.stack_size)
	{
		delete [] values;
		array_capacity = stk.array_capacity;
		values = new int[stk.array_capacity];
	}

	stack_size = stk.stack_size;	
	for (size_t count = 0; count < stack_size; count++)
	{
		values[count] = stk.values[count];
	}
	return *this;
}

void stack::push(int val)
{
	if (stack_size == array_capacity)
	{
		array_capacity *= 2;
		int* temp;
		temp = new int[array_capacity];

		for (int count = 0; count < stack_size; count++)
		{
		    temp[count] = values[count];
		}

		delete [] values;
		values = temp;
	}
    values[stack_size] = val;
	stack_size++;
}

int stack::peek() const
{
    	if (stack_size == 0)
    	{
        	throw std::invalid_argument("Stack is empty");
    	}
	return values[stack_size-1];
}

void stack::pop()
{
	if (stack_size == 0)
	{
		throw std::invalid_argument("Stack is empty");
	}
	else
	{
		stack_size--;
	}
}

void stack::clear()
{
    stack_size = 0;
}

size_t stack::size() const
    {
        return stack_size;
    }

bool stack::empty() const
{
	if (stack_size == 0)
	{
		return 1;
	}
	else
	{	
		return 0;
	}
}

stack::~stack()
{
	delete [] values;
}