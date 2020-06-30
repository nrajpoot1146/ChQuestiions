"""
Fiels: _items is a list of items
       _size is number of items that can be stored
"""

## Contiguous(S) produces contiguous memory of size s
## and initializes all entries to None.
## Requires: s is positive
class Contiguous:
    def __init__(self, s):
        self._items = []
        self._size = s;
        for index in range(self._size):
            self._items.append(None)
        
    ## repr(self) produces a strinng with the sequence of values.
    ## __repr__: contiguous -> Str

    def __repr__(self):
        to_return = "("
        for index in range(self._size - 1):
            if self.access(index) == None:
                to_print = "None"
            else:
                to_print = self.access(index)
            to_return = to_return + str(to_print) + ","
        
        if self.access(self._size - 1) == None:
            to_print = "None"
        else:
            to_print = self.access(self._size - 1)
        return to_return + str(to_print) + ")"

    ## self == other produces the size of self
    ## size. Contiguous -> Int

    def size(self):
        return self._size

    ## self == other produces True if self and other have the same 
    ##   size and store the same values at each index
    ## __eq__: Contiguous Contiguous -> Bool
    def __eq__(self, other):
        if(self.size() != other.size()):
            return False
        else:
            for pos in range(self.size()):
                if self.access(pos) != other.access(pos):
                    return False
                else:
                    return True
                
    ## self.access(index) produces the value at the given index
    ## access: Contiguous Int -> Any
    ## Requires : 0 <= index < self._size
    def access(self, index):
        return self._items[index]

    ## self.store(index, value) stores value at the given index
    ## Effects: Mutates self by storing value at the given index
    ## stores: Contiguous Int Any -> None
    ## Requires: 0 <= index <self._size
    def store(self, index, value):
        self._items[index] = value

class BinaryTree:
    def __init__(self):
        """
        Binary(): creates and empty Binary Tree
        __init__: void -> BinaryTree
        """
        self.contSpace = Contiguous(64)
        pass

    def is_empty(self):
        """
        self.is_empty(): returns True if self is empty, otherwise False
        is_empty: BinaryTree -> Bool
        """
        return self.contSpace.access(0) == None

    def root(self):
        """
        self.root(): return the ID of the root of self
        root: BinaryTree -> nodeID
        """
        return 0

    def value(self, ID):
        return self.contSpace.access(ID)
        pass

    # get parent of a child with given id
    def parent(self,ID):
        parId = (ID - 1) // 2
        return self.contSpace.access(parId)

    # get left child of any node
    def left_child(self, ID):
        return self.contSpace.access(2 * ID + 1)

    # get right child of any node
    def right_child(self, ID):
        return self.contSpace.access(2 * ID + 2)

    # set value at given id
    def set_value(self, ID, Value):
        self.contSpace.store(ID, Value)
        pass

    def add_leaf(self, Value, ParentID = None, Side = ""):
        if ParentID == None:
            self.contSpace = Contiguous(64)
            self.contSpace.store(0, Value)
        else:
            if Side == "Left":
                while self.contSpace.access(2 * ParentID + 1) != None:
                    ParentID = 2 * ParentID + 1
                self.contSpace.store( 2 * ParentID + 1, Value)
            else:
                while self.contSpace.access(2 * ParentID + 2) != None:
                    ParentID = 2 * ParentID + 2
                self.contSpace.store(2 * ParentID + 2, Value)
        pass

a = [1, 2, 3, 5, 6, 8]

binaryTree = BinaryTree()

side = "Left"
parId = 0

for index in range(len(a)):
    if index == 0:
        binaryTree.add_leaf(a[index])
    else:
        if side == "Left":
            binaryTree.set_value(2 * parId +1, a[index])
            side = "Right"
        else:
            binaryTree.set_value(2 * parId + 2, a[index])
            side = "Left"
            parId += 1

    
print("root: ")
print(binaryTree.parent(1))

print("\nchild of root: ")
print(str(binaryTree.left_child(0)) + " " +str(binaryTree.right_child(0)))

print("\nspace to store binary tree node: ")
print(str(binaryTree.contSpace))