//
// Created by 杨宗霖 on 2024/10/17.
//

#ifndef LRUCACHE_H
#define LRUCACHE_H

template <typename Key, typename Value>
class LRUCache
{
public:
    LRUCache(int capacity);
    ~LRUCache();
    Value get(const Key& k);
    void put(const Key& k, const Value& v);
};

#endif //LRUCACHE_H
