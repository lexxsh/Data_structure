#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class MaxHeap {
private:
    vector<T> items_;
    int heapSize_;

public:
    MaxHeap() : heapSize_(0) {}

    void heapify(int idx) {
        if (idx >= heapSize_) return; // Check if leaf node

        int largerChild = 2 * idx + 1; // Start with left child
        if (largerChild < heapSize_ - 1) { // Check if right child exists
            int rChild = largerChild + 1;
            if (items_[rChild] > items_[largerChild]) // Compare right child with left child
                largerChild = rChild;
        }

        if (items_[idx] < items_[largerChild]) { // Compare parent with larger child
            swap(items_[idx], items_[largerChild]);
            heapify(largerChild);
        }
    }

    void insert(T item) {
        items_.push_back(item);
        heapSize_++;
        int currentIndex = heapSize_ - 1;

        while (currentIndex > 0 && items_[(currentIndex - 1) / 2] < items_[currentIndex]) {
            swap(items_[currentIndex], items_[(currentIndex - 1) / 2]);
            currentIndex = (currentIndex - 1) / 2;
        }
    }

    void buildHeap() {
        for (int i = (heapSize_ / 2) - 1; i >= 0; i--) {
            heapify(i);
        }
    }

    void printHeap() {
        for (const T& item : items_) {
            cout << item << " ";
        }
        cout << endl;
    }
};

int main() {
    MaxHeap<int> maxHeap;
    vector<int> elements = { 15, 10, 8, 12, 6, 20, 3 };

    for (const auto& element : elements) {
        maxHeap.insert(element);
    }

    maxHeap.buildHeap();
    cout << "Max Heap: ";
    maxHeap.printHeap();

    return 0;
}
