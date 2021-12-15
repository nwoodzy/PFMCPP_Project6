/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
    Not every pointer can be converted.
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference.

    You have to ask yourself if each pointer can be converted to a (const) reference.
    Think carefully when making your changes.
 
 2) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */


#include <iostream>
#include <string>
struct T
{
    T(int v, const char* n) : value(v), name(n) {}//1
    int value;//2 
    std::string name;//3
};

struct Comp                                //4
{
    T* compare(T* a, T* b)
    {
        if ( a != nullptr && b != nullptr )
        {
            if( a->value < b->value ) return a;
            if( a->value > b->value ) return b;
        }
        return nullptr;
    }
};

struct U
{
    float x { 0 }, y { 0 };
    float updaterCopy(float* newValue)      //12
    {
        if (newValue != nullptr)
        {
            std::cout << "U's x value: " << this->x << std::endl;
            this->x = *newValue;
            std::cout << "U's x updated value: " << this->x << std::endl;
            while( std::abs(this->y - this->x) > 0.001f )
            {
                /*
                write something that makes the distance between that-><#name2#> and that-><#name1#> get smaller
                */
                this->y += .1f;
            }
            std::cout << "U's y updated value: " << this->y << std::endl;
            return this->y * this->x;
        }
        else
        {
            return 0;
        }
    }
};

struct Update
{
    static float updater(U* that, float* newVal )        //10
    {
        if ( that != nullptr && newVal != nullptr ) 
        {
            std::cout << "U's x value: " << that->x << std::endl;
            that->x = *newVal;
            std::cout << "U's x updated value: " << that->x << std::endl;
            while( std::abs(that->y - that->x) > 0.001f )
            {
                /*
                write something that makes the distance between that-><#name2#> and that-><#name1#> get smaller
                */
                that->y += .1f;
                std::cout << "Distance between that->y and that->x: " << std::abs(that->y - that->x) << std::endl;
            }
            std::cout << "U's y updated value: " << that->y << std::endl;
            return that->y * that->x;
        }
        else
        {
            return false;
        }
    }
};
        
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{
    T monday ( 12, "monday" );                                             //6
    T tuesday ( 9 , "tuesday" );                                             //6
    Comp f;                                            //7
    auto* smaller = f.compare( &monday, &tuesday );                              //8

    if (smaller != nullptr)
    {
        std::cout << "the smaller one is << " << smaller->name << std::endl; //9
    }
    
    U foo;
    float updatedValue = 5.f;
    std::cout << "[static func] updater's multiplied values: " << Update::updater( &foo, &updatedValue) << std::endl;                  //11
    U bar;
    std::cout << "updaterCopy bar's multiplied values: " << bar.updaterCopy( &updatedValue ) << std::endl;
}
