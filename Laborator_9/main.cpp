#include <cstring>
#include <iostream>

using namespace std;

template <typename K, typename V>
class Map {
private:
    struct MapItem {
        K key;
        V value;
        int index;
    };
    MapItem* items;
    int count = 0;
public:
    Map() {
        this->items = nullptr;
        this->count = 0;
    }
    ~Map() {
        delete[] items;
    }
    int Count() {
        return count;
    }
    void Clear() {
        delete[] items;
        items = nullptr;
        count = 0;
    }
    void Set(const K& key, const V& value) {
        //check if the element already exists
        for (int i = 0; i < count; i++) {
            if (items[i].key == key) {
                items[i].value = value;
                return;
            }
        }
        //if it does not exist
        MapItem* temp = new MapItem[count + 1];
        for (int i = 0; i < count; i++)
            temp[i] = items[i];
        temp[count].key = key;
        temp[count].value = value;
        temp[count].index = count;
        count++;
        delete[] items;

        items = temp;

    }
    bool Get(const K& key, V& value) {
        //check if the element already exists
        for (int i = 0; i < count; i++) {
            if (items[i].key == key) {
                value = items[i].value;
                return true;
            }
        }
        //if it does not exist
        return false;
    }
    bool Delete(const K& key) {
        // if it exists
        for (int i = 0; i < count; i++) {
            if (items[i].key == key) {
                MapItem* temp = new MapItem[count - 1];
                for (int j = 0; j < i; j++)
                    temp[j] = items[j];
                for (int j = i; j < count - 1; j++) {
                    items[j + 1].index--;
                    temp[j] = items[j + 1];
                }
                count--;
                delete[] items;
                items = temp;
                return true;
            }
        }
        // if it doesnt exist
        return false;
    }
    bool Includes(const Map<K, V>& map) {
        if (map.count > count)
            return false;
        // verify all keys of the included map
        for (int i = 0; i < map.count; i++) {
            bool ok = 0;
            for (int j = 0; j < count; j++) {
                if (map.items[i].key == items[j].key) {
                    ok = 1;
                    break;
                }
            }
            if (!ok)
                return false;
        }
        return true;
    }
    V& operator[] (const K& key) {
        // if it exists
        for (int i = 0; i < count; i++) {
            if (items[i].key == key) {
                return items[i].value;
            }
        }
        // if it doesnt exist create it
        Set(key, "");
        return items[count - 1].value;
    }
    const MapItem* begin() const {
        return &items[0];
    }
    const MapItem* end() const {
        return &items[count];
    }
};

int main() {

    Map<int, const char*> m;
    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";
    
    Map<int, const char*> m2;
    m2[10] = "C++";
    m2[20] = "test";
    m2[30] = "Poo";
    m2[40] = "Test";
    if (m2.Includes(m)) {
        cout << "m este in m2\n";
    }
    m.Delete(10);
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    cout << m.Count() << endl;
    m.Set(40, "Hello");
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    const char* text;
    bool result = m.Get(20, text);
    cout << text;
    m.Clear();
	return 0;
}