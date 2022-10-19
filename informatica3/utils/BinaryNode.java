package informatica3.utils;

public class BinaryNode<AnyType> {

    private Integer element;
    private BinaryNode<AnyType> left;
    private BinaryNode<AnyType> rigth;

    public BinaryNode() {
        this.element = null;
        this.left = null;
        this.rigth = null;
    }

    public BinaryNode(Integer theElement) {
        element = theElement;
        this.left = null;
        this.rigth = null;
    }

    public BinaryNode(Integer theElement, BinaryNode<AnyType> lt, BinaryNode<AnyType> rt) {
        element = theElement;
        rigth = rt;
        left = lt;
    }

    public Integer getElement() {
        return element;
    }

    public BinaryNode<AnyType> getLeft() {
        return left;
    }

    public BinaryNode<AnyType> getRight() {
        return rigth;
    }

    public void setElement(Integer x) {
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

        BinaryNode<AnyType> root = new BinaryNode<>(element, null, null);

        if (left != null) root.left = left.duplicate();//if there`s a left subtree, duplicate; attach
        if (rigth != null) root.rigth = rigth.duplicate();//if there`s a rigth subtree, suplicate attach

        return root; // return resulting tree
    }

    public void add(BinaryNode<AnyType> newRoot, Integer element) {
        if (element < newRoot.getElement()) {
            if (newRoot.getLeft() != null) add(newRoot.getLeft(), element);
            else newRoot.setLeft(new BinaryNode<>(element));
        } else {
            if (newRoot.getRight() != null) add(newRoot.getRight(), element);
            else newRoot.setRigth(new BinaryNode<>(element));
        }
    }

    public void addNotRep(Integer element, BinaryNode<AnyType> node) throws Exception {
        if (element < node.getElement()) {
            if (node.getLeft() == null) {
                node.setLeft(new BinaryNode<>(element));
            } else {
                addNotRep(element, node.getLeft());
            }
        } else if (element > getElement()) {
            if (node.getRight() == null) {
                node.setRigth(new BinaryNode<>(element));
            } else {
                addNotRep(element, node.getRight());
            }
        } else {
            throw new Exception("El elemento ya esta en el arbol");
        }
    }

    public BinaryNode<AnyType> delete(Integer element, BinaryNode<AnyType> node) throws Exception {
        if (element.equals(node.getElement())) {
            if (node.getLeft() == null && node.getRight() == null) node = null;
            else if (node.getRight() == null) node = node.getLeft();
            else if (node.getLeft() == null) node = node.getRight();
            else {
                BinaryNode<AnyType> aux = node.getLeft();
                node = node.getRight();
                BinaryNode<AnyType> aux2 = node.getLeft();
                if (aux2 != null) {
                    while (aux2.getLeft() != null) {
                        aux2 = aux2.getLeft();
                    }
                    aux2.setLeft(aux);
                } else node.setLeft(aux);
            }
        } else if (element < node.getElement() && node.getLeft() != null) node.setLeft(delete(element, node.getLeft()));
        else if (element > node.getElement() && node.getRight() != null)
            node.setRigth(delete(element, node.getRight()));
        else throw new Exception("El elemento no esta en el arbol");
        return node;
    }

    public Integer find(BinaryNode newRoot, Integer element) {

        if (element.equals(newRoot.getElement())) {
            return newRoot.getElement();
        } else if (element < newRoot.getElement()) {
            if (newRoot.getLeft() != null) return find(newRoot.getLeft(), element);
            else return null;
        } else {
            if (newRoot.getRight() != null) return find(newRoot.getRight(), element);
            else return null;
        }

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
