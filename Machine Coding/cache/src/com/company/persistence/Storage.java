package com.company.persistence;

import com.company.exceptions.NotFoundException;
import com.company.exceptions.StorageFullException;

public interface Storage<Key, Value> {
    void add(Key key, Value value) throws StorageFullException;

    void remove(Key key) throws NotFoundException;

    Value get(Key key) throws NotFoundException;
}
