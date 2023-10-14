#include <iostream>
#include <vector>

using namespace std;

typedef int HeapDataT;
typedef vector<HeapDataT> HeapT;

HeapDataT top(const HeapT &h);
HeapDataT pop(HeapT &h);
void push(HeapT &h, HeapDataT insert_value);
bool isEmpty(const HeapT &h);

int main()
{
    HeapT my_heap;

    int x;
    cin >> x;
    while (x != 0)
    {
        push(my_heap, x);
        cin >> x;
    }

    while (not isEmpty(my_heap))
    {
        cout << pop(my_heap) << '\t';
    }
    cout << '\n';


    return 0;
}


HeapDataT top(const HeapT &h)
{
    return h.back();
}


HeapDataT pop(HeapT &h)
{
    if (isEmpty(h)) throw std::runtime_error("Pop on empty heap!");

    HeapDataT return_value = h[0];
    h[0] = h.back();
    h.pop_back();
    HeapT::size_type i = 0;
    HeapT::size_type left = 2 * i + 1;
    HeapT::size_type right = 2 * i + 2;

    while ((left < h.size() &&  h[left] > h[i]) ||
           (right < h.size() &&  h[right] > h[i]))
    {
        if (right < h.size() && h[right] > h[i]) {swap(h[i], h[right]);}
        else {swap(h[i], h[left]);}
    }

    return return_value;
}

void push(HeapT &h, HeapDataT insert_value)
{
    h.push_back(insert_value);
    HeapT::size_type i = h.size() - 1;
    HeapT::size_type parent = (i - 1) / 2;

    while (parent >= 0 && h[parent] < h[i])
    {
        swap(h[parent], h[i]);
        i = parent;
        parent = (i - 1) / 2;
    }
}


bool isEmpty(const HeapT &h)
{
    return h.size() == 0;
}
