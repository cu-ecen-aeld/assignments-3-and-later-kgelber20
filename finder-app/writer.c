#include <stdio.h>
#include <syslog.h>


/**One difference from the write.sh instructions in Assignment 1:  You do not need to make your "writer" utility create directories which do not exist.  You can assume the directory is created by the caller.

Setup syslog logging for your utility using the LOG_USER facility.

Use the syslog capability to write a message “Writing <string> to <file>” where <string> is the text string written to file (second argument) and <file> is the file created by the script.  This should be written with LOG_DEBUG level.

Use the syslog capability to log any unexpected errors with LOG_ERR level.
 */

int main(int argc, char* argv[]) {
    openlog("writer", LOG_PID, LOG_USER);

    if(argc != 3){
        syslog(LOG_ERR, "Incorrect number of arguments");
        closelog();
        return 1;
    }    

    FILE *fileptr = fopen(argv[1], "w");

    if(fileptr == NULL){
        syslog(LOG_ERR, "ERROR: unable to open file");
        closelog();
        return 1;
    }

    if(fprintf(fileptr, "%s\n", argv[2]) < 0){
        syslog(LOG_ERR, "ERROR: unable to write to file");
        fclose(fileptr);
        closelog();
        return 1;
    }
    fclose(fileptr);

    closelog();
    return 0;
}

