#include <iostream>
#include <memory>
#include <mutex>

template <typename T>
class ListNode {
public:
    T x;
    std::shared_ptr<ListNode> next;
    ListNode(T _x): x(_x), next(nullptr) {
        std::cout << "created ListNode(" << x << ")" << std::endl;
    }
    ~ListNode() {
        std::cout << "destroyed ListNode(" << x << ")" << std::endl;
    }
};

template <typename T>
class LinkedList {

    std::shared_ptr< ListNode<T> > head, tail;
    std::mutex list_mutex;

public:
    LinkedList(): head(nullptr), tail(nullptr) {}

    /** Remove first list node that matches value */
    void remove(T _x) {

        if (head->x == _x) {
            std::lock_guard<std::mutex> guard(list_mutex);
            if (tail == head) {
                tail = head->next;
            }
            head = head->next;
            return;
        } 

        for (auto tmp = head; tmp->next != nullptr; tmp = tmp->next) {
            if (tmp->next->x == _x) {
                std::lock_guard<std::mutex> guard(list_mutex);
                if (tmp->next == tail) {
                    tail = tmp;
                }
                tmp->next = tmp->next->next;
                break;
            }
        }
    }

    /** Reverse all the nodes in the linked list */
    void reverse() {

        std::cout << "reversing list" << std::endl;
        if (head == nullptr)
            return;

        std::lock_guard<std::mutex> guard(list_mutex);

        tail = head;

        // Initial setup
        auto tmp = head->next;
        head->next = nullptr;

        while (tmp != nullptr) {
            auto tmp2 = tmp->next;
            tmp->next = head;
            head = tmp;
            tmp = tmp2;
        }
    }

    /** Append value to the tail of the linked list */
    void append(T _x) {
        auto new_node = std::make_shared< ListNode<T> >(ListNode<T>(_x));

        std::lock_guard<std::mutex> guard(list_mutex);

        if (tail == nullptr) {
            head = tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }

    /** print all the values in the linked list from head to tail */
    void print() {
        std::cout << "LinkedList: ";

        if (head == nullptr) {
            std::cout << "empty" << std::endl;
            return;
        }

        for (auto node = head; node != nullptr; node = node->next) {
            std::cout << node->x << " ";
        }

        std::cout << std::endl;
    }
};


int main()
{
    LinkedList<int> lst;

    lst.append(1);
    lst.append(2);
    lst.append(3);
    lst.append(4);

    lst.print();
    lst.reverse();
    lst.print();

    lst.remove(2);
    lst.print();

    lst.remove(1);
    lst.print();

    lst.remove(4);
    lst.print();


    lst.remove(3);
    lst.print();

    lst.reverse();
    lst.print();

    std::cout << "end of main" << std::endl;

    return 0;
}
