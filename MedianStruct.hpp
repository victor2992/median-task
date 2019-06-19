#ifndef MEDIANSTRUCT_HPP
#define MEDIANSTRUCT_HPP

#include <queue>
#include <vector>

template <class T>
class MeadianStruct
{
private:
    // one queue for the bottom half and one for the upper half
    // bottom will have floor(elements / 2.0)
    std::priority_queue<T> bottom;
    // bottom will have ceil(elements / 2.0)
    std::priority_queue<T, std::vector<T>, std::greater<T>> upper;
    // total number of elements in both queues
    unsigned int num_elements;

public:
    MeadianStruct() : num_elements(0){};
    // we suppose that T is a fundamental number type,
    // so there is no need to pass element by reference
    void add(T element);
    double calculate_median() const;
};

template <class T>
void MeadianStruct<T>::add(T element)
{
    if (num_elements == 0)
    {
        upper.push(element);
    }
    // we need to push the smallest element of element and upper into bottom
    // we know that we have at least one element in upper
    else if (num_elements % 2 == 1)
    {
        if (element <= upper.top())
            bottom.push(element);
        else
        {
            bottom.push(upper.top());
            upper.pop();
            upper.push(element);
        }
    }
    // we need to push the biggest element of element and bottom into upper
    // we know we have at least one element in both upper and bottom
    else
    {
        if (element >= bottom.top())
            upper.push(element);
        else
        {
            upper.push(bottom.top());
            bottom.pop();
            bottom.push(element);
        }
    }
    num_elements++;
}

template <class T>
double MeadianStruct<T>::calculate_median() const
{
    if (num_elements == 0)
    {
        throw std::logic_error("There is no median with 0 elements!");
    }
    else if (num_elements % 2 == 0)
    {
        return (double)(upper.top() + bottom.top()) / 2;
    }
    else
    {
        return (double)upper.top();
    }
}

#endif
