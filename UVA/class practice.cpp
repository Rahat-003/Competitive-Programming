#include <string>
#include <vector>
using namespace std;
struct Student
{
string name;
int id;
vector<double> scores;
// say I want 10 test scores per student
Student() /* mem allocated here */{
/*Can I do this to init.members?
name("Tommy Trojan");*/
id = 12313;
//scores(10);
}
};
int main()
{
Student
Student::Student(){
name = "Tommy Trojan";
id = 12313
scores.resize(10);
}
