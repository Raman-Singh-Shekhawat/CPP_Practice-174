/*
193. Code : Max Priority Queue: Implement the class for Max Priority Queue which includes following functions -

getSize -
Return the size of priority queue i.e. number of elements present in the priority queue.

isEmpty -
Check if priority queue is empty or not. Return true or false accordingly.

insert -
Given an element, insert that element in the priority queue at the correct position.

getMax -
Return the maximum element present in the priority queue without deleting. Return -Infinity if priority queue is empty.

removeMax -
Delete and return the maximum element present in the priority queue. Return -Infinity if priority queue is empty.
Note : main function is given for your reference which we are using internally to test the class.
*/

#include <vector>
class PriorityQueue
{
    vector<int> pq;

public:
    PriorityQueue()
    {
    }

    void insert(int element)
    {
        pq.push_back(element);

        // Up-Heapify
        int childIndex = pq.size() - 1;
        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;

            if (pq[parentIndex] < pq[childIndex])
            {
                int temp = pq[parentIndex];
                pq[parentIndex] = pq[childIndex];
                pq[childIndex] = temp;
            }
            else
            {
                break;
            }
            childIndex = parentIndex;
        }
    }

    int getMax()
    {
        if (pq.size() == 0)
        {
            return 0;
        }
        return pq[0];
    }

    int removeMax()
    {
        if (pq.size() == 0)
        {
            return 0;
        }
        int x = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();

        // Down-Heapify
        int parentIndex = 0;
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;

        while (leftChildIndex < pq.size())
        {
            int maxIndex = parentIndex;
            if (pq[maxIndex] < pq[leftChildIndex])
            {
                maxIndex = leftChildIndex;
            }
            if (rightChildIndex < pq.size() && pq[maxIndex] < pq[rightChildIndex])
            {
                maxIndex = rightChildIndex;
            }
            if (maxIndex == parentIndex)
            {
                break;
            }

            int temp = pq[maxIndex];
            pq[maxIndex] = pq[parentIndex];
            pq[parentIndex] = temp;

            parentIndex = maxIndex;
            leftChildIndex = 2 * parentIndex + 1;
            rightChildIndex = 2 * parentIndex + 2;
        }

        return x;
    }

    int getSize()
    {
        return pq.size();
    }

    bool isEmpty()
    {
        return pq.size() == 0;
    }
};
