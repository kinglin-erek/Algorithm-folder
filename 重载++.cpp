class obj {
   static int i, j;
public:
   void f() const { cout << "f: " << i++ << endl; }
   void g() const { cout << "g: " << j++ << endl; }
};

// 静态成员定义
int obj::i = 1;
int obj::j = 12;

// 为上面的类实现一个容器
class objContainer 
{
   vector<obj*> a;
public:
   void add(obj* obj)
   { 
      a.push_back(obj);  //调用向量的标准方法
   }
   
   friend class smartPointer;
};

// 实现智能指针，用于访问类 Obj 的成员
class smartPointer {
   objContainer oc;
   int index;
public:
   smartPointer(objContainer &objc)
   { 
       oc = objc;
       index = 0;
   }
   // 返回值表示列表结束
   bool operator ++ () // 前增量，只有一个括号
   { 
     if(index >= oc.a.size()) return false;
     if(oc.a[++index] == 0) return false;//index加1
     return true;
   }
   
   bool operator ++ (int) // 后增量，括号里面有一个int类型
   { 
      return operator++();
   }
   
   // 重载运算符 ->
   obj* operator -> () const 
   {
     if(!oc.a[index])
     {
        cout << "Zero value";
        return (obj*)0;
     }
     //不为空，指向oc.a向量里面的obj类的实例
     return oc.a[index];
   }
   
};

void pointerTest(){
   const int sz = 10;
   obj o[sz];
   objContainer oc;
   for(int i = 0; i < sz; i++)
   {
       oc.add(&o[i]);
   }
   smartPointer sp(oc); // 创建一个迭代器
   
   do {
      sp->f(); // 智能指针调用
      sp->g();
   } while(sp++);
}