/* Example from Head First C.

Downloaded from https://github.com/twcamper/head-first-c

Modified by Allen Downey.
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <wait.h>


void error(char *msg)
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}

int main(int argc, char *argv[])
{
    int status;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <search phrase>\n", argv[0]);
        return 1;
    }
    const char *PYTHON = "/usr/bin/python2";
    const char *SCRIPT = "rssgossip.py";
    char *feeds[] = {
        "http://www.nytimes.com/services/xml/rss/nyt/Africa.xml",
        "http://www.nytimes.com/services/xml/rss/nyt/Americas.xml",
        "http://www.nytimes.com/services/xml/rss/nyt/MiddleEast.xml",
        "http://www.nytimes.com/services/xml/rss/nyt/Europe.xml",
        "http://www.nytimes.com/services/xml/rss/nyt/AsiaPacific.xml"
    };
    int num_feeds = 5;
    char *search_phrase = argv[1];
    char var[255];
    int pid;

    for (int i=0; i<num_feeds; i++) {
        //The program only examines the first feed because execle exits the program. Therefore, we need to use threading to make sure all feeds are printed.
        sprintf(var, "RSS_FEED=%s\n", feeds[i]);
        char *vars[] = {var, NULL};

        pid_t pid = fork();

        if (pid == -1) {
            fprintf(stderr, "fork failed: %s\n", strerror(errno));
            perror(argv[0]);
            exit(1);
        }
        int res = 0;

        if (!pid) {
          if (execle(PYTHON, PYTHON, SCRIPT, search_phrase, NULL, vars) == -1) {
            fprintf(stderr, "Can't run script: %s", strerror(errno));
            exit(1);
          }

        }

    }

    for (int i=0; i<num_feeds; i++) {
        pid = wait(&status);

        if (pid == -1) {
            fprintf(stderr, "wait failed: %s\n", strerror(errno));
            perror(argv[0]);
            exit(1);
        }

        // check the exit status of the child
        status = WEXITSTATUS(status);
        //printf("Main exiting %d.\n", status);
    }
    // compute the elapsed time
    //stop = get_seconds();
    //printf("Elapsed time = %f seconds.\n", stop - start);

    exit(0);
    return 0;
}
