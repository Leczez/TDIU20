#include <iostream>
#include <string>

#include "queue.h"

Queue::Queue() : first{nullptr} {}
Queue::~Queue()
{
    while(first)
    {
        dequeue();
    }
}
Queue::Queue(Queue const& q) : first{nullptr}
{
    Task* tmp{q.first};
    while(tmp)
    {
        enqueue(tmp->task);
        tmp = tmp->next;
    }
    std::cout << "COPY CONSTRUCTED!\n";
}

Queue::Queue(Queue && q) : first{nullptr}
{
    std::swap(first, q.first);
    std::cout << "MOVE CONSTRUCTOR CALLED" << std::endl;
}

Queue & Queue::operator=(Queue const& q)
{
    if( this != &q)
    {
        (*this).~Queue();

        Task* tmp{q.first};
        while(tmp)
        {
            enqueue(tmp->task);
            tmp = tmp->next;
        }

        std::cout << "ASSIGNED\n";

    }
    else
    {
        std::cout << "SELF ASSIGN\n";

    }
    return *this;
}

Queue & Queue::operator=(Queue && q)
{
    if( this != &q)
    {
        (*this).~Queue();
        std::swap(first, q.first);
        std::cout << "MOVED\n";
    }
    else
    {
        std::cout << "SELF MOVE\n";
    }
    return *this;
}


std::string Queue::to_string() const
{
    std::string s{"[ "};
    Task* curr{first};
    while ( curr )
    {
	s += curr -> task;
	s += " ";
	curr = curr -> next;
    }
    s += "]";
    return s;
}

void Queue::enqueue(std::string t)
{
    if ( first == nullptr)
    {
	first = new Task{t, first};
    }
    else
    {
	Task* curr{first};
	while ( curr -> next )
	{
	    curr = curr -> next;
	}
	curr -> next = new Task{t, nullptr};
    }
}

void Queue::dequeue()
{
    if( first )
    {
	Task* tmp{first->next};
	first -> next = nullptr;
	delete first;
	first = tmp;
    }
}

void Queue::execute()
{
    if (first)
    {
	std::cout << first->task << std::endl;
	dequeue();
    }
    else
    {
	std::cout << "Queue is empty, no task to run" << std::endl;
    }
}
