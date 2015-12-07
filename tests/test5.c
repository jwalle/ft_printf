/* == HEADER == */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"
#include <string.h>
#include <sys/shm.h>

// #define assert_printf(msg, ...) \
// 	printf(msg, ##__VA_ARGS__); \
// 	ft_printf(msg, ##__VA_ARGS__); \
// 	ft_printf("\n"); \
// 	printf("\n")

static char *mytee(int size) {
   int shmid = shmget(IPC_PRIVATE, size + 1, 0660 | IPC_CREAT);
   int pipe_fds[2];
   pipe(pipe_fds);

   switch (fork()) {
      case -1:                      // = error
         perror("fork");
         exit(EXIT_FAILURE);
      case 0: {                     // = child
         char *out = shmat(shmid, 0, 0), c;
         int i = 0;
         out[0] = 0;
         dup2(pipe_fds[0], 0);      // redirect pipe to child's stdin
        close(pipe_fds[0]);
  		close(pipe_fds[1]);
         setvbuf(stdout, 0, _IONBF, 0);
         while (read(0, &c, 1) == 1 && i < size) {
            //printf("<%c>", c);      // pass parent's stdout to real stdout,
            out[i++] = c;           // and then buffer in mycapture buffer
            out[i] = 0;             // (the extra <> are just for clarity)
         }
         _exit(EXIT_SUCCESS);
      }
      default:                      // = parent
         dup2(pipe_fds[1], 1);      // replace stdout with output to child
        close(pipe_fds[0]);
  		close(pipe_fds[1]);
         setvbuf(stdout, 0, _IONBF, 0);
         return shmat(shmid, 0, 0); // return the child's capture buffer
   }
}

char buf1[4096] = { 0 };
char buf2[4096] = { 0 };

int main()
{
	//assert_printf("%s\n", "plop");
	// char *mycapture = mytee(100);    // capture first 100 bytes
	// ft_printf("Hello World");           // sample test string
	// char *mycapture2 = mytee(100);    // capture first 100 bytes
	// printf("Hello World");           // sample test string
	// fprintf(stderr, "\nCaptured 1 : %s\nCaptured 2 : %s\n", mycapture, mycapture2);


	// fclose(stdout);
	// stdout = fmemopen(buf1, sizeof(buf1), "w");
	// setbuf(stdout, NULL);
	// printf("PLOP\n");
	// fflush(stdout);
	// stdout = fmemopen(buf2, sizeof(buf2), "w");
	// setbuf(stdout, NULL);
	// ft_printf("PLOP2\n");

	// int		out;
	// int		p[2];
	// char	buf[100];

	// out = dup(1);
	// pipe(p);
	// dup2(p[1], 1);
	// printf("plop\n");
	// dup2(out, 1);
	// buf[read(p[0], buf, 100)] = 0;
	// close(p[0]);
	// close(p[1]);
	// close(out);
	
	// int old;
	// char *bp;
	// size_t size;
	// FILE *stream;

	// old = dup(1);

	// stream = open_memstream (&bp, &size);
	
	// dup2(fileno(stream), 1);
	// printf ("hello");
	// fflush (stdout);
	// //printf ("buf = `%s', size = %d\n", bp, size);
	// //fprintf (stream, ", world");
	// fclose (stream);
	// dup2(old, 1);
	// printf ("buf = `%s', size = %d\n", bp, size);

#define SIZE 100

	ft_printf("PLOP BORDEL\n");
	
	char string1[SIZE];
	char string2[SIZE];
	freopen("/dev/null", "a", stdout);
	setbuf(stdout, string1);
	printf("plop1");
	fflush(stdout);
	setbuf(stdout, string2);
	ft_printf("plop2");
	//write(1, "plop2", 5);
	fflush(stdout);
	
	fprintf(stderr, "string1 = %s, string2 = %s\n", string1, string2);
	return (0);
}