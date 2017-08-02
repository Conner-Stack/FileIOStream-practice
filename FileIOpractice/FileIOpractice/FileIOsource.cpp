#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main()
{

	//a class for writing content to a file
	ofstream myFile;
	//opens the file for changes and assigns a string in the argument as the file name
	myFile.open("practice.txt");
	/*a conditional using a pointer to a bool function that is used to check
	if the file is open or closed*/
	if (myFile.is_open())
	{
		//the content being written to the file
		myFile << "Writing this to a file." << endl;
		myFile << "does this work?" << endl;
		//closes the file to modification and frees up resources
		myFile.close();
	}
	//outputs a string to the console if the file is not open
	else
		cout << "Unable to open file";
	
	//a string variable used as a container for the strings contained within the file
	string line;

	/*ifstream is a class used to open and read an existing file 
	with the variable taking in the file name as an argument*/
	ifstream myFile2("practice.txt");
	
		/*a conditional using a pointer to a bool function that is used to check
	if the file is open or closed*/
	if (myFile2.is_open())
	{
		/*a loop that takes in the argument of fstream function getline
		which takes in an argument of the ifstream variable and a string*/
		while (getline(myFile2, line))
		{
			//used to print out every string read in the file to the console
			cout << line << endl;
		}
		
		//closes the file to free up resources
		myFile2.close();
		
	}
	//outputs a string to the console if the file is not open
	else
		cout << "Unable to open file" << endl;	
	
	ifstream myFile3("practice.txt");
	//variable containing the position in memory of the beginning of the file
	streampos beginning;

	//variable containing the position in memory of the end of the file
	streampos end;

	//gets the value of the beginning of the file and sets it to beginning
	beginning = myFile3.tellg();
	//jumps the pointer from it's current position to the end of the file with no offset
	myFile3.seekg(0, ios::end);
	//sets the value of end to the very end of the file in memory
	end = myFile3.tellg();
	//closes the file
	myFile3.close();
	//outputs the amount of bytes within the whole file
	cout << "this file is: " << (end - beginning) << " bytes long" << endl;
	//general c++ stuff
		system("pause");
		return 0;
}