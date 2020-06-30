import java.util.Stack;

public class Tree {
    private Tree left, right;
    private int data;
    public Tree(Tree l, Tree r, int d){
        this.left = l;
        this.right = r;
        this.data = d;
    }

    /**
     *
     * @param height of tree
     * @return root note of tree
     */
    public static Tree create(int height){
        Tree root = new Tree(null, null, -1);
        Stack<Tree> stack = new Stack<Tree>(); //stack to trace tree
        stack.push(root);
        int i=0;
        while (stack.size()>0 ){
            Tree currentNode = stack.peek();

            if (i != height && currentNode.left == null){ //condition to insert left element
                Tree left = new Tree(null, null, -1);
                currentNode.left = left;
                stack.push(left);
                i++;

            }else if( i!= height && currentNode.right == null){ // condition to insert right element
                Tree right = new Tree(null, null, -1);
                currentNode.right = right;
                stack.push(right);
                i++;
            }else { //pop an element if both left and right element is not equal to null or i == height
                stack.pop();
                i--;
            }

        }
        return root;
    }

    /**
     * fill array element to tree in inorder way
     * @param v
     * @return
     */
    public boolean fill(int[] v){
        if(v.length == 0 || v == null){
            return false;
        }
        Stack<Tree> stack = new Stack<Tree>();
        Tree currentNode = this;
        int i=0;
        while (currentNode != null || stack.size() > 0)
        {

            /* Reach the left most Node of the
            curr Node */
            while (currentNode !=  null)
            {
                //push currentNode on the stack
                stack.push(currentNode);
                currentNode = currentNode.left;
            }

            /* Current must be NULL at this point */
            currentNode = stack.pop();

            if (i == v.length)
                break;
            currentNode.data = v[i];
            i++;

            currentNode = currentNode.right;
        }

        return true;
    }

    /**
     * print tree in inorder
     * @param node root node
     */
    void printInorder(Tree node)
    {
        if (node == null)
            return;

        // first recur on left child
        printInorder(node.left);

        // print the data of node
        System.out.print(node.data + " ");

        // now recur on right child
        printInorder(node.right);
    }

}
