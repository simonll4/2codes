package informatica3.ABB;

import informatica3.utils.*;


public class Main {

    public static void main(String[] args) {
        BinaryTree<Integer> tree = new BinaryTree<>();

        tree.add(50);
        tree.add(20);
        tree.add(30);
        tree.add(60);
        tree.add(80);

        System.out.println("print postOrder");
        tree.printPostOrder();
        System.out.println("print preOrder");
        tree.printPreOrder();
        System.out.println("print inOrder");
        tree.printInOrder();

        if (tree.find(20) != null) System.out.println("NUMERO ECONTRADO");

    }

}
