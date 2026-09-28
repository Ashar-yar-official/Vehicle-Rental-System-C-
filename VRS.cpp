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
		cout<<"\t\t1. Customer Portal"<<endl;
		cout<<"\t\t2. Admin Portal"<<endl;
		cout<<"\t\t3. Exit\n"<<endl;
		int option;
		cout<<"\t\tEnter:";
		cin>>option;
		
		if(option==1)
		{
			cout<<"\n\t\tCustomer Portal"<<endl;
			customerMenu();
		}
		else if(option==2)
		{
			cout<<"\n\t\tAdmin Portal"<<endl;
			adminMenu();
		}
		else if(option==3)
		{
			cout<<"\t\tProgram Ended......."<<endl;
		}
		else{
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
				cout<<"\t\tEnter Your Credentials"<<endl;
				cusLogin();
			}
			else if(option==2){
				cout<<"\t\tEnter Details"<<endl;
				cusRegister();
			}
			else if(option==3)
			{
				mainMenu();
			}
			else{
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
			cout<<"\t\tAcess Granted....."<<endl;
			cusPortal(foundIndex);
		}
	}
	if(foundIndex==-1){
		cout<<"\t\tAcess Denied....."<<endl;
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
		}	
	}
	cout<<"\t\tEnter Phone Number:";
	getline(cin,cusPhone[totalCustomers]);
	cout<<"\t\tEnter Email:";
	getline(cin,cusEmail[totalCustomers]);
	cusUsername[totalCustomers]=cusEmail[totalCustomers];
	cout<<"\t\tSelect Password:";
	getline(cin,cusPassword[totalCustomers]);
	totalCustomers++;
		
	customerMenu();	
	}
	
	
}
void cusPortal(int foundIndex){
	if(totalCustomers==0)
	{
		cout<<"\t\tNo Customers on Portal"<<endl;
		customerMenu();
	}
	else{
		cout<<"\t\tCustomer Details....."<<endl;
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
			rentVehicle(foundIndex,found);
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
		cout<<"\t\tCustomer Management"<<endl;
		cusManagement();
	}
	else if(option==2)
	{
		cout<<"\t\tVehicle Management"<<endl;
		vehManagement();
	}
	else if(option==3)
	{
		cout<<"\t\tRent Vehicle"<<endl;
		rentMenu();
	}
	else if(option==4)
	{
		cout<<"\t\tReturn Vehicle"<<endl;
		returnMenu();
	}
	else if(option==5)
	{
		cout<<"\t\tTransaction Details"<<endl;
		transactionMenu();
	}
	else if(option==6)
	{
		cout<<"\t\tSave and exit"<<endl;
		saveMenu();
	}
	else{
		cout<<"\t\tInvalid Option Select Only 1,2,3,4,5 and 6"<<endl;
		adminPortal();
	}
}
void cusManagement(){
	cout<<"\n\n\t\t1.Customer Details"<<endl;
	cout<<"\t\t2. Customer Registration"<<endl;
	cout<<"\t\t3. Search Customer"<<endl;
	cout<<"\t\t4. Back"<<endl;
	
	int option;
	cout<<"\t\tEnter:";
	cin>>option;
	
	if(option==1)
	{
		cout<<"\t\tCustomer Details"<<endl;
		cusDetails();
	}
	else if(option==2)
	{
		cout<<"\t\tCustomer Registration"<<endl;
		cusRegAdmin();
	}
	else if(option==3)
	{
		cout<<"\t\tSearch Customer"<<endl;
		cusSearch();
	}
	else if(option==4)
	{
		adminPortal();
	}
	else{
		cout<<"\t\tInvalid OPtion Select only 1,2,3 and 4"<<endl;
		cusManagement();
	}
}
void cusDetails(){
	if(totalCustomers==0)
	{
		cout<<"\t\tNo CUstomers On Portal"<<endl;
		cusManagement();
	}
	else{
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
		cout<<"\t\tMaximum Number Of Customers Registered"<<endl;
		cusManagement();
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
			cusRegAdmin();
		}	
	}
	cout<<"\t\tEnter Phone Number:";
	getline(cin,cusPhone[totalCustomers]);
	cout<<"\t\tEnter Email:";
	getline(cin,cusEmail[totalCustomers]);
	cusUsername[totalCustomers]=cusEmail[totalCustomers];
	cout<<"\t\tSelect Password:";
	getline(cin,cusPassword[totalCustomers]);
	totalCustomers++;
	
	cusManagement();
	}
	
}
void cusSearch(){
	if(totalCustomers==0)
	{
		cout<<"\t\tNo Customers On Portal"<<endl;
		cusManagement();
	}
	else{
		cin.ignore();
	string sEmail;
	cout<<"\t\tEnter Customer Email:";
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
			cusManagement();
		}
	}
	cusManagement();
	if(foundIndex==-1)
	{
		cout<<"\t\tCustomer Not Found. Retry!"<<endl;
		cusSearch();
	}
}
	
}
void vehManagement(){
	cout<<"\t\t\n\n1. Vehicle Details"<<endl;
	cout<<"\t\t2. Vehicle Registration"<<endl;
	cout<<"\t\t3. View Available Vehicles"<<endl;
	cout<<"\t\t4. View Rented Vehicles"<<endl;
	cout<<"\t\t5. Search Vehicle"<<endl;
	cout<<"\t\t6. Back"<<endl;
	
	int option;
	cout<<"Enter:";
	cin>>option;
	
	if(option==1)
	{
		cout<<"\t\tVehicle Details"<<endl;
		vehDetails();
	}
	else if(option==2)
	{
		cout<<"\t\tVehicle Registration"<<endl;
		vehRegister();
	}
	else if(option==3)
	{
		cout<<"\t\tAvailable Vehicles"<<endl;
		vehAvailability();
	}
	else if(option==4)
	{
		cout<<"\t\tRented Vehicles"<<endl;
		vehRentility();
	}
	else if(option==5)
	{
		cout<<"\t\tSearch Vehicle"<<endl;
		vehSearch();
	}
	else if(option==6)
	{
		adminPortal();	
	}
	else {
		cout<<"\t\tInvalid Option Select Only 1,2,3,4,5 and 6"<<endl;
		vehManagement();
	}
}
void vehDetails(){
	for(int i=0;i<totalVehicles;i++)
	{
		cout<<"\t\tVehicle "<<i+1<<" Details"<<endl;
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
		cout<<"\t\tMaximum Number Of Vehicles Registered"<<endl;
		vehManagement();
	}
	else
	{
		cin.ignore();
	cout<<"\t\tVehicle Name:"<<"VEH-"<<totalVehicles+1<<endl;
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
		}	
	}
	isVehAvailable[totalVehicles] = false;
	cout<<"\t\tVehicle Status: Available"<<endl;
	cout<<"\t\tEnter Vehicle Rent:";
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
		cout<<"\t\tVehicle"<<i+1<<" Details"<<endl;
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
	
	if(foundIndex==-1)
	{
		cout<<"\t\tNo Available Cars"<<endl;
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
		cout<<"\t\tVehicle "<<i+1<<" Details"<<endl;
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
	
	if(foundIndex==-1)
	{
		cout<<"\t\tNo Rented Cars"<<endl;
		vehManagement();
	}
	vehManagement();
}
void vehSearch(){
	if(totalVehicles==0)
	{
		cout<<"\t\tNo Vehicles On Portal"<<endl;
		vehManagement();
	}
	else{
		cin.ignore();
	string tempId;
	cout<<"\t\tEnter Vehicle ID:";
	getline(cin,tempId);
	
	int foundIndex=-1;
	for(int i=0;i<totalVehicles;i++)
	{
		if(tempId==vehId[i])
		{
			foundIndex=i;
			cout<<"\t\tVehicle Id:"<<vehId[i]<<endl;
			cout<<"\t\tVehicle Name:"<<vehName[i]<<endl;
			cout<<"\t\tVehicle Identification Number:"<<vehNumber[i]<<endl;
			if (isVehAvailable[totalVehicles] == false)
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
		cout<<"\t\tVehicle Not Found. Retry!"<<endl;
		vehSearch();
	}
}
}
void rentMenu(){
	if(totalVehicles==0)
	{
		cout<<"\t\tNo Vehicles On Portal"<<endl;
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
		cout<<"\t\tVehicle "<<i+1<<" Details"<<endl;
		cout<<"\t\tVehicle ID:"<<vehId[i]<<endl;
		cout<<"\t\tVehicle Name:"<<vehName[i]<<endl;
		cout<<"\t\tVehicle Registration Number:"<<vehNumber[i]<<endl;
		if (isVehAvailable[totalVehicles] == false)
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
	cout<<"\t\tEnter Customer Name:";
	getline(cin,tempCusName);
	
	int foundIndex=-1;
	for(int i=0;i<totalCustomers;i++)
	{
		if(tempCusName==cusName[i])
		{
			foundIndex=i;
			cout<<"\t\tCustomer "<<i+1<<"Details"<<endl;
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
		cout<<"\t\tCustomer Not Found. Try Again."<<endl;
		rentToCustomer();
	}
	cin.ignore();
	string tempVehId;
	cout<<"\t\tEnter Vehicle ID:";
	getline(cin,tempVehId);
	
	int found=-1;
	for(int i=0;i<totalVehicles;i++)
	{
		if(tempVehId==vehId[i])
		{
			found=i;
			cout<<"\t\tVehicle "<<i+1<<" Details"<<endl;
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
	if(found==-1)
	{
		cout<<"\t\tVehicle Not Found. Try Again"<<endl;
		rentToCustomer();
	}
	cin.ignore();
	char option;
	cout<<"\t\tChoose you want to rent this car Y/N:";
	cin>>option;
	
	if(option=='y'||option=='Y')
	{
		cout<<"\t\tProceed"<<endl;
		cout<<"\t\tNumber of days you want to rent:";
		cin>>days[foundIndex];
		rentAmount[foundIndex]=stof(vehRent[found])*days[found];
		rentVehicle(foundIndex,found);
		adminPortal();
	}
	else if(option=='n'||option=='N'){
		cout<<"\t\tCancelled..."<<endl;
		rentToCustomer();
	}
	
	
}
void rentVehicle(int foundIndex,int found){
	cout<<"\t\tVehicle Renting......"<<endl;
	cout<<"\t\tVehicle ID:"<<vehId[found]<<endl;
	cout<<"\t\tVehicle Name:"<<vehName[found]<<endl;
	cout<<"\t\tVehicle Identification Number:"<<vehNumber[found]<<endl;
	cout<<"\t\tVehicle Daily Rent:"<<vehRent[found]<<endl;
	cout<<"\t\tNumber of Rent days:"<<days[foundIndex]<<endl;
	cout<<"\t\tYou Owe:"<<rentAmount[foundIndex]<<" Rs."<<endl;
	isVehAvailable[found]=true;
	customerVehicle[foundIndex] = found;
	vehAvailable--;
    vehRented++;
	isCusAvailable[foundIndex]=true;
	
	
}

void returnMenu(){
	if(vehRented==0)
	{
		cout<<"\t\tNo Vehicles Rented."<<endl;
		adminPortal();
	}
	else{
		cin.ignore();
	string tempVehId;
	cout<<"\t\tEnter Vehicle Number:";
	getline(cin,tempVehId);
	
	int foundIndex=-1;
	for(int i=0;i<totalVehicles;i++)
	{
		if(tempVehId==vehId[i])
		{
			foundIndex=i;
			cout<<"\t\tVehicle Details"<<endl;
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
	if(foundIndex==-1)
	{
		cout<<"\t\tVehicle Not Found. Try Again"<<endl;
		returnMenu();
	}
	if(isVehAvailable[foundIndex] == true)
	{
		char option;
		cout<<"\t\tVehicle is Rented."<<endl;
		cout<<"\t\tDo You Wish To Return the vehicle Y/N:"<<endl;
		cin>>option;
		
		if(option=='y'||option=='Y')
		{
			cout<<"\t\tVehicle Returned...."<<endl;
			cout<<"\t\tYou Owe:"<<rentAmount[foundIndex]<<" Rs."<<endl;
			payRent(foundIndex);
			adminPortal();
		}
		else if(option=='n'||option=='N'){
			cout<<"\t\tYou Owe:"<<rentAmount[foundIndex]<<" Rs."<<endl;
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
void payRent(int foundIndex){
	char option;
	cout<<"\t\tDo You Want To Pay The Rent:";
	cin>>option;
	
	if(option=='y'||option=='Y')
	{
		cout<<"\t\tPaying Rent..."<<endl;
		float howMuch;
		cout<<"\t\tEnter Amount:";
		cin>>howMuch;
		
		if(howMuch>rentAmount[foundIndex]||howMuch<rentAmount[foundIndex])
		{
			cout<<"\t\tYou Owe:"<<rentAmount[foundIndex]<<" Rs."<<endl;
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
		cout<<"\t\tYou Owe:"<<rentAmount[foundIndex]<<" Rs."<<endl;
		adminPortal();
	}
	else {
		cout<<"\t\tInvalid Option. Select only Y/N or y/n."<<endl;
		payRent(foundIndex);
	}
}

void transactionMenu(){
	cout<<"\t\tBusiness Revenue :"<<businessRevenue<<endl;
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
