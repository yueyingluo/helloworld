#include<iostream>
#include<list>
#include<string>
using namespace std;

/*
• 对象被插入容器中时, 被插入的是对象的一个复制品
• 容器: 可容纳各种数据类型的数据结构 
• 迭代器: 可依次存取容器中元素的工具
    - 普通的C++指针就是一种迭代器
    • 所有迭代器: ++p, p ++
    • 输入迭代器:*p, p=p1, p==p1, p!=p1 
    • 输出迭代器:*p, p=p1
    • 正向迭代器: 上面全部
    • 双向迭代器: 上面全部, --p, p --,
    • 随机访问迭代器: 上面全部, 以及:
        移动i个单元: p+=i, p-=i, p+i, p–i 
        大于/小于比较: p<p1, p<=p1, p>p1, p>=p1 
        数组下标p[i]: p 后面的第i个元素的引用
• 算法: 用来操作容器中元素的函数模板
- "x和y相等" <= => "x<y和y<x同时为假" 等价的 
- 与 = = 运算符无关
*/

//iostream迭代器
/*
• 模板类 ostream_iterator 描述一个输出迭代器对象
该对象使用提取运算符 << 将连续的元素写入输出流 
• 模板类istream_iterator 描述一个输入迭代器对象
- istream_iterator: 读取输入流, 支持比较(==, !=), 解引用(*, ->), 自增(++)
- ostream_iterator: 写入输出流, 支持解引用(*, ->), 自增(++)*/

#include <iostream>
#include <list>
#include <string>
using namespace std;

template <class T1,class T2>
void Copy(T1 s,T1 e, T2 x)
{
	for(; s != e; ++s,++x)
		*x = *s;
}

template<class T>
class myostream_iterator
{
private:
    string sep; //分隔符
    ostream & os; 
public:
    myostream_iterator(ostream & o, string s):sep(s), os(o){ } 
    void operator ++() { };
    myostream_iterator & operator * (){ return * this; }
    myostream_iterator & operator = ( const T & val) { os << val << sep; return * this; }
};
int main()
{	const int SIZE = 5;
	int a[SIZE] = {5,21,14,2,3};
	double b[SIZE] = { 1.4, 5.56,3.2,98.3,3.3};
	list<int> lst(a,a+SIZE);
	myostream_iterator<int> output(cout,",");
	Copy( lst.begin(),lst.end(),output); 
	cout << endl;
	myostream_iterator<double> output2(cout,"--");
	Copy(b,b+SIZE,output2);
	return 0;
}
