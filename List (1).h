#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

template <typename T>
class List {
    std::vector<T> data;

public:
    
    void insertion(T value) {
        data.push_back(value);
    }

    
    int search(T value) {
        typename std::vector<T>::iterator it = std::find(data.begin(), data.end(), value);
        if (it != data.end()) {
            return std::distance(data.begin(), it);
        } else {
            return -1;
        }
    }

    
    void update(int position, T newValue) {
        if (position >= 0 && position < data.size()) {
            data[position] = newValue;
        }
    }

    
    T deleteAt(int position) {
        if (position >= 0 && position < data.size()) {
            T value = data[position];
            data.erase(data.begin() + position);
            return value;
        }
        return T();
    }

    
    std::string toString() const {
        std::stringstream aux;
        aux << "[";
        for (size_t i = 0; i < data.size(); ++i) {
            aux << data[i];
            if (i != data.size() - 1) {
                aux << ", ";
            }
        }
        aux << "]";
        return aux.str();
    }
};

