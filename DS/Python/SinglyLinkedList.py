class Node:
    """Create a node for a linked list"""

    def __init__(self, data=None):
        self.data = data
        self.next = None


class LinkedList:
    """Create a Singly Linked List data structure"""

    def __init__(self):
        self.head = None

    def addAtBeg(self, data):
        """Add element at the begining of the list"""
        temp = Node(data)
        temp.next = self.head
        self.head = temp

    def removeAtBeg(self):
        """Remove an element from the begining of the linked list"""
        temp = self.head
        self.head = temp.next
        return temp.data

    def addAtLast(self, data):
        """Add element at the end of the list"""
        temp = Node(data)
        curr = self.head
        while curr.next:
            curr = curr.next
        curr.next = temp

    def removeAtLast(self):
        """Remove element from the end of the list"""
        curr = self.head
        while curr.next.next:
            curr = curr.next
        temp = curr.next.data
        curr.next = None
        return temp

    def addAt(self, data, pos):
        """Add element at the defined position"""
        if pos <= 1:
            self.addAtBeg(data)
        else:
            curr = self.head
            p = 1
            while p < pos-1 and curr:
                curr = curr.next
                p += 1
            if curr is None:
                print("Position not found")
                return
            temp = Node(data)
            temp.next = curr.next
            curr.next = temp

    def removeAt(self, pos):
        """Remove element at the defined position"""
        curr = self.head
        if pos == 1:
            return self.removeAtBeg()
        else:
            p = 1
            while p<pos-1 and curr:
                curr = curr.next
                p+=1
            if curr is None:
                print("Position not found")
                return
            temp = curr.next
            curr.next = temp.next
            temp.next = None
            return temp.data



    def listPrint(self):
        """Print all the elements of the list"""
        temp = self.head
        while temp:
            print(temp.data, end=' ')
            temp = temp.next
        print('\n')


if __name__ == '__main__':
    a = LinkedList()
    a.addAtBeg(1)
    a.addAtBeg(2)
    a.addAtBeg(3)
    a.addAtBeg(4)
    a.addAtLast(0)
    a.addAt(20,6)
    a.listPrint()
    print(a.removeAt(3))
    a.listPrint()
    print(a.removeAtBeg())
    print(a.removeAtLast())
    a.removeAtLast()
