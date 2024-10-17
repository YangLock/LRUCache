#include <iostream>
#include <string>
#include "LRUCache.h"

int main()
{
    LRUCache<int, std::string> cache(3);
    cache.put(1, "hello");
    cache.put(2, "world");
    cache.put(3, "cpp");

    // get key 1
    auto value1 = cache.get(1);
    if (value1.has_value())
    {
        std::cout << value1.value() << std::endl;
    }
    else
    {
        std::cout << "key 1 not found!" << std::endl;
    }

    // put key 4, then key 2 should be removed
    cache.put(4, "fun");
    auto value2 = cache.get(2);
    if (value2.has_value())
    {
        std::cout << value2.value() << std::endl;
    }
    else
    {
        std::cout << "key 2 not found!" << std::endl;
    }

    return 0;
}
