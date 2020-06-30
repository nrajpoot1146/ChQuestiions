import java.util.Scanner;

public class Graph {
    private int[][] matrix = new int[100][100];// edge-adjacency matrix
    private int n;// number of vertices
    private int e;// number of edges
    
    private Edge[] xx = new Edge[100]; // array to hold up to 100 edges

    public Graph() { //interactively input values for the edge-adjacency matrix 
        int i; 
        int j; e = 0; 
        int edge_cost; 
        Scanner in = new Scanner(System.in); 
        System.out.print("\n"); 
        System.out.print("input number of vertices: n = "); 
        n = in.nextInt(); 
        System.out.println(); 
        System.out.println("input costs of edges; cost is 0 for all non-edges"); 
        for (i = 1; i <= n; i++) { 
            for (j = i; j <= n; j++) { 
                System.out.println(); 
                System.out.println("cost for edge (" + i + "," + j + ") = "); 
                edge_cost = in.nextInt(); 
                // System.out.println(edge_cost); 
                //*** store the cost of the edge between vertices 
                //*** i and j in the edge-adjacency matrix (in 2 places) 
                //if there is an edge between i and j, enter the edge into array xx 
                if (edge_cost > 0) { 
                    e = e + 1;
                    //update the edge count 
                    //*** create the edge from i to j as an Edge object 
                    //*** and store it in xx[e] 
                }
            } 
        } 
    }

public final void kruskal() { 
    //*** declare an EDGEheap called A
    //*** set the number of edge nodes in the heap to equal e 
    //initialize the edge nodes for the heap, A.heap[1], ..., A.heap[e], 
    //from the edges xx[1], ..., xx[e]
    for(int p = 1; p <= e; p++){ 
        //*** set vertex 1 for A.heap[p] 
        //*** set vertex 2 
        //*** set the cost 
    } 
    MFS s = new MFS(n); 
    //create the MFS structure 
    System.out.println("\n" + "number vertices = " + s.get_size()); 
    //*** display the points table 
    //*** display the components table 
    int i; 
    int w1; 
    int w2; 
    int c1; 
    int c2; 
    System.out.println("initial heap of edges:"); 
    //*** turn A.heap, an array of EDGE objects, into a heap 
    //main loop of Kruskal's algorithm 
    System.out.println("\n" + "edges of MCST:"); 
    do { EDGE curr = A.dequeue();
        //remove the low-cost edge 
        //*** let w1 be vertex 1 of curr 
        //*** let w2 be vertex 2 of curr 
        //*** let c1 be the component of w1 
        //*** let c2 be the component of w2 
        //*** if the vertices are from different components, 
        //*** merge the smaller component into the larger 
        // and print the new edge for the MCST 
        System.out.println("\n"); 
        System.out.println(curr.get_v1() + " " + curr.get_v2()+" " +curr.get_cost()); } 
        while (s.get_num_comp() != 1);
        // loop ends when there is 1 component, i.e. the 
        // subgraph is now a MCST 
    } 
}