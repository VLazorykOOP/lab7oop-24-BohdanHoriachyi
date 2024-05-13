//ZAVDANIA 1 i 2

//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//template<typename T>
//void swapMinMax(T arr[], int size) {
//    if (size <= 1) return;
//    int minIndex = 0;
//    int maxIndex = 0;
//    for (int i = 1; i < size; ++i) {
//        if (arr[i] < arr[minIndex])
//            minIndex = i;
//        if (arr[i] > arr[maxIndex])
//            maxIndex = i;
//    }
//    std::swap(arr[minIndex], arr[maxIndex]);
//}
//
//template<>
//void swapMinMax<char*>(char* arr[], int size) {
//    if (size <= 1) return;
//    int minIndex = 0;
//    int maxIndex = 0;
//    for (int i = 1; i < size; ++i) {
//        if (strcmp(arr[i], arr[minIndex]) < 0)
//            minIndex = i;
//        if (strcmp(arr[i], arr[maxIndex]) > 0)
//            maxIndex = i;
//    }
//    std::swap(arr[minIndex], arr[maxIndex]);
//}
//
//template<typename T>
//void insertionSort(T arr[], int size) {
//    for (int i = 1; i < size; ++i) {
//        T key = arr[i];
//        int j = i - 1;
//        while (j >= 0 && arr[j] > key) {
//            arr[j + 1] = arr[j];
//            j = j - 1;
//        }
//        arr[j + 1] = key;
//    }
//}
//
//template<>
//void insertionSort<char*>(char* arr[], int size) {
//    for (int i = 1; i < size; ++i) {
//        char* key = arr[i];
//        int j = i - 1;
//        while (j >= 0 && strcmp(arr[j], key) > 0) {
//            arr[j + 1] = arr[j];
//            j = j - 1;
//        }
//        arr[j + 1] = key;
//    }
//}
//
//int main() {
//    int arrInt[] = { 5, 3, 9, 1, 7 };
//    int sizeInt = sizeof(arrInt) / sizeof(arrInt[0]);
//
//    std::cout << "Before swapMinMax:\n";
//    for (int i = 0; i < sizeInt; ++i) {
//        std::cout << arrInt[i] << " ";
//    }
//    std::cout << std::endl;
//
//    swapMinMax(arrInt, sizeInt);
//
//    std::cout << "After swapMinMax:\n";
//    for (int i = 0; i < sizeInt; ++i) {
//        std::cout << arrInt[i] << " ";
//    }
//    std::cout << std::endl;
//
//    insertionSort(arrInt, sizeInt);
//
//    std::cout << "After insertionSort:\n";
//    for (int i = 0; i < sizeInt; ++i) {
//        std::cout << arrInt[i] << " ";
//    }
//    std::cout << std::endl;
//
//    char* arrChar[] = { (char*)"banana", (char*)"apple", (char*)"orange", (char*)"grape", (char*)"pineapple" };
//    int sizeChar = sizeof(arrChar) / sizeof(arrChar[0]);
//
//    std::cout << "Before swapMinMax:\n";
//    for (int i = 0; i < sizeChar; ++i) {
//        std::cout << arrChar[i] << " ";
//    }
//    std::cout << std::endl;
//
//    swapMinMax(arrChar, sizeChar);
//
//    std::cout << "After swapMinMax:\n";
//    for (int i = 0; i < sizeChar; ++i) {
//        std::cout << arrChar[i] << " ";
//    }
//    std::cout << std::endl;
//
//    insertionSort(arrChar, sizeChar);
//
//    std::cout << "After insertionSort:\n";
//    for (int i = 0; i < sizeChar; ++i) {
//        std::cout << arrChar[i] << " ";
//    }
//    std::cout << std::endl;
//
//    return 0;
//}

//ZAVDANIA 3

//#include <iostream>
//#include <queue>
//
//using namespace std;
//
//template <typename T>
//class ParametrizedQueue {
//private:
//    queue<T> elements;
//
//public:
//    void push(const T& item) {
//        elements.push(item);
//    }
//
//    void pop() {
//        if (!elements.empty()) {
//            elements.pop();
//        }
//        else {
//            cout << "Queue is empty. Cannot pop." << endl;
//        }
//    }
//
//    T front() const {
//        if (!elements.empty()) {
//            return elements.front();
//        }
//        else {
//            throw runtime_error("Queue is empty.");
//        }
//    }
//
//    bool empty() const {
//        return elements.empty();
//    }
//
//    int size() const {
//        return elements.size();
//    }
//};
//
//int main() {
//    ParametrizedQueue<int> intQueue;
//    intQueue.push(10);
//    intQueue.push(20);
//    intQueue.push(30);
//
//    while (!intQueue.empty()) {
//        cout << intQueue.front() << " ";
//        intQueue.pop();
//    }
//
//    cout << endl;
//
//    ParametrizedQueue<string> stringQueue;
//    stringQueue.push("Hello");
//    stringQueue.push("World");
//    stringQueue.push("!");
//
//    while (!stringQueue.empty()) {
//        cout << stringQueue.front() << " ";
//        stringQueue.pop();
//    }
//
//    return 0;
//}


//ZAVDANIA 4

/*#include <iostream>

template<typename T>
class DoublyLinkedList;

template<typename T>
class DoublyLinkedListIterator {
    using Node = typename DoublyLinkedList<T>::Node;

public:
    DoublyLinkedListIterator(Node* node) : current(node) {}
    T& operator*() const {
        return current->data;
    }

    DoublyLinkedListIterator<T>& operator++() {
        current = current->next;
        return *this;
    }

    DoublyLinkedListIterator<T>& operator--() {
        current = current->prev;
        return *this;
    }

    bool operator==(const DoublyLinkedListIterator<T>& other) const {
        return current == other.current;
    }

    bool operator!=(const DoublyLinkedListIterator<T>& other) const {
        return !(*this == other);
    }

private:
    Node* current;
};

template<typename T>
class DoublyLinkedList {
    friend class DoublyLinkedListIterator<T>;

private:
    struct Node {
        T data;
        Node* prev;
        Node* next;

        Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
    };

public:
    using iterator = DoublyLinkedListIterator<T>;

    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    ~DoublyLinkedList() {
        clear();
    }
    void push_back(const T& value) {
        Node* newNode = new Node(value);
        if (tail == nullptr) {
            head = tail = newNode;
        }
        else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    iterator begin() const {
        return iterator(head);
    }

    iterator end() const {
        return iterator(nullptr);
    }

    void clear() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = tail = nullptr;
        size = 0;
    }
    bool empty() const {
        return size == 0;
    }

    size_t getSize() const {
        return size;
    }

private:
    Node* head;
    Node* tail;
    size_t size;
};

int main() {
    DoublyLinkedList<int> myList;

    myList.push_back(1);
    myList.push_back(2);
    myList.push_back(3);

    std::cout << "List elements: ";
    for (auto it = myList.begin(); it != myList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
*/
