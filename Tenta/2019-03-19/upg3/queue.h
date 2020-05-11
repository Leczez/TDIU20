#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>

class Queue
{
public:
    Queue();
    ~Queue();
    Queue(Queue const& q); //COPY CONTRUCTOR
    Queue(Queue && q);     //MOVE CONTRUCTOR
    Queue & operator=(Queue const& q); //COPY ASSIGNMENT
    Queue & operator=(Queue && q); //MOVE ASSIGNMENT
    std::string to_string() const;
    void enqueue(std::string t); //Enqueues element last in que
    void dequeue(); //Removes first element in que
    void execute(); //Prints and removes first element in que

private:
    struct Task
    {
	std::string task;
	Task* next;
    };
    Task* first;

};
#endif
