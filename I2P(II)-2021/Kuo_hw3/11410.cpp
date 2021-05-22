#include<cstddef>
#include<cstdlib>
#include<ctime>
#include<iostream>
#include<string>
//#include"function.h"
#include "11410.h"
#ifdef ONLINE_JUDGE
//#include"NTHUOJLock"
#endif
//Partial Judge starts
namespace oj {
	Vector::Vector() {
		begin_ = new Int[0];
		last_ = end_ = begin_;
	}
	Vector::~Vector() {
		delete [] begin_;
	}

	size_t Vector::capacity() const{
		return end_ - begin_;
	}
	size_t Vector::size() const{
		return last_ - begin_;
	}

	void Vector::pop_back() {
		if(size() > 0) last_ --;
	}
	void Vector::push_back(value_type val) {
		size_type old = capacity();
		if(size() == old) {
			reserve(old + 1 > old * 3 ? old + 1 : old * 3);
		}
		(*last_) = val;
		last_ ++;
	}
	void Vector::insert(size_type pos,size_type count,value_type val) {
		size_type old_size = size();
		size_type old_capacity = capacity();
		if(old_size + count > old_capacity) {
			reserve(old_capacity + old_capacity / 2 > old_capacity + count ? 
			old_capacity + old_capacity / 2 : old_capacity + count);
		}
		resize(old_size + count);
		for(size_type i = pos + count; i < size(); i++) { //push_back
			begin_[i] = begin_[i - count];
		}
		for(size_type i = pos; i < pos + count; i++) { //inserting val
			begin_[i] = val;
		}
	}
	void Vector::reserve(size_type new_capacity) {
		if(new_capacity > capacity()) {
			size_type old_size = size();
			pointer new_begin_ = new Int[new_capacity];
			for(size_type i = 0; i < old_size; i++) {
				new_begin_[i] = begin_[i];
			}
			delete [] begin_; //
			begin_ = new_begin_;
			end_ = &begin_[new_capacity];
			last_ = &begin_[old_size];
		}
	}
	void Vector::resize(size_type new_size) {
		size_type old_size = size();
		if(new_size > old_size) {
			if(new_size > capacity()) {
				reserve(new_size);
			}
			for(size_type i = old_size; i < new_size; i++) {
				push_back(0);
			}
		} else if(new_size < old_size) {
			last_ = begin_ + new_size;
		}
	}
}
//Partial Judge ends

namespace oj
{
	Int::Int()
		:val(0){}	//set val as 0
	
	Int::Int(const int val_)
		:val(val_){}
	
	Int::Int(const Int &rhs)
		:val(rhs.val){}	//copy from rhs.val

	Int& Int::operator=(const Int &rhs)
	{
		val=rhs.val;	//copy from rhs.val
		return *this;
	}

	std::ostream& operator<<(std::ostream &os,const Vector &vec)
	{
		for(std::size_t i(0);i!=vec.size();++i)
			os<<vec[i]<<' ';
		return os;
	}
}

int main()
{
	using namespace std;
	srand(time(NULL));
	{
		oj::Vector v,v2;
		string command;

		for(oj::data_t n;cin>>command;)
		{
			if(command=="pop_back")
			{
				if(rand()&1&&v2.size())
					v2.pop_back();
				v.pop_back();
				if(rand()&1&&v2.size())
					v2.pop_back();
				cout<<v<<endl;
			}
			else if(command=="push_back")
			{
				cin>>n;
				if(rand()&1)
					v2.push_back(n);
				v.push_back(n);
				if(rand()&1)
					v2.push_back(n);
				cout<<v<<endl;
			}
			else if(command=="insert")
			{
				size_t pos,count;
				cin>>pos>>count>>n;
				if(rand()&1&&pos<=v2.size())
					v2.insert(pos,count,n);
				v.insert(pos,count,n);
				if(rand()&1&&pos<=v2.size())
					v2.insert(pos,count,n);
				cout<<v<<endl;
			}
			else if(command=="capacity")
				cout<<v.capacity()<<endl;
			else if(command=="size")
				cout<<v.size()<<endl;
			else if(command=="reserve")
			{
				cin>>n;
				if(rand()&1)
					v2.reserve(n);
				v.reserve(n);
				if(rand()&1)
					v2.reserve(n);
				cout<<v<<endl;
			}
			else if(command=="resize")
			{
				cin>>n;
				if(rand()&1)
					v2.resize(n);
				v.resize(n);
				if(rand()&1)
					v2.resize(n);
				cout<<v<<endl;
			}
		}
		cout<<v<<endl;
	}
	oj::memory_leak_count_check();	//you don't have to pay attention on this
#ifdef ONLINE_JUDGE
	nthuoj_unlock();
#endif
}

namespace oj
{
	Memory_leak_count::Memory_leak_count()
	{
		++count_;	//memory request + 1
	}

	Memory_leak_count::~Memory_leak_count()
	{
		--count_;	//memory request - 1
	}

	unsigned Memory_leak_count::count_(0);

	void memory_leak_count_check()
	{
		if(Memory_leak_count::count_!=0)	//memory leak if count_ is not equal to 0
			std::cout<<"memory leak"<<std::endl;
	}
}