package informatica3.utils;

public class BinaryNode<AnyType> {

    private AnyType element;
    private BinaryNode<AnyType> left;
    private BinaryNode<AnyType> rigth;

    public BinaryNode() {
        this.element = null;
        this.left = null;
        this.rigth = null;
    }

    public BinaryNode(AnyType theElement, BinaryNode<AnyType> lt, BinaryNode<AnyType> rt) {
        element = theElement;
        rigth = rt;
        left = lt;
    }

    public AnyType getElement() {
        return element;
    }

    public BinaryNode<AnyType> getLeft() {
        return left;
    }

    public BinaryNode<AnyType> getRight() {
        return rigth;
    }

    public void setElement(AnyType x) {
        element = x;
    }

    public void setLeft(BinaryNode<AnyType> t) {
        left = t;
    }

    public void setRigth(BinaryNode<AnyType> t) {
        rigth = t;
    }

    public static <AnyType> int size(BinaryNode<AnyType> t) {

        if (t == null) return 0;
        else return 1 + size(t.left) + size(t.rigth);
    }

    public static <AnyType> int height(BinaryNode<AnyType> t) {

        if (t == null) return -1;
        else return 1 + Math.max(height(t.left), height(t.rigth));
    }

    public BinaryNode<AnyType> duplicate() {

        BinaryNode<AnyType> root = new BinaryNode<AnyType>(element, null, null);

        if (left != null) root.left = left.duplicate();//if there`s a left subtree, duplicate; attach
        if (rigth != null) root.rigth = rigth.duplicate();//if there`s a rigth subtree, suplicate attach

        return root; // return resulting tree
    }

    public void printPreOrder() {
        System.out.println(element);
        if (left != null) left.printPreOrder();
        if (rigth != null) rigth.printPreOrder();
    }

    public void printPostOrder() {
        if (left != null) left.printPostOrder();
        if (rigth != null) rigth.printPostOrder();
        System.out.println(element);
    }

    public void printInOrder() {
        if (left != null) left.printInOrder();
        System.out.println(element);
        if (rigth != null) rigth.printInOrder();
    }


}
