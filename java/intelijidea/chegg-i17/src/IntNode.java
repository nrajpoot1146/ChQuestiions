public class IntNode {
    public IntNode nextNode;
    public IntNode prevNode;
    public int data;

    /**
     * Constructor with parameter
     * @param data integer value for this node
     * @param prevNode reference of previous node
     * @param nextNode reference of next Node
     */
    IntNode(int data, IntNode prevNode, IntNode nextNode){
        this.data = data;
        this.prevNode = prevNode;
        this.nextNode = nextNode;
    }

    /**
     * Constructor with one parameter
     * @param data integer value for this node
     */
    IntNode(int data){
        this.data = data;
        this.prevNode = null;
        this.nextNode = null;
    }

    /**
     * print data value of current node
     */
    public void printNodeData(){
        System.out.print(this.data);
    }
}
