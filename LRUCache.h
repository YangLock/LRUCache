//
// Created by 杨宗霖 on 2024/10/17.
//

#ifndef LRUCACHE_H
#define LRUCACHE_H
#include <unordered_map>

template <typename Key, typename Value>
struct DLinkedNode
{
    Key key;
    Value value;
    DLinkedNode * prev;
    DLinkedNode * next;
    DLinkedNode(Key _key, Value _value): key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

template <typename Key, typename Value>
class LRUCache
{
private:
    std::unordered_map<Key, DLinkedNode<Key, Value>*> cache;
    DLinkedNode<Key, Value>* head;   // dummy head
    DLinkedNode<Key, Value>* tail;   // dummy tail
    int capacity;

public:
    // constructor and deconstructor
    explicit LRUCache(int cap);
    ~LRUCache();

    // LRUCache has two operate functions: get() and put()
    std::optional<Value> get(const Key& _key);
    void put(const Key& _key, const Value& _value);

    // functions for double linked list
    void addToHead(DLinkedNode<Key, Value>* node);
    void removeNode(DLinkedNode<Key, Value>* node);
    void moveToHead(DLinkedNode<Key, Value>* node);
    DLinkedNode<Key, Value>* removeTail();
};

#include "LRUCache.tpp"

#endif //LRUCACHE_H
