#include "company.h"

Companymember::Companymember(int num, CString statena, CString na)
{
	number = num;
	if (statename == "general_manager")
	{
		state = 4;
		statename == statena;
	}
	else if (statename == "sale_manager")
		{
			state = 3;
			statename == statena;
		}
	else if (statename == "technician")
	{
		state = 2;
		statename == statena;
	}
	else if (statename == "tech_manager")
	{
		state = 3;
		statename == statena;
	}
	else 
	{
		state = 1;
		statename == "salesperson";
	}
	name = na;
	 earn=0;
}

CString Companymember::getformula()
{
	CString mid;
	if (statename == "general_manager")
	{
		return "工资:20000";
	}
	else if (statename == "sale_manager")
	{
		mid.Format("工资:8000+提成:%f*0.005", (Getsalary()-8000)/0.005);
		return mid;
	}
	else if (statename == "technician")
	{
		mid.Format("工资:6000+奖金:%f", Getsalary()-6000);
		return mid;
	}
	else if (statename == "tech_manager")
	{
		mid.Format("工资:12000+奖金:%f", Getsalary() - 12000);
		return mid;
	}
	else
	{
		mid.Format("提成:%f*0.01",Getsalary()*100 );
		return mid;
	}
}

void Companymember::setstate(int newstate, bool tech)
{
	if (newstate == 4)
	{
		state = 4;
		statename = "general_manager";
		return;
	}
	else
	{
		if (tech)
		{
			state = newstate;
			if (state == 2)statename = "technician";
			else if (state == 3)statename = "tech_manager";
			else { statename = "salesperson"; state = 1; }
		}
		else
		{
			state = newstate;
			if (state == 1)statename = "salesperson";
			else if (state == 3)statename = "sale_manager";
			else { statename = "salesperson"; state = 1; }
		}
		return;
	}
}

void Companymember::setstatename(CString stana)
{
	statename = stana;
	if (stana == "general_manager")state = 4;
	else if (stana == "technician")state = 2;
	else if ("tech_manager" == stana || "sale_manager" == stana)state = 3;
	else
	{
		state = 1;
		statename = "salesperson";
	}

}

void Companymember::updatesalary(double bonus, double extraction)
{
	if (statename == "general_manager")salary = 20000;
	else if (statename == "sale_manager")salary = 8000 + 0.005 * extraction;
	else if (statename == "technician")salary = 6000 + bonus;
	else if (statename == "tech_manager")salary = 12000 + bonus;
	else salary = 0.01 * earn;
}

void Companymember::upgrade(bool tech)
{
	if (state < 4)state++;
	else state = 4;
	setstate(state, tech);
}

void Companymember::downgrade(bool tech)
{
	if (state > 0)state--;
	else state = 0;
	setstate(state, tech);
}

Company::Company()
{
	total_money = 0;
	month = Jan;
	memberpath = "./members.txt";
	datapath = "./sata.txt";
	int index = 0,countlines=0;

	char ss[100];
	std::string line;
	std::fstream Read(memberpath);
	while (Read.getline(ss, 100))countlines++;
	membernum = countlines;
	Read.close();
	Read.open(memberpath);
	members = new Companymember[membernum];
	countlines = 0;
	while (Read.getline(ss, 100))
	{
		line = ss;
		CString Line(line.c_str()),name,statename;
		index = Line.Find(";");
		members[countlines].setnum(atoi(Line.Left(index)));
		Line = Line.Right(index);
		index = Line.Find(";");
		members[countlines].setstatename(Line.Left(index));
		Line = Line.Right(index);
		members[countlines].setname(Line);
		countlines++;
	}
}

void Company::Savemembers()
{
	std::string line;
	std::fstream Write(memberpath);
	for (int i = 0; i < membernum; i++)
	{
		
		if(newmember!=1&&i==membernum-1) Write << members[i].Getnum() << ";" << members[i].Getstatename() << ";" << members[i].getname();
		else Write << members[i].Getnum() << ";" << members[i].Getstatename() << ";" << members[i].getname() << std::endl;
	}
	if(newmember)Write << Newmember.Getnum() << ";" << Newmember.Getstatename() << ";" << Newmember.getname() << std::endl;

}

void Company::setTotalmoney()
{
	total_money = 0;
	for (int i = 0; i < membernum; i++)total_money += members[i].getearn();
	total_money += Newmember.getearn();

}

void Company::AddNewmember(int num, CString statena, CString na)
{
	newmember = 1;
	Newmember.setEarn(0);
	Newmember.setname(na);
	Newmember.setnum(num);
	Newmember.setstatename(statena);
	Savemembers();
	membernum++;
	members[membernum - 1] = Newmember;
	newmember = 0;
	
}

CString Company::getname_byindex(int index)
{
	if (index >= membernum || index < 0)return "查无此人";
	return members[index].getname();
}

CString Company::getname_bynum(int num)
{
	return getname_byindex(get_index_by_num(num));
}

int Company::get_index_by_num(int num)
{
	for (int i = 0; i < membernum; i++)
	{
		if (num == members[i].Getnum())return i;
	}
	return -1;
}

int Company::get_index_by_name(CString name)
{
	for (int i = 0; i < membernum; i++)
	{
		if (name == members[i].getname())return i;
	}
	return -1;
}

int Company::Deletmember_bynum(int num)
{
	return Deletmember_byindex(get_index_by_num(num));
}

int Company::Deletmember_byname(CString name)
{
	return Deletmember_byindex(get_index_by_name(name));
}


int Company::Deletmember_byindex(int index)
{
	if (index >= membernum || index < 0)return -1;
	std::string line;
	std::fstream Write(memberpath);
	for (int i = 0; i < membernum; i++)
	{
		if (i == index)continue;
		if (i == membernum - 1) Write << members[i].Getnum() << ";" << members[i].Getstatename() << ";" << members[i].getname();
		else Write << members[i].Getnum() << ";" << members[i].Getstatename() << ";" << members[i].getname() << std::endl;
	}
	Load();
	return 1;
}

void Company::Load()
{
	char ss[100];
	int index = 0, countlines = 0;
	std::string line;
	std::fstream Read(memberpath);
	while (Read.getline(ss, 100))countlines++;
	membernum = countlines;
	Read.close();
	Read.open(memberpath);
	countlines = 0;
	while (Read.getline(ss, 100))
	{
		line = ss;
		CString Line(line.c_str()), name, statename;
		index = Line.Find(";");
		members[countlines].setnum(atoi(Line.Left(index)));
		Line = Line.Right(index);
		index = Line.Find(";");
		members[countlines].setstatename(Line.Left(index));
		Line = Line.Right(index);
		members[countlines].setname(Line);
		countlines++;
	}

}

void Company::Upgrade_byindex(int index,bool tec)
{
	if (index >= membernum || index < 0)return;
	members[index].upgrade(tec);
	Savemembers();
}

void Company::Upgrade_byname(CString name, bool tec)
{
	Upgrade_byindex(get_index_by_name(name), tec);
}

void Company::Upgrade_bynum(int num, bool tec)
{
	Upgrade_byindex(get_index_by_num(num), tec);
}

void Company::Downgrade_byindex(int index, bool tec)
{
	if (index >= membernum || index < 0)return;
	members[index].downgrade(tec);
	Savemembers();
}

void Company::Downgrade_byname(CString name, bool tec)
{
	Downgrade_byindex(get_index_by_name(name), tec);
}

void Company::Downgrade_bynum(int num, bool tec)
{
	Downgrade_byindex(get_index_by_num(num), tec);
}

CString Company::getsituation_now()
{
	CString situation;
	situation.Format("%d\n%d\n", year, month);
	int  *num,nu = 0;
	num = new int[membernum];
	for (int j = 0; j < membernum; j++)
	{
		num[j] = members[j].Getnum();
	}
	for (int j = 0; j < membernum; j++)
	{
		for (int i = 0; i < membernum - 1; i++)
		{
			if (num[i] > num[i + 1])
			{
				nu = num[i];
				num[i] = num[i + 1];
				num[i + 1] = nu;
			}
		}
	}
	for (int i = 0; i < membernum; i++)
	{
		CString mid;
		mid.Format("number: %d    name: %s    ", members[num[i]].Getnum(), members[num[i]].getname());
		situation.Append(mid);
		mid.Format("state: %d    \nsalary: %f  =  %s\n", members[num[i]].Getstate(), members[num[i]].Getsalary(),members[num[i]].getformula());
		situation.Append(mid);
	}
	return situation;
}


