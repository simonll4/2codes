package informatica3.utils;

public class ListQueue<AnyType> {

    private ListNode<AnyType> front;
    private ListNode<AnyType> back;

    public ListQueue() {
        front = back = null;
    }

    public void makeEmpty() {
        front = null;
        back = null;
    }

    public boolean isEmpty() {
        return front == null;
    }

    public AnyType dequeue() throws Exception {
        if (isEmpty()) throw new Exception("ListQueue empty");

        AnyType returnValue = front.element;
        front = front.next;
        return returnValue;
    }

    public void enqueue(AnyType x) {
        if (isEmpty())
            back = front = new ListNode<AnyType>(x);
        else {
            back = back.next = new ListNode<AnyType>(x);
        }
    }


    public AnyType getFront() throws Exception {
        if (isEmpty()) throw new Exception("ListQueue empty");
        return front.element;
    }

}
