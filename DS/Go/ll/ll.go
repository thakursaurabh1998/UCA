package ll

type (
	node struct {
		next *node
		val  int
	}
	MyLinkedList struct {
		head *node
		tail *node
	}
)

/** Initialize your data structure here. */
func Constructor() MyLinkedList {
	return MyLinkedList{}
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
func (this *MyLinkedList) Get(index int) int {
	iter := this.head
	for i := 0; i <= index; i++ {
		iter = iter.next
	}
	return iter.val
}

func createHead(linkedList *MyLinkedList, val int) {
	newNode := node{
		val: val,
	}
	linkedList.head = &newNode
	linkedList.tail = &newNode
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
func (this *MyLinkedList) AddAtHead(val int) {
	if this.head == nil {
		createHead(this, val)
	} else {
		newNode := &node{
			val:  val,
			next: this.head,
		}
		this.head = newNode
	}
}

/** Append a node of value val to the last element of the linked list. */
func (this *MyLinkedList) AddAtTail(val int) {
	if this.tail == nil {
		createHead(this, val)
	} else {
		newNode := &node{
			val: val,
		}
		// change next item of current tail
		this.tail.next = newNode
		// update the address of new tail
		this.tail = newNode
	}
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
func (this *MyLinkedList) AddAtIndex(index int, val int) {
	iter := this.head
	// loop will end at one item before the required index
	for i := 0; i <= index-1; i++ {
		iter = iter.next
	}
	newNode := &node{
		val:  val,
		next: iter.next,
	}
	iter.next = newNode
}

/** Delete the index-th node in the linked list, if the index is valid. */
func (this *MyLinkedList) DeleteAtIndex(index int) {
	iter := this.head
	// loop will end at one item before the required index
	for i := 0; i <= index-1; i++ {
		iter = iter.next
	}
	if iter.next == nil {
		this.head = nil
		this.tail = nil
	} else {
		iter.next = iter.next.next
	}
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Get(index);
 * obj.AddAtHead(val);
 * obj.AddAtTail(val);
 * obj.AddAtIndex(index,val);
 * obj.DeleteAtIndex(index);
 */
