// -*-c++-*- mock rtti
#pragma once
#include <typeinfo>
#include <string>
#include <map>
#include <iostream>
#include <cassert>

class mtype_info 
{
  std::string _name;
public:
  
  mtype_info (const char * name):
    _name(name)
  {
    
  }
  const std::string name() const
  {
    std::cout << "Name : " << _name << std::endl;
    //return "python_example." + _name;
    return  _name;
  }
} ;

bool operator ==(const mtype_info & a,const  mtype_info & b) {
  return 0;
}
class mtype_index {
public:
  int id;
  mtype_index() {}
  mtype_index(const mtype_info &) {}
  const std::string name() const { return "GCC";}
};
// std::type_info

bool operator ==(const mtype_index & a,const  mtype_index & b) {
  return 0;
}

bool operator<(const mtype_index& l, const mtype_index& r )
{
  return ( l.id < r.id );
}

namespace std {
  template <>
  struct hash<mtype_index>
  {
    std::size_t operator()(const mtype_index& k) const
    {
      //using std::size_t;
      //using std::hash;
      //using std::string;

      // from https://stackoverflow.com/questions/17016175/c-unordered-map-using-a-custom-class-type-as-the-key

      return hash<int>()(k.id);//((hash<string>()(k.first)
	//^ (hash<string>()(k.second) << 1)) >> 1)
	//^ (hash<int>()(k.third) << 1);
    }
  };

}


//const mtype_info single_typeinfo;

template <class T> static constexpr const mtype_info & mtypeid2(T&); // {return single_typeinfo; }
template <class T> static constexpr const mtype_info & mtypeid1(); // {return single_typeinfo; }

//template <class T> 

#define mtypeid(X) mtypeid1<X>()
#define mtypeidvar(X) mtypeid2(X)

//mtype_info * mtype_info[10];


class mtype {
  template <class T> T lock(){
    return T();
  }
} ; // for use of v_h.value_ptr<type>



