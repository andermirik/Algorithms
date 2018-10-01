#pragma once
#include <functional>

template <class Type>
class BinaryTree {
public: struct Node {
	int key;
	Type item;
	Node*Left;
	Node*Right;
	Node(int key, Type item) {
		this->key = key;
		this->item = item;
		this->Left = nullptr;
		this->Right = nullptr;
	}
};

public: Node*root;
private: int count;

public: BinaryTree() {
	int count = 0;
	root = nullptr;
}
public: void Add(int key, Type item) {
	if (!root) {
		root = new Node(key, item);
	}
	else {
		AddTo(root, key, item);
	}
	count++;
}
public: void AddTo(Node*node, int key, Type item) {
	if (key < node->key) {
		if (node->Left == nullptr)
			node->Left = new Node(key, item);
		else
			AddTo(node->Left, key, item);
	}
	else {
		if (node->Right == nullptr)
			node->Right = new Node(key, item);
		else
			AddTo(node->Right, key, item);
	}
}
public: bool Remove(int key) {
	Node* current(0);
	Node* parent(0);
	auto pair = FindWithParent(key);
	current = pair.first;
	parent = pair.second;

	if (current == nullptr)
		return false;

	count--;

	if (current->Right == nullptr) {
		if (parent == nullptr) {
			root = current->Left;
		}
		else {
			if (parent->key > current->key) {
				parent->Left = current->Left;
			}
			else if (parent->key < current->key) {
				parent->Right = current->Left;
			}
		}
	}//поставил
	else if (current->Right->Left == nullptr) {
		current->Right->Left = current->Left;
		if (parent == nullptr) {
			root = current->Right;
		}
		else {
			if (parent->key > current->key) {

				parent->Left = current->Right;
			}
			else if (parent->key < current->key) {
				parent->Right = current->Right;
			}
		}
	}
	else {
		Node* leftmost = current->Right->Left;
		Node* leftmostParent = current->Right;
		while (leftmost->Left != nullptr) {
			leftmostParent = leftmost;
			leftmost = leftmost->Left;
		}
		leftmostParent->Left = leftmost->Right;
		leftmost->Left = current->Left;
		leftmost->Right = current->Right;
		if (parent == nullptr) {
			root = leftmost;
		}
		else {
			if (parent->key > current->key) {

				parent->Left = leftmost;
			}
			else if (parent->key < current->key) {

				parent->Right = leftmost;
			}
		}
	}

	return true;
}

public: bool Contains(int key) {
	return FindWithParent(key).first != nullptr;
}
public: std::pair<Node*, Node*> FindWithParent(int key) {
	Node*current = root;
	Node*parent = nullptr;

	while (current != nullptr) {
		if (current->key > key) {
			parent = current;
			current = current->Left;
		}
		else if (current->key < key) {
			parent = current;
			current = current->Right;
		}
		else {
			break;
		}
	}
	return std::pair<Node*, Node*>(current, parent);
}
public: void Clear() {
	Postorder([this](Node* node) {
		if (std::is_array<Type>::value && !std::is_same<Type, const char*>::value) {
			delete[] node->item;
			node->item = nullptr;
		}
		if (std::is_pointer<Type>::value && !std::is_same<Type, const char*>::value) {
			delete node->item;
			node->item = nullptr;
		}
		delete node;
		node = nullptr;
	});
	root = nullptr;
}
public: void Preorder(std::function<void(Node*)> Action) {
	Preorder(Action, root);
}
private: void Preorder(std::function<void(Node*)> Action, Node*node) {
	if (node != nullptr) {
		Action(node);
		Preorder(Action, node->Left);
		Preorder(Action, node->Right);
	}
}
public: void Postorder(std::function<void(Node*)> Action) {
	Postorder(Action, root);
}
private: void Postorder(std::function<void(Node*)> Action, Node* node) {
	if (node != nullptr) {
		Postorder(Action, node->Left);
		Postorder(Action, node->Right);
		Action(node);
	}
}
public: void Inorder(std::function<void(Node*)> Action) {
	Inorder(Action, root);
}
private: void Inorder(std::function<void(Node*)>Action, Node* node) {
	if (node != nullptr) {
		Inorder(Action, node->Left);
		Action(node);
		Inorder(Action, node->Right);
	}
}
public: int Count() {
	return count;
}
public: ~BinaryTree() {
	Postorder([](Node* node) {
		if (std::is_array<Type>::value && !std::is_same<Type, const char*>::value) {
			delete[] node->item;
			node->item = nullptr;
		}
		if (std::is_pointer<Type>::value && !std::is_same<Type, const char*>::value) {
			delete node->item;
			node->item = nullptr;
		}
		delete node;
		node = nullptr;
	});
	root = nullptr;
}
};