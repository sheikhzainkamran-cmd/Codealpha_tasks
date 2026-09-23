#include<iostream>
#include<string>
using namespace std;
int main ()
{
	const int MAX_COURSES = 6;
    int nmbr_of_crs,semester;
    float crdt_hours,grade_point,semester_crdts,semester_grade,total_crdts = 0,total_grade = 0,semester_gpa,cgpa;
    string grade;
    cout<<"= = = = = = = = = = = = = = = = = = =\n";
    cout<<"         CGPA Calculator      \n";
    cout<<"= = = = = = = = = = = = = = = = = = =\n";
    while(true)
    {
	
        cout <<"Enter the number of smemester for cgpa :";
    	cin>>semester;
    	if (cin.fail() )
    	{
    		cout<<"\033[31m Invalid Number ! enter a valid number \033[0m\n ";
    		cin.clear();
    		cin.ignore(1000,'\n') ;
		}
		
    else if(semester <= 0 || semester > 8)
    {
    	cout<<"\033[31m The semester number should be greater than 0 and  less than or equal to 8 \033[0m\n ";
	}
	else 
	{
		break ;
	}
}
      string course_grades[MAX_COURSES];
    for(int i =0;i<semester;i++)
    {
    	semester_crdts=0,semester_grade=0;
    while (true)
    {
        cout<<"Enter the Number of courses for semester "<< i+1<<" : ";
        cin>>nmbr_of_crs; 
    
    	if (cin.fail())
    	{
    		cout<<"\033[31m Invalid Number ! enter a valid number \033[0m\n ";
    		cin.clear();
    		cin.ignore(1000,'\n') ;
		}
		else if (nmbr_of_crs >6 || nmbr_of_crs<=0)
		{
			cout<<"\033[31m Number of courses should grater than 0 and  less than or equal to 6 \033[0m\n";
		}
		else 
		{
			break;
		}
	} 
    for (int j=0;j<nmbr_of_crs;j++)
    {
    	while (true)
    	{
    	  cout<<"Enter the course "<<j+1<<" grade : ";
    	  cin>>grade;
    	  if (grade == "A+" || grade == "A" || grade == "A-" ||
        grade == "B+" || grade == "B" || grade == "B-" ||
        grade == "C+" || grade == "C" || grade == "C-" ||
        grade == "D+" || grade == "D" || grade == "F")
        {
        		 
      if (grade == "A+" ||grade == "A")
     {
     	grade_point = 4.0;
	 }
	 else if (grade == "A-")
     {
     	grade_point = 3.67;
	 }
	 else if (grade == "B+")
     {
     	grade_point = 3.33;
	 }
	 else if (grade == "B")
     {
     	grade_point = 3.0;
	 }
	 else if (grade == "B-")
     {
     	grade_point = 2.67;
	 }
	 else if (grade == "C+")
     {
     	grade_point = 2.33;
	 }
	 else if (grade == "C")
     {
     	grade_point = 2.0;
	 }
	 else if (grade == "C-")
     {
     	grade_point = 1.67;
	 }
	 else if (grade =="D+")
     {
     	grade_point = 1.33;
	 }
	 else if (grade == "D")
     {
     	grade_point = 1.0;
	 }
	 else if (grade == "F")
     {
     	grade_point = 0.00;
	 }
        	break ;
		}
    else
    {
        cout << "\033[31m Invalid Grade! Enter a valid grade.\033[0m\n";
     }
     
	 }
	 
	 course_grades[j] = grade;
	 
		while(true)
		{
			cout<<"Enter the credit Hours : ";
    	  cin>>crdt_hours;
    	  if(cin.fail() )
    	  {
    		cout<<"\033[31m Invalid Number ! enter a valid Number \033[0m\n ";
    		cin.clear();
			cin.ignore(1000,'\n') ; 
	      }
	      else if (crdt_hours<=0)
	      {
	      	cout<<"\033[31m Invalid Number ! enter a valid Number \033[0m\n ";
		  }
		  else if (crdt_hours>4)
		  {
		  	cout<<"\033[31m Credit hours should be less then or equal to 4\033[0m\n";
		  }
	      else 
	      {
	      	break ;
		  }
		 
		}
		
		semester_crdts = semester_crdts + crdt_hours;
        semester_grade = semester_grade + (grade_point * crdt_hours);
        
        total_crdts = total_crdts + crdt_hours;
        total_grade = total_grade + (grade_point * crdt_hours);
	}
	cout << "\nIndividual Course Grades:\n";

for(int k = 0; k < nmbr_of_crs; k++)
{
    cout << "Course " << k + 1 << " Grade = "
         << course_grades[k] << "\n";
}
	cout <<"Total credit hours"<<semester_crdts<<"\n";
	cout<<"Total Grade Points "<<semester_grade<<"\n";
	semester_gpa = semester_grade / semester_crdts;
    cout << "Semester " << i + 1 << " GPA = " << semester_gpa << "\n"; 
    cout << "\n==============================\n";
}
    cgpa = total_grade / total_crdts;
    cout << "\n==============================\n";
cout << "Overall CGPA = " << cgpa << "\n";
cout << "Total Credits = " << total_crdts << "\n";
cout << "Total Grade Points = " << total_grade << "\n";
return 0;
	}