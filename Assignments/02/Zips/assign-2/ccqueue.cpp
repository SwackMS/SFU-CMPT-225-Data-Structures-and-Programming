// File:        ccqueue.cpp
// Author:      Justin Mang
// Date:        January 30, 2016
// Description: Implementation of a customer complaint queue class for CMPT 225 assignment 2

#include <sstream>
#include <string>

#include "ccqueue.h"

using namespace std;

// default constructor
// maxticketid begins at 0
// note that tickets does not need to be re-declared
CCQueue::CCQueue()
{
	maxticketid = 0;
}

// MUTATORS

// enqueues a new ticket at the back of the ticket queue and returns true
// ticketid is assigned automatically as 1+maxticketid if enqueueing is possible
// does not enqueue and returns false if either parameter is empty string
// POST:  new ticket with supplied parameters is added to back of tickets,
//        maxticketid is incremented
// PARAM: customer and complaint fields to pass to Ticket constructor
bool CCQueue::Add(string customer, string complaint)
{
	if (customer != "" && complaint != "")
	{
		maxticketid += 1;
		tickets.InsertBack(Ticket(maxticketid, customer, complaint));
		return true;
	}
	else
		return false;
}

// removes and returns an item from the front of the ticket queue
// throws a logic_error if the ticket queue is empty
// POST:  first item of the ticket queue is removed
Ticket CCQueue::Service()
{
	if (!tickets.IsEmpty())
	{
		return tickets.RemoveAt(0);
//		return tickets.ElementAt(0);
	}
	else
	{
		throw std::logic_error("Queue is empty");
	}
}

// moves an item towards the front of the queue by 1 position and returns true
// returns false if supplied index is 0 (first item) or outside the list boundaries
// POST:  DLinkedList items at position and position-1 swap spots in the list
// PARAM: initial index of item to move up
bool CCQueue::MoveUp(int index)
{
	if (index == 0 || index >= tickets.Size())
	{
		return false;
	}
	else
	{
		tickets.InsertAt(tickets.RemoveAt(index), index - 1);
		return true;
	}
}

// moves an item towards the back of the queue by 1 position and returns true
// returns false if supplied index is the last item or outside the list boundaries
// POST:  DLinkedList items at position and position+1 swap spots in the list
// PARAM: initial index of item to move down
bool CCQueue::MoveDown(int index)
{
	if (index >= tickets.Size() - 1)
	{
		return false;
	}
	else
	{
		tickets.InsertAt(tickets.RemoveAt(index + 1), index);
		return true;
	}
}

// ACCESSORS

// returns the number of tickets
int CCQueue::Size() const
{
	return tickets.Size();
}

