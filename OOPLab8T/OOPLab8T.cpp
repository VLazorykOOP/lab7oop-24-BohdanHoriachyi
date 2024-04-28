/*#include <iostream>
#include <cstring>
template <typename T>
void swapFirstMinMax(T arr[], int size) {
    if (size <= 1) return;

    int minIndex = 0;
    int maxIndex = 0;

    for (int i = 1; i < size; ++i) {
        if (arr[i] < arr[minIndex]) minIndex = i;
        if (arr[i] > arr[maxIndex]) maxIndex = i;
    }

    T temp = arr[minIndex];
    arr[minIndex] = arr[maxIndex];
    arr[maxIndex] = temp;
}

int main() {

    int intArray[] = { 3, 8, 1, 6, 2 };
    int sizeInt = sizeof(intArray) / sizeof(intArray[0]);

    swapFirstMinMax(intArray, sizeInt);

    std::cout << "Swapped integer array: ";
    for (int i = 0; i < sizeInt; ++i) {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;


    const char* strArray[] = { "apple", "orange", "banana", "grape", "kiwi" };
    int sizeStr = sizeof(strArray) / sizeof(strArray[0]);

    swapFirstMinMax(strArray, sizeStr);

    std::cout << "Swapped string array: ";
    for (int i = 0; i < sizeStr; ++i) {
        std::cout << strArray[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}*/

//ZAVDANIA 2
//
//#include <iostream>
//#include <cstring> // Для використання strcmp
//
//template <typename T>
//void swapFirstMinMax(T arr[], int size) {
//    if (size <= 1) return; // Якщо масив порожній або містить тільки один елемент, виходимо
//
//    int minIndex = 0;
//    int maxIndex = 0;
//
//    // Знаходимо індекси першого мінімального та першого максимального елементів
//    for (int i = 1; i < size; ++i) {
//        if (arr[i] < arr[minIndex]) minIndex = i;
//        if (arr[i] > arr[maxIndex]) maxIndex = i;
//    }
//
//    // Обмін значень між першим мінімальним та першим максимальним елементами
//    T temp = arr[minIndex];
//    arr[minIndex] = arr[maxIndex];
//    arr[maxIndex] = temp;
//}
//
//int main() {
//    // Приклад з числовим масивом
//    int intArray[] = { 3, 8, 1, 6, 2 };
//    int sizeInt = sizeof(intArray) / sizeof(intArray[0]);
//
//    swapFirstMinMax(intArray, sizeInt);
//
//    std::cout << "Swapped integer array: ";
//    for (int i = 0; i < sizeInt; ++i) {
//        std::cout << intArray[i] << " ";
//    }
//    std::cout << std::endl;
//
//    // Приклад з масивом рядків (char*)
//    const char* strArray[] = { "apple", "orange", "banana", "grape", "kiwi" };
//    int sizeStr = sizeof(strArray) / sizeof(strArray[0]);
//
//    swapFirstMinMax(strArray, sizeStr);
//
//    std::cout << "Swapped string array: ";
//    for (int i = 0; i < sizeStr; ++i) {
//        std::cout << strArray[i] << " ";
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


