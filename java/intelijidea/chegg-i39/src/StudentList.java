import java.util.Scanner;

/**
 * Student Linked List to maintain student data
 */
public class StudentList {
    private Node head; // head node of linked list
    private Node tail; // tail node of linked list

    StudentList(){
        this.head = null;
        this.tail = null;
    }

    /**
     * add new student to linked list
     * @param student new student data to be add
     */
    public void add(Student student){
        Node node = new Node(); // create new node
        node.student = student; // set new node data

        // list is empty
        // initialize head and tail to new Node
        if (isEmpty()){
            this.head = node;
            this.tail = node;
            return;
        }

        // if list is not empty add data to next of tail;
        // set tail to new Node
        this.tail.next = node;
        this.tail = node;
    }

    /**
     * delete an student from current linked list
     * @param id if student to be delete
     */
    public void delete(int id){
        // sort current list in ascending order
        this.sortInAscending();

        // if id is equal to the id of head node
        // delete head node
        if (id == this.head.student.getId()){
            this.head = this.head.next;
            return;
        }

        // if id is not equal to the id of current node
        Node curr = this.head.next;
        Node pre = this.head;
        // find node
        while (curr != null && id <= curr.student.getId()){
            if (id == curr.student.getId()){
                // if node is found delete it
                pre.next = this.head.next;
                return;
            }
            pre = curr;
            curr = curr.next;
        }
    }

    /**
     * update student information
     * @param id of student to be update
     */
    public void update(int id){
        //search student if, exist
        Student student = this.search(id);

        if (student == null){
            System.out.println("No student found with this id.");
            return;
        }

        // fetch new data from user and update it
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter student age: ");
        student.setAge(scanner.nextInt()); // fetch and update age
        scanner.nextLine();

        System.out.println("Enter student gender (M/F): ");
        student.setGender(scanner.nextLine().charAt(0)); // fetch and update gender

        System.out.println("Enter student nationality: ");
        student.setNationality(scanner.nextLine()); // fetch and update nationality

        System.out.println("Enter student phone number: ");
        student.setPhoneNo(scanner.nextLine()); // fetch and update phone number

        scanner.close();
    }

    /**
     * display all  student information present in current list
     */
    public void display(){
        Node curr = this.head;
        while (curr != null){
            System.out.println();
            curr.student.print();
            System.out.println();
            curr = curr.next;
        }
    }

    /**
     * sort current student list in ascending order
     * use bubble sort algorithm
     *
     */
    public void sortInAscending(){
        Node currOne = this.head;

        while (currOne != null){
            Node currTwo = this.head;
            while (currTwo.next != null){
                if (currTwo.student.getId() > currTwo.next.student.getId()){
                    Student student = currTwo.student;
                    currTwo.student = currTwo.next.student;
                    currTwo.next.student = student;
                }
                currTwo = currTwo.next;
            }
            currOne = currOne.next;
        }
    }

    /**
     * sort current student list in descending order
     * use selection sort algorithm
     */
    public void  sortInDescending(){
        Node curr = this.head;
        while (curr != null){
            Node max = curr; // set max to current element
            Node c = max.next;
            while (c != null) {
                if (max.student.getId() < c.student.getId()) {
                    // if max id is less then c.student.getId() swap c.student with max
                    max = c;
                }
                c = c.next;
            }
            // swap max with current element
            Student student = curr.student;
            curr.student = max.student;
            max.student = student;
            curr = curr.next;
        }
    }

    /**
     * search a student using student id
     * use binary search algorithm
     * @param id of student
     * @return instance of student
     */
    public Student search(int id){
        Node start = head;
        Node last = null;

        do {
            Node midNode = findMidNode(start, last);
            if (midNode == null)
                return null;
            if (midNode.student.getId() == id)
                return midNode.student;
            else if (midNode.student.getId() > id) {
                start = midNode.next;
            } else
                last = midNode;
        } while (last == null || last != start);
        return null;
    }

    /**
     * find middle node of linked list
     * @param start head of list
     * @param last tail of list
     * @return middle node
     */
    private Node findMidNode(Node start, Node last)
    {
        if (start == null)
            return null;

        Node slw = start;
        Node fst = start.next;

        while (fst != last) {
            fst = fst.next;
            if (fst != last) {
                slw = slw.next;
                fst = fst.next;
            }
        }
        return slw;
    }

    /**
     *
     * @return true if list is empty otherwise return false
     */
    public boolean isEmpty(){
        if(this.head == null){
            return true;
        }
        return false;
    }
}
