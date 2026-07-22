# A02 — Console Output Analysis

int main(){
    Base b1;  //Call constructor Base() ---> Base constructor-0 param
    Base b2(3);  //Call constructor Base(int u) ---> Base constructor-1 param
    Base*pb=new Base(1); //Call constructor Base(int u) ---> Base constructor-1 param

    DerivedA da1;  //Call constructor Base() for da1 first, then constructor DerivedA()
                   //---> Base constructor-0 param
                   //     DerivedA constructor-0 param
    DerivedA da2(2);  //Call constructor Base() for da2 first, then constructor DerivedA(int x)
                      //---> Base constructor-0 param
                      //     DerivedA constructor-1 param
    DerivedA da3(2,3);  //Call constructor Base() for da3 first, then constructor DerivedA(int u, int x)
                        //---> Base constructor-0 param
                        //     DerivedA constructor-2 params
    DerivedA da4(da2);  //Call constructor Base() for da4 first, then constructor DerivedA(const DerivedA& da)
                        //DerivedA's copy ctor chains to Base() (default) instead of Base(other) (copy)
                        //---> Base constructor-0 param
                        //     DerivedA copy constructor
    pb=new DerivedA(4,5); //Call constructor Base() first, then constructor DerivedA(int u, int x)
                          //Note: previous new Base(1) is leaked (pb overwritten without delete)
                          //---> Base constructor-0 param
                          //     DerivedA constructor-2 params

    DerivedB db1;  //Call constructor Base() for db1 first, then constructor DerivedB()
                   //---> Base constructor-0 param
                   //     DerivedB constructor-0 param
    DerivedB db2(2.7);  //Call constructor Base() for db2 first, then constructor DerivedB(float x)
                        //---> Base constructor-0 param
                        //     DerivedB constructor-1 params
    DerivedB db3(3,2.7);  //Call constructor DerivedB(int u, float x), which calls constructor Base(int u) before the 
                          //output ---> Base constructor-1 param
                          //            DerivedB constructor-2 params
    DerivedB db4(db2);  //Call constructor DerivedB(const DerivedB& db), which calls constructor Base(const Base& db)
                        //DerivedB's copy ctor properly chains to Base(other)
                        //---> Base copy constructor
                        //     DerivedB copy constructor
    pb=new DerivedB(4,5); //Call constructor DerivedB(int u, float x), which then call
                          //constructor Base(int u) ---> Base constructor-1 param
                          //Note: previous new DerivedA(4,5) is leaked
                          //                             DerivedB constructor-2 params

    f(b1);  //Call f(base B), then because b1 is passed by value, f makes a copy of b1 and when its copy goes out of scope,
            //it gets destroyed
            //---> Base copy constructor
            //     Function f
            //     Base destructor
    f(da1);  //Call f(base B), then because da1 is passed by value, f makes a copy ONLY of the Base portion (object slicing)
             //---> Base copy constructor
             //     Function f
             //     Base destructor
    f(db1);  //Call f(base B), then because db1 is passed by value, f makes a copy ONLY of the Base portion (object slicing)
             //---> Base copy constructor
             //     Function f
             //     Base destructor
    delete pb;  //pb is pointing to a DerivedB, but Base's destructor is NOT virtual ---> Undefined Behavior!
                //Only ~Base() runs; ~DerivedB() is skipped (DerivedB resources leak)
                //---> Base destructor
    return 0; //Main ends here, every automatic variable is destroyed
              //---> DerivedB destructor
              //     Base destructor (for db4)
              //     DerivedB destructor
              //     Base destructor (for db3)
              //     DerivedB destructor
              //     Base destructor (for db2)
              //     DerivedB destructor
              //     Base destructor (for db1)
              //     DerivedA destructor
              //     Base destructor (for da4)
              //     DerivedA destructor
              //     Base destructor (for da3)
              //     DerivedA destructor
              //     Base destructor (for da2)
              //     DerivedA destructor
              //     Base destructor (for da1)
              //     Base destructor (for b2)
              //     Base destructor (for b1)
} 
