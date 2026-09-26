#include<iostream>
#include<string>
using namespace std;

// FUCTION PROTOTYPES
void mainMenu();
void customerMenu();
void cusLogin();
void cusRegister();
void cusPortal(int foundIndex);
void adminMenu();
void adminPortal();
void cusManagement();
void cusDetails();
void cusRegAdmin();
void cusSearch();
void vehManagement();
void vehDetails();
void vehRegister();
void vehAvailability();
void vehRentility();
void vehSearch();
void rentMenu();
void rentToCustomer();
void rentVehicle(int foundIndex,int found);

void returnMenu();
void payRent(int foundIndex);
void transactionMenu();
void saveMenu();




//Global Variables
string cusUsername[10],cusPassword[10];
string cusName[10],cusPhone[10],cusEmail[10];
string vehId[10],vehName[10],vehNumber[10],vehRent[10];
float rentAmount[10],businessRevenue;
bool isVehAvailable[10],isCusAvailable[10];
int customerVehicle[10];
int days[10];
int totalCustomers=0;
int totalVehicles=0,vehAvailable=0,vehRented=0;

int found;

// FUNCTIONS DECLARATION

void mainMenu(){
		cout<<"1. Customer Portal"<<endl;
		cout<<"2. Admin Portal"<<endl;
		cout<<"3. Exit\n"<<endl;
		int option;
		cout<<"Enter:";
		cin>>option;
		
		if(option==1)
		{
			cout<<"\nCustomer Portal"<<endl;
			customerMenu();
		}
		else if(option==2)
		{
			cout<<"\nAdmin Portal"<<endl;
			adminMenu();
		}
		else if(option==3)
		{
			cout<<"Program Ended......."<<endl;
		}
		else{
			cout<<"Invalid Choice Select only 1,2 and 3\n"<<endl;
			mainMenu();	
		}
		
}
void customerMenu(){
			cout<<"\n1. Login"<<endl;
			cout<<"2. Register"<<endl;
			cout<<"3. Back\n\n"<<endl;
			int option;
			cout<<"Enter:";
			cin>>option;
			
			if(option==1)
			{
				cout<<"Enter Your Credentials"<<endl;
				cusLogin();
			}
			else if(option==2){
				cout<<"Enter Details"<<endl;
				cusRegister();
			}
			else if(option==3)
			{
				mainMenu();
			}
			else{
				cout<<"\nInvalid Choice Select Only 1,2 and 3"<<endl;
				customerMenu();
			}
}
void cusLogin(){
	cin.ignore();
	string tempUsername,tempPassword;
	cout<<"Enter username:";
	getline(cin,tempUsername);
	cout<<"Enter Password:";
	getline(cin,tempPassword);
	
	int foundIndex=-1;
	for(int i=0;i<totalCustomers;i++)
	{
		if(tempUsername==cusUsername[i]&&tempPassword==cusPassword[i])
		{
			foundIndex=i;
			cout<<"Acess Granted....."<<endl;
			cusPortal(foundIndex);
		}
	}
	if(foundIndex==-1){
		cout<<"Acess Denied....."<<endl;
		customerMenu();
	}
}
void cusRegister(){
	if(totalCustomers>=10)
	{
		cout<<"Maximum Number Of Customers Registered"<<endl;
		customerMenu();
	}
	else
	{
	cin.ignore();
	cout<<"Enter Name:";
	getline(cin,cusName[totalCustomers]);
	int foundIndex=-1;
	for(int i=0;i<totalCustomers;i++){
		if(cusName[totalCustomers]==cusName[i])
		{
			foundIndex=i;
			cout<<"Customer Already Exists with same Name."<<endl;
			cusRegister();
		}	
	}
	cout<<"Enter Phone Number:";
	getline(cin,cusPhone[totalCustomers]);
	cout<<"Enter Email:";
	getline(cin,cusEmail[totalCustomers]);
	cusUsername[totalCustomers]=cusEmail[totalCustomers];
	cout<<"Select Password:";
	getline(cin,cusPassword[totalCustomers]);
	totalCustomers++;
		
	customerMenu();	
	}
	
	
}
void cusPortal(int foundIndex){
	if(totalCustomers==0)
	{
		cout<<"No Customers on Portal"<<endl;
		customerMenu();
	}
	else{
		cout<<"Customer Details....."<<endl;
		cout<<"Username:"<<cusUsername[foundIndex]<<endl;
		cout<<"Name:"<<cusName[foundIndex]<<endl;
		cout<<"Phone Number:"<<cusPhone[foundIndex]<<endl;
		cout<<"Email:"<<cusEmail[foundIndex]<<endl;
		if(isCusAvailable[foundIndex]==false)
		{
			cout<<"Customer Rental Status: No Rents"<<endl;
		}
		else{
			cout<<"Customer Rental Status: Rented A Vehicle"<<endl;
			rentVehicle(foundIndex,found);
		}
		customerMenu();
	}
	
	
	customerMenu();
}
void adminMenu(){
	cin.ignore();
	string tempAdUser,tempAdPass;
	cout<<"Enter Username:";
	getline(cin,tempAdUser);
	cout<<"Enter Password:";
	getline(cin,tempAdPass);
	
	if(tempAdUser=="admin"&&tempAdPass=="admin123")
	{
		cout<<"Acess Granted....."<<endl;
		adminPortal();
	}
	else{
		cout<<"Acess Denied....."<<endl;
		adminMenu();
	}
}
void adminPortal(){
	cout<<"\n\n1. Customer Management"<<endl;
	cout<<"2. Vehicle Management"<<endl;
	cout<<"3. Rent Vehicle"<<endl;
	cout<<"4. Return Vehicle"<<endl;
	cout<<"5. Transaction Details"<<endl;
	cout<<"6. Save/Exit"<<endl;
	int option;
	cout<<"Enter:";
	cin>>option;
	
	if(option==1)
	{
		cout<<"Customer Management"<<endl;
		cusManagement();
	}
	else if(option==2)
	{
		cout<<"Vehicle Management"<<endl;
		vehManagement();
	}
	else if(option==3)
	{
		cout<<"Rent Vehicle"<<endl;
		rentMenu();
	}
	else if(option==4)
	{
		cout<<"Return Vehicle"<<endl;
		returnMenu();
	}
	else if(option==5)
	{
		cout<<"Transaction Details"<<endl;
		transactionMenu();
	}
	else if(option==6)
	{
		cout<<"Save and exit"<<endl;
		saveMenu();
	}
	else{
		cout<<"Invalid Option Select Only 1,2,3,4,5 and 6"<<endl;
		adminPortal();
	}
}
void cusManagement(){
	cout<<"\n\n1.Customer Details"<<endl;
	cout<<"2. Customer Registration"<<endl;
	cout<<"3. Search Customer"<<endl;
	cout<<"4. Back"<<endl;
	
	int option;
	cout<<"Enter:";
	cin>>option;
	
	if(option==1)
	{
		cout<<"Customer Details"<<endl;
		cusDetails();
	}
	else if(option==2)
	{
		cout<<"Customer Registration"<<endl;
		cusRegAdmin();
	}
	else if(option==3)
	{
		cout<<"Search Customer"<<endl;
		cusSearch();
	}
	else if(option==4)
	{
		adminPortal();
	}
	else{
		cout<<"Invalid OPtion Select only 1,2,3 and 4"<<endl;
		cusManagement();
	}
}
void cusDetails(){
	if(totalCustomers==0)
	{
		cout<<"No CUstomers On Portal"<<endl;
		cusManagement();
	}
	else{
	for(int i=0;i<totalCustomers;i++)
	{
		cout<<"Customer "<<i+1<<" Details"<<endl;
		cout<<"Username:"<<cusUsername[i]<<endl;
		cout<<"Name:"<<cusName[i]<<endl;
		cout<<"Phone Number:"<<cusPhone[i]<<endl;
		cout<<"Email:"<<cusEmail[i]<<endl<<endl;
	}
	cusManagement();
	}
	
}
void cusRegAdmin(){
	if(totalCustomers>=10)
	{
		cout<<"Maximum Number Of Customers Registered"<<endl;
		cusManagement();
	}
	else
	{
	cin.ignore();
	cout<<"Enter Name:";
	getline(cin,cusName[totalCustomers]);
	int foundIndex=-1;
	for(int i=0;i<totalCustomers;i++){
		if(cusName[totalCustomers]==cusName[i])
		{
			foundIndex=i;
			cout<<"Customer Already Exists with same Name."<<endl;
			cusRegAdmin();
		}	
	}
	cout<<"Enter Phone Number:";
	getline(cin,cusPhone[totalCustomers]);
	cout<<"Enter Email:";
	getline(cin,cusEmail[totalCustomers]);
	cusUsername[totalCustomers]=cusEmail[totalCustomers];
	cout<<"Select Password:";
	getline(cin,cusPassword[totalCustomers]);
	totalCustomers++;
	
	cusManagement();
	}
	
}
void cusSearch(){
	if(totalCustomers==0)
	{
		cout<<"No Customers On Portal"<<endl;
		cusManagement();
	}
	else{
		cin.ignore();
	string sEmail;
	cout<<"Enter Customer Email:";
	getline(cin,sEmail);
	
	int foundIndex=-1;
	for(int i=0;i<totalCustomers;i++)
	{
		if(sEmail==cusEmail[i])
		{
			foundIndex=i;
			cout<<"Customer"<<i+1<<" Details"<<endl;
			cout<<"Username:"<<cusUsername[i]<<endl;
			cout<<"Name:"<<cusName[i]<<endl;
			cout<<"Phone Number:"<<cusPhone[i]<<endl;
			cout<<"Email:"<<cusEmail[i]<<endl;
			cusManagement();
		}
	}
	cusManagement();
	if(foundIndex==-1)
	{
		cout<<"Customer Not Found. Retry!"<<endl;
		cusSearch();
	}
}
	
}
void vehManagement(){
	cout<<"\n\n1. Vehicle Details"<<endl;
	cout<<"2. Vehicle Registration"<<endl;
	cout<<"3. View Available Vehicles"<<endl;
	cout<<"4. View Rented Vehicles"<<endl;
	cout<<"5. Search Vehicle"<<endl;
	cout<<"6. Back"<<endl;
	
	int option;
	cout<<"Enter:";
	cin>>option;
	
	if(option==1)
	{
		cout<<"Vehicle Details"<<endl;
		vehDetails();
	}
	else if(option==2)
	{
		cout<<"Vehicle Registration"<<endl;
		vehRegister();
	}
	else if(option==3)
	{
		cout<<"Available Vehicles"<<endl;
		vehAvailability();
	}
	else if(option==4)
	{
		cout<<"Rented Vehicles"<<endl;
		vehRentility();
	}
	else if(option==5)
	{
		cout<<"Search Vehicle"<<endl;
		vehSearch();
	}
	else if(option==6)
	{
		adminPortal();	
	}
	else {
		cout<<"Invalid Option Select Only 1,2,3,4,5 and 6"<<endl;
		vehManagement();
	}
}
void vehDetails(){
	for(int i=0;i<totalVehicles;i++)
	{
		cout<<"Vehicle"<<i+1<<" Details"<<endl;
		cout<<"Vehicle ID:"<<vehId[i]<<endl;
		cout<<"Vehicle Name:"<<vehName[i]<<endl;
		cout<<"Vehicle Registration Number:"<<vehNumber[i]<<endl;
		if (isVehAvailable[i] == false)
	{
    	cout << "Vehicle Status: Available" << endl;
	}
	else
	{
   	cout << "Vehicle Status: Rented" << endl;
	}
		cout<<"Vehicle  Daily Rent:"<<vehRent[i]<<endl;
	}
	vehManagement();
}
void vehRegister(){
	if(totalVehicles>=10)
	{
		cout<<"Maximum Number Of Vehicles Registered"<<endl;
		vehManagement();
	}
	else
	{
		cin.ignore();
	cout<<"Vehicle Name:"<<"VEH-"<<totalVehicles+1<<endl;
	vehId[totalVehicles]="VEH-"+to_string(totalVehicles+1);
	cout<<"Enter Vehicle Name:";
	getline(cin,vehName[totalVehicles]);
	cout<<"Enter vehicle Identification Number:";
	getline(cin,vehNumber[totalVehicles]);
	int foundIndex=-1;
	for(int i=0;i<totalVehicles;i++){
		if(vehNumber[totalVehicles]==vehNumber[i])
		{
			foundIndex=i;
			cout<<"Vehicle Already Exists with same Identification Number."<<endl;
			vehRegister();
		}	
	}
	isVehAvailable[totalVehicles] = false;
	cout<<"Vehicle Status: Available"<<endl;
	cout<<"Enter Vehicle Rent:";
	getline(cin,vehRent[totalVehicles]);
	totalVehicles++;
		
	vehManagement();	
	}
	
}
void vehAvailability(){
	int foundIndex=-1;
	for(int i=0;i<totalVehicles;i++)
	{
		if(isVehAvailable[i]==false)
		{
		foundIndex=i;
		cout<<"Vehicle"<<i+1<<" Details"<<endl;
		cout<<"Vehicle ID:"<<vehId[i]<<endl;
		cout<<"Vehicle Name:"<<vehName[i]<<endl;
		cout<<"Vehicle Registration Number:"<<vehNumber[i]<<endl;
		if (isVehAvailable[i] == false)
		{
	    	cout << "Vehicle Status: Available" << endl;
		}
		else
		{
	   	cout << "Vehicle Status: Rented" << endl;
		}
			cout<<"Vehicle  Daily Rent:"<<vehRent[i]<<endl;
		}
	
	}
	
	if(foundIndex==-1)
	{
		cout<<"No Available Cars"<<endl;
		vehManagement();
	}
	vehManagement();
}
void vehRentility(){
		int foundIndex=-1;
	for(int i=0;i<totalVehicles;i++)
	{
		if(isVehAvailable[i]==true)
		{
		foundIndex=i;
		cout<<"Vehicle"<<i+1<<" Details"<<endl;
		cout<<"Vehicle ID:"<<vehId[i]<<endl;
		cout<<"Vehicle Name:"<<vehName[i]<<endl;
		cout<<"Vehicle Registration Number:"<<vehNumber[i]<<endl;
		if (isVehAvailable[i] == false)
		{
	    	cout << "Vehicle Status: Available" << endl;
		}
		else
		{
	   	cout << "Vehicle Status: Rented" << endl;
		}
			cout<<"Vehicle  Daily Rent:"<<vehRent[i]<<endl;
		}
	
	}
	
	if(foundIndex==-1)
	{
		cout<<"No Rented Cars"<<endl;
		vehManagement();
	}
	vehManagement();
}
void vehSearch(){
	if(totalVehicles==0)
	{
		cout<<"No Vehicles On Portal"<<endl;
		vehManagement();
	}
	else{
		cin.ignore();
	string tempId;
	cout<<"Enter Vehicle ID:";
	getline(cin,tempId);
	
	int foundIndex=-1;
	for(int i=0;i<totalVehicles;i++)
	{
		if(tempId==vehId[i])
		{
			foundIndex=i;
			cout<<"Vehicle Id:"<<vehId[i]<<endl;
			cout<<"Vehicle Name:"<<vehName[i]<<endl;
			cout<<"Vehicle Identification Number:"<<vehNumber[i]<<endl;
			if (isVehAvailable[totalVehicles] == false)
		{
	    	cout << "Vehicle Status: Available" << endl;
		}
		else
		{
	   	cout << "Vehicle Status: Rented" << endl;
		}
			cout<<"Vehicle Daily Rent:"<<vehRent[i]<<endl;
			vehManagement();
		}
	}
	vehManagement();
	if(foundIndex==-1)
	{
		cout<<"Vehicle Not Found. Retry!"<<endl;
		vehSearch();
	}
}
}
void rentMenu(){
	if(totalVehicles==0)
	{
		cout<<"No Vehicles On Portal"<<endl;
		adminPortal();
	}
	else{
		cin.ignore();
		int foundIndex=-1;
	for(int i=0;i<totalVehicles;i++)
	{
		if(isVehAvailable[i]==false)
		{
		foundIndex=i;
		vehAvailable++;
		cout<<"Vehicle"<<i+1<<" Details"<<endl;
		cout<<"Vehicle ID:"<<vehId[i]<<endl;
		cout<<"Vehicle Name:"<<vehName[i]<<endl;
		cout<<"Vehicle Registration Number:"<<vehNumber[i]<<endl;
		if (isVehAvailable[totalVehicles] == false)
		{
	    	cout << "Vehicle Status: Available" << endl;
		}
		else
		{
	   	cout << "Vehicle Status: Rented" << endl;
		}
			cout<<"Vehicle  Daily Rent:"<<vehRent[i]<<endl;
		}
	
	}
	rentToCustomer();
}
}
void rentToCustomer(){
	string tempCusName;
	cout<<"Enter Customer Name:";
	getline(cin,tempCusName);
	
	int foundIndex=-1;
	for(int i=0;i<totalCustomers;i++)
	{
		if(tempCusName==cusName[i])
		{
			foundIndex=i;
			cout<<"Customer "<<i+1<<"Details"<<endl;
			cout<<"Customer Name:"<<cusName[i]<<endl;
			cout<<"Customer Phone Number:"<<cusPhone[i]<<endl;
			if(isCusAvailable[i]==false)
			{
				cout<<"Customer Rental Status: No Rents"<<endl;
			}
			else{
				cout<<"Customer Rental Status: Rented A Vehicle"<<endl;
				
			}
		}
	}
	if(foundIndex==-1)
	{
		cout<<"Customer Not Found. Try Again."<<endl;
		rentToCustomer();
	}
	cin.ignore();
	string tempVehId;
	cout<<"Enter Vehicle ID:";
	getline(cin,tempVehId);
	
	int found=-1;
	for(int i=0;i<totalVehicles;i++)
	{
		if(tempVehId==vehId[i])
		{
			found=i;
			cout<<"Vehicle "<<i+1<<" Details"<<endl;
			cout<<"Vehicle ID:"<<vehId[i]<<endl;
			cout<<"Vehicle Name:"<<vehName[i]<<endl;
			cout<<"Vehicle Identification Number:"<<vehNumber[i]<<endl;
			if (isVehAvailable[i] == false)
			{
		    	cout << "Vehicle Status: Available" << endl;
			}
			else
			{
		   	cout << "Vehicle Status: Rented" << endl;
			}
				cout<<"Vehicle  Daily Rent:"<<vehRent[i]<<endl;
		}
	}
	if(found==-1)
	{
		cout<<"Vehicle Not Found. Try Again"<<endl;
		rentToCustomer();
	}
	cin.ignore();
	char option;
	cout<<"Choose you want to rent this car Y/N:";
	cin>>option;
	
	if(option=='y'||option=='Y')
	{
		cout<<"Proceed"<<endl;
		cout<<"Number of days you want to rent:";
		cin>>days[foundIndex];
		rentAmount[foundIndex]=stof(vehRent[found])*days[found];
		rentVehicle(foundIndex,found);
		adminPortal();
	}
	else if(option=='n'||option=='N'){
		cout<<"Cancelled..."<<endl;
		rentToCustomer();
	}
	
	
}
void rentVehicle(int foundIndex,int found){
	cout<<"Vehicle Renting......"<<endl;
	cout<<"Vehicle ID:"<<vehId[found]<<endl;
	cout<<"Vehicle Name:"<<vehName[found]<<endl;
	cout<<"Vehicle Identification Number:"<<vehNumber[found]<<endl;
	cout<<"Vehicle Daily Rent:"<<vehRent[found]<<endl;
	cout<<"Number of Rent days:"<<days[foundIndex]<<endl;
	cout<<"You Owe:"<<rentAmount[foundIndex]<<" Rs."<<endl;
	isVehAvailable[found]=true;
	customerVehicle[foundIndex] = found;
	vehAvailable--;
    vehRented++;
	isCusAvailable[foundIndex]=true;
	
	
}

void returnMenu(){
	if(vehRented==0)
	{
		cout<<"No Vehicles Rented."<<endl;
		adminPortal();
	}
	else{
		cin.ignore();
	string tempVehId;
	cout<<"Enter Vehicle Number:";
	getline(cin,tempVehId);
	
	int foundIndex=-1;
	for(int i=0;i<totalVehicles;i++)
	{
		if(tempVehId==vehId[i])
		{
			foundIndex=i;
			cout<<"Vehicle Details"<<endl;
			cout<<"Vehicle ID:"<<vehId[i]<<endl;
			cout<<"Vehicle Name:"<<vehName[i]<<endl;
			cout<<"Vehicle Identification Number:"<<vehNumber[i]<<endl;
			if (isVehAvailable[i] == false)
	{
    	cout << "Vehicle Status: Available" << endl;
	}
	else
	{
   	cout << "Vehicle Status: Rented" << endl;
	}
		cout<<"Vehicle  Daily Rent:"<<vehRent[i]<<endl;
		}
	}
	if(foundIndex==-1)
	{
		cout<<"Vehicle Not Found. Try Again"<<endl;
		returnMenu();
	}
	if(isVehAvailable[foundIndex] == true)
	{
		char option;
		cout<<"Vehicle is Rented."<<endl;
		cout<<"Do You Wish To Return the vehicle Y/N:"<<endl;
		cin>>option;
		
		if(option=='y'||option=='Y')
		{
			cout<<"Vehicle Returned...."<<endl;
			cout<<"You Owe:"<<rentAmount[foundIndex]<<" Rs."<<endl;
			payRent(foundIndex);
			adminPortal();
		}
		else if(option=='n'||option=='N'){
			cout<<"You Owe:"<<rentAmount[foundIndex]<<" Rs."<<endl;
			adminPortal();
		}
		else{
			cout<<"Invalid Option. Select only Y/N or y/n..."<<endl;
			returnMenu();
		}
	}
	else{
		cout<<"Vehicle is'nt  Rented.."<<endl;
		adminPortal();
	}
}	
}
void payRent(int foundIndex){
	char option;
	cout<<"Do You Want To Pay The Rent:";
	cin>>option;
	
	if(option=='y'||option=='Y')
	{
		cout<<"Paying Rent..."<<endl;
		float howMuch;
		cout<<"Enter Amount:";
		cin>>howMuch;
		
		if(howMuch>rentAmount[foundIndex]||howMuch<rentAmount[foundIndex])
		{
			cout<<"You Owe:"<<rentAmount[foundIndex]<<" Rs."<<endl;
			payRent(foundIndex);
		}
		else{
			businessRevenue+=rentAmount[foundIndex];
			rentAmount[foundIndex]=0.0;
			int customerIndex=-1;
			for(int i=0;i<totalCustomers;i++)
			{
		    if(customerVehicle[i]==foundIndex)
    		{
        	customerIndex=i;
        	break;
    		}
			}
			vehAvailable++;
    		vehRented--;
			isVehAvailable[foundIndex]=false;
			isCusAvailable[customerIndex] = false;
			adminPortal();
		}
	}
	else if(option=='n'||option=='N')
	{
		cout<<"You Owe:"<<rentAmount[foundIndex]<<" Rs."<<endl;
		adminPortal();
	}
	else {
		cout<<"Invalid Option. Select only Y/N or y/n."<<endl;
		payRent(foundIndex);
	}
}

void transactionMenu(){
	cout<<"Business Revenue :"<<businessRevenue<<endl;
	adminPortal();
}
void saveMenu(){
	mainMenu();
}


// INT MAIN FUNCTION
int main(){
	cout<<"Vehicle Rental System"<<endl;
	cout<<"A C++ Console Based Program\n\n"<<endl;
	mainMenu();
	
	return 0;
}
