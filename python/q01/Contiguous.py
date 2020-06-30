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

    def __eq__(self, other):
        if(self.size() != other.size()):
            return False
        else:
            for pos in range(self.size()):
                if self.access(pos) != other.access(pos):
                    return False
                else:
                    return True
                
    def access(self, index):
        return self._items[index]

    def store(self, index, value):
        self._items[index] = value