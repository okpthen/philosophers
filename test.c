#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
// int main(int argc, char **argv) {
//   struct timeval tv;
//   gettimeofday(&tv, NULL);
//   printf("%ld %06lu\n", tv.tv_sec, tv.tv_usec);
//   gettimeofday(&tv, NULL);
//   printf("%ld %06lu\n", tv.tv_sec, tv.tv_usec);
//   return 0;
// }

int main()
{
	struct timeval	tv;
	struct timeval	tv1;
	int				now;
	int				usec;

	now = 0;
	gettimeofday(&tv, NULL);
	while (now < 1000)
	{
		gettimeofday(&tv1, NULL);
		usec = tv1.tv_usec - tv.tv_usec;
		if (usec > 0)
		{
			now = (tv1.tv_sec - tv.tv_sec) * 1000 + (tv1.tv_usec - tv.tv_usec) / 1000;
		}
		else if (usec < 0)
		{
			now = (tv1.tv_sec - tv.tv_sec) * 1000 - (tv.tv_usec - tv1.tv_usec) / 1000;
		}
		// now = (tv1.tv_sec - tv.tv_sec) * 1000;
		printf("%d\n", now);
		usleep(400);
	}
	printf("now=%d\n", now);
}