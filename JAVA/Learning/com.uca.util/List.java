package com.uca.util;

public interface List<T> extends Collection<T> {
    public void add(T t, int index);

    public void remove(int index);

    public T get(int index);
}