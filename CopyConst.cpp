#include<iostream>
#include<cstring>
using namespace std;
class Inhastu {
public:
	char* name;
	int studentID;
	Inhastu() {
		studentID = 0;
		name = NULL;
	}
	Inhastu(Inhastu &o) {
		studentID = o.studentID;
		name = strdup(o.name);
	}
};
int main() {
	Inhastu stu1;
	stu1.studentID = 12201928;
	char n[] = "SangHyuck";
	stu1.name = n;
	Inhastu stu2(stu1);
	stu1.name[0] = 'K';
	cout << "student1 name : " << stu1.name << endl;
	cout << "student2 name : " << stu2.name << endl;
}