#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <pthread.h>
// int main(int argc, char **argv) {
//   struct timeval tv;
//   gettimeofday(&tv, NULL);
//   printf("%ld %06lu\n", tv.tv_sec, tv.tv_usec);
//   gettimeofday(&tv, NULL);
//   printf("%ld %06lu\n", tv.tv_sec, tv.tv_usec);
//   return 0;
// }

void	*fnc2(void *arg)
{
	pthread_mutex_t	*mutex;

	mutex = arg;
	pthread_mutex_lock(mutex);
	while (1)
		printf("111");
	pthread_mutex_unlock(mutex);
}

void	*fnc1(void *arg)
{
	pthread_mutex_t	*mutex;

	mutex = arg;
	pthread_mutex_lock(mutex);
	while (1)
		printf("222");
	pthread_mutex_unlock(mutex);
}

int	main (void)
{
	pthread_t		t_id1;
	pthread_t		t_id2;
	pthread_mutex_t	mutex;

	pthread_mutex_init(&mutex, NULL);
	pthread_create(&t_id1, NULL, fnc1, &mutex);
	pthread_create(&t_id2, NULL, fnc2, &mutex);
	pthread_join(t_id1, NULL);
	pthread_join(t_id2, NULL);
	pthread_mutex_destroy(&mutex);
}