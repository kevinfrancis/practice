#include <iostream>
#include <memory>

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

public:
    LinkedList(): head(nullptr), tail(nullptr) {}

    void remove(T _x) {

        if (head->x == _x) {
            if (tail == head) {
                tail = head->next;
            }
            head = head->next;
            return;
        } 

        for (auto tmp = head; tmp->next != nullptr; tmp = tmp->next) {
            if (tmp->next->x == _x) {
                if (tmp->next == tail) {
                    tail = tmp;
                }
                tmp->next = tmp->next->next;
                break;
            }
        }
    }

    void reverse() {

        std::cout << "reversing list" << std::endl;
        if (head == nullptr)
            return;

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

    void append(T _x) {
        auto new_node = std::shared_ptr< ListNode<T> >(new ListNode<T>(_x));

        if (tail == nullptr) {
            head = tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }

    void print() {
        std::cout << "LinkedList: ";

        if (head == nullptr) {
            std::cout << "empty" << std::endl;
            return;
        }

        std::shared_ptr< ListNode<T> > node = head;
        while (node) {
            std::cout << node->x << " ";
            node = node->next;
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
