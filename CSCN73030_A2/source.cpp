#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>

#define PRE_RELEASE

// Custom structure storing student data (first and last name)
struct STUDENT_DATA {
	std::string lastName;
	std::string firstName;
	std::string email;
	
	void displayStudentInfo() {
		std::cout << "First Name: " << firstName;
		std::cout << ", Last Name: " << lastName;
	#ifdef PRE_RELEASE
		std::cout << ", Email: " << email;
	#endif
		std::cout << std::endl;
	}
};

int main(void) {

	// Print out a message to state the current source code type (standard or pre-release)
#ifdef PRE_RELEASE
	std::cout << "Pre-Release Source Code\n";
#else
	std::cout << "Standard Source Code\n";
#endif


	// Define our information needed for processing
#ifdef PRE_RELEASE
	const std::string studentDataFile = "studentData_Emails.txt";	// File to read the student data in from
#else
	const std::string studentDataFile = "studentData.txt"
#endif


	std::vector<STUDENT_DATA> studentData;					// Declare vector with our custom structure

	// Perform file IO
	std::ifstream filein(studentDataFile);					// Open file for reading


	if (!filein.is_open()) {								// Check if file is open before modifying (exit if not open)
		std::cerr << "File is not open. Exiting safely\n";
		return 0;
	}


	std::string line;
	while (std::getline(filein, line)) {					// Read in each line of the file until EOF is found
		std::istringstream iss(line);						// Create an input string stream that will store each line as an object
		STUDENT_DATA temp_student;							// Create a temporary student object to store the data
		

	#ifdef PRE_RELEASE										// Parse through the iss object to get the first name, last name, and email
		std::string first, last, email;						// Uses comma as a delimiter
		std::getline(iss, last, ',');
		std::getline(iss, first, ',');
		std::getline(iss, email, ',');
		temp_student.lastName = last;
		temp_student.firstName = first;
		temp_student.email = email;
	#else													// Read in each line, using whitespace as a delimeter
		iss >> temp_student.lastName >> temp_student.firstName;		
	#endif
		studentData.push_back(temp_student);				// Add the student to the vector
	}	

	filein.close();											// Close the file


#ifdef _DEBUG
	for (int i = 0; i < studentData.size(); i++) { studentData[i].displayStudentInfo(); } // Display student data when in DEBUG mode
#endif	

	return 1;
}