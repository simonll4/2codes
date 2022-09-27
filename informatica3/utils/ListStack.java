package informatica3.utils;

public class ListStack<AnyType> {

    private ListNode<AnyType> topOfstack = null;

    public ListStack() {

    }

    public boolean isEmpty() {
        return topOfstack == null;
    }

    public void makeEmpty() {
        topOfstack = null;
    }

    public void push(AnyType x) {
        topOfstack = new ListNode<AnyType>(x, topOfstack);
    }

    public void pop() throws Exception {
        if (isEmpty()) throw new Exception("ListStack empty");
        topOfstack = topOfstack.next;
    }

    public AnyType top() throws Exception {
        if (isEmpty()) throw new Exception("ListStack empty");
        return topOfstack.element;
    }

    public AnyType topAndPop() throws Exception {
        if (isEmpty()) throw new Exception("ListStack empty");
        AnyType topItem = topOfstack.element;
        topOfstack = topOfstack.next;
        return topItem;
    }

}
