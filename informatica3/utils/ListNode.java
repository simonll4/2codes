package informatica3.utils;

public class ListNode<AnyType> {

    public AnyType element;
    public ListNode next;

    public ListNode(AnyType theElement) {
        this(theElement, null);
    }
    public ListNode(AnyType theElement, ListNode<AnyType> n) {
        element = theElement;
        next = n;
    }

}
