

public class IntList {
    // Linked list nodes
    public IntNode headNode;
    public IntNode tailNode;

    public IntList() {
        // Front of nodes list
        headNode = null;
        tailNode = null;
    }

    // append
    public void append(IntNode newNode) {
        if (headNode == null) { // List empty
            headNode = newNode;
            tailNode = newNode;
        }
        else {
            tailNode.nextNode = newNode;
            newNode.prevNode = tailNode;
            tailNode = newNode;
        }
    }

    // prepend
    public void prepend(IntNode newNode) {
        if (headNode == null) { // list empty
            headNode = newNode;
            tailNode = newNode;
        }
        else {
            newNode.nextNode = headNode;
            headNode.prevNode = newNode;
            headNode = newNode;
        }
    }

    // insertAfter
    public void insertAfter(IntNode curNode, IntNode newNode) {
        IntNode sucNode;
        if (headNode == null) { // List empty
            headNode = newNode;
            tailNode = newNode;
        }
        else if (curNode == tailNode) { // Insert after tail
            tailNode.nextNode = newNode;
            newNode.prevNode = tailNode;
            tailNode = newNode;
        }
        else {
            sucNode = curNode.nextNode;
            newNode.nextNode = sucNode;
            newNode.prevNode = curNode;
            curNode.nextNode = newNode;
            sucNode.prevNode = newNode;
        }
    }

    // TODO: Write insertInDescendingOrder() method
    public void insertInDescendingOrder(IntNode newNode) {

        if (this.headNode == null || this.headNode.data < newNode.data){ // add newNode as head node if list is empty
            this.prepend(newNode);                                       // or newNode.data > headNode.data
            return;
        }

        if(this.tailNode.data > newNode.data){ // add newNode at the end of the node
            this.append(newNode);
            return;
        }

        IntNode curNode = this.headNode;
        while (curNode != null && curNode.data > newNode.data ){
            curNode = curNode.nextNode;
        }

        this.insertAfter(curNode.prevNode, newNode);
    }

    public void printIntList() {
        IntNode curNode;

        curNode = headNode;
        while (curNode != null) {
            curNode.printNodeData();
            System.out.print(" ");
            curNode = curNode.nextNode;
        }
    }
}