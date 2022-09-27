package informatica3.utils;


import java.util.Stack;

public class ArrayStack<AnyType> {

    private AnyType[] theArray;
    private int topOfStack;
    private static final int DEFAULT_CAPACITY = 10;

    public ArrayStack() {
        theArray = (AnyType[]) new Object[DEFAULT_CAPACITY];
        topOfStack = -1;
    }

    public boolean isEmpty() {
        return topOfStack == -1;
    }

    public void makeEmpty() {
        topOfStack = -1;
    }

    public AnyType top() throws Exception {
        if (isEmpty()) throw new Exception("ArrayStack empty");
        return theArray[topOfStack];
    }

    public void pop() throws Exception {
        if (isEmpty()) throw new Exception("ArrayStack empty");
        topOfStack--;
    }

    public AnyType topAndPop() throws Exception {
        if (isEmpty()) throw new Exception("ArrayStack empty");
        return theArray[topOfStack--];
    }

    public void push(AnyType x) {
        if (topOfStack + 1 == theArray.length) doubleArray();
        theArray[++topOfStack] = x;
    }

    private void doubleArray() {
        AnyType[] arrayAux = (AnyType[]) new Object[2 * theArray.length];

        for (int i = 0; i < theArray.length; i++) {
            arrayAux[i] = theArray[i];
        }
        theArray = arrayAux;

    }

}
