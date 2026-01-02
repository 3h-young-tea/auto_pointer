#ifndef	tea_h
#define	tea_h
#include<bits/stdc++.h>
namespace yt{
template<class ty>
class tea{
	ty *x;
public:
	tea(void);
	tea(tea&)=delete;
	tea(const tea&)=delete;
	tea(tea&&);
	~tea(void);
	auto operator=(tea&)=delete;
	auto operator=(const tea&)=delete;
	auto operator=(tea&&);
	template<class...args>
	void make(args&&...);
	void remove(void);
	auto empty(void);
	auto is_valid(void);
	auto operator->(void);
};
template<class ty>
tea<ty>::tea(void){
	x=nullptr;
}
template<class ty>
tea<ty>::tea(tea &&y){
	x=y.x;
	y.x=nullptr;
}
template<class ty>
tea<ty>::~tea(void){
	remove();
}
template<class ty>
auto	tea<ty>::operator=(tea &&y){
	if(this==&y)
		return *this;
	remove();
	x=y.x;
	y.x=nullptr;
	return is_valid();
}
template<class ty>
template<class...args>
void	tea<ty>::make(args&&...arg){
	remove();
	x=new ty(std::forward<args>(arg)...);
}
template<class ty>
void	tea<ty>::remove(void){
	if(x==nullptr)
		return;
	delete x;
	x=nullptr;
}
template<class ty>
auto	tea<ty>::empty(void){
	return x==nullptr;
}
template<class ty>
auto	tea<ty>::is_valid(void){
	return x!=nullptr;
}
template<class ty>
auto	tea<ty>::operator->(void){
	return x;
}
}
#endif
