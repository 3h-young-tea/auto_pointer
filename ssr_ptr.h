#ifndef	ssr_ptr_h
#define	ssr_ptr_h
#include<bits/stdc++.h>
namespace yt{
template<class T>
class ssr_ptr{
	T *x;
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
	auto operator->(void)->T*;
	auto operator->(void)const->const T*;
};
template<class T>
ssr_ptr<T>::ssr_ptr(void){
	x=nullptr;
}
template<class T>
ssr_ptr<T>::ssr_ptr(ssr_ptr &&y){
	x=y.x;
	y.x=nullptr;
}
template<class T>
ssr_ptr<T>::~ssr_ptr(void){
	remove();
}
template<class T>
auto	ssr_ptr<T>::operator=(ssr_ptr &&y)->ssr_ptr&{
	if(this==&y)
		return *this;
	remove();
	x=y.x;
	y.x=nullptr;
	return *this;
}
template<class T>
template<class...args>
void	ssr_ptr<T>::make(args&&...arg){
	remove();
	x=new T(std::forward<args>(arg)...);
}
template<class T>
void	ssr_ptr<T>::remove(void){
	if(x==nullptr)
		return;
	delete x;
	x=nullptr;
}
template<class T>
auto	ssr_ptr<T>::empty(void)->bool{
	return x==nullptr;
}
template<class T>
auto	ssr_ptr<T>::is_valid(void)->bool{
	return x!=nullptr;
}
template<class T>
auto	ssr_ptr<T>::operator->(void)->T*{
	return x;
}
template<class T>
auto	ssr_ptr<T>::operator->(void)const->const T*{
	return x;
}
}
#endif
