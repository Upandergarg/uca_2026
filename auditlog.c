#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int fd;
    char ch;
    int line = 1;
    int newLine = 1;
    char num[20];
    int len;

    // Check for command
    if (argc < 2)
    {
        printf("Usage:\n");
        printf("./auditlog --add \"message\"\n");
        printf("./auditlog --view\n");
        return 1;
    }

    // add
    if (strcmp(argv[1], "--add") == 0)
    {
        if (argc < 3)
        {
            printf("Please provide a message.\n");
            return 1;
        }

        fd = open("audit.log", O_WRONLY | O_CREAT | O_APPEND, 0644);

        write(fd, argv[2], strlen(argv[2]));
        write(fd, "\n", 1);

        close(fd);
    }

    // view
    else if (strcmp(argv[1], "--view") == 0)
    {
        fd = open("audit.log", O_RDONLY);

        while (read(fd, &ch, 1) > 0)
        {
            // print numbering once for a line
            if (newLine)
            {
                len = sprintf(num, "%d: ", line);
                write(1, num, len);

                newLine = 0;
            }

            // from buffer to stdout
            write(1, &ch, 1);

            // For end line, and for next line
            if (ch == '\n')
            {
                line++;
                newLine = 1;
            }
        }

        close(fd);
    }

    else
    {
        printf("Invalid command!\n");
    }

    return 0;
}
