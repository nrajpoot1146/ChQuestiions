import Contiguous

class BinaryTree:
    def __init__(self):
        """
        Binary(): creates and empty Binary Tree
        __init__: void -> BinaryTree
        """
        self.contSpace = Contiguous()
        pass

    def is_empty(self):
        return self.contSpace.access(0) == None

    def root(self):
        return self.contSpace.access(0)

    def value(self, ID):
        return self.contSpace.access(ID)
        pass

    def parent(self,ID):
        parId = (ID - 1) // 2
        return self.contSpace.access(parId)

    def left_child(self, ID):
        return self.contSpace.access(2 * ID + 1)

    def right_child(self, ID):
        return self.contSpace.access(2 * ID + 2)

    def set_value(self, ID, Value):
        self.contSpace.store(ID, Value)
        pass

    def add_leaf(self, Value, ParentID = None, Side = ""):
        if ParentID == None:
            self.contSpace = Contiguous()
            self.contSpace.store(0, Value)
        else:
            if Side == "Left":
                self.contSpace.store(2 * ParentID + 1)
            else:
                self.contSpace.store(2 * ParentID + 2)
        pass