#include<iostream>
using namespace std;
class Node {
public:
	double data;
	Node* next;
};
class List {
public:
	List(void) { head = NULL; }
	~List(void) {
		Node* currNode = head, * nextNode = NULL;
		while (currNode != NULL) {
			nextNode = currNode->next;
			delete currNode;
			currNode = nextNode;
		}
	}

	bool IsEmpty() { return head == NULL; }
	Node* InsertNode(int index, double x) {
		if (index < 0) return NULL;
		int nextIndex = 1;
		Node* currNode = head;
		while (currNode && index > nextIndex) {
			currNode = currNode->next;
			nextIndex++;
		}
		if (index > 0 && currNode == NULL) return NULL;
		Node* newNode = new Node;
		newNode->data = x;
		if (index == 0) {
			newNode -> next = head;
			head = newNode;
		}
		else {
			newNode->next = currNode->next;
			currNode->next = newNode;
		}
		return newNode;
	}
	int FindNode(double x) {
		Node* currNode = head;
		int currIndex = 0;
		while (currNode && currNode->data != x) {
			currNode = currNode->next;
			currIndex++;
		}
		if (currNode) return currIndex;
		return -1;
	}
	int DeleteNode(double x) {
		Node* prevNode = NULL;
		Node* currNode = head;
		int currIndex = 0;
		while (currNode && currNode->data != x) {
			prevNode = currNode;
			currNode = currNode->next;
			currIndex++;
		}
		if (currNode) {
			if (prevNode) {
				prevNode->next = currNode->next;
				delete currNode;
			}
			else {
				head = currNode->next;
				delete currNode;
			}
			return currIndex;
		}
		return -1;
	}
	void DisplayList() {
		int num = 0;
		Node* currNode = head;
		while (currNode != NULL) {
			cout << currNode->data << endl;
			currNode = currNode->next;
			num++;
		}
		cout << "Number of nodex in the list: " << num << endl;
	}
	void DisplayRecursive(Node* currNode) {
		if (currNode == nullptr) {
			cout << "Number of nodes in the list: 0" << endl;
			return;
		}
		cout << currNode->data << endl;
		DisplayRecursive(currNode->next);
	}
	void DisplayRecursiveBack(Node* currNode) {
		if (currNode == nullptr) {
			cout << "Number of nodes in the list: 0" << endl;
			return;
		}
		DisplayRecursiveBack(currNode->next);
		cout << currNode->data << endl;
	}
	Node* GetHead() {
		return head;
	}
private:
	Node* head;
};
#include <iostream>
using namespace std;

int main() {
	List myList;

	// Insert nodes
	myList.InsertNode(0, 10);
	myList.InsertNode(1, 20);
	myList.InsertNode(2, 30);
	myList.InsertNode(3, 40);
	myList.InsertNode(4, 50);

	// Display the list
	myList.DisplayList();

	// Find a node
	int searchValue = 20;
	int foundIndex = myList.FindNode(searchValue);
	if (foundIndex != -1) {
		cout << "Node with value " << searchValue << " found at index " << foundIndex << endl;
	}
	else {
		cout << "Node with value " << searchValue << " not found in the list" << endl;
	}

	// Delete a node
	int deleteValue = 20;
	int deletedIndex = myList.DeleteNode(deleteValue);
	if (deletedIndex != -1) {
		cout << "Node with value " << deleteValue << " deleted at index " << deletedIndex << endl;
	}
	else {
		cout << "Node with value " << deleteValue << " not found in the list" << endl;
	}

	// Display the updated list
	myList.DisplayList();
	myList.DisplayRecursive(myList.GetHead());
	myList.DisplayRecursiveBack(myList.GetHead());
	return 0;
}
