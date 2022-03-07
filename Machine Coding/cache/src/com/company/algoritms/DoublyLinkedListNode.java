package com.company.algoritms;

public class DoublyLinkedListNode<E> {
    DoublyLinkedListNode<E> next;
    DoublyLinkedListNode<E> prev;
    E element;

    public E getElement() {
        return element;
    }

    DoublyLinkedListNode(E element) {
        this.element = element;
        this.next = null;
        this.prev = null;
    }
}
