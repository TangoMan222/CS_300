
#include "Header.h"

int main() {
	//the variables and assignments that are used are defined here
	BinarySearchTree* bst;
	bst = new BinarySearchTree();
	Course course;
	int choice = 0;
	string courseNum;
	string tempName;
	string fileName;
	string line;
	ifstream input;
	bool loopVar = true;
	fileName = "";

	while (loopVar) {//Continues to loop until false, allows the menu options to be accessed multiple times.
		cout << "\n";
		cout << "Welcome to my course list program.\n\n";
		cout << "1. Load Data Structure.\n";
		cout << "2. Print Course List.\n";
		cout << "3. Print Course.\n";
		cout << "4. Exit\n\n";
		cout << "Please choose a numerical option to continue.\n";

		try {//checks for valid int input if not closes program

			cin >> choice;

			if (cin.fail()) {
				throw runtime_error("Input failed.");
			}
		}

		catch (runtime_error& excpt) {
			loopVar = false;
			cout << excpt.what();
		}

		switch (choice) {
		case 1:

			cout << "Enter included list exactly as shown: \"CourseList.txt\" if not the program may not run.\n";
			cout << "Please enter the name of the file you would like to open:\n";
			cin >> fileName;
			cout << "You entered: " << fileName << "\n";

			input.open(fileName);

			if (!input.is_open()) {
				cout << "File failed to open.\n";
				loopVar = false;
			}

			while (getline(input, line)) {

				string courseNum;
				string courseName;
				string prerequ;

				//creates a stringstream that reads the values separated by commas

				stringstream ss(line);

				//Create a course object to be later filled

				Course course;

				//adds the required info to the course object

				getline(ss, courseNum, ',');
				course.courseNum = courseNum;

				getline(ss, courseName, ',');
				course.courseName = courseName;

				getline(ss, prerequ);
				course.prereq = prerequ;

				//stores the course in a the data structure

				bst->Insert(course);
			}

			//input is no longer needed so we close it

			input.close();
			break;

		case 2:
			cout << "Printing courses in order.\n\n";

			//orders courses then prints them to the screen

			bst->InOrder();

			break;

		case 3: {

			//prompts user for input
			cout << "Please enter a course in this format: CSCI400\n";
			cout << "Enter your course number: \n";

			cin >> courseNum;

			//loops through courseNum and capitalizes each time to match the data stored in the file

			for (unsigned int i = 0; i < courseNum.size(); i++) {
				courseNum[i] = toupper(courseNum[i]);
			}
			cout << "You entered: " << courseNum << "\n";

			//assign a temporary course value to prevent any errors

			Course temp = bst->Search(courseNum);

			//print out the info requested, otherwise it will print void.

			cout << temp.courseNum << ", " << temp.courseName << "\n";
			cout << "Course Prerequisites: " << temp.prereq << "\n";

			break;
		}

		case 4:
		{
			cout << "Thank you for using my software!\n";
			//exits program
			return 1;
		}

		}

	}

	return 0;
}