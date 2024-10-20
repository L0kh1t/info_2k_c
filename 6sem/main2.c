#include "list.h"

int main()
{
	List a = init(5);
	print(&a);
	
	push_back(&a, 8);
	print(&a);
	
	printf("%i\n", pop_back(&a));
	print(&a);

	printf("%i\n", pop_back(&a));
	print(&a);
	
	push_front(&a, 10);
	print(&a);

	push_front(&a, 0);
	print(&a);

	printf("%i\n", pop_front(&a));
	print(&a);

}
