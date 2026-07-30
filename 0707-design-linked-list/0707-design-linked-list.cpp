class MyLinkedList {
public:
    struct Node {
        int data;
        Node* next;
        Node(int val) {
            data = val;
            next = NULL;
        }
    };

    Node* head;

    MyLinkedList() {
        head = NULL;
    }

    int get(int index) {
        Node* temp = head;
        int i = 0;

        while (temp != NULL) {
            if (i == index) return temp->data;
            temp = temp->next;
            i++;
        }
        return -1;
    }

    void addAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void addAtTail(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void addAtIndex(int index, int val) {

        if (index == 0) {
            addAtHead(val);
            return;
        }

        Node* temp = head;
        int i = 0;

        while (temp != NULL && i < index - 1) {
            temp = temp->next;
            i++;
        }

        if (temp == NULL) return;

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteAtIndex(int index) {

        if (head == NULL) return;

        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;
        int i = 0;

        while (temp->next != NULL && i < index - 1) {
            temp = temp->next;
            i++;
        }

        if (temp->next == NULL) return;

        Node* del = temp->next;
        temp->next = del->next;
        delete del;
    }
};