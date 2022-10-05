package informatica3.utils;

public class BinaryTree<AnyType> {

    private BinaryNode<AnyType> root;

    public BinaryTree() {
        root = null;
    }

    public BinaryTree(AnyType rootItem) {
        root = new BinaryNode<AnyType>(rootItem, null, null);
    }

    public BinaryNode<AnyType> getRoot() {
        return root;
    }

    public int size() {
        return BinaryNode.size(root);
    }

    public int height() {
        return BinaryNode.height(root);
    }

    public void printPreOrder() {
        if (root != null) root.printPreOrder();
    }

    public void printInOrder() {
        if (root != null) root.printInOrder();
    }

    public void printPostOrder() {
        if (root != null) root.printPostOrder();
    }

    public void makeEmpty() {
        root = null;
    }

    public boolean isEmpty() {
        return root == null;
    }

    public void merge(AnyType rootItem, BinaryTree<AnyType> t1, BinaryTree<AnyType> t2) {

        if (t1.root == t2.root && t1.root != null) throw new IllegalArgumentException();

        //allocate new node
        root = new BinaryNode<AnyType>(rootItem, t1.root, t2.root);

        //ensure that every node is in one tree
        if (this != t1) t1.root = null;
        if (this != t2) t2.root = null;

    }


}

