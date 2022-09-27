package informatica3.utils;

public class ArrayQueue<AnyType> {

    private AnyType[] theArray;
    private int currentSize;
    private int front;
    private int back;
    private static final int DEFAULT_CAPACITY = 10;

    public ArrayQueue() {
        theArray = (AnyType[]) new Object[DEFAULT_CAPACITY];
        makeEmpty();
    }

    public void makeEmpty() {
        currentSize = 0;
        front = 0;
        back = -1;
    }

    public boolean isEmpty() {
        return currentSize == 0;
    }

    public AnyType dequeue() throws Exception {
        if(isEmpty()) throw new Exception("ArrayQueue empty");
        currentSize--;

        AnyType returnValue = theArray[front];
        front = increment(front);
        return returnValue;
    }

    public void enqueue(AnyType x) {
        if (currentSize == theArray.length) doubleQueue();
        back = increment(back);
        theArray[back] = x;
        currentSize++;
    }

    public AnyType getFront() throws Exception {
        if(isEmpty()) throw new Exception("ArrayQueue empty");
        return theArray[front];
    }

    private int increment(int x) {
        if (++x == theArray.length) x = 0;
        return x;
    }

    private void doubleQueue() {
        AnyType[] arrayAux;

        arrayAux = (AnyType[]) new Object[theArray.length * 2];

        for (int i = 0; i < currentSize; i++, front = increment(front)) {
            arrayAux[i] = theArray[front];
        }
        theArray = arrayAux;
        front = 0;
        back = currentSize - 1;
    }


}
