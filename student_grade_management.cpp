//Mini Project of C++

/*for input and output used iostream and for string data type used string library*/
#include <iostream>
#include <string>
using namespace std;

//maximum no. of students is placed as 100
const int max_students = 100;

//class is ussed to record the student data with marks and grade
class Student {
  public:
  int roll;
  string name;
  int math;
  int english;
  int computerScience;
  int total;
  int percent;
  char grade;
};

//array used to store all student records
Student arr1[max_students];

//counter to track how many student data are stored
int countStudents = 0;

/*function result is used to calculate total, percentage and grade of student*/
void result (Student &s) {
  s.total = s.math + s.english + s.computerScience;
  s.percent = s.total / 3;
  if (s.percent >= 80) { 
    s.grade = 'A';
  }
  else if (s.percent >= 70) {
    s.grade = 'B';
  }
  else if (s.percent >= 60) {
    s.grade = 'C';
  }
  else if (s.percent >= 50) {
    s.grade = 'D';
  }
  else {
    s.grade = 'E';
  }
}

/*function findByRoll is used to search the student using theri roll numbers which returns indes if found and -1 if not found*/
int findByRoll(int roll) {
  for (int i=0;i<countStudents;i++) {
    if (arr1[i].roll == roll) {
      return i;
    }
  }
  return -1;
}

/*fundtion addStudent is used to read new data of student from the user */
void addStudent() {
  //checks if array is full
  if (countStudents >= max_students) {
    cout <<"Database full."<<endl;
    return;
  }

  Student s; //temporary student object to hold the input
  // reads roll number entered by user
  cout <<"Enter Roll No: ";
  cin >>s.roll;

  //checks for duplicate roll number
  if (findByRoll(s.roll) != -1) {
    cout<<"Roll already exists."<<endl;
    return;
  }

  /*read students name and marks*/
  cout<<"Enter Name: ";
  cin.ignore();
  getline(cin, s.name);
  cout<<"Enter Math marks (0-100): ";
  cin>>s.math;
  cout<<"Enter Englis marks (0-100): ";
  cin>>s.english;
  cout<<"Enter Computer Science marks (0-100): ";
  cin>>s.computerScience;

  //calculate the total, percentage and grade
  result(s);
  //stores the record and increases the counter
  arr1[countStudents] = s;
  countStudents++;

  cout <<"Student added."<<endl;
}

/*function show is used to display the record of all students added in tabular format*/
void show() {
  //checks if there is records added or not and if not prints no records
  if (countStudents == 0) {
    cout<< "No records/"<<endl;
    return;
  }
  //\t is used to fill space in between known as tab 
  //print table headers
  cout<<"\nRoll\tName\tMath\tEng\tCom\tTotal\t%\tGrade"<<endl;
  cout<<"-----------------------------------------------------------"<<endl;

  //loop through all students and print the records
  for (int i=0;i<countStudents;i++) {
    cout<<arr1[i].roll<<"\t"
        <<arr1[i].name<<"\t"
        <<arr1[i].math<<"\t"
        <<arr1[i].english<<"\t"
        <<arr1[i].computerScience<<"\t"
        <<arr1[i].total<<"\t"
        <<arr1[i].percent<<"\t"
        <<arr1[i].grade<<endl;
  }
  cout<<"-----------------------------------------------------------"<<endl;

}

/*function search is used for searching the students through the roll number of student*/
void search() {
  //asks for the roll number of student to search for
  int roll;
  cout<<"Enter Roll No of the Student: ";
  cin>>roll;

  //use findByRoll helper to locate the student index
  int idx = findByRoll(roll);
  //display error if the roll number is invalid
  if (idx == -1) {
    cout <<"Not found."<<endl;
    return;
  }

  //displays the record of the student if the roll number is found
  Student s = arr1[idx];
  cout <<"\nRoll: "<<s.roll
       <<"\nName: "<<s.name
       <<"\nMath: "<<s.math
       <<"\nEnglish: "<<s.english
       <<"\nComputer Science: "<<s.computerScience
       <<"\nTotal: "<<s.total
       <<"\nPercent: "<<s.percent
       <<"\nGrade: "<<s.grade<<endl;
}

//function update is used to update the date of the student
void update() {
  //asks user to enter roll number
  int roll;
  cout<<"Enter Roll No to update: ";
  cin>>roll;

  //display error if the roll number is not found
  int idx = findByRoll(roll);
  if (idx == -1) {
    cout<<"Not found"<<endl;
    return;
  }
//shows the student name for correct student
  cout <<"Updating marks for "<<arr1[idx].name<<endl;
  //read new marks directly into array elements
  cout<<"New Math Marks (0-100): ";
  cin>>arr1[idx].math;
  cout<<"New English Marks (0-100): ";
  cin>>arr1[idx].english;
  cout<<"New Computer Science Marks (0-100): ";
  cin>>arr1[idx].computerScience;

  //recalculates the toatl, percent and grade and display updated
  result(arr1[idx]);
  cout<<"Updated"<<endl;
}

/*function deleteStudent is used to delete the record of perticular student by searching them by roll number*/
void deleteStudent() {
  int roll;
  cout<<"Enter Roll No to delete: ";
  cin>>roll;

  //find the student in array
  int idx = findByRoll(roll);
  //display error if roll number not found
  if (idx==-1) {
    cout <<"Not found."<<endl;
    return;
  }

  //Shift elements left to remove the gap left by deleted student
  for (int i=idx;i<countStudents-1;i++) {
    arr1[i]= arr1[i+1];
  }
  //reduce the count of the student and display the message deleted
  countStudents--;
  cout<<"Deleted."<<endl;
}

/*function showMenu to display the menu for the user */
void showMenu() {
  cout<<"\n================================"<<endl;
  cout<<"Students Grade Management"<<endl;
  cout<<"\n================================"<<endl;
  cout<<"1) Add Students"<<endl;
  cout<<"2) Show All Students"<<endl;
  cout<<"3) Search by Roll NO"<<endl;
  cout<<"4) Update Marks"<<endl;
  cout<<"5) Delete Student Data"<<endl;
  cout<<"6) Exit"<<endl;
  cout<<"Choose (1-6): ";
}

//function main to run the main loop
int main() {
  cout<<"Student Grade System (C++)"<<endl;
  //main program loop to run until user selects the exit which is 6th option
  while(true) {
    showMenu();  //display menu
    int choice;
    cin>>choice; //read users choice
    
    //call function according to the choice
    if(choice==1) {
      addStudent();  //call funtion to add new student
    } else if (choice==2) {
      show();        //call function to show all record
    } else if (choice==3) {
      search();      //call funtion to search the particular student
    } else if (choice==4) {
      update();      //call funtion to update the data
    } else if (choice==5) {
      deleteStudent();  //call function to delete record of student
    } else if (choice==6) {
      cout <<"Goodbye!"<<endl;  //exit the program
    } else {
      cout <<"Invalid."<<endl;  //display invalid if other choices are made
      break;
    }
  }
  return 0;
}