#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[])
{
    struct stat fileStat;

    // Check number of command-line arguments
    if (argc != 2)
    {
        fprintf(stderr, "needs file path\n");
        return 1;
    }

    // Get file information
    if (stat(argv[1], &fileStat) == -1)
    {
        perror("stat");
        return 1;
    }

    printf("=== File Attributes for: %s ===\n", argv[1]);

    // File Type
    printf("File Type:            ");
    if (S_ISREG(fileStat.st_mode))
        printf("Regular File\n");
    else if (S_ISDIR(fileStat.st_mode))
        printf("Directory\n");
    else if (S_ISCHR(fileStat.st_mode))
        printf("Character Device\n");
    else if (S_ISBLK(fileStat.st_mode))
        printf("Block Device\n");
    else if (S_ISFIFO(fileStat.st_mode))
        printf("FIFO (Pipe)\n");
    else if (S_ISLNK(fileStat.st_mode))
        printf("Symbolic Link\n");
    else if (S_ISSOCK(fileStat.st_mode))
        printf("Socket\n");
    else
        printf("Unknown\n");

    // Permissions
    printf("Permissions:          %04o\n", fileStat.st_mode & 0777);

    // File Size
    // we write long becuase printf needs a datatype to print
    // as st_size is a type def like size_t
    // it can be long long,int,long acc to system
    printf("File Size:            %ld bytes\n", (long)fileStat.st_size);

    // Hard Links
    printf("Hard Links Count:     %ld\n", (long)fileStat.st_nlink);

    // Owner and Group
    printf("Owner (UID):          %d\n", fileStat.st_uid);
    printf("Group (GID):          %d\n", fileStat.st_gid);

    // Time Information
    printf("Last Access Time:     %s", ctime(&fileStat.st_atime));
    printf("Last Modification:    %s", ctime(&fileStat.st_mtime));
    printf("Status Change Time:   %s", ctime(&fileStat.st_ctime));

    return 0;
}
