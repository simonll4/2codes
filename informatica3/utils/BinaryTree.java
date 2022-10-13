package informatica3.utils;

public class BinaryTree<AnyType> {

    private BinaryNode<AnyType> root;

    public BinaryTree() {
        root = new BinaryNode<>();
    }

    public BinaryTree(Integer rootItem) {
        root = new BinaryNode<>(rootItem, null, null);
    }

    public void add(Integer element) {


        if (root.getElement() == null) {    //chequeo si el arbol esta vacio
            root.setElement(element);
        } else {
            //Si el valor a insertar es menor al valor del nodo se insertará a la izquierda.
            //Si el valor a insertar es mayor al valor del nodo se insertará a la derecha.
            if (element < root.getElement()) {
                if (root.getLeft() != null) add(root.getLeft(), element);
                else root.setLeft(new BinaryNode<>(element));
            } else {
                if (root.getRight() != null) add(root.getRight(), element);
                else root.setRigth(new BinaryNode<>(element));
            }
        }
    }

    // metodo para producir la recursividad en el add
    void add(BinaryNode<AnyType> newRoot, Integer element) {
        if (element < newRoot.getElement()) {
            if (newRoot.getLeft() != null) add(newRoot.getLeft(), element);
            else newRoot.setLeft(new BinaryNode<>(element));
        } else {
            if (newRoot.getRight() != null) add(newRoot.getRight(), element);
            else newRoot.setRigth(new BinaryNode<>(element));
        }
    }

    public void addNotRep(Integer element) throws Exception{

        if(element.equals(root.getElement())){
            throw new Exception("ELEMENTO YA AGREGADO");
        }

    }

    public Integer find(Integer element){

        if(element.equals(root.getElement())){
            return root.getElement();
        }
        else if(element < root.getElement()){
            if(root.getLeft() != null) return find(root.getLeft(),element);
            else return null;
        }
        else{
            if(root.getRight() != null) return find(root.getRight(),element);
            else return null;
        }

    }

    Integer find(BinaryNode newRoot,Integer element){

        if(element.equals(newRoot.getElement())){
            return newRoot.getElement();
        }
        else if(element < newRoot.getElement()){
            if(newRoot.getLeft() != null) return find(newRoot.getLeft(),element);
            else return null;
        }
        else{
            if(newRoot.getRight() != null) return find(newRoot.getRight(),element);
            else return null;
        }

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

    public void merge(Integer rootItem, BinaryTree<AnyType> t1, BinaryTree<AnyType> t2) {

        if (t1.root == t2.root && t1.root != null) throw new IllegalArgumentException();

        //allocate new node
        root = new BinaryNode<>(rootItem, t1.root, t2.root);

        //ensure that every node is in one tree
        if (this != t1) t1.root = null;
        if (this != t2) t2.root = null;

    }


}

