#include <stdio.h>
#include <sys/time.h>
int main (void)
{
	struct timeval	s;
	long			t;

	gettimeofday(&s, NULL);
	t = s.tv_sec *1000 + s.tv_usec / 1000;
	printf("%ld\n", t);
	printf("%ld %ld\n", (s.tv_sec * 1000), (s.tv_usec / 1000));
}
