class obj {
   static int i, j;
public:
   void f() const { cout << "f: " << i++ << endl; }
   void g() const { cout << "g: " << j++ << endl; }
};

// ��̬��Ա����
int obj::i = 1;
int obj::j = 12;

// Ϊ�������ʵ��һ������
class objContainer 
{
   vector<obj*> a;
public:
   void add(obj* obj)
   { 
      a.push_back(obj);  //���������ı�׼����
   }
   
   friend class smartPointer;
};

// ʵ������ָ�룬���ڷ����� Obj �ĳ�Ա
class smartPointer {
   objContainer oc;
   int index;
public:
   smartPointer(objContainer &objc)
   { 
       oc = objc;
       index = 0;
   }
   // ����ֵ��ʾ�б����
   bool operator ++ () // ǰ������ֻ��һ������
   { 
     if(index >= oc.a.size()) return false;
     if(oc.a[++index] == 0) return false;//index��1
     return true;
   }
   
   bool operator ++ (int) // ������������������һ��int����
   { 
      return operator++();
   }
   
   // ��������� ->
   obj* operator -> () const 
   {
     if(!oc.a[index])
     {
        cout << "Zero value";
        return (obj*)0;
     }
     //��Ϊ�գ�ָ��oc.a���������obj���ʵ��
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
   smartPointer sp(oc); // ����һ��������
   
   do {
      sp->f(); // ����ָ�����
      sp->g();
   } while(sp++);
}