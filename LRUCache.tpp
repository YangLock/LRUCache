//
// Created by 杨宗霖 on 2024/10/17.
//

template <typename Key, typename Value>
LRUCache<Key, Value>::LRUCache(int cap): capacity(cap)
{
    head = new DLinkedNode<Key, Value>(Key(), Value());
    tail = new DLinkedNode<Key, Value>(Key(), Value());
    head->next = tail;
    tail->prev = head;
}

template <typename Key, typename Value>
LRUCache<Key, Value>::~LRUCache()
{
    DLinkedNode<Key, Value> *curr = head;
    while (curr != nullptr)
    {
        DLinkedNode<Key, Value> *next = curr->next;
        delete curr;
        curr = next;
    }
}

template <typename Key, typename Value>
std::optional<Value> LRUCache<Key, Value>::get(const Key& _key)
{
    // If the specific key does not exist, return nullopt.
    // Otherwise, query the node in cache, move this to head of double linked list.
    // Return the value of this node.
    if (cache.count(_key) == 0)
    {
        return std::nullopt;
    }
    DLinkedNode<Key, Value> *node = cache[_key];
    moveToHead(node);
    return node->value;
}

template <typename Key, typename Value>
void LRUCache<Key, Value>::put(const Key& _key, const Value& _value)
{
    // 1. If the specific key does not exist, then create a new node.
    // Add this node into the head of double linked list.
    // Add this node into cache.
    // If cache size is larger than capacity, then remove the tali node.
    // Remove this node from cache.
    // 2. If cache has this key, then find this node.
    // Modify the value of this node.
    // Move this node to the head of double linked list.
    if (cache.count(_key) == 0)
    {
        DLinkedNode<Key, Value> *node = new DLinkedNode<Key, Value>(_key, _value);
        addToHead(node);
        cache[_key] = node;
        if (cache.size() > capacity)
        {
            DLinkedNode<Key, Value> *romovedNode = removeTail();
            cache.erase(romovedNode->key);
            delete romovedNode;
        }
    }
    else
    {
        DLinkedNode<Key, Value> *node = cache[_key];
        node->value = _value;
        moveToHead(node);
    }
}

template <typename Key, typename Value>
void LRUCache<Key, Value>::addToHead(DLinkedNode<Key, Value>* node)
{
    node->prev = head;
    node->next = head->next;
    head->next->prev = node;
    head->next = node;
}

template <typename Key, typename Value>
void LRUCache<Key, Value>::removeNode(DLinkedNode<Key, Value>* node)
{
    node->prev->next = node->next;
    node->next->prev = node->prev;
}

template <typename Key, typename Value>
void LRUCache<Key, Value>::moveToHead(DLinkedNode<Key, Value>* node)
{
    removeNode(node);
    addToHead(node);
}

template <typename Key, typename Value>
DLinkedNode<Key, Value>* LRUCache<Key, Value>::removeTail()
{
    DLinkedNode<Key, Value> *node = tail->prev;
    removeNode(node);
    return node;
}