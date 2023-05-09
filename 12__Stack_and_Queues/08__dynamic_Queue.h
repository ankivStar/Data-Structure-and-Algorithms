template<typename T>
class QueueUsingArray{
    T *data;
    int nextIndex;
    int firstIndex;
    int size;
    int capacity;

    public :

    QueueUsingArray(int s){
        data = new T[s];
        nextIndex = 0;
        firstIndex = -1;
        size = 0;
        capacity = s;
    }

    int getSize(){
        return size;
    }

    bool isEmpty(){
        return size == 0;
    }

    //insert element
    void enqueue(T element){
        if (size == capacity){
            T *temp = new T[2*capacity];
            for (int i = 0; i < capacity; i++)
            {
                temp[i] = data[firstIndex];
                firstIndex = (firstIndex + 1) % 10;
            }
            firstIndex = 0;
            nextIndex = capacity;
            capacity = 2 * capacity;
            delete [] data;
            data = temp;
        }
        data[nextIndex] = element;
        nextIndex = (nextIndex + 1) % capacity;
        size++;
        if (firstIndex == -1){
            firstIndex = 0;
        }
    }

    T front(){
        if(isEmpty()){
            cout << "Queue is empty " << endl;
            return 0;
        }

        return data[firstIndex];
    }

    T deQueue(){
        if(isEmpty()){
            cout << "Queue is empty " << endl;
            return 0;
        }

        T temp = data[firstIndex];
        firstIndex = (firstIndex + 1) % capacity;
        size--;
        return temp;
    }
};
