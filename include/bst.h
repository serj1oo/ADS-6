#include <iostream>
using namespace std;

template<typename T>
class BST {
public:
	struct Node
	{
		T value;
		int count;
		Node* left;
		Node* right;
	};
	BST();
	~BST();
	BST(const BST<T>& temp);
	void Add(T);
	void Print();

	int  depth();
	int  search(T);

	void Clear();
	void Remove(int);
private:
	Node* base;
	Node* AddNode(Node*, T);

	void  PrintTree(Node*)const;

	int   DepthTree(Node*);
	int   SearchNode(Node*, T);

	void  DeleteTree(Node*);
	Node* DeleteNode(Node*, int);

	Node* CopyNode(Node*, Node*);
};


template <typename T>
BST<T>::BST(const BST<T>& temp) {
	base = new Node;
	base->value = temp.base->value;
	base->count = temp.base->count;
	base->left = base->right = nullptr;
	base->left = CopyNode(base->left, temp.base->left);
	base->right = CopyNode(base->right, temp.base->right);
}


template<typename T>
typename BST<T>::Node* BST<T>::CopyNode(Node* base, Node* temp) {
	if (!(temp == nullptr))
	{
		base = new Node;
		base->value = temp->value;
		base->count = temp->count;
		base->left = base->right = nullptr;
		base->left = CopyNode(base->left, temp->left);
		base->right = CopyNode(base->right, temp->right);
	}
	return base;
}


template<typename T>
BST<T>::BST() :base(nullptr) {}

template<typename T>
BST<T>::~BST()
{
	if (base)
		DeleteTree(base);
	base = nullptr;
}

template<typename T>
typename BST<T>::Node* BST<T>::AddNode(Node* base, T value) {
	if (base == nullptr) {
		base = new Node;
		base->value = value;
		base->count = 1;
		base->left = base->right = nullptr;
	}
	else if (base->value > value) {
		base->left = AddNode(base->left, value);
	}
	else if (base->value < value) {
		base->right = AddNode(base->right, value);
	}
	else
		base->count++;
	return base;
}

template<typename T>
void BST<T>::Add(T value) {
	base = AddNode(base, value);
}

template<typename T>
void BST<T>::PrintTree(Node* base)const {
	if (base == nullptr)
	{
		return;
	}
	PrintTree(base->left);
	for (int i = 0; i < base->count; i++)
		std::cout << base->value << " ";
	PrintTree(base->right);
}

template<typename T>
void BST<T>::Print() {
	PrintTree(base);
}

template<typename T>
int BST<T>::DepthTree(Node* base) {
	if (base == nullptr)
		return 0;
	if (base->left == nullptr && base->right == nullptr)
		return 0;
	int left = DepthTree(base->left);
	int right = DepthTree(base->right);
	if (left > right)
		return left + 1;
	else
		return right + 1;
}

template<typename T>
int BST<T>::depth() {
	return DepthTree(base);
}

template<typename T>
int BST<T>::SearchNode(Node* base, T value)
{
	if (base == nullptr)
		return 0;
	else if (base->value > value)
		return SearchNode(base->left, value);
	else if (base->value < value)
		return SearchNode(base->right, value);
	else
		return base->count;
}

template<typename T>
int BST<T>::search(T value)
{
	return SearchNode(base, value);
}

template<typename T>
void  BST<T>::DeleteTree(Node* base)
{
	if (base == nullptr)
		return;
	else
	{
		DeleteTree(base->left);
		DeleteTree(base->right);
		delete base;
		base = nullptr;
	}
}

template<typename T>
void BST<T>::Clear()
{
	if (base)
	{
		DeleteTree(base);
		base = nullptr;
	}
}
template<typename T>
typename BST<T>::Node* BST<T>::DeleteNode(typename BST<T>::Node* base, int value)
{
	Node* b, * v;
	if (base == nullptr)
		return base;
	else if (value < base->value)
		base->left = DeleteNode(base->left, value);
	else if (value > base->value)
		base->right = DeleteNode(base->right, value);
	else
	{
		b = base;
		if (base->right == nullptr)
			base = base->left;
		else if (base->left == nullptr)
			base = base->right;
		else
		{
			v = base->left;
			if (v->right)
			{
				while (v->right->right)
					v = v->right;
				base->value = v->right->value;
				base->count = v->right->count;
				b = v->right;
				v->right = v->right->left;
			}
			else
			{
				base->value = v->value;
				base->count = v->count;
				b = v;
				base->left = base->left->left;
			}
		}
		delete b;
	}
	return base;
}

template<typename T>
void BST<T>::Remove(int value)
{
	if (base)
		base = DeleteNode(base, value);
}
