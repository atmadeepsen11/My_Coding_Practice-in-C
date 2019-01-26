
/*	STEPS

Create a normal process (Parent process)
Create a child process from within the above parent process
The process hierarchy at this stage looks like :  TERMINAL -> PARENT PROCESS -> CHILD PROCESS
Terminate the the parent process.
The child process now becomes orphan and is taken over by the init process.
Call setsid() function to run the process in new session and have a new group.
After the above step we can say that now this process becomes a daemon process without having a controlling terminal.
Change the working directory of the daemon process to root and close stdin, stdout and stderr file descriptors.
Let the main logic of daemon process run.


About logs… Writing on a disk is a heavy operation. Well, not “heavy” as you think of it, but compared to memory manipulation, it takes a while to write to a file. 
That’s why most UNIX systems use file buffers : contents are loaded into the buffer, and your modifications happen in it as well. Regularly, the kernel will unload
the buffer into the files in order to apply changes. This operation is called syncing, and even though it happens regularly on kernel orders, you can ask for it 
using the sync() function. If you don’t, and your daemon crashes, changes to the log file might not be visible, as the automatic syncing may not have happened yet.
By the way, buffer contents are pushed into the real file upon the fclose call, no need for a final sync().
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main(int argc, char* argv[])
{
	FILE *fp= NULL;
	pid_t process_id = 0;
	pid_t sid = 0;
// Create child process
	process_id = fork();
// Indication of fork() failure
	if (process_id < 0)
	{
		printf("fork failed!\n");
// Return failure in exit status
		exit(1);
	}
// PARENT PROCESS. Need to kill it.
	if (process_id > 0)
	{
		printf("process_id of child process %d \n", process_id);
// return success in exit status
		exit(0);
	}
//unmask the file mode
	umask(0);
//set new session
	sid = setsid();
	if(sid < 0)
	{
		// Return failure
		exit(1);
	}
// Change the current working directory to root.
	chdir("/");
// Close stdin. stdout and stderr
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
// Open a log file in write mode.
	fp = fopen ("Log.txt", "w+");
	while (1)
	{
	//Dont block context switches, let the process sleep for some time
		sleep(10);
		fprintf(fp, "Logging info...\n");
		fflush(fp);
// Implement and call some function that does core work for this daemon.
	}
	fclose(fp);
	return (0);
}




/*
#include <stdio.h>
#include <fcntl.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define RUNNING_DIR "/tmp"
#define LOCK_FILE "daemond.lock"
#define LOG_FILE "daemond.log"

void log_message(char *filename,char *message){

    FILE *logfile;
    logfile = fopen(filename,"a");
    if(!logfile)
        return;
    fprintf(logfile,"%s",message);
    fclose(logfile);
}

void signal_handler(int sig){

    switch(sig){
    case SIGHUP:
        log_message(LOG_FILE,"Hangup Signal Catched");
        break;
    case SIGTERM:
        log_message(LOG_FILE,"Terminate Signal Catched");
        exit(0);
        break;
    }
}

void daemonize()
{
    int i,lfp;
    char str[10];
    if(getppid() == 1)
        return;
    i = fork();

    if(i < 0)
        exit(1);

    if(i > 0)
        exit(0);
    setsid();

    for(i = getdtablesize(); i >= 0; --i)
        close(i);
		
    i = open("/dev/null",O_RDWR);
    dup(i);
    dup(i);
    umask(027);
    chdir(RUNNING_DIR);
    lfp = open(LOCK_FILE,O_RDWR|O_CREAT,0640);
    if(lfp < 0)

        exit(1);
    if(lockf(lfp,F_TLOCK,0) < 0)

        exit(1);

    sprintf(str,"%d\n",getpid());
    write(lfp,str,strlen(str));
    signal(SIGCHLD,SIG_IGN);
    signal(SIGTSTP,SIG_IGN);
    signal(SIGTTOU,SIG_IGN);
    signal(SIGTTIN,SIG_IGN);
    signal(SIGHUP,signal_handler);
    signal(SIGTERM,signal_handler);
}

int main(int argc,char **argv){

    daemonize();
    while(1)
        sleep(1);
}

*/