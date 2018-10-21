package com.uca.util;

public interface Collection<T extends Comparable<T>> extends Iterable<E> {
    public void add(T t);

    public void remove(T t);

    public int size();
    
    public boolean isEmpty();

    public void clear();
}