#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
struct record
{
	char acc_no[60];
	char phone_no[60];
	char name[60];
	char age[60];
	char balance[60];
}sup;
struct bank
{
	char res[100];
	int acc_no;
	double phone;
	char name[60];
	int age;
	float balance;
	float amount;
	double phone2;
//}bk;
}task,trans,first;

int number;


void default_act();
void new_account();
void new_account_1();
void transfer();
void transfer_1();
void deposite();
void deposite_1();
void balance();
void request_check();
void request_debit();
void request_credit();
void loan();
void loan_1();
void convertitos(char *, double);
void send_to_target(char *phone2,float,float);
void back_to_interaction(char *phone);
void loading();

void main()
{
	number=1000;
	FILE *message,*ptr;
	message = fopen("message.txt","r");
	fscanf(message,"%lf %s",&first.phone,first.res);
	int choice = atoi(first.res);
	fclose(message);
	int decider = 1;//dummy
	int action=0;
	ptr = fopen("record.dat","r");
	while(fscanf(ptr,"%d %lf %s %d %f",&task.acc_no,&task.phone,task.name,&task.age,&task.balance)!= EOF)
	{
		if(first.phone==task.phone)
		{
			action = 1;
			break;
		}
	}
	if(action==0){
		choice = 100;
		printf("%d",choice);
	}
	if(atoi(first.res)==11)
	{
		printf("%d",choice);
		choice=11;
	}
	fclose(ptr);
	/*
	int checker;
	ptr = fopen("record.dat","r");
	while(fscanf(ptr,"%d %lf %s %d %f",&task.acc_no,&task.phone,&task.name,&task.age,&task.balance)!= EOF)
	{
		if(first.phone==task.phone)
		{
			checker = 1;
			break;
		}
		else 
			checker = 0;
	}
	fclose(ptr);
	if(checker == 0)
		choice = 100;
	if(first.res == 11)
		choice = 11;
	*/
	if(decider)
		switch(choice)
		{
			case 100 : new_account();break;
			case 11 : new_account_1();break;
			case 2 : transfer();break;
			case 22 : transfer_1();break;
			case 3 : deposite();break;
			case 33 : deposite_1();break;
			case 1 : balance();break;
			case 5 : request_check();break;
			case 6 : request_debit();break;
			case 7 : request_credit();break;
			case 4 : loan();break;
			case 44 : loan_1();break;
	
			default : default_act();
		}
}
void default_act()
{
	FILE *reply;
	reply= fopen("reply.txt","w");
	fprintf(reply,"Welcome to banking with whats app we are Pleased to serve you with the comform of your home.\nHow can we assist you today?\n\n1.Balance\n2.transfer\n3.Deposite\n4.Apply for Loan\n5.Request for Check Book\n6.Request for Debit Card\n7.Request for Credit Card\n\n please select the options number");
	fclose(reply);
}
void new_account()
{
	FILE *reply;
	reply = fopen("reply.txt","w");
	fprintf(reply,"%s","We checked accross our Data Base and you do not have a account in our Bank.\n\nReply with the format given below to create an new account:- \n11 <Name> <age> \n\n\n You will still have to reach to the nearest bank to get your identity verified at a maximum of 45 days.");
	fclose(reply);
}
void new_account_1()
{
	FILE *reply,*message,*ptr,*num;
	num = fopen("Zaccount_no_manager.dat","r");
	int acc_num;
	fscanf(num,"%d",&acc_num);
	fclose(num);
	acc_num++;
	num = fopen("Zaccount_no_manager.dat","w");
	fprintf(num,"%d",acc_num);
	fclose(num);
	reply = fopen("reply.txt","w");
	message = fopen("message.txt","r");
	ptr=fopen("record.dat","a+");
	//while(fscanf(ptr,"%d %lf %s %d %f",&task.acc_no,&task.phone,&task.name,&task.age,&task.balance)!= EOF);
	fscanf(message,"%lf %d %s %d",&task.phone,&task.res,task.name,&task.age);
	task.acc_no = acc_num;
	task.balance = 0.0;
	fprintf(ptr,"%d %lf %s %d %f\n",task.acc_no,task.phone,task.name,task.age,task.balance);
	fclose(ptr);
	fclose(message);
	fprintf(reply,"Welcome %s your Account was sucessfuly created.\nAccount Number is %d",task.name,task.acc_no);
	fclose(reply);
}
void transfer()
{
	FILE *reply;
	reply = fopen("reply.txt","w");
	fprintf(reply,"%s","Reply with the format given below to perform a Transaction:- \n22 <phone_number_the person> <Ammount> \n\n\n You will still have to reach to the nearest bank to get your identity verified at a maximum of 45 days.");
	fclose(reply);
}
void transfer_1()
{
	FILE *old,*newrec,*message,*reply;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");
	message=fopen("message.txt","r");
	reply=fopen("reply.txt","w");
	fscanf(message,"%lf %d %lf %f",&trans.phone,&trans.res,&trans.phone2,&trans.amount);
	int trial = 0;
	while(fscanf(old,"%d %lf %s %d %f",&task.acc_no,&task.phone,task.name,&task.age,&task.balance)!= EOF)
	{
		if(trans.phone2==task.phone)
		{
			trial = 1;break;
		}
	}
	fclose(old);
	if(trial)
	{
		old=fopen("record.dat","r");
		float bal,bal2;
		float amount = trans.amount;
		char phone[20];
		char phone2[20];
		while(fscanf(old,"%d %lf %s %d %f",&task.acc_no,&task.phone,task.name,&task.age,&task.balance)!= EOF)
		{
			if(trans.phone==task.phone)
			{
				//printf("Entre sender\n");
				task.balance-=trans.amount;
				bal = task.balance;
				convertitos(phone,task.phone);
				//printf("phone %s\n",phone);
			}
			else if(trans.phone2==task.phone)
			{
				task.balance+=trans.amount;
				convertitos(phone2,task.phone);
				bal2=task.balance;
				//printf("phone2 %s\n",phone2);

			}
			fprintf(newrec,"%d %lf %s %d %f\n",task.acc_no,task.phone,task.name,task.age,task.balance);
		}
		fclose(old);
		fclose(newrec);
		fclose(message);
		fprintf(reply,"The transfer was successful.\nYour new balance is %0.2f",bal);
		fclose(reply);
		remove("record.dat");
		rename("new.dat","record.dat");
		send_to_target(phone2,amount,bal2);
		back_to_interaction(phone);
	}
	else 
	{
		fprintf(reply,"Sorry the person whome you want to transfer money doesn't have a account in our Bank");
		fclose(newrec);
		fclose(message);
		fclose(reply);
		remove("new.dat");

	}
}
void deposite()
{
	FILE *reply;
	reply = fopen("reply.txt","w");
	fprintf(reply,"Reply with the format given below to Deposite Amount:- \n33 <Ammount> \n\n\nYou will still have to reach to the nearest Bank/ATM to deposite your money within a maximum period of 32 Hours.");
	fclose(reply);
}
void deposite_1()
{
	FILE *old,*newrec,*message,*reply,*temp;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");
	message=fopen("message.txt","r");
	reply=fopen("reply.txt","w");
	fscanf(message,"%lf %d %f",&trans.phone,&trans.res,&trans.amount);
	float bal;
	temp=fopen("temp.dat","w");
	fprintf(temp,"%f",trans.amount);
	fclose(temp);
	while(fscanf(old,"%d %lf %s %d %f",&task.acc_no,&task.phone,task.name,&task.age,&task.balance)!= EOF)
	{
		if(trans.phone==task.phone)
		{
			task.balance+=trans.amount;
			bal = task.balance;
		}
		fprintf(newrec,"%d %lf %s %d %f\n",task.acc_no,task.phone,task.name,task.age,task.balance);
	}
	fprintf(reply,"The Deposite was successful.\nYour new balance is %0.2f \n\n\n\nPlease deposite %0.2f to nearest ATM within 32 Hours to avoide extra charges.",bal,trans.amount);
	fclose(old);
	fclose(newrec);
	fclose(message);
	fclose(reply);
	remove("record.dat");
	rename("new.dat","record.dat");
}
void balance()
{
	FILE *reply,*message,*ptr;
	reply = fopen("reply.txt","w");
	message = fopen("message.txt","r");
	ptr=fopen("record.dat","r");
	fscanf(message,"%lf %d",&trans.phone,&trans.res);
	while(fscanf(ptr,"%d %lf %s %d %f",&task.acc_no,&task.phone,task.name,&task.age,&task.balance)!= EOF)
	{
		if(task.phone == trans.phone)
			fprintf(reply,"The Balance in your account is %0.2f",task.balance);
	}
	fclose(ptr);
	fclose(message);
	fclose(reply);	
}
void request_check()
{
	FILE *reply,*message,*check;
	reply = fopen("reply.txt","w");
	message = fopen("message.txt","r");
	check=fopen("Check_Book.dat","a");
	fscanf(message,"%lf %d",&trans.phone,&trans.res);
	fprintf(check,"%lf requests for a new Check Book\n",trans.phone);
	fprintf(reply,"The request has been put up, you will be contacted within 2 working day's for furthur information\n");
	fclose(check);
	fclose(message);
	fclose(reply);
}
void request_debit()
{
	FILE *reply,*message,*card;
	reply = fopen("reply.txt","w");
	message = fopen("message.txt","r");
	card=fopen("cards.dat","a");
	fscanf(message,"%lf %d",&trans.phone,&trans.res);
	fprintf(card,"%lf requests for a new Debit Card\n",trans.phone);
	fprintf(reply,"The request has been put up, you will be contacted within 2 working day's for furthur information\n");
	fclose(card);
	fclose(message);
	fclose(reply);
}
void request_credit()
{
	FILE *reply,*message,*card;
	reply = fopen("reply.txt","w");
	message = fopen("message.txt","r");
	card=fopen("cards.dat","a");
	fscanf(message,"%lf %d",&trans.phone,&trans.res);
	fprintf(card,"%lf requests for a new Credit Card\n",trans.phone);
	fprintf(reply,"The request has been put up, you will be contacted within 2 working day's for furthur information\n");
	fclose(card);
	fclose(message);
	fclose(reply);
}
void loan()
{
	FILE *reply;
	reply= fopen("reply.txt","w");
	fprintf(reply,"Reply with the format given below to request for a loan saction.\n\n44 <amount> <period_in_months> ");
	fclose(reply);
}
void loan_1()
{
	FILE *reply,*message,*loan;
	reply = fopen("reply.txt","w");
	message = fopen("message.txt","r");
	loan=fopen("loan_requests.dat","a");
	fscanf(message,"%lf %d %f %d",&trans.phone,&trans.res,&trans.amount,&trans.age);
	float principle = (float)(trans.amount*(pow(12,(trans.age/12))));
	fprintf(reply,"Your request will be proccessed shortly.\nThe amount to be paid at the end of %d will be %0.2f.\n\n\n\nThe the amount specified is just for reference the final amount will be informed at time of issue of the loan.",trans.age,principle);
	fprintf(loan,"%lf has requested for a loan of principle amount %0.2f for a period of %d. The end amount to be recover would turn out to be %0.2f\n",trans.phone,trans.amount,trans.age,principle);
	fclose(message);
	fclose(reply);
	fclose(loan);
}
///
//
/// functions to just suport the program.
//
///
void convertitos(char *p, double x)
{
	long long int number = (long long int)x;
	//printf("%lld \n",number);
	p[10] = '\n';
	for(int i=9;i>=0;i--)
	{
		p[i] = (number%10)+'0';
		number /= 10;
	}
	//printf("%s \n",p);
}
void send_to_target(char *phone2,float amount,float balance)//,char *name,float amount,float nbal)
{
	FILE *old,*temp,*you;
    old=fopen("record.dat","r");
	/*
	temp=fopen("temp.dat","r");
	char amount[20];
	fscanf(temp,"%s",amount);
	fclose(temp);
	remove("temp.dat");
	*/
	while(fscanf(old,"%s %[^.] %s %s %[^.]",sup.acc_no,sup.phone_no,sup.name,sup.age,sup.balance)!= EOF)
	{
		if(!(strcmp(phone2,sup.phone_no)))
		{
			break;
		}
	}
	char html[200]="start \"\" \"https://wa.me/91";
	strcat(html,phone2);
	/*
	strcat(html,"?text=Rs%20");
	strcat(html,amount);
	strcat(html,"%20was%20credited%20to%20your%20Account%20your%20new%20Balance:-%20is%20");
	strcat(html,sup.balance);
	//strcat(html,".00");
	*/
	system(html);
	//printf("fiirst %s\n",phone2);
	fclose(old);
	you=fopen("transaction.txt","w");
	fprintf(you,"Rs %0.2f was credited to your account.\nYour new Balance is %0.2f",amount,balance);
	fclose(you);
	system("python send.py");
	for(int i=0;i<4;i++)
		loading();
	//system("start \"\" \"https://wa.me/919380515813?text=hi%20i%27m%20interested%20in%20your%20project%20and%20we%20are%20\"");
}
void back_to_interaction(char *phone)
{
	char html[200]="start \"\" \"https://wa.me/91";
	strcat(html,phone);
	//printf("2nd:-%s \n",html);
	system(html);
	for(int i=0;i<8;i++)
		loading();
	system("WhatsApp.lnk");
	for(int i=0;i<14;i++)
		loading();
}
void loading()
{
	int i=0;
	while(i<10000000)
		i++;
}