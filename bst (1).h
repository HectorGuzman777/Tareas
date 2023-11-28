#ifndef BST_H
#define BST_H

#include <iostream>
#include <queue>
#include <sstream>
#include <string>

template <class T>
class Node {
public:
    T value;
    Node<T> *left, *right;

    Node(T val) {
        value = val;
        left = right = nullptr;
    }

    void add(T val) {
        if (val < value) {
            if (left == nullptr) {
                left = new Node<T>(val);
            } else {
                left->add(val);
            }
        } else {
            if (right == nullptr) {
                right = new Node<T>(val);
            } else {
                right->add(val);
            }
        }
    }

    bool find(T val) {
        if (val == value) {
            return true;
        } else if (val < value) {
            return (left != nullptr && left->find(val));
        } else {
            return (right != nullptr && right->find(val));
        }
    }

    void preorder(std::stringstream &aux) const {
        aux << value << " ";
        if (left != nullptr) {
            left->preorder(aux);
        }
        if (right != nullptr) {
            right->preorder(aux);
        }
    }

    void inorder(std::stringstream &aux) const {
        if (left != nullptr) {
            left->inorder(aux);
        }
        aux << value << " ";
        if (right != nullptr) {
            right->inorder(aux);
        }
    }

    void postorder(std::stringstream &aux) const {
        if (left != nullptr) {
            left->postorder(aux);
        }
        if (right != nullptr) {
            right->postorder(aux);
        }
        aux << value << " ";
    }

    int height() const {
        int left_height = 0;
        int right_height = 0;
        if (left != nullptr) {
            left_height = left->height();
        }
        if (right != nullptr) {
            right_height = right->height();
        }
        return 1 + std::max(left_height, right_height);
    }

    bool ancestors(T val, std::stringstream &aux) const {
        if (val == value) {
            return true;
        } else if (val < value) {
            if (left != nullptr && left->ancestors(val, aux)) {
                aux << value << " ";
                return true;
            } else {
                return false;
            }
        } else {
            if (right != nullptr && right->ancestors(val, aux)) {
                aux << value << " ";
                return true;
            } else {
                return false;
            }
        }
    }

    int whatlevelamI(T val, int level = 1) const {
        if (val == value) {
            return level;
        } else if (val < value) {
            return (left != nullptr ? left->whatlevelamI(val, level + 1) : -1);
        } else {
            return (right != nullptr ? right->whatlevelamI(val, level + 1) : -1);
        }
    }

};

template <class T>
class BST {

private:
	Node<T> *root;

public:
	BST() : root(nullptr){};

	bool empty() const {return root == nullptr;}

	void add(T val){
		if(root != nullptr){
			if(!root->find(val)){
				root->add(val);
			}
		}else{
			root = new Node<T>(val);
		}
	}

	bool find(T val){
		if(root != nullptr){
			return root->find(val);
		}else{
			return false;
		}
	}

	std::string visit(){
	    std::stringstream aux;
	    aux << "[";
	    root->preorder(aux);
	    aux << "]\n[";
	    root->inorder(aux);
	    aux << "]\n[";
	    root->postorder(aux);
	    aux << "]\n[";
	    levelbylevel(aux);
	    aux << "]";
	    return aux.str();
	}

	void levelbylevel(std::stringstream &aux) const{
	    std::queue<Node<T>*> q;
	    q.push(root);

	    while(!q.empty()){
	        Node<T>* current = q.front();
	        q.pop();

	        aux << current->value << " ";

	        if(current->left){
	            q.push(current->left);
	        }

	        if(current->right){
	            q.push(current->right);
	        }
	    }
	}

	int height(){
	    if(root == nullptr){
	        return 0;
	    }else{
	        return root->height();
	    }
	}

	std::string ancestors(T val){
	    std::stringstream aux;
	    aux << "[";
	    root->ancestors(val, aux);
	    aux << "]";
	    return aux.str();
	}

	int whatlevelamI(T val){
	    if(root == nullptr){
	        return -1;
	    }else{
	        return root->whatlevelamI(val);
	    }
	}
};

#endif


