#include<iostream>
using namespace std;
void khoitaoMTK(int *a,int n)
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			*(a+i*n+j)=0;
	}
}
class dinh;
class Danh_sach_ke;
void Them_PT(Danh_sach_ke a[10],int pos,int key);
void Print(Danh_sach_ke a[10],int n);
class mA_TRan_ke
{

	private :
		int *G,n;
	public:
		mA_TRan_ke(int n){
			G=new int [n*n];
			this->n=n;
			khoitaoMTK(G,n);
		};
		void add_element(int i,int j){
		*(G+i*n+j)=1;	
		};
		void delete_element(int i,int j){
		*(G+i*n+j)=0;	
		};
		void print(){
			cout<<" ";
			for(int i=0;i<n;i++ )
			cout<<"	"<<i+1;
			cout<<endl;
			for(int i=0;i<n;i++){
				cout<<i+1<<"	";
				for(int j=0;j<n;j++){
					cout<<*(G+i*n+j)<<"	";
				}
				cout<<endl;
			}
		};
		int get_n(){
			return n;
		};
		int Check_Pointer(int pos_i,int pos_j){
			if(*(G+pos_i*n+pos_j)==1)
			return 1;
		}
};
class dinh{
	private:
		dinh *next;
		int key;
	public:
		dinh(int key){
			this->key=key;
			next=NULL;
		};
	friend class Danh_sach_ke;
};
class Danh_sach_ke{
	private	:
		dinh *head,*tail;
	public :
		Danh_sach_ke(){
			head=NULL;
		}
		void add_element(int key){
			if(head==NULL)
			{
				tail=head=new dinh(key);
			}
			else{
				tail->next=new dinh(key);
				tail=tail->next;
			}
		};
		void print(){
			dinh *a=head;
			while(a!=NULL)
			{
				cout<<a->key<<"->";
				a=a->next;
			}
			cout<<"NULL"<<endl;
		}
		bool itNULL()
		{
			if(head!=NULL)
			return 0;
			else return 1;
		}
		int get_key(){
			if(head!=NULL)
			{
				int a=(head->key)-1;
				if(head==tail)
				{
					dinh *b=head;
					head=tail=NULL;
					delete b;
					return a;
				}
			else{
				dinh *b=head;
				head=head->next;
				delete b;
				return a;
			} 
			}
		}
};
int n=3;
void Them_PT(Danh_sach_ke a[10],int pos,int key)
{
	a[pos].add_element(key+1);
}
void Print(Danh_sach_ke a[10],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"["<<i+1<<"]->";
		a[i].print();			
	}
}
void Change_DSK(mA_TRan_ke a){
	int n=a.get_n();
	Danh_sach_ke b[n];
	for(int i=0;i<n;i++)
			for(int j=0;j<n;j++){
				if(a.Check_Pointer(i,j))
					Them_PT(b,i,j);
			}
	Print(b,n);		
}
void Change_MTK(Danh_sach_ke *a,int n)
{
	mA_TRan_ke b(n);
	for(int i=0;i<n;i++)
	{
		while(!a[i].itNULL())
		{
			int tmp=a[i].get_key();
			b.add_element(i,tmp);
		}
	}
	b.print();
}
// main(){
// 	Danh_sach_ke a[5];
// 	Them_PT(a,0,1);
// 	Them_PT(a,0,4);
// 	Them_PT(a,1,3);
// 	Them_PT(a,1,2);
// 	Them_PT(a,2,3);
// 	Them_PT(a,3,0);
// 	Them_PT(a,4,3);
// 	Print(a,5);	
// 	Change_MTK(a,5);
// }
//main()
//{
//	mA_TRan_ke a(5);
//	a.add_element(0,0);
//	a.add_element(2,1);
//	a.print();
//	Change_DSK(a);
//}
