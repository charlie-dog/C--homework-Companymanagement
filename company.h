#pragma once
#include <afxwin.h>
#include <fstream>
#include <sstream>

class Companymember
{
public:
	Companymember() : bonus(0),state(1), number(-1), statename("salesperson"), salary(0), name("kuli"),earn(0) { }
	Companymember(int num): bonus(0), state(1),number(num),statename("salesperson"),salary(0),name("kuli"), earn(0) { }
	Companymember(int num, CString statena, CString na);
	int Getnum(){return number;	}

	int Getstate() {return state; }
	
	CString Getstatename(){	return statename;}
	
	double Getsalary() {return salary; }
	
	CString getname() { return name; }

	double getearn() { return earn; }

	CString getformula();

	CString getsituation_now();
	
	void setEarn(double ear) { earn = ear; }

	void setnum(int num) { number = num; }
	
	void upgrade(bool tech);

	void downgrade(bool tech);

	void setname(CString nam) { name = nam; }

	void setstate(int newstate, bool tech);

	void setstatename(CString stana);

	void setbonus(double bon) { bonus = bon; }

	void updatesalary(double bon=0,double extraction=0);
private:
	int state,number;
	CString statename,name;
	double salary,earn,bonus;
};

class Company
{
public:
	Company();
	void Savemembers();
	bool newmember;
	void setTotalmoney();
	double getearnmoney() { return total_money; }
	double getearnmoney_id(int id) { return members[get_index_by_num(id)].getearn(); }
	void AddNewmember(int num, CString statena, CString na);
	CString getname_bynum(int num);
	int Deletmember_byname(CString name);
	int Deletmember_bynum(int name);
	int Getyear() { return year; }
	int Getmonth() { return month; }
	CString getsituation(int Year,int Month);
	CString getsituation_now();
	CString getsituation_now_num(int id);
	bool Idexsist(int id);
	void Upgrade_bynum(int num, bool tec);
	void Upgrade_byname(CString name, bool tec);
	void Downgrade_bynum(int num, bool tec);
	void Downgrade_byname(CString name, bool tec);
	void Load();
	int SetBonus(int id,double bon);
	int SetEarn(int id, double ear);
	int month, year;
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
	int membernum;
	Companymember members[100],Newmember;
	
};