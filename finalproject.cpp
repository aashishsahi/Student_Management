#include<stdio.h> 
#include<iostream>
#include<fstream>
#include<string.h>
 
using namespace std;

class student
{

	public:
	int n;
	char data[15];
	void signup(int count_n)
	{
		string empty="00";
		cout << "Enter the number of students: ";
    	cin >> n;
    	count_n = count_n + n;
     
    	for (int i = 0;i < n;i++)
    	{
		    ofstream outfile;
		    outfile.open("Example.txt",ios::app);
		    //The entire data of a single student is stored line-by-line.
		    cout << "Enter your registration number: ";
		    cin.ignore();
		    cin >> data;
		    outfile << data << "\t";
		     
		    cout << "Enter your name: ";
		    cin.ignore();
		    cin >> data;
		    int len = strlen(data);
		     
		    while (len < 15){
		        data[len] = ' ';
		        len = len + 1;
		    }
		    outfile << data << "\t";
		    //Inserting empty data initially into the file
		    outfile << empty << "\t";
		    outfile << empty ;    
		     
		    outfile <<  endl;
     }
     }
     void getdata()
     {
     	char regno[9];
        cout << "Enter your registration number: ";
        cin.ignore();
        cin >> regno;
        ifstream infile;
        int check = 0;
        infile.open("Example.txt",ios::in);
        
        //This loop prints out the data according to the registration number specified.
        while (infile >> data){
        if (strcmp(data,regno) == 0){
            cout << "\nRegistration Number: " << data << endl;
            infile >> data;
            cout << "Name: " << data << endl;
             
            infile >> data;
                cout << "CSE1001 mark: " << data << endl;
             
            infile>>data;
            cout<<"CSE1002 mark: "<<data<<endl;
             
             
            infile.close();
            check = 1;}
        }
         
        if (check == 0){
            cout<<"No such registration number found!"<<endl;}  
         
    }
		
};	
	
class admin
{
	public:
	void getdata(int count_n)
	{
		char subcode[7],data[15];
		int option;
        cout << "Enter your subject code: ";
        cin >> subcode;
        string code1 = "CSE1001", code2 = "CSE1002",mark = "";
        ifstream infile;
        int check = 0;
         
        cout << "\nAvailable operations: \n1. Add data about marks\n"
                << "2. View data\nEnter option: ";
        cin >> option;
         cout<<count_n<<endl;
        if (option == 1){
            cout << "Warning! You would need to add mark"
                    << "details for all the students!" << endl;
            for(int i = 0;i < count_n;i++){
                fstream file("Example.txt");
 
                                //The seek in file has been done according to the length
            //of the data being inserted. It needs to adjusted accordingly
            //for diffferent lengths of data.
 
            if(strcmp(subcode,code1.c_str()) == 0){
                        file.seekp(26+32*i,std::ios_base::beg);
                    cout << "Enter the mark of student#" << (i+1) << " : ";
                cin >> mark;
                file.write(mark.c_str(),2);}
             
            if(strcmp(subcode,code2.c_str()) == 0){
                file.seekp(29+32*i,std::ios_base::beg);
                cout << "Enter the mark of student#" << (i+1) << " : ";
                cin >> mark;
                file.write(mark.c_str(),2);}
            }
             
        }
 
        //This loop is used to view marks of a student.
        //The extra infile commands have been used to get a specific mark 
        //only since the data has been seperated by a tabspace.
 
        else if(option == 2){
        infile.open("Example.txt",ios::in);
        if (strcmp(subcode,code1.c_str()) == 0){
            cout << "Registration number      -Marks\n" << endl;
            while(infile >> data){
            cout << data;
            infile >> data;
                infile >> data;
            cout << " - " << data << endl;
            infile >> data;
            
            check = 1;
            
            }
        }
        
         
        infile.close();
        infile.open("Example.txt",ios::in);     
 
        if(strcmp(subcode,code2.c_str()) == 0){
            cout << "Registration number - Marks\n" << endl;
                while(infile >> data){
            cout << data;
            infile >> data;
            infile >> data;
            infile >> data;
            cout << " - " << data << endl;
            infile >> data;
            check = 1;
            }
        }}
         
        infile.close();
         
        if (check == 0){
            cout << "No such subject code found!" << endl;
        }
         
    }
    void view()
    {
    	char password[25];
        cout << "Enter the admin password: ";
        cin >> password;
 
        //This variable value can be changed according to your requirement 
        //of the administrator password.
 
        string admin_pass = "admin";
         
        if (strcmp(password,admin_pass.c_str()) == 0){
            cout << "Reg No.       \tName\tCSE1001\tCSE1002" << endl;
            ifstream infile;
            infile.open("Example.txt",ios::in);
            char data[20];
             
            while(infile >> data){
                cout << data << "\t";
                infile >> data;
                cout << data << "\t";
                infile >> data;
                cout << data << "\t";
                infile >> data;
                cout << data << "\t"<<endl;
                
            }
        }
    }
    
	
};


int main()
{
	admin adm1;
	student st1;
	//Considering the max length of data entered (name) to be 15.
    char data[15];  
    int n = 0, count_n = 0,choice;
    //This is the initial mark alloted to a subject.
    string empty = "00";    
    string proctor = "";
    //Name of the file in which DB is stored.
    ifstream f("Example.txt");      
    string line;
    
    //The following for loop counts the total number of lines in the file.
    for (int i = 0; std::getline(f, line); ++i){    
        count_n++;}
    cout<<"1. Admin Login"<<endl;
	cout<<"2. Student Login"<<endl;
	cout<<"3. Student SignUp"<<endl;
	cout<<"4. Admin View"<<endl;
	cout<<"5. Exit"<<endl;
	cout<<"Enter Choice: ";
	cin>>choice;
	while(choice!=5)
	{
	
	switch(choice)
	{	
		case 1:
			adm1.getdata(count_n);
			
		break;
		case 2:
			st1.getdata();
			
		break;
		case 3:
			st1.signup(count_n);
			cout<<"------------Thank you for signing up...------------"<<endl<<endl<<endl;
		break;
		case 4:
			adm1.view();
		break;
		default:
			return 0;
	}
	cout<<"1. Admin Login"<<endl;
	cout<<"2. Student Login"<<endl;
	cout<<"3. Student SignUp"<<endl;
	cout<<"4. Admin View"<<endl;
	cout<<"5. Exit"<<endl;
	cout<<"Enter Choice: ";
	cin>>choice;
	}
}
