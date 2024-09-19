#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>

// Custom structure storing student data (first and last name)
struct STUDENT_DATA {
	std::string firstName;
	std::string lastName; 

	void displayStudentInfo() {
		std::cout << "First Name: " << firstName << ", Last Name: " << lastName << std::endl;
	}
};

int main(void) {

	// Define our information needed for processing
	const std::string studentDataFile = "studentData.txt";	// File to read the student data in from
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
		iss >> temp_student.lastName >> temp_student.firstName;		// Read in the first and last name from the line
		studentData.push_back(temp_student);				// Add the student to the vector
	}	

	filein.close();											// Close the file

	#ifdef _DEBUG
	for (int i = 0; i < studentData.size(); i++) { studentData[i].displayStudentInfo(); } // Display student data when in DEBUG mode
	#endif	

	return 1;
}