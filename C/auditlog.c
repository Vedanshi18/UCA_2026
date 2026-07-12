#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage:\n");
        printf("./auditlog --add \"message\"\n");
        printf("./auditlog --view\n");
        return 1;
    }

    // -------- ADD --------
    if (strcmp(argv[1], "--add") == 0)
    {
        if (argc < 3)
        {
            printf("Message missing\n");
            return 1;
        }

        int fd = open("audit.log", O_WRONLY | O_CREAT | O_APPEND, 0644);

        write(fd, argv[2], strlen(argv[2]));
        write(fd, "\n", 1);

        close(fd);
    }

    // -------- VIEW --------
    else if (strcmp(argv[1], "--view") == 0)
    {
        int fd = open("audit.log", O_RDONLY);

        if (fd < 0)
        {
            printf("No log file found\n");
            return 1;
        }
	char ch;
        int line = 1;

        printf("%d: ", line);

        while (read(fd, &ch, 1) > 0)
        {
            write(1, &ch, 1);

            if (ch == '\n')
            {
                if (read(fd, &ch, 1) > 0)
                {
                    line++;
                    printf("%d: ", line);
                    write(1, &ch, 1);
                }
            }
        }

        close(fd);
    }

    else
    {
        printf("Invalid command\n");
    }

    return 0;
}

