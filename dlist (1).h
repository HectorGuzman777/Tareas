#ifndef DLIST_H
#define DLIST_H

#include <string>
#include <sstream>

template <class T> class DList;

template <class T>
class DLink {
private:
	DLink(T);
	DLink(T, DLink<T>*, DLink<T>*);
	DLink(const DLink<T>&);

	T	    value;
	DLink<T> *previous, *next;

	friend class DList<T>;
};

template <class T>
DLink<T>::DLink(T val) : value(val), previous(0), next(0) {}

template <class T>
DLink<T>::DLink(T val, DLink* prev, DLink* nxt)
	: value(val), previous(prev), next(nxt) {}

template <class T>
DLink<T>::DLink(const DLink<T> &source)
	: value(source.value), previous(source.previous), next(source.next) {}

template <class T>
class DList {
public:
	DList();
	~DList();

	void insertion(T);
	int search(T);
	void update(int, T);
	T deleteAt(int);

	std::string toStringForward() const;
	std::string toStringBackward() const;

private:
	DLink<T> *head, *tail;
	int size;
};

template <class T>
DList<T>::DList() : head(0), tail(0), size(0) {}

template <class T>
DList<T>::~DList() {
	DLink<T> *p;

	while (head != 0) {
		p = head;
		head = head->next;
		delete p;
	}
	size = 0;
}

template <class T>
void DList<T>::insertion(T val) {
    DLink<T> *newLink;

    newLink = new DLink<T>(val);

    if (size == 0) {
        head = newLink;
        tail = newLink;
    } else {
        tail->next = newLink;
        newLink->previous = tail;
        tail = newLink;
    }
    size++;
}

template <class T>
int DList<T>::search(T val) {
    DLink<T> *p;
    int index = 0;

    p = head;
    while (p != 0) {
        if (p->value == val) {
            return index;
        }
        p = p->next;
        index++;
    }

    return -1;  
}

template <class T>
void DList<T>::update(int position, T val) {
    DLink<T> *p;
    int index = 0;

    p = head;
    while (p != 0) {
        if (index == position) {
            p->value = val;
            return;
        }
        p = p->next;
        index++;
    }
}

template <class T>
T DList<T>::deleteAt(int position) {
    DLink<T> *p;
    T val;
    int index = 0;

    p = head;
    while (p != 0) {
        if (index == position) {
        
            if (p->previous == 0) {
                head = p->next;
                head->previous = 0;
            } else {
                
                if (p->next == 0) {
                    tail = p->previous;
                    tail->next = 0;
                } else { 
                    p->previous->next = p->next;
                    p->next->previous = p->previous;
                }
            }
            val = p->value;
            delete p;
            size--;
            return val;
        }
        p = p->next;
        index++;
    }

    
    return -1; 
}

template <class T>
std::string DList<T>::toStringForward() const {
	std::stringstream aux; 
	DLink<T> *p; 

	p = head; 
	aux << "[";
	while (p != 0) { 
		aux << p->value; 
		if (p->next != 0) { 
			aux << ", "; 
		}
		p = p->next; 
	}
	aux << "]";
	return aux.str(); 
}

template <class T>
std::string DList<T>::toStringBackward() const {
	std::stringstream aux; 
	DLink<T> *p; 

	p = tail; 
	aux << "[";
	while (p != 0) { 
		aux << p->value; 
		if (p->previous != 0) { 
			aux << ", "; 
		}
		p = p->previous; 
	}
	aux << "]";
	return aux.str(); 
}

#endif

