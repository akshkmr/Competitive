package com.company.policies;

import com.company.exceptions.InvalidElementException;
import com.company.exceptions.InvalidKeyException;

public interface EvictionPolicy<Key> {
    void keyAccessed(Key key) throws InvalidKeyException, InvalidElementException;

    Key evictKey(Key key);
}
