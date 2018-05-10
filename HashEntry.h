class HashEntry {
private:
      int key;
public:
    HashEntry(int key) {
        this->key = key;
    }

    int getKey() {
        return key;
    }
};