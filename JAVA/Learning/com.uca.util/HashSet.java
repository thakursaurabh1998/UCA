package com.uca.util;

import java.util.LinkedList;

public class HashSet<E> {
    private int bucketSize;
    private int size;
    private float loadFactor;
    private LinkedList<E>[] bucket;

    public HashSet(int size, float loadFactor) {
        this.bucketSize = size;
        this.loadFactor = loadFactor;
        this.size = 0;
        this.bucket = (LinkedList<E>[]) new Object[size];
    }

    public HashSet() {
        this(16, 0.75f);
    }

    public void resize() {
        this.bucketSize = this.bucketSize * 2;
        Iterator<E> ite = this.iterator();
        LinkedList<E>[] temp = (LinkedList<E>[]) new Object[this.bucketSize];
        while (ite.hasNext()) {
            E curr = ite.next();
            int bucketNumber = curr.hashCode() % bucketSize;
            
        }
    }

    public void add(E e) {
        int bucketNumber = e.hashCode() % bucketSize;
        if (bucket[bucketNumber] == null) {
            bucket[bucketNumber] = new LinkedList<>();
        }
        if (!bucket[bucketNumber].contains(e)) {
            bucket[bucketNumber].add(e);
            size++;
            if (bucket[bucketNumber].size() >= size * loadFactor)
                resize();
        }
    }
}