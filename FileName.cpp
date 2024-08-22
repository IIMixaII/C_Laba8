#include <iostream>

struct TQueue {
    int* array;
    int capacity;
    int size;
    int front;
    int rear;
};

// �������� ������������ ���������
void InitQueue(TQueue& Q, int capacity) {
    Q.array = new int[capacity];
    Q.capacity = capacity;
    Q.size = 0;
    Q.front = 0;
    Q.rear = -1;
}

// ���������� ������ ��������
void Enqueue(TQueue& Q, int value) {
    if (Q.size < Q.capacity) {
        Q.rear = (Q.rear + 1) % Q.capacity;
        Q.array[Q.rear] = value;
        Q.size++;
    }
    else {
        std::cerr << "������� �����������!" << std::endl;
    }
}

// �������� �������� (Dequeue)
int Dequeue(TQueue& Q) {
    if (Q.size > 0) {
        int value = Q.array[Q.front];
        Q.front = (Q.front + 1) % Q.capacity;
        Q.size--;
        return value;
    }
    else {
        std::cerr << "������� �����!" << std::endl;
        return -1; // ��� ������ �������� �� ���������
    }
}

int main() {
    TQueue myQueue;
    InitQueue(myQueue, 5);

    // ��������� �������� � �������
    Enqueue(myQueue, 1);
    Enqueue(myQueue, 2);
    Enqueue(myQueue, 3);
    Enqueue(myQueue, 4);
    Enqueue(myQueue, 5);

    // ��������� � ������� ������ ���� ���������
    for (int i = 0; i < 5; ++i) {
        int value = Dequeue(myQueue);
        if (value != -1) {
            std::cout << "�������� �������: " << value << std::endl;
        }
    }

    delete[] myQueue.array;

    return 0;
}
