#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() {
        head = nullptr;
    }

    void insert(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void deleteNode(int val) {
        if (!head) return;

        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;
        while (temp->next && temp->next->data != val) {
            temp = temp->next;
        }

        if (temp->next) {
            Node* nodeToDelete = temp->next;
            temp->next = temp->next->next;
            delete nodeToDelete;
        }
    }

    bool search(int val) {
        Node* temp = head;
        while (temp) {
            if (temp->data == val) return true;
            temp = temp->next;
        }
        return false;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void reverse() {
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;

        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    int findMiddle() {
        if (!head) return -1;

        Node* slow = head;
        Node* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow->data;
    }
};

int main() {
    SinglyLinkedList list;

    int choice;
    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Insert element" << endl;
        cout << "2. Delete element" << endl;
        cout << "3. Search element" << endl;
        cout << "4. Display list" << endl;
        cout << "5. Reverse list" << endl;
        cout << "6. Find middle element" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int val;
                cout << "Enter element to insert: ";
                cin >> val;
                list.insert(val);
                break;
            }
            case 2: {
                int val;
                cout << "Enter element to delete: ";
                cin >> val;
                list.deleteNode(val);
                break;
            }
            case 3: {
                int val;
                cout << "Enter element to search: ";
                cin >> val;
                if (list.search(val)) {
                    cout << val << " found in the list." << endl;
                } else {
                    cout << val << " not found in the list." << endl;
                }
                break;
            }
            case 4:
                list.display();
                break;
            case 5:
                list.reverse();
                cout << "List reversed." << endl;
                break;
            case 6: {
                int middle = list.findMiddle();
                if (middle != -1) {
                    cout << "Middle element: " << middle << endl;
                } else {
                    cout << "List is empty." << endl;
                }
                break;
            }
            case 7:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
