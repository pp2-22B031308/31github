#include <iostream>
#include <vector>

using namespace std;

class MaxHeap {// we create class to implement max heap
private:
    int _size; /// to track heap size
    vector<int> vect;

public:
    MaxHeap() {
        _size = 0;
    }

    void insert(int val);
    void shiftDown(int i);
    void shiftUp(int i);
    void print();
    int extractMax();
};

void MaxHeap::shiftUp(int i) {
    if (i == 0) return;// If the index is the root node, return. bc if root then nowhere to go up to
    int p = (i - 1) / 2;//calculate parent nde for this exact index(by formula)
    if (vect[i] > vect[p]) {// Chech if i is greater than parent
        swap(vect[p], vect[i]);//if true, swap the values of the current node and its parent
        shiftUp(p);// Recursively call shiftUp on the parent node
    }
}

void MaxHeap::shiftDown(int i) {
    int l = i * 2 + 1; // index of left ch
    int r = i * 2 + 2; //indx right child
    int swapId = i; //swapId = current node index
// Check if the left child exists and if it's bigger than the current node
    if (l < _size && vect[l] > vect[swapId]) {
        swapId = l;// If true, update swapId to the left child's index
    }
    //same to the right
    if (r < _size && vect[r] > vect[swapId]) {
        swapId = r;
    }
    // If swapId is not equal to the initial node index i, then we ned to swap them
    if (swapId != i) {
        swap(vect[i], vect[swapId]);// Swap the current node 
        shiftDown(swapId);// Recursively call shiftDown on the updated node
    }
}

void MaxHeap::insert(int val) {
    _size++;
    if (_size > vect.size()) {// If the current size exceeds the capacity of the vector
        vect.push_back(val);// Add the value to the end 
    } else {
        vect[_size - 1] = val;// If there is space in the vector, place the value at the last index
    }
    shiftUp(_size - 1);// Perform the shiftUp operation starting from the last index
}

int MaxHeap::extractMax() {
    //if heap is empty
    if (_size == 0) {
        cerr << "Heap is empty!" << endl;
        return -1; 
    }
    int Max = vect[0]; // Save the maximum value (root of the heap)
    swap(vect[0], vect[_size - 1]);// Swap the maximum value (root) with the last element in the heap
    _size--;// Decrease the size of the heap (effectively removing the last element)
    shiftDown(0);// Restore the max-heap property by shifting down the swapped element
    return Max;// Return the extracted maximum value
}

void MaxHeap::print() {
    for (int i = 0; i < _size; i++) {
        cout << vect[i] << " ";
    }
    cout << endl;
}

int main() {
    MaxHeap max_heap;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        max_heap.insert(x);
    }

    cout << "Max Heap: ";
    max_heap.print();

    cout << "Extracting Max: " << max_heap.extractMax() << endl;
    cout << "Updated Heap: ";
    max_heap.print();

    return 0;
}
