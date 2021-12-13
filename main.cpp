#include <iostream>
#include <stdlib.h>
#include <fstream>
#include<stdio.h>
#include<windows.h>
#include <sstream>
#include <conio.h>
#include <process.h>

using namespace std;

int year,month,day,leap;//global variable to determine day month and year

int noInventory;//global function to calculate the number of items in inventory

typedef struct {//user define structure for admin
    string name;//username for admin
    string password;//password for admin
}Admin;

typedef struct{//user define structure for salesman
    string name;//username for salesman
    string password;//password for salesman
}Salesman;

Admin fiveAdmin[5];//declare UDS of array size 5
Salesman tenSalesman[10];//define UDS of array size 10

typedef struct{//user define structure for inventory system
    string name;//declare as a phrase
    int ID;//declare as a whole number
    float price;//declare as a monetary value
    string manufacture;//declare as a string
    int quantity;//declare as a whole number
    int expDay;//declare as a whole number
    int expMonth;//declare as a whole number
    int expYear;//declare as a whole number
    string location;//declare as a string
    string type;//declare as a string
}Inventory;//name of UDS
Inventory store[100];//call inventory

void checkExpire()//function to give 5% discount if it is 5 day or less left
{
    int difference,left,monthDiff,yearDiff,monthCheck;//declare as a whole number
    for (int i=0;i<noInventory;i++){//loop for no of inventory times
    if (store[i].expYear==year){//if inventory expire year matches with the year today
        if (store[i].expMonth==month){//if inventory expire month matches with the month today
            left=store[i].expDay-day;//find the difference of days
            difference=5-left;
            if (left<=5&&left>0){//if difference is between 1 to 5
                if (store[i].type=="Food"||store[i].type=="Grocery Product"||store[i].type=="Bakery"||store[i].type=="Raw Flesh"||store[i].type=="Prepared Food"){//if product is this type
                for(int j=0;j<difference;j++){//loop for the number of days left
                    store[i].price=store[i].price*95/100;}}}//apply 5% discount
            if (left<=0){//if product is expired
                if (store[i].type=="Food"||store[i].type=="Grocery Product"||store[i].type=="Bakery"||store[i].type=="Raw Flesh"||store[i].type=="Prepared Food")//if product is this type
                store[i].quantity=0;//set quantity to 0
            }
        }
        else if (store[i].expMonth>month){
            monthDiff=store[i].expMonth-month;
            if (monthDiff==1){
                switch (month){
                    case 1:
                    case 3:
                    case 5:
                    case 7:
                    case 8:
                    case 10:
                    case 12:
                        left=(31-day)+store[i].expDay;
                        difference=5-left;
                        if (left<=5&&left>0){//if difference is between 1 to 5
                            if (store[i].type=="Food"||store[i].type=="Grocery Product"||store[i].type=="Bakery"||store[i].type=="Raw Flesh"||store[i].type=="Prepared Food"){//if product is this type
                                for(int j=0;j<difference;j++){//loop for the number of days left
                                    store[i].price=store[i].price*95/100;}}}//apply 5% discount
                        if (left<=0){//if product is expired
                            if (store[i].type=="Food"||store[i].type=="Grocery Product"||store[i].type=="Bakery"||store[i].type=="Raw Flesh"||store[i].type=="Prepared Food")//if product is this type
                            store[i].quantity=0;//set quantity to 0
                        }
                        break;
                    case 2:
                        left=(28+leap-day)+store[i].expDay;
                        difference=5-left;
                        if (left<=5&&left>0){//if difference is between 1 to 5
                            if (store[i].type=="Food"||store[i].type=="Grocery Product"||store[i].type=="Bakery"||store[i].type=="Raw Flesh"||store[i].type=="Prepared Food"){//if product is this type
                                for(int j=0;j<difference;j++){//loop for the number of days left
                                    store[i].price=store[i].price*95/100;}}}//apply 5% discount
                        if (left<=0){//if product is expired
                            if (store[i].type=="Food"||store[i].type=="Grocery Product"||store[i].type=="Bakery"||store[i].type=="Raw Flesh"||store[i].type=="Prepared Food")//if product is this type
                            store[i].quantity=0;//set quantity to 0
                        }
                        break;
                    case 4:
                    case 6:
                    case 9:
                    case 11:
                        left=(30-day)+store[i].expDay;
                        difference=5-left;
                        if (left<=5&&left>0){//if difference is between 1 to 5
                            if (store[i].type=="Food"||store[i].type=="Grocery Product"||store[i].type=="Bakery"||store[i].type=="Raw Flesh"||store[i].type=="Prepared Food"){//if product is this type
                                for(int j=0;j<difference;j++){//loop for the number of days left
                                    store[i].price=store[i].price*95/100;}}}//apply 5% discount
                        if (left<=0){//if product is expired
                            if (store[i].type=="Food"||store[i].type=="Grocery Product"||store[i].type=="Bakery"||store[i].type=="Raw Flesh"||store[i].type=="Prepared Food")//if product is this type
                            store[i].quantity=0;//set quantity to 0
                        }
                        break;
                }

            }

        }
        }
         if (store[i].expYear>year){
            yearDiff=store[i].expYear-year;
            if (yearDiff==1){
                monthCheck=month-store[i].expMonth;
                Sleep(1000);
                  if (monthCheck==11){
                        left=(31-day)+store[i].expDay;
                        difference=5-left;
                        if (left<=5&&left>0){//if difference is between 1 to 5
                            if (store[i].type=="Food"||store[i].type=="Grocery Product"||store[i].type=="Bakery"||store[i].type=="Raw Flesh"||store[i].type=="Prepared Food"){//if product is this type
                                for(int j=0;j<difference;j++){//loop for the number of days left
                                    store[i].price=store[i].price*95/100;}}}//apply 5% discount
                        if (left<=0){//if product is expired
                            if (store[i].type=="Food"||store[i].type=="Grocery Product"||store[i].type=="Bakery"||store[i].type=="Raw Flesh"||store[i].type=="Prepared Food")//if product is this type
                            store[i].quantity=0;//set quantity to 0

                        }
                         break;
                }
            }
        }
        if (year>store[i].expYear){
            if (store[i].type=="Food"||store[i].type=="Grocery Product"||store[i].type=="Bakery"||store[i].type=="Raw Flesh"||store[i].type=="Prepared Food")//if product is this type
                store[i].quantity=0;//set quantity to 0


        }

    }
}
void checkDay()
{
	int loop=0;//declare as a whole number
	char deter;//declare as a single character
	do {//loop
        deter=0;//set deter to 0
        cout<<"Enter year :";//prompt for year
        cin>>year;//get year
        if (cin.fail()||year<2019){//if invalid input or year less than 2019
            cin.clear();//clear cin
            cin.ignore();//ignore input
            cout<<"Please enter a valid year";//display enter a valid year
            Sleep(1000);//delay for 1 second
            system("CLS");//clear screen
            deter=1;//set deter to 1
        }
	}while (deter==1);//loop while deter is 1
	//leap year theory: is leap year if it can be evenly divided by 4 and 400 and cannot be divided by 100
	if((year%4==0) && (year%100!=0))
	{
		deter='L';
		leap=1;
	}
	else if((year%100==0) && (year%400==0))
	{
		deter='L';
		leap=1;
	}
	else if(year%400==0)
	{
		deter='L';
		leap=1;
	}
	else
	{
		deter='N';
		leap=0;
	}
	switch(deter){//switch statement for deter
        case 'L':{//if deter is leap year
            do{//loop
            deter=0;//set deter to 0
            system("CLS");//clear screen
            cout<<"Please enter the month : ";//prompt for month
            cin>>month;//get month
            switch (month){//switch statement for month
                //condition to check if month have 31 days
                case 1:
                case 3:
                case 5:
                case 7:
                case 8:
                case 10:
                case 12:
                    do{//loop
                        loop=0;//set loop to 0
                        system("CLS");//clear screen
                        cout<<"Please enter the day : ";//prompt for day
                        cin>>day;//get day
                        if (day<=31&&day>0){//if day is more than 0 and less or equal to 31
                            loop=0;//set loop to 0
                        }
                        if (cin.fail()||day>31||day<1){//if invalid input or day is more than 31 or less than 1
                            cin.clear();//clear cin
                            cin.ignore();//ignore input
                            cout<<"Please enter a valid day";//prompt for a valid day
                            Sleep(1000);//delay for 1 second
                            loop=1;//set loop to 1
                            system("CLS");//clear screen
                        }
                    }while (loop==1);//loop if loop is 1
                    break;
                case 2:
                    //check if month has 29 days(leap year)
                    do{//loop
                        loop=0;//set loop to 0
                        system("CLS");//clear screen
                        cout<<"Please enter the day : ";//prompt for day
                        cin>>day;//get day
                        if (day<=29&&day>0){//if day is more than 0 and less than or equal to 29
                            loop=0;//set loop to 0
                        }
                        if (cin.fail()||day>29||day<1){//if invalid input or day is more than 29 or less than 1
                            cin.clear();//clear cin
                            cin.ignore();//ignore input
                            cout<<"Please enter a valid day";//prompt for a valid day
                            Sleep(1000);//delay for 1 second
                            loop=1;//set loop to 1
                            system("CLS");//clear screen
                        }
                    }while (loop==1);//loop if loop is 1
                    break;
                //check if month has 30 days
                case 4:
                case 6:
                case 9:
                case 11:
                    do{//loop
                        loop=0;//set loop to 0
                        system("CLS");//clear screen
                        cout<<"Please enter the day : ";//prompt for day
                        cin>>day;//get day
                        if (day<=30&&day>0){//if day is more than 0 and less than or equal to 30
                            loop=0;//set loop to 0
                        }
                        if (cin.fail()||day>30||day<1){//if invalid input or day is less than 1 or more than 30
                            cin.clear();//clear cin
                            cin.ignore();//ignore input
                            cout<<"Please enter a valid day";//prompt for a valid day
                            Sleep(1000);//delay for 1 second
                            loop=1;//set loop to 1
                            system("CLS");//clear screen
                        }
                    }while (loop==1);//loop if loop is 1
                    break;
                default:{//if none of the month above
                    cin.clear();//clear cin
                    cin.ignore();//ignore input
                    cout<<"Please input a valid month";//prompt for a valid month
                    Sleep(1000);//delay for 1 second
                    system("CLS");//clear screen
                    deter=1;//set deter to 1
                    break;
                }
            }
        }while (deter==1);//loop while deter is 1
        break;
        }//end of case for leap year
    case 'N':{//if deter is not a leap year
        do{//loop
            deter=0;//set deter to 0
            system("CLS");//clear screen
            cout<<"Please enter the month : ";//prompt for the month
            cin>>month;//get month
            switch (month){//switch statement for month
                //check if month has 31 days
                case 1:
                case 3:
                case 5:
                case 7:
                case 8:
                case 10:
                case 12:
                    do{//loop
                        loop=0;//set loop to 0
                        system("CLS");//clear screen
                        cout<<"Please enter the day : ";//prompt for day
                        cin>>day;//get day
                        if (day<=31&&day>0){//if day is between 1 and 31
                            loop=0;//set loop to 0
                        }
                        if (cin.fail()||day>31||day<1){//if invalid input or day is less than 1 or more than 0
                            cin.clear();//clear cin
                            cin.ignore();//ignore input
                            cout<<"Please enter a valid day";//prompt for a valid input
                            Sleep(1000);//delay for 1 second
                            loop=1;//set loop to 1
                            system("CLS");//clear screen
                        }
                    }while (loop==1);//loop if loop is 1
                    break;
                case 2:
                //check if month has 28 days
                    do{//loop
                        loop=0;//set loop to 0
                        system("CLS");//clear screen
                        cout<<"Please enter the day : ";//prompt for day
                        cin>>day;//get day
                        if (day<=28&&day>0){//if day is between 1 and 28
                            loop=0;//set loop to 0
                        }
                        if (cin.fail()||day>28||day<1){//if invalid input or day is less than 1 or more than 28
                            cin.clear();//clear cin
                            cin.ignore();//ignore input
                            cout<<"Please enter a valid day";//prompt for a valid day
                            Sleep(1000);//delay for 1 second
                            loop=1;//set loop to 1
                            system("CLS");//clear screen
                        }
                    }while (loop==1);//loop if loop is 1
                    break;
                //check if month has 30 days
                case 4:
                case 6:
                case 9:
                case 11:
                    do{//loop
                        loop=0;//set loop to 0
                        system("CLS");//clear screen
                        cout<<"Please enter the day : ";//prompt for day
                        cin>>day;//get day
                        if (day<=30&&day>0){//if day is between 1 and 30
                            loop=0;//set day to 0
                        }
                        if (cin.fail()||day>30||day<1){//if invalid input or day is less than 1 or more than 30
                            cin.clear();//clear cin
                            cin.ignore();//ignore input
                            cout<<"Please enter a valid day";//prompt for a valid day
                            Sleep(1000);//delay for 1 second
                            loop=1;//set loop to 1
                            system("CLS");//clear screen
                        }
                    }while (loop==1);//loop if loop is 1
                    break;
                default:{//if month is neither of the value
                    cin.clear();//clear cin
                    cin.ignore();//ignore input
                    cout<<"Please input a valid month";//prompt for a valid month
                    Sleep(1000);//delay for 1 second
                    system("CLS");//clear screen
                    deter=1;//set deter to 1
                    break;
                }
            }
        }while (deter==1);//loop if deter is 1
    break;
    }
}
}

void billCode(int &bill){//bill entry code loader
    ifstream countBillCode("BillEntry.txt");//call text file
    countBillCode>>bill;//set the value in text file to bill
    countBillCode.close();//close the file
}

void fillInventory(){//void to get Inventory data from text file
    ifstream checkInventory("NoInventory.txt");//open file that contains number of items in inventory
    checkInventory>>noInventory;//get the value from text file
    checkInventory.close();//close file
    ifstream retrieveInventory("Inventory.txt");//open text file
    string convert;//string to get any string data type from text file
    for (int i=0;i<noInventory;i++){//loop noInventory times
        getline(retrieveInventory,convert);//get whole phrase
        store[i].name=convert;//get product name
        retrieveInventory>>store[i].ID;//get product id
        retrieveInventory>>store[i].price;//get product id
        retrieveInventory.ignore();//ignore cin
        getline(retrieveInventory,convert);//get whole phrase
        store[i].manufacture=convert;//get product manufacture
        retrieveInventory>>store[i].quantity;//get quantity
        retrieveInventory>>store[i].expDay;//get expiry day
        retrieveInventory>>store[i].expMonth;//get expiry month
        retrieveInventory>>store[i].expYear;//get expiry year
        retrieveInventory.ignore();//ignore cin
        getline(retrieveInventory,convert);//get the whole line to get location and store to a string variable
        store[i].location=convert;////store location in array
        getline(retrieveInventory,convert);//get the whole line to get location and store to a string variable
        store[i].type=convert;////store location in array
        retrieveInventory.ignore();//ignore cin
    }//assign value from text file to UDS
    retrieveInventory.close();//close file
}

void getAdmin(){//function to get admin details from text file
 ifstream retrieveAdmin("Admin.txt");//open file
    for (int i=0;i<5;i++){//loop 5 times
        retrieveAdmin>>fiveAdmin[i].name>>fiveAdmin[i].password;//get username and password from text file
    }
    retrieveAdmin.close();//close file
}
void getStaff(){//function to get staff details from text file
 ifstream retrieveStaff("Staff.txt");//open file
    for (int i=0;i<10;i++){//loop 10 times
        retrieveStaff>>tenSalesman[i].name>>tenSalesman[i].password;//get username and password
    }
    retrieveStaff.close();//close file
}

void loginAdmin(int &mainmenu){//function to verify Admin login
    getAdmin();//call function
    string username,password;//declare as a phrase
    int i,verify=0,deter;//declare as a whole number
    do{//loop
        system("CLS");//clear screen
        cout<<"Username : ";//prompt for Username
        cin>>username;//get Username
        cout<<"Password : ";//prompt for Password
        cin>>password;//get for Password
        for (i=0;i<5;i++){//loop 5 times
            if (username==fiveAdmin[i].name&&password==fiveAdmin[i].password){//if username and password entered matches with the user define structure sequence
                cout<<"Admin Acess Granted!";//display access granted
                Sleep(1000);//delay for 1 second
                system("CLS");//clear screen}
                verify=1;}//set verify to 1
        }
            if (verify==0){//if verify is 0
                cout<<"Invalid Input\n";//display invalid input
                Sleep(1000);//delay for 1 second
                do{//loop
                    system("CLS");//clear screen
                    cout<<"Do you want to try again?\n1.Yes\n2.No\n";//ask if user want to try again
                    cin>>deter;//get user input
                    if (deter==2){//if user input 2
                        mainmenu=4;//set mainmenu to 4
                        verify=1;//set verify to 1
                    }
                    if (cin.fail()||deter<1||deter>2){//if user enters an invalid input or enter a int less than 1 equals to 2 or more than 3
                        cin.clear();//clear cin
                        cin.ignore();//ignore input
                        deter=5;
                    }
                }while(deter==5);//loop while deter is 1
            }
    }while(verify==0);//loop while verify is 0
}

void loginStaff(string & username,int &staffselect){//function to verify Staff login
    getStaff();//call function
    string password;//declare as a phrase
    int deter,i,verify=0;//declare as a whole number
    do{//loop
        system("CLS");//clear screen
        cout<<"Username : ";//prompt for Username
        cin>>username;//get Username
        cout<<"Password : ";//prompt for Password
        cin>>password;//get for Password
        for (i=0;i<10;i++){//loop 10 times
            if (username==tenSalesman[i].name&&password==tenSalesman[i].password){//if username and password entered matches with the user define structure sequence
                cout<<"Staff Acess Granted!";//display access granted
                Sleep(1000);//delay for 1 second
                system("CLS");//clear screen}
                verify=1;}//set verify to 1
        }
        if (verify==0){//if verify is 0
            cout<<"Invalid Input\n";//display invalid input
            Sleep(1000);//delay for 1 second
            do{//loop
                system("CLS");//clear screen
                cout<<"Do you want to try again?\n1.Yes\n2.No\n";//ask if user want to try again
                cin>>deter;//get user input
                if (deter==2){//if user input 2
                    staffselect=3;//set staff select to 3
                    verify=1;//set verify to 1
                }
                if (cin.fail()||deter<1||deter>2){//if user enters an invalid input or enter a int less than 1 equals to 2 or more than 3
                    cin.clear();//clear cin
                    cin.ignore();//ignore input
                    deter=5;
                }
            }while(deter==5);//loop while deter is 1
        }
    }while(verify==0);//loop while verify is 0
}

void option(int &select){//function to prompt for access level
    select=0;//set select to 0
    do{//loop
        system("CLS");//clear screen
        cout<<"Access Level:\n1.Admin\n2.Salesman\n3.Exit\n";//Prompt for access level
        cin>>select;//get select
        if (cin.fail()||select<1||select>3){//if select is a not a integer or not 1 or 2
            cin.clear();//clear select
            cin.ignore();//ignore input
            cout<<"Invalid Input";//display invalid input
            Sleep(1000);//delay for 1 seconds
        }
    }while (select<1||select>3);//loop while select is not 1 or 2
}

void adminOption(int &admin){//display admin options
int check;//set as whole number
    do{//loop
        check=0;//set check to 0
        cout<<"Please choose an option\n";//display options
        cout<<"1.View Inventory\n";
        cout<<"2.Update Inventory\n";
        cout<<"3.Locate Item\n";
        cout<<"4.Logout\n";
        cin>>admin;//get option
        if (cin.fail()||admin<1||admin>4){//if invalid input or admin is less than 1 or more than 4
            cin.clear();//clear cin
            cin.ignore();//ignore input
            cout<<"Invalid Input";//display invalid input
            Sleep(1000);//delay for 1 second
            system("CLS");//clear screen
            check=1;//set check to 1
        }
    }while (check==1);//loop while check is 1
}

void locateProduct(){//void to locate product
        int iD,deter=0;//declare as a whole number
    do{//loop
    system("CLS");//clear screen
    cout<<"Please enter the product ID: ";//prompt for user ID
    cin>>iD;//get ID
    for (int i=0;i<noInventory;i++){//loop noInventory times
        if (store[i].ID==iD){//if store id matches with id user entered
            cout<<store[i].location;//output location
            getch();//wait for any user input
            deter=1;//set deter to 1
        }
    }
    if (cin.fail()||deter==0){//if invalid input of deter is 0
        cin.clear();//clear cin
        cin.ignore();//ignore input
        cout<<"Invalid Product ID";//display invalid id
        Sleep(1000);}//delay for 1 second
        system("CLS");//clear screen
    }while (deter==0);//loop while deter is 0
}

void removeItem(){//function to remove item from inventory
    int productID,check=0;//declare as a whole number
    do{//loop
        check=0;//set check to 0
        system("CLS");//clear screen
        for (int k=0;k<noInventory;k++){//display the option available
            cout<<"Name : "<<store[k].name<<"\n";
            cout<<"ID : "<<store[k].ID<<"\n\n";
        }
        cout<<"Please enter the Product ID to remove the Item : ";//prompt for product id
        cin>>productID;//get product id
        system("CLS");//clear screen
        for (int j=0;j<noInventory;j++){//loop to find product id
            if (productID==store[j].ID){// if id matches with the array
                store[j].quantity=0;//set quantity to 0
                ofstream updateInventory("Inventory.txt");//output text file
                for (int i=0;i<noInventory;i++){//loop until value is no Inventory
                    if (store[i].quantity==0){}//if quantity is 0 system will not output anything
                    else{//else output the entire UDS into the text file
                        updateInventory<<store[i].name<<"\n"<<store[i].ID<<"\n"<<store[i].price<<"\n"<<store[i].manufacture<<"\n"<<store[i].quantity<<"\n"<<store[i].expDay<<"\n"<<store[i].expMonth<<"\n"<<store[i].expYear<<"\n"<<store[i].location<<"\n"<<store[i].type<<"\n\n";
                        check=1;//set check to 1 to exit loop
                    }
                }//assign new values to inventory text file
                updateInventory.close();//close inventory file
                ofstream checkInventory("NoInventory.txt");//open text file
                noInventory=noInventory-1;//minus 1 item from inventory
                checkInventory<<noInventory;//write the new value in text file
                checkInventory.close();//close text file
                fillInventory();//update inventory
            }
        }
        if (cin.fail()||check==0){//if invalid input or cin fails
            cin.clear();//clear cin
            cin.ignore();//ignore input
            cout<<"Please enter a valid Product ID\n";//display invalid ID
            Sleep(1000);//delay for 1 second
        }
    }while (check==0);//loop while check is 0
}

void checkExp(int&expYear,int&expMonth,int&expDay)
{
	int loop=0;//declare as a whole number
	char deter;//declare as a single character
	do {//loop
        deter=0;//set deter to 0
        cout<<"Enter year :";//prompt for year
        cin>>expYear;//get year
        if (cin.fail()||expYear<2019){//if invalid input or year less than 2019
            cin.clear();//clear cin
            cin.ignore();//ignore input
            cout<<"Please enter a valid year";//display enter a valid year
            Sleep(1000);//delay for 1 second
            system("CLS");//clear screen
            deter=1;//set deter to 1
        }
	}while (deter==1);//loop while deter is 1
	//leap year theory: is leap year if it can be evenly divided by 4 and 400 and cannot be divided by 100
	if((expYear%4==0) && (expYear%100!=0))
	{
		deter='L';
	}
	else if((expYear%100==0) && (expYear%400==0))
	{
		deter='L';
	}
	else if(expYear%400==0)
	{
		deter='L';
	}
	else
	{
		deter='N';
	}
	switch(deter){//switch statement for deter
        case 'L':{//if deter is leap year
            do{//loop
            deter=0;//set deter to 0
            system("CLS");//clear screen
            cout<<"Please enter the month : ";//prompt for month
            cin>>expMonth;//get month
            switch (expMonth){//switch statement for month
                //condition to check if month have 31 days
                case 1:
                case 3:
                case 5:
                case 7:
                case 8:
                case 10:
                case 12:
                    do{//loop
                        loop=0;//set loop to 0
                        system("CLS");//clear screen
                        cout<<"Please enter the day : ";//prompt for day
                        cin>>expDay;//get day
                        if (expDay<=31&&expDay>0){//if day is more than 0 and less or equal to 31
                            loop=0;//set loop to 0
                        }
                        if (cin.fail()||expDay>31||expDay<1){//if invalid input or day is more than 31 or less than 1
                            cin.clear();//clear cin
                            cin.ignore();//ignore input
                            cout<<"Please enter a valid day";//prompt for a valid day
                            Sleep(1000);//delay for 1 second
                            loop=1;//set loop to 1
                            system("CLS");//clear screen
                        }
                    }while (loop==1);//loop if loop is 1
                    break;
                case 2:
                    //check if month has 29 days(leap year)
                    do{//loop
                        loop=0;//set loop to 0
                        system("CLS");//clear screen
                        cout<<"Please enter the day : ";//prompt for day
                        cin>>expDay;//get day
                        if (expDay<=29&&expDay>0){//if day is more than 0 and less than or equal to 29
                            loop=0;//set loop to 0
                        }
                        if (cin.fail()||expDay>29||expDay<1){//if invalid input or day is more than 29 or less than 1
                            cin.clear();//clear cin
                            cin.ignore();//ignore input
                            cout<<"Please enter a valid day";//prompt for a valid day
                            Sleep(1000);//delay for 1 second
                            loop=1;//set loop to 1
                            system("CLS");//clear screen
                        }
                    }while (loop==1);//loop if loop is 1
                    break;
                //check if month has 30 days
                case 4:
                case 6:
                case 9:
                case 11:
                    do{//loop
                        loop=0;//set loop to 0
                        system("CLS");//clear screen
                        cout<<"Please enter the day : ";//prompt for day
                        cin>>expDay;//get day
                        if (expDay<=30&&expDay>0){//if day is more than 0 and less than or equal to 30
                            loop=0;//set loop to 0
                        }
                        if (cin.fail()||expDay>30||expDay<1){//if invalid input or day is less than 1 or more than 30
                            cin.clear();//clear cin
                            cin.ignore();//ignore input
                            cout<<"Please enter a valid day";//prompt for a valid day
                            Sleep(1000);//delay for 1 second
                            loop=1;//set loop to 1
                            system("CLS");//clear screen
                        }
                    }while (loop==1);//loop if loop is 1
                    break;
                default:{//if none of the month above
                    cin.clear();//clear cin
                    cin.ignore();//ignore input
                    cout<<"Please input a valid month";//prompt for a valid month
                    Sleep(1000);//delay for 1 second
                    system("CLS");//clear screen
                    deter=1;//set deter to 1
                    break;
                }
            }
        }while (deter==1);//loop while deter is 1
        break;
        }//end of case for leap year
    case 'N':{//if deter is not a leap year
        do{//loop
            deter=0;//set deter to 0
            system("CLS");//clear screen
            cout<<"Please enter the month : ";//prompt for the month
            cin>>expMonth;//get month
            switch (expMonth){//switch statement for month
                //check if month has 31 days
                case 1:
                case 3:
                case 5:
                case 7:
                case 8:
                case 10:
                case 12:
                    do{//loop
                        loop=0;//set loop to 0
                        system("CLS");//clear screen
                        cout<<"Please enter the day : ";//prompt for day
                        cin>>expDay;//get day
                        if (expDay<=31&&expDay>0){//if day is between 1 and 31
                            loop=0;//set loop to 0
                        }
                        if (cin.fail()||expDay>31||expDay<1){//if invalid input or day is less than 1 or more than 0
                            cin.clear();//clear cin
                            cin.ignore();//ignore input
                            cout<<"Please enter a valid day";//prompt for a valid input
                            Sleep(1000);//delay for 1 second
                            loop=1;//set loop to 1
                            system("CLS");//clear screen
                        }
                    }while (loop==1);//loop if loop is 1
                    break;
                case 2:
                //check if month has 28 days
                    do{//loop
                        loop=0;//set loop to 0
                        system("CLS");//clear screen
                        cout<<"Please enter the day : ";//prompt for day
                        cin>>expDay;//get day
                        if (expDay<=28&&expDay>0){//if day is between 1 and 28
                            loop=0;//set loop to 0
                        }
                        if (cin.fail()||expDay>28||expDay<1){//if invalid input or day is less than 1 or more than 28
                            cin.clear();//clear cin
                            cin.ignore();//ignore input
                            cout<<"Please enter a valid day";//prompt for a valid day
                            Sleep(1000);//delay for 1 second
                            loop=1;//set loop to 1
                            system("CLS");//clear screen
                        }
                    }while (loop==1);//loop if loop is 1
                    break;
                //check if month has 30 days
                case 4:
                case 6:
                case 9:
                case 11:
                    do{//loop
                        loop=0;//set loop to 0
                        system("CLS");//clear screen
                        cout<<"Please enter the day : ";//prompt for day
                        cin>>expDay;//get day
                        if (expDay<=30&&expDay>0){//if day is between 1 and 30
                            loop=0;//set day to 0
                        }
                        if (cin.fail()||expDay>30||expDay<1){//if invalid input or day is less than 1 or more than 30
                            cin.clear();//clear cin
                            cin.ignore();//ignore input
                            cout<<"Please enter a valid day";//prompt for a valid day
                            Sleep(1000);//delay for 1 second
                            loop=1;//set loop to 1
                            system("CLS");//clear screen
                        }
                    }while (loop==1);//loop if loop is 1
                    break;
                default:{//if month is neither of the value
                    cin.clear();//clear cin
                    cin.ignore();//ignore input
                    cout<<"Please input a valid month";//prompt for a valid month
                    Sleep(1000);//delay for 1 second
                    system("CLS");//clear screen
                    deter=1;//set deter to 1
                    break;
                }
            }
        }while (deter==1);//loop if deter is 1
    break;
    }
}
}

void addInventory(){//function to add item to inventory
    int check=0,ID,quantity,expDay,expMonth,expYear;//set as whole number
    string name,manufacture,location,type;//set as a string
    float price;//product price
    ofstream keluar("Inventory.txt",ios::app);//append file
    system("CLS");//clear screen
        cout<<"Please enter the product name :";//prompt to enter product name
        cin.ignore();//ignore cin
        getline(cin,name);//get the whole line
        do{//loop
            check=0;//set check to 0
            cout<<"Please enter the product ID :";//prompt for product ID
            cin>>ID;//get ID
            if (cin.fail()||ID<0){//if invalid input or ID is negative
                cin.clear();//clear cin
                cin.ignore();//ignore input
                cout<<"Please enter a valid product ID";//prompt for a valid input
                Sleep(1000);//delay for 1 second
                system("CLS");//clear screen
                check=1;//set check to 1
            }
            for (int i=0;i<noInventory;i++){//loop noInventory times
                if(store[i].ID==ID){//if store ID matches with ID user input
                    cout<<"Product ID is currently taken\nPlease input another ID\n ";//Display product ID is taken
                    Sleep(1000);//delay 1 second
                    system("CLS");//clear screen
                    check=1;//set check to 1
                }
            }
        }while(check==1);//loop while check is 1
        do{//loop
            check=0;//set check to 0
            cout<<"Please enter the product price :";//prompt for product price
            cin>>price;//get product price
            if (cin.fail()||price<=0){//if cin fails or price is less or equal to 0
                cin.clear();//clear cin
                cin.ignore();//ignore input
                cout<<"Please enter a valid product price";//prompt for a valid price
                Sleep(1000);//delay for 1 second
                system("CLS");//clear screen
                check=1;//set check to 1
            }
        }while(check==1);//loop while check is 1
        cout<<"Please enter the product manufacture :";//prompt for manufacterer name
        cin.ignore();//ignore input
        getline(cin,manufacture);//get the whole phrase
        do{//loop
            check=0;//set check to 0
            cout<<"Please enter the product quantity :";//prompt for product quantity
            cin>>quantity;//get product quantity
            if (cin.fail()||quantity<=0){//if invalid or negative input
                cin.clear();//clear cin
                cin.ignore();//ignore input
                cout<<"Please enter a valid quantity ";//prompt for a valid input
                Sleep(1000);//delay for 1 second
                system("CLS");//clear screen
                check=1;//set check to 1
            }
        }while(check==1);//loop while check is 1
        checkExp(expYear,expMonth,expDay);//function to get exp day month and year
        cout<<"Please enter the product location :";//prompt for product location
        cin.ignore();//ignore cin
        getline(cin,location);//get the whole phrase
        cin.ignore();//ignore cin
        cout<<"Please enter the product type :";//prompt for product type
        getline(cin,type);//get the whole phrase
        keluar<<name<<endl;//write name to file
        keluar<<ID<<endl;//output ID to text file
        keluar<<price<<endl;//output price to text file
        keluar<<manufacture<<endl;//write manufacturer name to text file
        keluar<<quantity<<endl;//write quantity to text file
        keluar<<expDay<<endl;//write expire day to text file
        keluar<<expMonth<<endl;//write expire month to text file
        keluar<<expYear<<endl;//write expire year to text file
        keluar<<location<<endl;//write location to text file
        keluar<<type<<endl<<endl;//write product type to text file
    keluar.close();//close text file
    ofstream checkInventory("NoInventory.txt");//open inventory counter text file
    noInventory=noInventory+1;//add 1 to noInventory
    checkInventory<<noInventory;//write the new value to text file
    checkInventory.close();//close text file
    fillInventory();//update text file
    system("CLS");//clear screen
}

void editProduct(){//function to edit product details
    int option,ID,check,inner;
    string location;//declare as a string
    do{//loop
        system("CLS");//clear screen
        check=0;//set check to 0
        for (int k=0;k<noInventory;k++){//display the option available
            cout<<"Name : "<<store[k].name<<"\n";
            cout<<"ID : "<<store[k].ID<<"\n\n";
        }
        cout<<"Please enter the Product ID : ";//prompt for product ID
        cin>>ID;//get product ID
        for (int i=0;i<noInventory;i++){//loop for noInventory times
            if (store[i].ID==ID){//if store in UDS matches with the ID user entered
                check=1;//set check to 1
                do{//loop
                    system("CLS");//clear screen
                    inner=0;//set inner to 0
                    cout<<"Please choose an option\n1.Change Price\n2.Change Quantity\n3.Change Location\n";//print option
                    cin>>option;//get option
                    switch (option){//case statement for option
                        case 1:{//case if option is 1
                            cout<<"Please enter the new price : RM";//prompt for new price
                            cin>>store[i].price;//overwrite the array price
                            ofstream updateInventory("Inventory.txt");//open text file
                                for (int i=0;i<noInventory;i++){//loop noInventory times
                                    updateInventory<<store[i].name<<"\n"<<store[i].ID<<"\n"<<store[i].price<<"\n"<<store[i].manufacture<<"\n"<<store[i].quantity<<"\n"<<store[i].expDay<<"\n"<<store[i].expMonth<<"\n"<<store[i].expYear<<"\n"<<store[i].location<<"\n"<<store[i].type<<"\n\n";
                                }
                                updateInventory.close();//close inventory file
                                system("CLS");//clear screen
                            break;
                        }
                        case 2:{//case if option is 2
                            cout<<"Please enter the new quantity : ";//prompt for a new quantity
                            cin>>store[i].quantity;//overwrite the array quantity
                            ofstream updateInventory("Inventory.txt");//open text file
                            for (int i=0;i<noInventory;i++){//loop noInventory times
                                updateInventory<<store[i].name<<"\n"<<store[i].ID<<"\n"<<store[i].price<<"\n"<<store[i].manufacture<<"\n"<<store[i].quantity<<"\n"<<store[i].expDay<<"\n"<<store[i].expMonth<<"\n"<<store[i].expYear<<"\n"<<store[i].location<<"\n"<<store[i].type<<"\n\n";
                                }
                                updateInventory.close();//close inventory file
                                system("CLS");//clear screen
                            break;
                        }
                        case 3:{//case if option is 3
                            cout<<"Please enter the new location : ";//prompt for a new location
                            cin.ignore();//ignore cin
                            getline(cin,store[i].location);//get the whole phrase
                            ofstream updateInventory("Inventory.txt");//open text file
                            for (int i=0;i<noInventory;i++){//loop noInventory times
                                updateInventory<<store[i].name<<"\n"<<store[i].ID<<"\n"<<store[i].price<<"\n"<<store[i].manufacture<<"\n"<<store[i].quantity<<"\n"<<store[i].expDay<<"\n"<<store[i].expMonth<<"\n"<<store[i].expYear<<"\n"<<store[i].location<<"\n"<<store[i].type<<"\n\n";
                                }
                                updateInventory.close();//close inventory file
                                system("CLS");//clear screen
                            break;
                        }
                        default:{//if none of the input above is entered
                            cin.clear();//clear cin
                            cin.ignore();//ignore input
                            cout<<"Please enter a valid input ";//prompt for a valid input
                            Sleep(1000);//delay for 1 second
                            system("CLS");//clear screen
                            inner=1;//set inner to 1
                        }
                    }
                }while (inner==1);//loop if inner is 1
            }
        }
        if (cin.fail()||ID<0||check==0){//if invalid input or ID is negative or check is 0
            cin.clear();//clear cin
            cin.ignore();//ignore input
            cout<<"Please enter a valid input ";//prompt for a valid input
            Sleep(1000);//delay for 1 second
            system("CLS");}//clear screen
        }while (check==0);//loop if check is 0
}

void updateOption(){//function to display update options
    char select;//set as a single character
    while (select!='4'){//while select is not 4
        system("CLS");//clear screen
        cout<<"1.Add Item\n";//display options
        cout<<"2.Remove Item\n";
        cout<<"3.Edit Product Details\n";
        cout<<"4.Back\n";
        cin>>select;//get select
        switch (select){//case statement for select
        case '1':{//if select is 1
            addInventory();//call addInventory function
            break;
        }
        case '2':{//if select is 2
            removeItem();//call removeItem function
            break;
        }
        case '3':{//if select is 3
            editProduct();//call editProduct function
            break;
        }
        case '4':{//if select is 4
            system("CLS");//clear screen
            break;
        }
        default:{//if select is none of the input
            cin.clear();//clear cin
            cin.ignore();//ignore input
            cout<<"Invalid Input\n";//display invalid input
            Sleep(1000);//delay for 1 second
            break;}
        }
    }
}

void staffOption(int &option){//void to prompt for staff option
    do{//loop
        system("CLS");//clear screen
        cout<<"Do you want to scan a bill or create a bill?\n1.Scan\n2.Create\n3.Exit\n";//prompt for option
        cin>>option;//get option
        if (cin.fail()||option<1||option>3){//if option is not an int or not 1 or 2
            cin.clear();//clear option
            cin.ignore();//ignore input
            cout<<"Invalid Input";//display invalid input
            Sleep(1000);//delay for 1 seconds
        }
    }while(option<1||option>3);//loop if option is not 1 or 2
}

 int calcTotal(int one,int two){//function to calculate total
        int total;//declare as a whole number
        total=one+two;//total equals one plus two
        return (total);//return the value of total
    }

void createBill(string username,float &total){//function to create bill
    int productID,quantity,i,checkout=1,validID,validQuantity,validMember=0,bill,occasion,test;//declare as a whole number
    float normal=0,food=0;//declare as a monetary value
    double discount=0;//declare as a double
    char member;//declare as 1 bit size
    billCode(bill);//get bill number using function
    bill=bill+1;//plus 1 to the current bill value to generate unique bill id
    string title, text=".txt";//declare as a string
    stringstream conversion;//to convert int to string
    ofstream makeBill;//decalre output file
    conversion<<bill;//assign bill value to conversion
    title=conversion.str();//assign title of file as conversion name
    do{//loop
        system("CLS");//clear screen
        validID=0;//set validID to 0
        validQuantity=0;//set validQuantity to 0
        system("CLS");//clear screen
        for (int k=0;k<noInventory;k++){//display the option available
            cout<<"Name : "<<store[k].name<<"\n";
            cout<<"ID : "<<store[k].ID<<"\n";
            cout<<"Available : "<<store[k].quantity<<"\n";
            cout<<"Price : "<<store[k].price<<endl<<endl;
        }
        cout<<"Please enter the product ID :";//prompt to enter product id
        cin>>productID;//get product id
        for (i=0;i<noInventory;i++){//loop twice
            if (store[i].ID==productID){//if input matches with the inventory
                validID=1;//set validate to 1
                if (validID==1){//if validate is 1
                    cout<<"Please enter the quantity : ";//prompt quantity
                    cin>>quantity;//get quantity
                        if (quantity<=0){}//if quantity is less tham 0
                        else{//if an valid amount is input
                            makeBill.open((title + text).c_str());//make file using the value of title
                            makeBill<<"Bill Code :"<<bill<<"\n";//output bill number in file
                            makeBill<<"Staff Name :"<<username<<endl;//print out staff name who created the receipt
                            makeBill<<"ProductID\tPrice Per Quantity\tProduct Name\tProduct Quantity\tTotal Price\n";//output title in file
                            if (quantity<=store[i].quantity){//if quantity entered didn't exceed the amount in inventory
                                makeBill<<productID<<"\t\t\t"<<store[i].price<<"\t\t"<<store[i].name<<"\t\t\t"<<quantity<<"\t\t"<<store[i].price*quantity<<endl;//enter the valid input to text file
                                validQuantity=1;//set validQuantity to 1
                                store[i].quantity=store[i].quantity-quantity;//update the amount in inventory
                                if (store[i].type!="Food"){//if the type of product is not food
                                    normal=normal+(store[i].price*quantity);//add up the product that is not food
                                }
                                if (store[i].type=="Food"){//if the product is food
                                    food=food+(store[i].price*quantity);//sum up the total cost for food
                                }
                            }
                            else//if the quantity exceeds the amount in inventory
                                cout<<"Quantity exceeds the amount in inventory"<<endl;//display error
                        }
                }
            }
        }
        if (validID==0||validQuantity==0||cin.fail()){//if validID is 0 or validQuantity is 0 or cin fails
            cin.clear();//clear cin
            cin.ignore();//ignore input
            cout<<"Invalid Input\nPlease try again\n";//display error
        }
        cout<<"Enter 0 to Continue and Any Key to Proceed with Checkout"<<endl;//prompt user to input again or proceed with checkout
        cin>>checkout;//get checkout
        if (cin.fail()){
            cin.clear();
            cin.ignore();
            checkout=1;
        }
        cin.ignore();
    }while (checkout==0);//loop while checkout is 0
    system("CLS");//clear screen
    total=calcTotal(normal,food);//get value of total by sending normal and food to function
    if (total>=1){
    do{
        test=0;
        discount=0;
        cout<<"Is it a Special Occasion ?\n1.Yes\n2.No\n";
        cin>>occasion;
           if (cin.fail()||occasion<1||occasion>2){
            cin.clear();
            cin.ignore();
            cout<<"Please enter a valid input";
            Sleep(1000);
            system("CLS");
            test=1;
        }
        }while (test==1);
        if(occasion==1){
            discount=rand()%10+5;}
        if (occasion==2){
        if (total>500){//if total exceeds 500
            discount=5;//allocate 5 percent discount
        }
        else if (total<=500&&total>=250){//if total is between 250 and 500
            do{//loop
                system("CLS");//clear screen
                cout<<"Do they have a membership card?"<<endl;//ask if they have membership card
                cout<<"<Y> for Yes <N> for No"<<endl;//display options
                cin>>member;//get option
                if (member=='Y'||member=='y'){//if member is y
                    validMember=1;//set valid member to 1
                    discount=2;//allocate 2 percent discount
                    if (total==500){//if total is 500
                        food=food*98/100;//allocate 2 percent discount to food only
                    }
                }
                else if (member=='N'||member=='n')//if they have no membership card
                validMember=1;//set validMember to 1
                if(validMember==0||cin.fail()){//if valid Member is 0 or error cin input
                    cin.clear();//clear cin
                    cin.ignore();//ignore input
                    cout<<"Invalid Input";//display invalid
                    Sleep(1000);//delay for 1 second
                }
            }while(validMember==0);//loop while valid Member is 0
        }
        }


    system("CLS");//clear screen
    if (discount>1){//if discount is more than 1
        total=(normal+food)*((100-discount)/100);//calculate the new total by applying the discount
        makeBill<<"You are entitled to a "<<discount<<"% discount"<<endl;//input the percentage of discount in text file
        makeBill<<"Total price is RM"<<total<<endl;//input the final price in text file
        cout<<"You are entitled to a "<<discount<<"% discount"<<endl;//display the discount
        cout<<"Total price is RM"<<total<<endl;//display the final price
    }
    else{//if discount is not more than 1
        makeBill<<"Total price is RM"<<total<<endl;//input the nett price in text file
        cout<<"Total price is RM"<<total<<endl;}//display the final price
    ofstream updateBillNo("BillEntry.txt");//open billEntry
    updateBillNo<<bill;//update the bill number
    updateBillNo.close();//close file
    makeBill.close();//close file for receipt
    ofstream updateInventory("Inventory.txt");//open inventory text file
    for (i=0;i<noInventory;i++){//loop noInventory times
       updateInventory<<store[i].name<<"\n"<<store[i].ID<<"\n"<<store[i].price<<"\n"<<store[i].manufacture<<"\n"<<store[i].quantity<<"\n"<<store[i].expDay<<"\n"<<store[i].expMonth<<"\n"<<store[i].expYear<<"\n"<<store[i].location<<"\n"<<store[i].type<<"\n\n";
    }//assign new values to inventory text file
    updateInventory.close();//close inventory file

}
}

void viewInventory(){//void to view inventory
    system("CLS");//clear screen
    string nameOfFile,content;//declare as a phrase
    for (int i=0;i<noInventory;i++){//loop noInventory times
       cout<<"Product Name: "<<store[i].name<<"\n"<<"Product ID: "<<store[i].ID<<"\n"<<"Product Price: "<<store[i].price<<"\n"<<"Product Manufacture: "<<store[i].manufacture<<"\n"<<"Product Quantity: "<<store[i].quantity<<"\n"<<"Expiry Date: "<<store[i].expDay<<"/"<<store[i].expMonth<<"/"<<store[i].expYear<<"\n"<<"Product Location: "<<store[i].location<<"\n"<<"Product Type: "<<store[i].type<<"\n\n";
    //display all items in the inventory
    }
    getch();//pause to get any user input
    }

void scanBill(){
    string nameOfFile,content;//declare as a phrase
    int check=0;//declare as a whole number
    ifstream scan;//prep to open file
    do{//loop
        system("CLS");//clear screen
        cout<<"Please enter bill ID : ";//prompt for file name
        cin>>nameOfFile;//get file name
        scan.open((nameOfFile+".txt").c_str());//open file name
            if (scan.is_open())//if file is open
            {
                check=1;//set check to 1
                while(getline(scan,content))//print every line tin the file
                {
                    cout<<content<<endl;//print out value of content
                }
                scan.close();//close file
                getch();//pause for any user input
            }
            else{
                cout<<"Invalid file name\nPlease try again";//if file is not found
                Sleep(1000);}//delay for 1 seconds
    }while (check!=1);//loop if check is not equals to 1
}

void printBill(){//function to print bill
    int bill;//declare as a whole number
    billCode(bill);//get text file name
    string title;//declare as a string
    stringstream conversion;//to convert int to string
    conversion<<bill;//assign bill value to conversion
    title=conversion.str();//assign title of file as conversion name
    system(("notepad /p "+title+".txt").c_str());//print file
    cout<<"Printing....";//display printing
    Sleep(1000);//delay for 2 second
    system("CLS");//clear screen
}

int main()
{
    int select, staffselect,billEntry,mainMenu=0;;//declare as a whole number
    float total=0;//declare as a whole number
    char newBill,printOption;//declare as a single character
    string staffName;//declare as a phrase
    fillInventory();//call function to fill in inventory
    billCode(billEntry);//function to call bill entry to print bill code
    checkDay();
    checkExpire();
    ofstream updateInventory("Inventory.txt");//open inventory text file
    for (int i=0;i<noInventory;i++){//loop noInventory times
       updateInventory<<store[i].name<<"\n"<<store[i].ID<<"\n"<<store[i].price<<"\n"<<store[i].manufacture<<"\n"<<store[i].quantity<<"\n"<<store[i].expDay<<"\n"<<store[i].expMonth<<"\n"<<store[i].expYear<<"\n"<<store[i].location<<"\n"<<store[i].type<<"\n\n";
    }//assign new values to inventory text file
    updateInventory.close();//close inventory file
    system("CLS");
    while (select!=3){//loop while select is not equals to 3
    option(select);//send to function and return value of select
    switch (select){//selection for select variable
        case 1:{//if select is 1
            loginAdmin(mainMenu);//call loginAdmin function
            while (mainMenu!=4){
                adminOption(mainMenu);
                switch (mainMenu){
                    case 1:{
                        viewInventory();
                        system("CLS");
                        break;
                    }
                    case 2:{
                        updateOption();
                        break;}
                    case 3:{
                        locateProduct();
                        break;}
                    default:{}
                }
            }
                mainMenu=0;

            break;}//break
        case 2:{//if select is 2
            loginStaff(staffName,staffselect);//call loginStaff function
            while (staffselect!=3){
            staffOption(staffselect);//call staffOption function
            switch (staffselect){//selection for staffSelect variable
                case 1:{//if staffSelect is 1
                    scanBill();//call scanBill function
                    break;
                }
                case 2:{
                    do{
                        createBill(staffName,total);//call function to create bill
                        if (total>1){//if total is more than 1
                            cout<<"Do you want to print a receipt?\nEnter <Y> for Yes and any key for No : ";//prompt user if they want a receipt
                            cin>>printOption;//get printOption
                        if (printOption=='Y'||printOption=='y'){//if yes
                            printBill();}//call print function
                            system("CLS");}//clear screen
                            cout<<"Do you want to make a new bill?\nEnter <Y> for Yes and any key for No : ";//ask if they want to print a new bill
                            cin>>newBill;//get input
                        } while (newBill=='Y'||newBill=='y');//loop while user wants to make a new bill
                    system("CLS");//clear screen
                    break;//break
                }
                default:{}
            }
                }
                staffselect=0;
            break;}//break
        case 3:{
            system("CLS");//clear screen
            cout<<"Thank You";//display thank you
            Sleep(1000);}//delay for 1 second

        default:{}//if not 1 or 2 or 3
            }//close case
            }

    return 0;
}
