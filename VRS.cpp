#include<iostream>
#include<string>
#include<fstream>
using namespace std;

// FUCTION PROTOTYPES
int mainMenu();
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
void rentVehicle(int customerIndex,int vehicleIndex);
void returnMenu();
void payRent(int vehicleIndex, int customerIndex);
void transactionMenu();
void saveMenu();
void saveCusDetails();
void saveVehDetails();
void saveRevenue();
void loadCusData();
void loadVehData();
void loadRevenue();

//Global Variables
string cusUsername[10],cusPassword[10];
string cusName[10],cusPhone[10],cusEmail[10];
string vehId[10],vehName[10],vehNumber[10],vehRent[10];
float rentAmount[10],businessRevenue=0;
bool isVehAvailable[10],isCusAvailable[10];
int customerVehicle[10];
int days[10];
int totalCustomers=0;
int totalVehicles=0,vehAvailable=0,vehRented=0;
int found;

// FUNCTIONS DECLARATION
int mainMenu(){
		cout<<"\t\t1. Customer Portal"<<endl;
		cout<<"\t\t2. Admin Portal"<<endl;
		cout<<"\t\t3. Exit\n"<<endl;
		int option;
		cout<<"\t\tEnter:";
		cin>>option;
		if(option==1)
		{
			cout<<"\t--------------------------------------------------"<<endl;
			cout<<"\t--------------------------------------------------"<<endl;
			cout<<"\n\t\tCustomer Portal"<<endl;
			customerMenu();
		}
		else if(option==2)
		{
			cout<<"\t--------------------------------------------------"<<endl;
			cout<<"\t--------------------------------------------------"<<endl;
			cout<<"\n\t\tAdmin Portal"<<endl;
			adminMenu();
		}
		else if(option==3)
		{
			cout<<"\t--------------------------------------------------"<<endl;
			cout<<"\t--------------------------------------------------"<<endl;
			cout<<"\t\tProgram Ended......."<<endl;
			return 0;
		}
		else{
			cout<<"\t--------------------------------------------------"<<endl;
			cout<<"\t\tInvalid Choice Select only 1,2 and 3\n"<<endl;
			mainMenu();	
		}
}

void customerMenu(){
			cout<<"\n\t\t1. Login"<<endl;
			cout<<"\t\t2. Register"<<endl;
			cout<<"\t\t3. Back\n\n"<<endl;
			int option;
			cout<<"\t\tEnter:";
			cin>>option;
			if(option==1)
			{
				cout<<"\t--------------------------------------------------"<<endl;
				cout<<"\t--------------------------------------------------"<<endl;
				cout<<"\n\t\tEnter Your Credentials"<<endl;
				cusLogin();
			}
			else if(option==2){
				cout<<"\t--------------------------------------------------"<<endl;
				cout<<"\t--------------------------------------------------"<<endl;
				cout<<"\n\t\tEnter Details"<<endl;
				cusRegister();
			}
			else if(option==3)
			{
				cout<<"\t--------------------------------------------------"<<endl;
				cout<<"\t--------------------------------------------------"<<endl;
				mainMenu();
			}
			else{
				cout<<"\t--------------------------------------------------"<<endl;
				cout<<"\t--------------------------------------------------"<<endl;
				cout<<"\n\t\tInvalid Choice Select Only 1,2 and 3"<<endl;
				customerMenu();
			}
}

void cusLogin(){
	cin.ignore();
	string tempUsername,tempPassword;
	cout<<"\t\tEnter username:";
	getline(cin,tempUsername);
	cout<<"\t\tEnter Password:";
	getline(cin,tempPassword);
	int foundIndex=-1;
	for(int i=0;i<totalCustomers;i++)
	{
		if(tempUsername==cusUsername[i]&&tempPassword==cusPassword[i])
		{
			foundIndex=i;
			cout<<"\n\t\tAcess Granted....."<<endl;
			cusPortal(foundIndex);
		}
	}
	if(foundIndex==-1){
		cout<<"\n\t\tAcess Denied....."<<endl;
		customerMenu();
	}
}

void cusRegister(){
	if(totalCustomers>=10)
	{
		cout<<"\t\tMaximum Number Of Customers Registered"<<endl;
		customerMenu();
	}
	else
	{
	cin.ignore();
	cout<<"\t\tEnter Name:";
	getline(cin,cusName[totalCustomers]);
	int foundIndex=-1;
	for(int i=0;i<totalCustomers;i++){
		if(cusName[totalCustomers]==cusName[i])
		{
			foundIndex=i;
			cout<<"\t\tCustomer Already Exists with same Name."<<endl;
			cusRegister();
			return;
		}	
	}
	cout<<"\t\tEnter Phone Number:";
	getline(cin,cusPhone[totalCustomers]);
	cout<<"\t\tEnter Email:";
	getline(cin,cusEmail[totalCustomers]);
	int foundEmail=-1;
	for(int i=0;i<totalCustomers;i++){
		if(cusEmail[totalCustomers]==cusEmail[i])
		{
			foundEmail=i;
			cout<<"\t\tCustomer Already Exists with same Email."<<endl;
			cusRegister();
			return;
		}	
	}
	if(foundEmail==-1)
	{
	cusUsername[totalCustomers]=cusEmail[totalCustomers];2
	}
	cout<<"\t\tSelect Password:";
	getline(cin,cusPassword[totalCustomers]);
	customerVehicle[totalCustomers] = -1;
	isCusAvailable[totalCustomers] = false;
	days[totalCustomers] = 0;
	rentAmount[totalCustomers] = 0.0;
	totalCustomers++;
	saveCusDetails();
	customerMenu();	
	}	
}

void cusPortal(int foundIndex){
	if(totalCustomers==0)
	{
		cout<<"\t--------------------------------------------------"<<endl;
		cout<<"\t--------------------------------------------------"<<endl;
		cout<<"\n\t\tNo Customers on Portal"<<endl;
		customerMenu();
	}
	else{
		cout<<"\t--------------------------------------------------"<<endl;
		cout<<"\t--------------------------------------------------"<<endl;
		cout<<"\n\t\tCustomer Details....."<<endl;
		cout<<"\t\tUsername:"<<cusUsername[foundIndex]<<endl;
		cout<<"\t\tName:"<<cusName[foundIndex]<<endl;
		cout<<"\t\tPhone Number:"<<cusPhone[foundIndex]<<endl;
		cout<<"\t\tEmail:"<<cusEmail[foundIndex]<<endl;
		if(isCusAvailable[foundIndex]==false)
		{
			cout<<"\t\tCustomer Rental Status: No Rents"<<endl;
		}
		else{
			cout<<"\t\tCustomer Rental Status: Rented A Vehicle"<<endl;
			rentVehicle(foundIndex,customerVehicle[foundIndex]);
		}
		customerMenu();
	}
	customerMenu();
}

void adminMenu(){
	cin.ignore();
	string tempAdUser,tempAdPass;
	cout<<"\t\tEnter Username:";
	getline(cin,tempAdUser);
	cout<<"\t\tEnter Password:";
	getline(cin,tempAdPass);
	if(tempAdUser=="admin"&&tempAdPass=="admin123")
	{
		cout<<"\t\tAcess Granted....."<<endl;
		adminPortal();
	}
	else{
		cout<<"\t\tAcess Denied....."<<endl;
		adminMenu();
	}
}

void adminPortal(){
	cout<<"\t--------------------------------------------------"<<endl;
	cout<<"\t--------------------------------------------------"<<endl;
	cout<<"\n\n\t\t1. Customer Management"<<endl;
	cout<<"\t\t2. Vehicle Management"<<endl;
	cout<<"\t\t3. Rent Vehicle"<<endl;
	cout<<"\t\t4. Return Vehicle"<<endl;
	cout<<"\t\t5. Transaction Details"<<endl;
	cout<<"\t\t6. Save/Exit"<<endl;
	int option;
	cout<<"\t\tEnter:";
	cin>>option;
	if(option==1)
	{
		cout<<"\t--------------------------------------------------"<<endl;
		cout<<"\t--------------------------------------------------"<<endl;
		cout<<"\n\t\tCustomer Management"<<endl;
		cusManagement();
	}
	else if(option==2)
	{
		cout<<"\t--------------------------------------------------"<<endl;
		cout<<"\t--------------------------------------------------"<<endl;
		cout<<"\n\t\tVehicle Management"<<endl;
		vehManagement();
	}
	else if(option==3)
	{
		cout<<"\t--------------------------------------------------"<<endl;
		cout<<"\t--------------------------------------------------"<<endl;
		cout<<"\n\t\tRent Vehicle"<<endl;
		rentMenu();
	}
	else if(option==4)
	{
		cout<<"\t\tReturn Vehicle"<<endl;
		returnMenu();
	}
	else if(option==5)
	{
		cout<<"\t--------------------------------------------------"<<endl;
		cout<<"\t--------------------------------------------------"<<endl;
		cout<<"\n\t\tTransaction Details"<<endl;
		transactionMenu();
	}
	else if(option==6)
	{
		cout<<"\t\tSave and exit"<<endl;
		saveMenu();
	}
	else{
		cout<<"\t--------------------------------------------------"<<endl;
		cout<<"\t--------------------------------------------------"<<endl;
		cout<<"\n\t\tInvalid Option Select Only 1,2,3,4,5 and 6"<<endl;
		adminPortal();
	}
}

void cusManagement(){
	cout<<"\t--------------------------------------------------"<<endl;
	cout<<"\t--------------------------------------------------"<<endl;
	cout<<"\n\n\t\t1. Customer Details"<<endl;
	cout<<"\t\t2. Customer Registration"<<endl;
	cout<<"\t\t3. Search Customer"<<endl;
	cout<<"\t\t4. Back"<<endl;
	int option;
	cout<<"\t\tEnter:";
	cin>>option;
	if(option==1)
	{
		cout<<"\t--------------------------------------------------"<<endl;
		cout<<"\t--------------------------------------------------"<<endl;
		cout<<"\n\t\tCustomer Details"<<endl;
		cusDetails();
	}
	else if(option==2)
	{
		cout<<"\t--------------------------------------------------"<<endl;
		cout<<"\t--------------------------------------------------"<<endl;
		cout<<"\n\t\tCustomer Registration"<<endl;
		cusRegAdmin();
	}
	else if(option==3)
	{
		cout<<"\t--------------------------------------------------"<<endl;
		cout<<"\t--------------------------------------------------"<<endl;
		cout<<"\n\t\tSearch Customer"<<endl;
		cusSearch();
	}
	else if(option==4)
	{
		cout<<"\t--------------------------------------------------"<<endl;
		cout<<"\t--------------------------------------------------"<<endl;
		adminPortal();
	}
	else{
		cout<<"\t--------------------------------------------------"<<endl;
		cout<<"\t--------------------------------------------------"<<endl;
		cout<<"\n\t\tInvalid OPtion Select only 1,2,3 and 4"<<endl;
		cusManagement();
	}
}

void cusDetails(){
	if(totalCustomers==0)
	{
		cout<<"\t--------------------------------------------------"<<endl;
		cout<<"\t--------------------------------------------------"<<endl;
		cout<<"\n\t\tNo Customers On Portal"<<endl;
		cusManagement();
	}
	else{
		cout<<"\t--------------------------------------------------"<<endl;
		cout<<"\t--------------------------------------------------"<<endl;
	for(int i=0;i<totalCustomers;i++)
	{
		cout<<"\t\tCustomer "<<i+1<<" Details"<<endl;
		cout<<"\t\tUsername:"<<cusUsername[i]<<endl;
		cout<<"\t\tName:"<<cusName[i]<<endl;
		cout<<"\t\tPhone Number:"<<cusPhone[i]<<endl;
		cout<<"\t\tEmail:"<<cusEmail[i]<<endl<<endl;
	}
	cusManagement();
	}
}

void cusRegAdmin(){
	if(totalCustomers>=10)
	{
		cout<<"\t--------------------------------------------------"<<endl;
		cout<<"\t--------------------------------------------------"<<endl;
		cout<<"\n\t\tMaximum Number Of Customers Registered"<<endl;
		cusManagement();
	}
	else
	{
		cout<<"\t--------------------------------------------------"<<endl;
		cout<<"\t--------------------------------------------------"<<endl;
	cin.ignore();
	cout<<"\t\tEnter Name:";
	getline(cin,cusName[totalCustomers]);
	int foundIndex=-1;
	for(int i=0;i<totalCustomers;i++){
		if(cusName[totalCustomers]==cusName[i])
		{
			foundIndex=i;
			cout<<"\t\tCustomer Already Exists with same Name."<<endl;
			cusRegAdmin();
			return;
		}	
	}
	cout<<"\t\tEnter Phone Number:";
	getline(cin,cusPhone[totalCustomers]);
	cout<<"\t\tEnter Email:";
	getline(cin,cusEmail[totalCustomers]);
	int foundEmail=-1;
	for(int i=0;i<totalCustomers;i++){
		if(cusEmail[totalCustomers]==cusEmail[i])
		{
			foundEmail=i;
			cout<<"\t\tCustomer Already Exists with same Email."<<endl;
			cusRegAdmin();
			return;
		}	
	}
	if(foundEmail==-1)
	{
	cusUsername[totalCustomers]=cusEmail[totalCustomers];
	};
	cout<<"\t\tSelect Password:";
	getline(cin,cusPassword[totalCustomers]);
	customerVehicle[totalCustomers] = -1;
	isCusAvailable[totalCustomers] = false;
	days[totalCustomers] = 0;
	rentAmount[totalCustomers] = 0.0;
	totalCustomers++;
	cusManagement();
	}
	
}

void cusSearch(){
	if(totalCustomers==0)
	{
		cout<<"\t--------------------------------------------------"<<endl;
		cout<<"\t--------------------------------------------------"<<endl;
		cout<<"\n\t\tNo Customers On Portal"<<endl;
		cusManagement();
	}
	else{
		cout<<"\t--------------------------------------------------"<<endl;
		cout<<"\t--------------------------------------------------"<<endl;
		cin.ignore();
	string sEmail;
	cout<<"\n\t\tEnter Customer Email:";
	getline(cin,sEmail);
	
	int foundIndex=-1;
	for(int i=0;i<totalCustomers;i++)
	{
		if(sEmail==cusEmail[i])
		{
			foundIndex=i;
			cout<<"\t\tCustomer "<<i+1<<" Details"<<endl;
			cout<<"\t\tUsername:"<<cusUsername[i]<<endl;
			cout<<"\t\tName:"<<cusName[i]<<endl;
			cout<<"\t\tPhone Number:"<<cusPhone[i]<<endl;
			cout<<"\t\tEmail:"<<cusEmail[i]<<endl;
			break;
		}
	}
	cusManagement();
	if(foundIndex==-1)
	{
		cout<<"\t--------------------------------------------------"<<endl;
		cout<<"\t--------------------------------------------------"<<endl;
		cout<<"\n\t\tCustomer Not Found. Retry!"<<endl;
		cusSearch();
	}
}
}

void vehManagement(){
	cout<<"\t--------------------------------------------------"<<endl;
	cout<<"\t--------------------------------------------------"<<endl;
	cout<<"\n\t\t1. Vehicle Details"<<endl;
	cout<<"\t\t2. Vehicle Registration"<<endl;
	cout<<"\t\t3. View Available Vehicles"<<endl;
	cout<<"\t\t4. View Rented Vehicles"<<endl;
	cout<<"\t\t5. Search Vehicle"<<endl;
	cout<<"\t\t6. Back"<<endl;
	int option;
	cout<<"\n\t\tEnter:";
	cin>>option;
	if(option==1)
	{
		cout<<"\t--------------------------------------------------"<<endl;
		cout<<"\t--------------------------------------------------"<<endl;
		cout<<"\n\t\tVehicle Details"<<endl;
		vehDetails();
	}
	else if(option==2)
	{
		cout<<"\t--------------------------------------------------"<<endl;
		cout<<"\t--------------------------------------------------"<<endl;
		cout<<"\n\t\tVehicle Registration"<<endl;
		vehRegister();
	}
	else if(option==3)
	{
		cout<<"\t--------------------------------------------------"<<endl;
		cout<<"\t--------------------------------------------------"<<endl;
		cout<<"\n\t\tAvailable Vehicles"<<endl;
		vehAvailability();
	}
	else if(option==4)
	{
		cout<<"\t--------------------------------------------------"<<endl;
		cout<<"\t--------------------------------------------------"<<endl;
		cout<<"\n\t\tRented Vehicles"<<endl;
		vehRentility();
	}
	else if(option==5)
	{
		cout<<"\t--------------------------------------------------"<<endl;
		cout<<"\t--------------------------------------------------"<<endl;
		cout<<"\n\t\tSearch Vehicle"<<endl;
		vehSearch();
	}
	else if(option==6)
	{
		cout<<"\t--------------------------------------------------"<<endl;
		cout<<"\t--------------------------------------------------"<<endl;
		adminPortal();	
	}
	else {
		cout<<"\t--------------------------------------------------"<<endl;
		cout<<"\t--------------------------------------------------"<<endl;
		cout<<"\n\t\tInvalid Option Select Only 1,2,3,4,5 and 6"<<endl;
		vehManagement();
	}
}

void vehDetails(){
	cout<<"\t--------------------------------------------------"<<endl;
	cout<<"\t--------------------------------------------------"<<endl;
	for(int i=0;i<totalVehicles;i++)
	{
		cout<<"\n\t\tVehicle "<<i+1<<" Details"<<endl;
		cout<<"\t\tVehicle ID:"<<vehId[i]<<endl;
		cout<<"\t\tVehicle Name:"<<vehName[i]<<endl;
		cout<<"\t\tVehicle Registration Number:"<<vehNumber[i]<<endl;
		if (isVehAvailable[i] == false)
	{
    	cout << "\t\tVehicle Status: Available" << endl;
	}
	else
	{
   	cout << "\t\tVehicle Status: Rented" << endl;
	}
		cout<<"\t\tVehicle  Daily Rent:"<<vehRent[i]<<endl;
	}
	vehManagement();
}

void vehRegister(){
	if(totalVehicles>=10)
	{
		cout<<"\t--------------------------------------------------"<<endl;
		cout<<"\t--------------------------------------------------"<<endl;
		cout<<"\n\t\tMaximum Number Of Vehicles Registered"<<endl;
		vehManagement();
	}
	else
	{
		cout<<"\t--------------------------------------------------"<<endl;
		cout<<"\t--------------------------------------------------"<<endl;
		cin.ignore();
		cout<<"\n\t\tVehicle ID:"<<"VEH-"<<totalVehicles+1<<endl;
		vehId[totalVehicles]="VEH-"+to_string(totalVehicles+1);
		cout<<"\t\tEnter Vehicle Name:";
		getline(cin,vehName[totalVehicles]);
		cout<<"\t\tEnter vehicle Identification Number:";
		getline(cin,vehNumber[totalVehicles]);
		int foundIndex=-1;
		for(int i=0;i<totalVehicles;i++){
			if(vehNumber[totalVehicles]==vehNumber[i])
			{
				foundIndex=i;
				cout<<"\t\tVehicle Already Exists with same Identification Number."<<endl;
				vehRegister();
				return;
			}	
		}
		isVehAvailable[totalVehicles] = false;
		vehAvailable++;
		cout<<"\t\tVehicle Status: Available"<<endl;
		cout<<"\t\tEnter Vehicle Rent:";
		getline(cin,vehRent[totalVehicles]);
		
		totalVehicles++;	
		vehManagement();	
		}
}

void vehAvailability(){
	cout<<"\t--------------------------------------------------"<<endl;
	cout<<"\t--------------------------------------------------"<<endl;
	int foundIndex=-1;
	for(int i=0;i<totalVehicles;i++)
	{
		if(isVehAvailable[i]==false)
		{
		foundIndex=i;
		cout<<"\n\t\tVehicle"<<i+1<<" Details"<<endl;
		cout<<"\t\tVehicle ID:"<<vehId[i]<<endl;
		cout<<"\t\tVehicle Name:"<<vehName[i]<<endl;
		cout<<"\t\tVehicle Registration Number:"<<vehNumber[i]<<endl;
		cout<<"\t\tVehicle Status: Available"<<endl;
		cout<<"\t\tVehicle  Daily Rent:"<<vehRent[i]<<endl;
		}
	}
	if(foundIndex==-1)
	{
		cout<<"\t--------------------------------------------------"<<endl;
		cout<<"\t--------------------------------------------------"<<endl;
		cout<<"\n\t\tNo Available Cars"<<endl;
		vehManagement();
	}
	vehManagement();
}

void vehRentility(){
	cout<<"\t--------------------------------------------------"<<endl;
	cout<<"\t--------------------------------------------------"<<endl;
		int foundIndex=-1;
	for(int i=0;i<totalVehicles;i++)
	{
		if(isVehAvailable[i]==true)
		{
		foundIndex=i;
		cout<<"\n\t\tVehicle "<<i+1<<" Details"<<endl;
		cout<<"\t\tVehicle ID:"<<vehId[i]<<endl;
		cout<<"\t\tVehicle Name:"<<vehName[i]<<endl;
		cout<<"\t\tVehicle Registration Number:"<<vehNumber[i]<<endl;
		cout<<"\t\tVehicle Status: Rented"<<endl;
		cout<<"\t\tVehicle  Daily Rent:"<<vehRent[i]<<endl;
		}
	}
	if(foundIndex==-1)
	{
		cout<<"\t--------------------------------------------------"<<endl;
		cout<<"\t--------------------------------------------------"<<endl;
		cout<<"\n\t\tNo Rented Cars"<<endl;
		vehManagement();
	}
	vehManagement();
}

void vehSearch(){
	if(totalVehicles==0)
	{
		cout<<"\t--------------------------------------------------"<<endl;
		cout<<"\t--------------------------------------------------"<<endl;
		cout<<"\n\t\tNo Vehicles On Portal"<<endl;
		vehManagement();
	}
	else{
		cout<<"\t--------------------------------------------------"<<endl;
		cout<<"\t--------------------------------------------------"<<endl;
		cin.ignore();
	string tempId;
	cout<<"\n\t\tEnter Vehicle ID:";
	getline(cin,tempId);
	int foundIndex=-1;
	for(int i=0;i<totalVehicles;i++)
	{
		if(tempId==vehId[i])
		{
			foundIndex=i;
			cout<<"\n\t\tVehicle Id:"<<vehId[i]<<endl;
			cout<<"\t\tVehicle Name:"<<vehName[i]<<endl;
			cout<<"\t\tVehicle Identification Number:"<<vehNumber[i]<<endl;
			if (isVehAvailable[i] == false)
		{
	    	cout << "\t\tVehicle Status: Available" << endl;
		}
		else
		{
	   	cout << "\t\tVehicle Status: Rented" << endl;
		}
			cout<<"\t\tVehicle Daily Rent:"<<vehRent[i]<<endl;
			vehManagement();
		}
	}
	vehManagement();
	if(foundIndex==-1)
	{
		cout<<"\t--------------------------------------------------"<<endl;
		cout<<"\t--------------------------------------------------"<<endl;
		cout<<"\n\t\tVehicle Not Found. Retry!"<<endl;
		vehSearch();
	}
}
}

void rentMenu(){
	if(totalVehicles==0)
	{
		cout<<"\t--------------------------------------------------"<<endl;
		cout<<"\t--------------------------------------------------"<<endl;
		cout<<"\n\t\tNo Vehicles On Portal"<<endl;
		adminPortal();
	}
	else{
		cout<<"\t--------------------------------------------------"<<endl;
		cout<<"\t--------------------------------------------------"<<endl;
		cin.ignore();
		int foundIndex=-1;
	for(int i=0;i<totalVehicles;i++)
	{
		if(isVehAvailable[i]==false)
		{
		foundIndex=i;
		cout<<"\n\t\tVehicle "<<i+1<<" Details"<<endl;
		cout<<"\t\tVehicle ID:"<<vehId[i]<<endl;
		cout<<"\t\tVehicle Name:"<<vehName[i]<<endl;
		cout<<"\t\tVehicle Registration Number:"<<vehNumber[i]<<endl;
		if (isVehAvailable[i] == false)
		{
	    	cout << "\t\tVehicle Status: Available" << endl;
		}
		else
		{
	   	cout << "\t\tVehicle Status: Rented" << endl;
		}
			cout<<"\t\tVehicle  Daily Rent:"<<vehRent[i]<<endl;
		}
	}
	rentToCustomer();
}
}

void rentToCustomer(){
	string tempCusName;
	cout<<"\n\t\tEnter Customer Name:";
	getline(cin,tempCusName);
	int foundIndex=-1;
	for(int i=0;i<totalCustomers;i++)
	{
		if(tempCusName==cusName[i]&&isCusAvailable[i]==false)
		{
			foundIndex=i;
			cout<<"\n\t\tCustomer "<<i+1<<"Details"<<endl;
			cout<<"\t\tCustomer Name:"<<cusName[i]<<endl;
			cout<<"\t\tCustomer Phone Number:"<<cusPhone[i]<<endl;
			if(isCusAvailable[i]==false)
			{
				cout<<"\t\tCustomer Rental Status: No Rents"<<endl;
			}
			else{
				cout<<"\t\tCustomer Rental Status: Rented A Vehicle"<<endl;
			}
		}
	}
	if(foundIndex==-1)
	{
		cout<<"\t--------------------------------------------------"<<endl;
		cout<<"\t--------------------------------------------------"<<endl;
		cout<<"\n\t\tCustomer Not Found. Try Again."<<endl;
		rentToCustomer();
	}
	string tempVehId;
	cout<<"\n\t\tEnter Vehicle ID:";
	getline(cin,tempVehId);
	int foundD=-1;
	for(int i=0;i<totalVehicles;i++)
	{
		if(tempVehId==vehId[i] && isVehAvailable[i]==false)
		{
			foundD=i;
			cout<<"\n\t\tVehicle "<<i+1<<" Details"<<endl;
			cout<<"\t\tVehicle ID:"<<vehId[i]<<endl;
			cout<<"\t\tVehicle Name:"<<vehName[i]<<endl;
			cout<<"\t\tVehicle Identification Number:"<<vehNumber[i]<<endl;
			if (isVehAvailable[i] == false)
			{
		    	cout << "\t\tVehicle Status: Available" << endl;
			}
			else
			{
		   	cout << "\t\tVehicle Status: Rented" << endl;
			}
				cout<<"\t\tVehicle  Daily Rent:"<<vehRent[i]<<endl;
		}
	}
	if(foundD==-1)
	{
		cout<<"\t--------------------------------------------------"<<endl;
		cout<<"\t--------------------------------------------------"<<endl;
		cout<<"\n\t\tVehicle Not Found. Try Again"<<endl;
		rentToCustomer();
	}
	char option;
	cout<<"\t\tChoose you want to rent this car Y/N:";
	cin>>option;
	if(option=='y'||option=='Y')
	{
		cout<<"\t\tProceeding...."<<endl;
		cout<<"\t\tNumber of days you want to rent:";
		cin>>days[foundIndex];
		rentAmount[foundIndex]=stof(vehRent[foundD])*days[foundIndex];
		rentVehicle(foundIndex,foundD);
		adminPortal();
	}
	else if(option=='n'||option=='N'){
		cout<<"\t\tCancelled..."<<endl;
		rentToCustomer();
	}
}

void rentVehicle(int customerIndex,int vehicleIndex){
	cout<<"\t--------------------------------------------------"<<endl;
	cout<<"\t--------------------------------------------------"<<endl;
	cout<<"\n\t\tVehicle Details......"<<endl;
	cout<<"\t\tVehicle ID:"<<vehId[vehicleIndex]<<endl;
	cout<<"\t\tVehicle Name:"<<vehName[vehicleIndex]<<endl;
	cout<<"\t\tVehicle Identification Number:"<<vehNumber[vehicleIndex]<<endl;
	cout<<"\t\tVehicle Daily Rent:"<<vehRent[vehicleIndex]<<endl;
	cout<<"\t\tNumber of Rent days:"<<days[customerIndex]<<endl;
	cout<<"\t\tYou Owe:"<<rentAmount[customerIndex]<<" Rs."<<endl;
	isVehAvailable[vehicleIndex]=true;
	customerVehicle[customerIndex] = vehicleIndex;
	vehAvailable--;
    vehRented++;
	isCusAvailable[customerIndex]=true;
}

void returnMenu(){
	if(vehRented==0)
	{
		cout<<"\t--------------------------------------------------"<<endl;
		cout<<"\t--------------------------------------------------"<<endl;
		cout<<"\n\t\tNo Vehicles Rented."<<endl;
		adminPortal();
	}
	else{
		cout<<"\t--------------------------------------------------"<<endl;
		cout<<"\t--------------------------------------------------"<<endl;
		cin.ignore();
	string tempVehId;
	cout<<"\n\t\tEnter Vehicle Number:";
	getline(cin,tempVehId);
	int foundIndex=-1;
	for(int i=0;i<totalVehicles;i++)
	{
		if(tempVehId==vehId[i])
		{
			foundIndex=i;
			cout<<"\n\t\tVehicle Details"<<endl;
			cout<<"\t\tVehicle ID:"<<vehId[i]<<endl;
			cout<<"\t\tVehicle Name:"<<vehName[i]<<endl;
			cout<<"\t\tVehicle Identification Number:"<<vehNumber[i]<<endl;
			cout<<"\t\tVehicle Status: Available"<<endl;
			cout<<"\t\tVehicle  Daily Rent:"<<vehRent[i]<<endl;
			}
	}
	if(foundIndex==-1)
	{
		cout<<"\t--------------------------------------------------"<<endl;
		cout<<"\t--------------------------------------------------"<<endl;
		cout<<"\n\t\tVehicle Not Found. Try Again"<<endl;
		returnMenu();
	}
	int customerIndex=-1;
	for(int i=0;i<totalCustomers;i++)
	{
    	if(customerVehicle[i] == foundIndex)
    	{
    	   	customerIndex=i;
    	    break;
    	}
	}
	if(customerIndex == -1)
	{
    	cout<<"\t\tNo Customer Found For This Vehicle."<<endl;
    	adminPortal();
    	return;
	}
	if(isVehAvailable[foundIndex] == true)
	{
		char option;
		cout<<"\t\tVehicle is Rented."<<endl;
		cout<<"\t\tDo You Wish To Return the vehicle Y/N:"<<endl;
		cin>>option;
		
		if(option=='y'||option=='Y')
		{
			cout<<"\t\tVehicle Returning...."<<endl;
			cout<<"\t\tYou Owe:"<<rentAmount[customerIndex]<<" Rs."<<endl;
			payRent(foundIndex,customerIndex);
			adminPortal();
		}
		else if(option=='n'||option=='N'){
			cout<<"\t\tYou Owe:"<<rentAmount[customerIndex]<<" Rs."<<endl;
			adminPortal();
		}
		else{
			cout<<"\t\tInvalid Option. Select only Y/N or y/n..."<<endl;
			returnMenu();
		}
	}
	else{
		cout<<"\t\tVehicle is'nt  Rented.."<<endl;
		adminPortal();
	}
}	
}

void payRent(int vehicleIndex, int customerIndex){
	char option;
    cout<<"\n\t\tDo You Want To Pay The Rent:";
    cin>>option;
    if(option=='y'||option=='Y')
    {
        cout<<"\t\tPaying Rent..."<<endl;
        float howMuch;
        cout<<"\t\tEnter Amount:";
        cin>>howMuch;
        if(howMuch != rentAmount[customerIndex])
        {
        	cout<<"\t\tIncorrect Amount."<<endl;
            cout<<"\t\tYou Owe:"<<rentAmount[customerIndex]<<" Rs."<<endl;
            adminPortal();
        }
        else
        {
            businessRevenue += rentAmount[customerIndex];
            rentAmount[customerIndex] = 0.0;
            days[customerIndex] = 0;
            vehAvailable++;
            vehRented--;
            isVehAvailable[vehicleIndex] = false;
            isCusAvailable[customerIndex] = false;
            customerVehicle[customerIndex] = -1;
            adminPortal();
        }
    }
    else if(option=='n'||option=='N')
    {
        cout<<"\t\tYou Owe:"<<rentAmount[customerIndex]<<" Rs."<<endl;
        adminPortal();
    }
    else
    {
        cout<<"\t\tInvalid Option. Select only Y/N or y/n."<<endl;
        payRent(vehicleIndex,customerIndex);
    }
}

void transactionMenu(){
	cout<<"\t--------------------------------------------------"<<endl;
	cout<<"\t--------------------------------------------------"<<endl;
	cout<<"\n\t\tBusiness Revenue :"<<businessRevenue<<endl;
	adminPortal();
}

void saveMenu(){
	cout<<"\t--------------------------------------------------"<<endl;
	cout<<"\t--------------------------------------------------"<<endl;
	saveCusDetails();
	saveVehDetails();
    saveRevenue();
    cout<<"\t\tData Saved Successfully."<<endl;
	mainMenu();
}

void saveCusDetails(){
	ofstream out("RegisteredCustomers.txt");
	if(out.is_open()){
		for(int i=0;i<totalCustomers;i++)
		{
	out<<cusName[i]<<endl;
	out<<cusPhone[i]<<endl;
	out<<cusEmail[i]<<endl;
	out<<cusUsername[i]<<endl;
	out<<cusPassword[i]<<endl;
	out<<isCusAvailable[i]<<endl;
	out << customerVehicle[i] <<endl;
	out<<days[i]<<endl;
	out << rentAmount[i] << endl <<endl;
	}
	out.close();
	}
	else{
		cout<<"File not present. Data not saved."<<endl;
	}
}

void saveVehDetails(){
	ofstream out("RegisteredVehicles.txt");
	if(out.is_open()){
		for(int i=0;i<totalVehicles;i++)
		{
	out<<vehId[i]<<endl;
	out<<vehName[i]<<endl;
	out<<vehNumber[i]<<endl;
	out<<isVehAvailable[i]<<endl;
	out<<vehRent[i]<<endl<<endl;
	}
	out.close();
	}
	else{
		cout<<"File not present. Data not saved."<<endl;
	}
}

void loadCusData(){
    ifstream in("RegisteredCustomers.txt");
    if(in.is_open()){
        totalCustomers = 0;
        while(totalCustomers < 10 && getline(in, cusName[totalCustomers]))
        {
            if(cusName[totalCustomers] == "")
                continue;
            getline(in, cusPhone[totalCustomers]);
            getline(in, cusEmail[totalCustomers]);
            getline(in, cusUsername[totalCustomers]);
            getline(in, cusPassword[totalCustomers]);
            int status;
            in >> status;
            isCusAvailable[totalCustomers] = status;
            in.ignore();
            in >> customerVehicle[totalCustomers];
			in.ignore();
			in >> days[totalCustomers];
			in.ignore();
			in >> rentAmount[totalCustomers];
			in.ignore();
            totalCustomers++;
        }
        in.close();
    }
    else{
        totalCustomers = 0;
    }
}

void loadVehData(){
    ifstream in("RegisteredVehicles.txt");
    if(in.is_open()){
        totalVehicles=0;
        vehAvailable=0;
        vehRented=0;
        while(totalVehicles < 10 && getline(in, vehId[totalVehicles]))
        {
            if(vehId[totalVehicles] == "")
                continue;
            getline(in, vehName[totalVehicles]);
            getline(in, vehNumber[totalVehicles]);
			int status;
			in >> status;
			isVehAvailable[totalVehicles] = status;
			in.ignore();
            getline(in, vehRent[totalVehicles]);
            if(isVehAvailable[totalVehicles] == false)
            {
                vehAvailable++;
            }
            else
            {
                vehRented++;
            }

            totalVehicles++;
        }
        in.close();
    }
    else{
        totalVehicles = 0;
    }
}

void saveRevenue(){
	ofstream out("Revenue.txt");
	out<<businessRevenue<<endl<<endl;
}

void loadRevenue(){
	ifstream in("Revenue.txt");
	in>>businessRevenue;
}

// INT MAIN FUNCTION
int main(){
	cout<<"\t\tVehicle Rental System"<<endl;
	cout<<"\t\tA C++ Console Based Program\n\n"<<endl;
	loadCusData();
	loadVehData();
	loadRevenue();
	mainMenu();
	return 0;
}
