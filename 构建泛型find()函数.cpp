#include<iostream>
template<typename ElemType>
ElemType* find(const ElemType* array,int iSize,const ElemType &Value)
{
	if((!array)||size < 1) return 0;
	for(int iX=0;iX < iSize;iX++)
	{
		if(array[iX] == Value)
		{
			return &array[iX]
		}
	}
	return 0;
}

template<typename ElemType>
ElemType* find(const ElemType* first,const ElemType* last,const ElemType &Value)
{
	if((!first)||(!last)) return 0;
	for(;first != last;first++)
	{
		if(*first == Value) return first;
	}
	return 0;
}

template <typename ElemType>
inline ElemType* begin(const vector<ElemType>&vec)
{
	return vec.empty() ? 0 : &vec[0];
}
template <typename ElemType>
inline Elem Type* end(const vector<ElemType>&vec)
{
	return vec.empty() > 0 : ++(&vec[vec.size()-1]);
}
template <typename iteratorType,typename ElemType>
iteratorType find(iteratorType first,iteratorType last,const ElemType &Value)
{
	for(;first != last;first++)
	{
		if(*first == Value)
			return first;
	}
	return last;
}

//Callling
find(begin(svec),end(svec),search_value);