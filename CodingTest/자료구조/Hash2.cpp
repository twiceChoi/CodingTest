//unordered_Set : hash의 자료구조로 되어있다. : 자료구조의 꽃 (Hash table)
//Key Data 자체를 인덱스 배열로 사용한다는게 키포인트 

#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;


enum Sex {
	man,
	woman,
	unknown
};

class Person {
public:
	Person(const std::string name, const int id);
	Person(const std::string name, const int id, const bool sex, const int age);
	int Id_get() const { return this->_id; };
	void print() const { std::cout << "name : " << this->_name << " id : " << this->_id << std::endl; };

private:
	std::string _name;
	int _id;
	int _sex; // 0 -> man , 1 -> woman , 2 -> unknown
	int _age; // -1 -> unknown

};

Person::Person(const std::string name, const int id)
	: _name(name), _id(id)
{
	this->_age = -1;
	this->_sex = unknown;
}

Person::Person(const std::string name, const int id, const bool sex, const int age)
	:_name(name), _id(id), _age(age), _sex(sex)
{

}


bool operator==(const Person& lhs, const Person& rhs)
{
	lhs.Id_get() == rhs.Id_get();
}
struct MyHash
{
	size_t operator()(Person const& s) const noexcept
	{
		std::size_t h1 = std::hash<std::int32_t>{}(s.Id_get());
		std::size_t h2 = std::hash<std::int32_t>{}(s.Id_get());
		return h1 ^ (h2 << 1); // or use boost::hash_combine (see Discussion)
	}
};

int main()
{
	unordered_set<Person, MyHash> PersonHash;

	PersonHash.emplace(Person("이민주", 123));
	PersonHash.emplace(Person("윤민식", 763));
	PersonHash.emplace(Person("최우재", 59));

	for (auto it = PersonHash.begin(); it != PersonHash.end(); it++)
		(*it).print();


	return 0;
}