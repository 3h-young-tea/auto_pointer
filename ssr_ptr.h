#ifndef	ssr_ptr_h
#define	ssr_ptr_h
#include<bits/stdc++.h>
namespace yt{
template<class ty>
class ssr_ptr{
	ty *x;
public:
	ssr_ptr(void);
	ssr_ptr(ssr_ptr&)=delete;
	ssr_ptr(const ssr_ptr&)=delete;
	ssr_ptr(ssr_ptr&&);
	~ssr_ptr(void);
	auto operator=(ssr_ptr&)=delete;
	auto operator=(const ssr_ptr&)=delete;
	auto operator=(ssr_ptr&&)->ssr_ptr&;
	template<class...args>
	void make(args&&...);
	void remove(void);
	auto empty(void)->bool;
	auto is_valid(void)->bool;
	auto operator->(void)->ty*;
	auto operator->(void)const->const ty*;
};
template<class ty>
ssr_ptr<ty>::ssr_ptr(void){
	x=nullptr;
}
template<class ty>
ssr_ptr<ty>::ssr_ptr(ssr_ptr &&y){
	x=y.x;
	y.x=nullptr;
}
template<class ty>
ssr_ptr<ty>::~ssr_ptr(void){
	remove();
}
template<class ty>
auto	ssr_ptr<ty>::operator=(ssr_ptr &&y)->ssr_ptr&{
	if(this==&y)
		return *this;
	remove();
	x=y.x;
	y.x=nullptr;
	return *this;
}
template<class ty>
template<class...args>
void	ssr_ptr<ty>::make(args&&...arg){
	remove();
	x=new ty(std::forward<args>(arg)...);
}
template<class ty>
void	ssr_ptr<ty>::remove(void){
	if(x==nullptr)
		return;
	delete x;
	x=nullptr;
}
template<class ty>
auto	ssr_ptr<ty>::empty(void)->bool{
	return x==nullptr;
}
template<class ty>
auto	ssr_ptr<ty>::is_valid(void)->bool{
	return x!=nullptr;
}
template<class ty>
auto	ssr_ptr<ty>::operator->(void)->ty*{
	return x;
}
template<class ty>
auto	ssr_ptr<ty>::operator->(void)const->const ty*{
	return x;
}
}
#endif
