package minheap

import "fmt"

type MinIntHeap struct {
	heap     []uint64
	capacity int
	size     int
}

func Init(maxCap int) *MinIntHeap {

	return &MinIntHeap{
		capacity: maxCap,
		heap: make([]uint64, maxCap),
	}
}

func (mh *MinIntHeap) Insert(key uint64) error {
	if mh.size == mh.capacity {
		return fmt.Errorf("MaxCapacity")
	}
	mh.heap[mh.size] = key
	mh.size++
	mh.bubbleUp()
	return nil
}

func (mh *MinIntHeap) Len() int {
	return mh.size
}

func (mh *MinIntHeap) Pop() (uint64, error) {
	if mh.size == 0 {
		return 0, fmt.Errorf("HeapEmpty")
	}
	minVal := mh.heap[0]
	mh.heap[0] = mh.heap[mh.size-1]
	mh.size--
	mh.sink()
	return minVal, nil
}

// Bubble up a key in a heap when the parent is greater
// than the new inserted key, used when inserting a new keys
func (mh *MinIntHeap) bubbleUp() {
	keyIndex := mh.size - 1
	parentIndex := (keyIndex - 1) / 2
	for keyIndex > 0 && mh.heap[parentIndex] > mh.heap[keyIndex] {
		mh.heap[parentIndex], mh.heap[keyIndex] = mh.heap[keyIndex], mh.heap[parentIndex]
		keyIndex = parentIndex
		parentIndex = (keyIndex - 1) / 2
	}
}

// Sink a key in a heap when the child is smaller
// than the root key, used when removing a key from the heap
func (mh *MinIntHeap) sink() {
	keyIndex := 0
	leftChildIndex := keyIndex*2 + 1
	rightChildIndex := keyIndex*2 + 2

	for leftChildIndex < mh.size {
		smallerChildIndex := leftChildIndex
		if rightChildIndex < mh.size && mh.heap[rightChildIndex] < mh.heap[leftChildIndex] {
			smallerChildIndex = rightChildIndex
		}

		if mh.heap[keyIndex] > mh.heap[smallerChildIndex] {
			mh.heap[keyIndex], mh.heap[smallerChildIndex] = mh.heap[smallerChildIndex], mh.heap[keyIndex]
			keyIndex = smallerChildIndex
		} else {
			break
		}
		leftChildIndex = keyIndex*2 + 1
		rightChildIndex = keyIndex*2 + 2
	}
}
