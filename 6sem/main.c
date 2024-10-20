#include "dynarray.h"


int main()
{
    Dynarray a;
    init(&a, 0);
    for (size_t i = 0; i < 100; ++i)
    {
        push_back(&a, i);
    }
    print(&a);
    //проверка функции pop_back
    printf("%i\n", pop_back(&a));
    print(&a);

    // resize
    resize(&a, 20);
    print(&a);

    resize(&a, 200);
    print(&a);
    
    //shallow_copy
    Dynarray b = shallow_copy(&a);
    printf("\nshallow_copy\n");
    print(&b);

    //deep_copy
    printf("\ndeep_copy\n");
    Dynarray d = deep_copy(&a);
    print(&d);

    destroy(&a);
}