#include <iostream>
using namespace std;

const int MAX_QUEUE_SIZE = 5;
int queueArray[MAX_QUEUE_SIZE];
int currentSize = 0;
int front = 0;
int rear = 0;

void Enqueue(int);
void Dequeue();
void Peek();
void Size();
void ViewQueue();

int main()
{
    int userInput;
    int enqNum;
    string shouldContinue;
    bool again;

    do {
        system("CLS");
        cout << "What function would you like to perform? \n1-Enqueue \n2-Dequeue \n3-Peek \n4-Size \n5-View Queue \n0-Quit" << endl;
        cin >> userInput;

        switch (userInput) {
            case 1:
                cin.clear();
                cout << "Enter a number to enqueue: " << endl;
                cin >> enqNum;
                Enqueue(enqNum);
                break;
            case 2:
                Dequeue();
                break;
            case 3:
                Peek();
                break;
            case 4:
                Size();
                break;
            case 5: 
                ViewQueue();
                break;
            case 0: 
                return 1;
                break;
            default:
                break;
        }

        cin.clear();
        cout << "Would you like to perform another function?(y/n): ";
        cin >> shouldContinue;
        again = shouldContinue == "y" || shouldContinue == "Y" ? true : false;
    } while (again);
}

void Enqueue(int x) {
    if (currentSize == MAX_QUEUE_SIZE) {
        cout << "Cannot enqueue onto a full queue!" << endl;
    }
    else {
        queueArray[rear++] = x;
        currentSize++;
        if (rear == MAX_QUEUE_SIZE) {
            rear = 0;
        }
    }
}

void Dequeue() {
    if (currentSize == MAX_QUEUE_SIZE) {
        cout << "Cannot dequeue from an empty queue!" << endl;
    }
    else {
        int value = queueArray[front++];
        currentSize--;
        if (front == MAX_QUEUE_SIZE) {
            front = 0;
        }
        cout << "Dequeue'd " << value << " from the queue!" << endl;
    }
}

void Peek() {
    if (currentSize == 0) {
        cout << "Cannot peek an empty queue!" << endl;
    }
    else {
        cout << queueArray[front] << " is at the front of the queue!" << endl;
    }
}

void Size() {
    cout << "The queue's max size is: " << MAX_QUEUE_SIZE << endl;
}

void ViewQueue() {
    for (int i = front; i < currentSize; i++) {
        cout << " " << queueArray[i] << " |";
    }
}