#include<iostream>
#include<string>
using namespace std;
template<class A>
class snode{
public:
	A info;
	snode *next ;
};
template<class A>
class cnode{
public:
	cnode(){next=NULL;}
	A info;
	cnode *next ;
};
class course{
public:
	string cname;
	int cid;
	float grade;
};
class student{
public:
	static int sid;
	student(){ sid++;id=sid;listen=NULL; }
	~student(){sid--;}
	string fname;
	string lname;
	int mid;
	int id;
	cnode<course>*listen;
};
int student::sid=0;
snode<student>* newstudent(snode<student>*p){


	if (p==NULL)
	{
		snode<student>*s2;
		s2=new snode<student>;
		s2->next=NULL;
		cout<<"nam:"<<endl;
		cin>>s2->info.fname;
		cout<<"nam khanevadegi:"<<endl;
		cin>>s2->info.lname;
		cout<<"sabt nam ba movafaqiat anjam shod"<<endl;
		cout<<"shomare daneshjoyi:"<<s2->info.sid<<endl;
		//cout<<s2<<endl;
		return s2;
	}
	else{

		snode<student>*s2;

		s2=new snode<student>;
		p->next=s2;
		s2->next=NULL;
		p->next=s2;
		cout<<"nam:"<<endl;
		cin>>s2->info.fname;
		cout<<"nam khanevadegi:"<<endl;
		cin>>s2->info.lname;
		cout<<"sabt nam ba movafaqiat anjam shod"<<endl;
		cout<<"shomare daneshjoyi:"<<s2->info.sid<<endl;

		return s2;
	}
}
snode<student>* serchid(snode<student>*p,int id){
	//cout<<p<<endl;
	snode<student>*qb=p;
	//cout<<qb;
	while (qb!=NULL)
	{
		if(qb->info.id==id){
			cout<<qb->info.fname<<endl<<qb->info.lname<<endl;
			return qb;
		}
		qb=qb->next;
	}
	if (qb==NULL)
	{
		cout<<"not foun";
		exit(0);
	}
}
void newcurse(snode<student>*p){
	//cout<<p->info.listen<<endl;
	cnode<course>*c=p->info.listen;
	cnode<course>*r;
	if (c==NULL)
	{
		cnode<course>*c1=new cnode<course>;
		p->info.listen=c=c1;
		c1->next=NULL;
		cout<<"nam dars"<<endl;
		cin>>c1->info.cname;
		cout<<"cod dars:"<<endl;
		cin>>c1->info.cid;
		cout<<"nomre:"<<endl;
		cin>>c1->info.grade;
		return;
	}
	if (c!=NULL)
	{
		while (c!=NULL)
		{
			r=c;
			c=c->next;
			if (c==NULL)
			{
				cnode<course>*c1=new cnode<course>;
				r->next=c=c1;
				c1->next=NULL;
				cout<<"nam dars"<<endl;
				cin>>c1->info.cname;
				cout<<"cod dars:"<<endl;
				cin>>c1->info.cid;
				cout<<"nomre:"<<endl;
				cin>>c1->info.grade;
				return;
			}
		}
	}
}
void chap(snode<student>*p){
	cnode<course>*c=p->info.listen;
	if (c==NULL) cout<<"darsi vojod nadarad."<<endl;
	else{
		while (c!=NULL)
		{
			cout<<c->info.cid<<"."<<c->info.cname<<":"<<c->info.grade<<endl;
			c=c->next;
		}
	}

}
cnode<course>* serchcid(snode<student>*p,int id){

	cnode<course>*qb=p->info.listen;
	cnode<course>*r=NULL;

	while (qb!=NULL)
	{
		if(qb->info.cid==id){
			cout<<qb->info.cid<<"."<<qb->info.cname<<endl;
			return r;
		}
		r=qb;
		qb=qb->next;
	}
	if (qb==NULL)
	{
		cout<<"darsi ba in moshakhasat nadard";
		exit(0);
	}
}
void chaplist(snode<student>*p,int id)
{
	int qq=0;
	snode<student>*q=p;
	if (q==NULL) cout<<"daneshjoyi vojod nadarad"<<endl;
	else{
		while (q!=NULL)
		{
			cnode<course>*c=q->info.listen;
			while(c!=NULL)
			{
				if (c->info.cid==id)
				{
					cout<<q->info.fname<<" "<<q->info.lname<<endl;
					qq++;
				}
				c=c->next;
			}
			q=q->next;
		}

	}
	if (qq==0)cout<<" hich daneshoyi in dars ra nadard.";
}
void max(snode<student>*p,int id)
{
	string w;
	int qq=0;
	float mux=0;
	snode<student>*q=p;
	snode<student>*mx=q;
	if (q==NULL) cout<<"daneshjoyi vojod nadarad"<<endl;
	else{
		while (q!=NULL)
		{
			cnode<course>*c=q->info.listen;
			while(c!=NULL)
			{
				if (c->info.cid==id)
				{
					qq++;
					if (c->info.grade>mux)
					{
						mux=c->info.grade;
						w=c->info.cname;
						mx=q;	
					}
					
				}
				c=c->next;
			}
			q=q->next;
		}

	}
	if (qq!=0)
	{
		cout<<"maxsimom dar dars "<<w<<endl<<mx->info.fname<<" "<<mx->info.lname<<"="<<mux<<endl;
	}
	if (qq==0)cout<<" hich daneshoyi in dars ra nadard.";
}
int main()
{
	snode<student>*p=NULL;
	snode<student>*q=NULL;
	int a;
	do{
		cout<<"1.sabt nam"<<endl<<"2.sabt dars az tariq shomare daneshjoyi"<<endl<<"3.chap karname az tariq shomare daneshjyi"<<endl;
		cout<<"4.hazf dars az tariq shomare daneshjoyi va code dars"<<endl<<"5.list daneshjoyani dar darsi moshakhas"<<endl;
		cout<<"6.bishtarin nomre dar darsi moshakhas"<<endl;
		cin>>a;

		if (a==1)
		{
			q=newstudent(q);
			if (q->info.sid==1)
				p=q;
		}
		if (a==2)
		{
			int id;
			cout<<"lotfan shomare daneshjoyi ra vared konid"<<endl;
			cin>>id;
			snode<student>*o=serchid(p,id);
			newcurse(o);
		}
		if (a==3)
		{
			cout<<"lotfan shomare daneshjoyi ra vared konid"<<endl;
			int id;
			cin>>id;
			snode<student>*o=serchid(p,id);
			chap(o);

		}
		if (a==4)
		{
			cout<<"lotfan shomare daneshjoyi ra vared konid"<<endl;
			int id,cid;
			cin>>id;
			snode<student>*o=serchid(p,id);
			cout<<"lotfan cod dars ra vared konid"<<endl;
			cin>>cid;
			cnode<course>*t=serchcid(o,cid);
			cout<<"motmaen hastid?('y'=YES , 'n'=NO)"<<endl;
			char tq;
			cin>>tq;
			if (tq=='y' && t==NULL)
			{
				cnode<course>*t2=o->info.listen;
				o->info.listen=t2->next;
				t2->next=NULL;
				delete t2;

			}
			if(tq=='y'  && t!=NULL){
				cnode<course>*t2=t->next;
				t->next=t2->next;
				t2->next=NULL;
				delete t2;

			}
		}
		if (a==5)
		{
			cout<<"lotfan code darse mored nazar ra vare konid:"<<endl;
			int cid;
			cin>>cid;
			chaplist(p,cid);
		}
		if (a==6)
		{
			cout<<"lotfan code darse mored nazar ra vare konid:"<<endl;
			int cid;
			cin>>cid;
			max(p,cid);
		}
		cout<<"0.khoroj"<<endl<<"1.bazgasht b meno asli"<<endl;
		cin>>a;
	} while (a!=0);

	return 0;
}