package com.uca.util;

public class LinkedList<T> implements List<T> {
    private Node<T> head;
    private int size;

    private class Node<T> {
        T data;
        Node next;

        Node(T d) {
            this.data = d;
            this.next = null;
        }
    }

    LinkedList() {
        this.head = null;
    }

    public int size() {
        return this.size;
    }

    public T get(int a) {
        T b = (T) new Object();
        return b;
    }

    public void remove(int a) {

    }

    public void add(T a, int b) {

    }

    public void clear() {

    }

    public boolean isEmpty() {
        return false;
    }

    public void remove(T t) {

    }

    // @Override
    public void add(T v) {
        if (this.head == null) {
            this.head = new Node(v);
            return;
        }
        Node<T> root = this.head;
        while (root.next != null) {
            root = root.next;
        }
        root.next = new Node(v);
    }

    public String toString() {
        String res = "HEAD -> ";
        Node root = this.head;
        while (root != null) {
            res = res + root.data.toString() + " -> ";
            root = root.next;
        }
        return res;
    }

    public static void main(String[] args) {
        LinkedList ll = new LinkedList();
        ll.add(1);
        ll.add(2);
        ll.add(3);
        ll.add(4);
        System.out.println(ll.toString());
    }
}