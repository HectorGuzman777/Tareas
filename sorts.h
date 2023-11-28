#ifndef SORTS_H
#define SORTS_H

#include <vector>

template <class T>
void merge(std::vector<T> &vec, int left, int middle, int right);

template <class T>
class Sorts {
public:
    void ordenaSeleccion(std::vector<T> &vec);
    void ordenaBurbuja(std::vector<T> &vec);
    void ordenaMerge(std::vector<T> &vec);
    void ordenaMerge(std::vector<T> &vec, int left, int right);
    int busqSecuencial(const std::vector<T> &vec, T dato);
    int busqBinaria(const std::vector<T> &vec, T dato);
};

template <class T>
void Sorts<T>::ordenaSeleccion(std::vector<T> &vec) {
    int n = vec.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (vec[j] < vec[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            std::swap(vec[i], vec[minIndex]);
        }
    }
}

template <class T>
void Sorts<T>::ordenaBurbuja(std::vector<T> &vec) {
   int n = vec.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (vec[j] > vec[j + 1]) {
                std::swap(vec[j], vec[j + 1]);
            }
        }
    }
}

template <class T>
void merge(std::vector<T> &vec, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    std::vector<T> leftVec(n1);
    std::vector<T> rightVec(n2);

    for (int i = 0; i < n1; i++) {
        leftVec[i] = vec[left + i];
    }
    for (int i = 0; i < n2; i++) {
        rightVec[i] = vec[middle + 1 + i];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftVec[i] <= rightVec[j]) {
            vec[k++] = leftVec[i++];
        } else {
            vec[k++] = rightVec[j++];
        }
    }

    while (i < n1) {
        vec[k++] = leftVec[i++];
    }

    while (j < n2) {
        vec[k++] = rightVec[j++];
    }
}

template <class T>
void Sorts<T>::ordenaMerge(std::vector<T> &vec) {
    ordenaMerge(vec, 0, vec.size() - 1);
}

template <class T>
void Sorts<T>::ordenaMerge(std::vector<T> &vec, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        ordenaMerge(vec, left, middle);
        ordenaMerge(vec, middle + 1, right);
        merge(vec, left, middle, right);
    }
}

template <class T>
int Sorts<T>::busqSecuencial(const std::vector<T> &vec, T dato) {
    int n = vec.size();
    for (int i = 0; i < n; i++) {
        if (vec[i] == dato) {
            return i;
        }
    }
    return -1;
}

template <class T>
int Sorts<T>::busqBinaria(const std::vector<T> &vec, T dato) {
    int left = 0;
    int right = vec.size() - 1;

    while (left <= right) {
        int middle = left + (right - left) / 2;

        if (vec[middle] == dato) {
            return middle;
        }

        if (vec[middle] < dato) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }

    return -1; 
}

#endif 

