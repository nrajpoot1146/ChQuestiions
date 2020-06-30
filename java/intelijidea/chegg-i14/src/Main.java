public class Main {
    public static void main(String[] args){
        Tree t = Tree.create(2);
        int[] v = {1, 2, 3, 4, 5, 6};
        t.fill(v);
        t.printInorder(t);
    }
}