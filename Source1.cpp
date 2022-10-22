#include "Header.h"

BinarySearchTree::BinarySearchTree() {
	root = nullptr;
}
BinarySearchTree::~BinarySearchTree() {

}
void BinarySearchTree::InOrder() {
	this->inOrder(root);
}
void BinarySearchTree::Insert(Course course) {
	if (root == nullptr) {
		root = new Node(course);
	}
	else {
		addNode(root, course);
	}
}

Course BinarySearchTree::Search(string courseNum) {

	// set current node equal to root
	Node* current = root;
	// will continue to loop until match is found or end of data is reached
	while (current != nullptr) {
		// if match found, return current bid
		if (current->course.courseNum.compare(courseNum) == 0) {
			return current->course;
		}
		// if bid is smaller than current node then traverse left
		if (courseNum.compare(current->course.courseNum) < 0) {
			current = current->left;
		}
		else {        // else larger so traverse right

			current = current->right;
		}
	}

	//Creates a course to be returned
	Course course;
	return course;
}

void BinarySearchTree::addNode(Node* node, Course course) {
	// if node is larger then it is added to the left
	if (node->course.courseNum.compare(course.courseNum) > 0) {
		 // if no left node
		if (node->left == nullptr) {
			// this node becomes left
			node->left = new Node(course);
		}// else recurse down the left node
		else {
			addNode(node->left, course);
		}
	}//else node bid is larger
	else {
		if (node->right == nullptr) {
			// this node becomes right
			node->right = new Node(course);
		}// else recurse down the left node
		else {
			addNode(node->right, course);
		}
	}
}

void BinarySearchTree::inOrder(Node* node) {

	//if node is not nullptr, begin traversing the tree
	if (root != nullptr) {

		//if node to the left is filled
		if (node->left != nullptr) {

			inOrder(node->left);
		}

		//lowest value in the tree has been reached so we print it
		cout << node->course.courseNum << ", " << node->course.courseName << endl;

		//if node to the right is not empty go right
		if (node->right != nullptr) {

			inOrder(node->right);
		}
	}
}