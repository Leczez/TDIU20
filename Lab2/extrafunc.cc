List::List(initializer_list<int> const &data)
{
    last = new Element{};
    first = new Element{};
    last->prev = first;
    first->next = last;

    for(size_t i{};i < data.size();i++)
    {
        insert(*(data.begin()+i));
    }
}


List::Element::~Element()
{
    if(this->next != nullptr)
    {
        if(this->next->next != nullptr)
        {
            delete this->next;
        }
    }
}

/*
    while(temp != last || temp->prev == first)
    {
        if(N <= temp->value || temp == last)
        {
            new_box->next = temp;
            new_box->prev = temp->prev;
            temp->prev->next = new_box;
            temp->prev = new_box;

            temp = last;
        }
        else
        {
            temp = temp->next;
            if(temp == last)
            {
                new_box->next = temp;
                new_box->prev = temp->prev;
                temp->prev->next = new_box;
                temp->prev = new_box;
            }
        }
    }
*/
