// E must be a class that implements Comparable
public class BSTSet<E extends Comparable<E>> extends AbstractBSTSet<E> {
    /* **************************************************
     *
     *    You are provided the following attribute
     *    and implemented methods from AbstractBSTSet:
     *
     *    public Node<E> root;
     *    public void add(E e){};
     *    public void remove(E e) {};
     *
     * **************************************************/

    // Construct a new empty set
    public BSTSet() {}

    // Returns true if the set contains the specified element.
    public boolean contains(E e) {
        return contains(e, root);
    }

    // Returns true if the set contains the specified element.
    private boolean contains(E e, Node<E> root) {
        if (root == null){
            return false;
        }else if (root.data == e){ // if current node contains same data
            return true;
        }

        int compare = e.compareTo(root.data);
        if(compare<0){
            return contains(e, root.left);
        } else{
            return contains(e, root.right);
        }
    }

    // Returns the minimum element in the BST
    public E minimum(Node<E> root) {
        if (root.left == null){
            return root.data;
        }
        return minimum(root.left);
    }

    // Returns the number of edges in the longest path from root to leaf
    public int height(Node<E> root) {
        if (root == null){
            return 0;
        }else {
            int lHeight = height(root.left);
            int rHeight = height(root.right);

            if(lHeight > rHeight){
                if (root == this.root){
                    return lHeight;
                }
                return lHeight + 1;
            }else
                if (root == this.root){
                    return rHeight;
                }
                return rHeight + 1;
        }
    }

    // Returns true if the compared trees have the exact same structure
    public boolean sameTree(Node<E> root1, Node<E> root2) {
        if (root1 == null && root2 == null) { // if both tree are empty return true
            return true;
        }

        if (root1 != null && root2 != null) { // it both tree are not empty
            return (
                    root1.data == root2.data && // comparison of data of current node
                    sameTree(root1.left, root2.left) && // comparision left subtree of current node
                    sameTree(root1.right, root2.right) // comparision right subtree of current node
                    );
        }

        return false;
    }


}