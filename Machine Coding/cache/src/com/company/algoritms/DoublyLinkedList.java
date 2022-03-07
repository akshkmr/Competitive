package com.company.algoritms;

import com.company.exceptions.InvalidElementException;
import com.company.exceptions.InvalidKeyException;

import java.util.NoSuchElementException;

public class DoublyLinkedList<E> {
    DoublyLinkedListNode<E> head;
    DoublyLinkedListNode<E> tail;

    public DoublyLinkedList() {
        head = new DoublyLinkedListNode<E>(null);
        tail = new DoublyLinkedListNode<E>(null);

        head.next = tail;
        tail.prev = head;
    }

    public void detachNode(DoublyLinkedListNode<E> node) {
        if (node != null) {
            node.prev.next = node.next;
            node.next.prev = node.prev;
        }
    }

    public void addNodeAtLast(DoublyLinkedListNode<E> node) throws InvalidKeyException {
        if (node == null)
            throw new InvalidKeyException();

        DoublyLinkedListNode<E> tailPrev = tail.prev;
        tailPrev.next = node;
        node.next = tail;
        tail.prev = node;
        node.prev = tailPrev;
    }

    public DoublyLinkedListNode<E> addElementAtLast(E element) throws  InvalidKeyException {
        if (element == null)
            throw  new InvalidKeyException();

        DoublyLinkedListNode<E> newNode = new DoublyLinkedListNode<E>(element);
        addNodeAtLast(newNode);
        return newNode;
    }

    public boolean isItemPresent() {
        return head.next != tail;
    }

    public DoublyLinkedListNode<E> getFirstNode() {
        if (!isItemPresent())
            throw new NoSuchElementException();
        return head.next;
    }

    public DoublyLinkedListNode<E> getLastNode() {
        if (!isItemPresent())
            throw new NoSuchElementException();
        return tail.prev;
    }
}
