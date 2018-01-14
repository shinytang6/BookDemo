#include <string>
using namespace std;
struct Student{
	string name;
	int score;

	// override "<"'s definition
	bool operator<(const Student &otherStudent){
		// if two students have the same score , return the minimum name
		return score != otherStudent.score ? score < otherStudent.score : name < otherStudent.name;
	}

	// override "<<"'s definition
	friend ostream& operator<<(ostream &os, const Student &student){
		os<<"Student: "<<student.name<<" "<<student.score<<endl;
		return os;
	}
};