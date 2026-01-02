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
	void push(args&&...);
	void pop(void);
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
	pop();
}
template<class ty>
auto	tea<ty>::operator=(tea &&y){
	if(this==&y)
		return is_valid();
	pop();
	x=y.x;
	y.x=nullptr;
	return is_valid();
}
template<class ty>
template<class...args>
void	tea<ty>::push(args&&...arg){
	pop();
	x=new ty(std::forward<args>(arg)...);
}
template<class ty>
void	tea<ty>::pop(void){
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
