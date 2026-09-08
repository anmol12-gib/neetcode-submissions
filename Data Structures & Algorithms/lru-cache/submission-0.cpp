class LRUCache {
public:
    int capacity;

    // {key, value}
    list<pair<int, int>> cache;

    // key -> position in list
    unordered_map<int, list<pair<int, int>>::iterator> mp;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if(mp.find(key) == mp.end()) {
            return -1;
        }

        // Get the node
        auto it = mp[key];
        int value = it->second;

        // Move it to front (most recently used)
        cache.erase(it);
        cache.push_front({key, value});

        // Update map
        mp[key] = cache.begin();

        return value;
    }

    void put(int key, int value) {
        // Key already exists
        if(mp.find(key) != mp.end()) {
            auto it = mp[key];

            // Remove old node
            cache.erase(it);

            // Add updated node at front
            cache.push_front({key, value});

            // Update map
            mp[key] = cache.begin();

            return;
        }

        // New key
        cache.push_front({key, value});
        mp[key] = cache.begin();

        // Capacity exceeded
        if(cache.size() > capacity) {
            auto last = cache.back();

            mp.erase(last.first);
            cache.pop_back();
        }
    }
};
