#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
#include <cstring>
using namespace std;
#ifndef Header
#define Header

//Structures mad up of courses and every course has a Number, Name, and might have prerequisites

struct Course {

	//variables required for courses

	string courseNum;
	string courseName;
	string prereq;

	//a default Course constructor sets each variable to the string "Void"
	//this will print if the course searched is not inside the data structure

	Course() {
		courseNum = "Void";
		courseName = "Void";
		prereq = "Void";
	}
};

//a structure that holds nodes every node has a left and right pointer and contains a course structure like the ones described above

struct Node {
	Course course;
	Node* left;
	Node* right;

	//default Node constructor that sets the right and left pointers to nullptr

	Node() {
		left = nullptr;
		right = nullptr;
	}

	//overloaded constructor, if a Node is created with a course then its course will point to the course passed instead of the course initialized with void in all fields

	Node(Course aCourse) : Node() {
		this->course = aCourse;
	}
};

class BinarySearchTree {
private:
	Node* root;

	void addNode(Node* node, Course course);
	void inOrder(Node* node);

public:
	BinarySearchTree();
	virtual ~BinarySearchTree();
	void InOrder();
	void Insert(Course course);
	Course Search(string courseNum);
};

#endif
