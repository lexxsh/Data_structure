template <typename T>
class Node {
public:
	T value;
	int key;
	Node* prev, * next;
	Node(T val, int k)
		: value(val), key(k), prev(nullptr), next(nullptr) {}
};

template <typename T>
class MinPriorityQueue {
private:
	DoublyLinkedList<T> list;
public:
	void insertItem(T value, int key);
	T minElement();
	int minKey();
	T removeMinElement();
};

template<typename T>
void MinPriorityQueue<T>::insertItem(T value, int key)
{
	Node<T>* newNode = new Node<T>(value, key);
	if (list.isEmpty()) {
		// 빈 리스트인 경우, head와 tail을 새 노드로 설정
		list.head = list.tail = newNode;
	}
	else {
		Node<T>* current = list.head;
		while (current && current->key <= key) {
			current = current->next;
		}
		if (current) {
			// 중간이나 시작 부분에 삽입
			list.insertBefore(current, value, key);
		}
		else {
			// 맨 끝에 삽입
			list.insertAfter(list.tail, value, key);
		}
	}
}

template<typename T>
T MinPriorityQueue<T>::minElement()
{
	if (list.isEmpty()) {
		throw std::runtime_error("Priority Queue is empty.");
	}
	return list.head->value;
}

template<typename T>
int MinPriorityQueue<T>::minKey()
{
	if (list.isEmpty()) {
		throw std::runtime_error("Priority Queue is empty.");
	}
	return list.head->key;
}

	template<typename T>
T MinPriorityQueue<T>::removeMinElement()
{
	if (list.isEmpty()) {
		throw std::runtime_error("Priority Queue is empty.");
	}
	T minValue = list.head->value;
	list.remove(list.head);
	return minValue;

}
