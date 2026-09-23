class MyHashMap {
public:

    vector<vector<pair<int,int>>> table;
    int size;

    MyHashMap() {

        size = 1000;
        table.resize(size);
    }

    void put(int key, int value) {

        int index = key % size;

        for(int i=0; i<table[index].size(); i++) {

            if(table[index][i].first == key) {
                table[index][i].second = value;
                return;
            }
        }

        table[index].push_back({key,value});
    }

    int get(int key) {

        int index = key % size;

        for(int i=0; i<table[index].size(); i++) {

            if(table[index][i].first == key) {
                return table[index][i].second;
            }
        }

        return -1;
    }

    void remove(int key) {

        int index = key % size;

        for(int i=0; i<table[index].size(); i++) {

            if(table[index][i].first == key) {
                table[index].erase(table[index].begin() + i);
                return;
            }
        }
    }
};