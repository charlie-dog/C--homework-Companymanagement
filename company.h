#pragma once
#include <afxwin.h>
#include <fstream>
#include <sstream>

class Companymember
{
public:
	Companymember() : state(1), number(1), statename("salesperson"), salary(0), name("kuli"),earn(0) { }
	Companymember(int num): state(1),number(num),statename("salesperson"),salary(0),name("kuli"), earn(0) { }
	Companymember(int num, CString statena, CString na);
	int Getnum(){return number;	}

	int Getstate() {return state; }
	
	CString Getstatename(){	return statename;}
	
	double Getsalary() {return salary; }
	
	CString getname() { return name; }

	double getearn() { return earn; }

	CString getformula();
	
	void setEarn(double ear) { earn = ear; }

	void setnum(int num) { number = num; }
	
	void upgrade(bool tech);

	void downgrade(bool tech);

	void setname(CString nam) { name = nam; }

	void setstate(int newstate, bool tech);

	void setstatename(CString stana);

	void updatesalary(double bonus=0,double extraction=0);
private:
	int state,number;
	CString statename,name;
	double salary,earn;
};

class Company
{
public:
	Company();
	void Savemembers();
	bool newmember;
	void setTotalmoney();
	double getearnmoney() { return total_money; }
	void AddNewmember(int num, CString statena, CString na);
	CString getname_bynum(int num);
	int Deletmember_byname(CString name);
	int Deletmember_bynum(int name);
	CString getsituation(int Year,int Month);
	CString getsituation_now();
	void Upgrade_bynum(int num, bool tec);
	void Upgrade_byname(CString name, bool tec);
	void Downgrade_bynum(int num, bool tec);
	void Downgrade_byname(CString name, bool tec);
	void Load();
private:
	CString getname_byindex(int index);
	int get_index_by_num(int num);
	int get_index_by_name(CString name);
	int Deletmember_byindex(int index);
	void Upgrade_byindex(int index,bool tec);
	void Downgrade_byindex(int index, bool tec);
	double total_money;
	CString datapath, memberpath;
	enum month {Jan=1,Feb,Mar,Apr,May,Jun,Jul,Aug,Sep,Oct,Nov,Dec};
	int year,membernum,month;
	Companymember *members,Newmember;
	
};