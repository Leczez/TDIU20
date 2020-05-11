#include "queue.h"

using namespace std;
void do_stuff(Queue &);
int main()
{
/*    Queue q1{};
    for(int i{}; i < 5; ++i)
    {
	       q1.enqueue("task" + to_string(i));
    }
    cout << q1.to_string() << "q1 LISTA" << endl;

    Queue copycon{q1};
    Queue assi_copy{};
    assi_copy = q1;
    assi_copy = assi_copy;
    Queue movecon{std::move(q1)};
    Queue assi_move{};
    assi_move = std::move(copycon);
    assi_move = std::move(assi_move);

    cout << "Q1----------------------------------------------------\n";
    do_stuff(q1);
    cout << "COPYCONSTRUCTOR----------------------------------------------------\n";
    do_stuff(copycon);
    cout << "MOVECONSTRUCTOR----------------------------------------------------\n";
    do_stuff(movecon);

    cout << "ASSIGN COPY----------------------------------------------------\n";
    do_stuff(assi_copy);
    cout << "ASSIGN MOVE----------------------------------------------------\n";
    do_stuff(assi_move);*/
    {//Kopieringskonstruktor
    	Queue queue{};
    	for(int i{}; i < 5; ++i)
    	{
    	    queue.enqueue("task" + to_string(i));
    	}
    	Queue queue2{queue};
    }
    {//Tilldelningsoperator
    	Queue queue{};
    	for(int i{}; i < 5; ++i)
    	{
    	    queue.enqueue("task" + to_string(i));
    	}
    	Queue queue2 = queue;
    }
    {//Flyttkonstruktor
    	Queue queue{};
    	for(int i{}; i < 5; ++i)
    	{
    	    queue.enqueue("task" + to_string(i));
    	}
    	Queue queue2{move(queue)};
    }
    {//Flyttilldelningsoperator
    	Queue queue{};
    	for(int i{}; i < 5; ++i)
    	{
    	    queue.enqueue("task" + to_string(i));
    	}
    	Queue queue2 = move(queue);
    }
    {
	Queue queue{};
	for(int i{}; i < 5; ++i)
    	{
    	    queue.enqueue("task" + to_string(i));
    	}
	cout << queue.to_string() << endl;
	for(int i{}; i < 2; ++i)
	{
	    queue.execute();
	}
	queue.execute();
	cout << queue.to_string() << endl;
    }
}

void do_stuff(Queue &queue)
{

    for(int i{}; i < 5; ++i)
    {
	       queue.execute();
    }
    queue.execute();
    cout << queue.to_string() << endl;
}
