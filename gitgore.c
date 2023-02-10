#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char reponame_buffer[256] = {0};
char command_buffer[256] = {0};

const char* bobs_blessings[] = {
    "BOB wishes you a very good day.",
    "BOB will help you through the day.",
    "BOB has made cringe no longer an issue for you.",
    "BOB trusts you."
};

const char git_icon = 
⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣷⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠐⢿⣿⣿⣿⣿⣦⡀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⢀⣴⣿⣦⡀⠙⠉⠻⣿⣿⣿⣦⡀⠀⠀⠀⠀⠀
⠀⠀⠀⢀⣴⣿⣿⣿⣿⣇⠀⠀⠀⢽⣿⣿⣿⣿⣦⡀⠀⠀⠀
⠀⢀⣴⣿⣿⣿⣿⣿⣿⣿⡇⠀⣦⡀⠙⢿⢿⣿⣿⣿⣦⡀⠀
⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⣿⣿⡆⠀⠀⠈⢻⣿⣿⣿⣆
⠙⢿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⣿⣿⣷⣄⣀⣠⣿⣿⣿⠟⠁
⠀⠀⠙⢿⣿⣿⣿⣿⣿⡿⠃⠀⠻⣿⣿⣿⣿⣿⣿⠟⠁⠀⠀
⠀⠀⠀⠀⠙⢿⣿⣿⣿⣇⠀⠀⠀⣽⣿⣿⣿⠟⠁⠀⠀⠀⠀
"⠀⠀⠀⠀⠀⠀⠙⢿⣿⣿⣷⣶⣾⣿⣿⠟⠁⠀⠀⠀⠀⠀⠀"
"⠀⠀⠀⠀⠀⠀⠀⠀⠙⢿⣿⣿⣿⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀"
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠛⠁⠀⠀⠀⠀"


int main(int argc, char const *argv[])
{
    switch (argc) {
    case 3:
        if (!strcmp(argv[1], "set")) {
            FILE* f = fopen(".gitgore-repo", "w");
            if (!f) {
                perror("Failed to set repository.");
                return EXIT_FAILURE;
            }
            fputs(argv[2], f);
            fclose(f);
            puts("Ready to be productive ? (y/n)");
            if (getchar() != 'y') {
                return EXIT_SUCCESS;
            }
        } else if (!strcmp(argv[1] ,"bob")) {
            puts("You have recieved a blessing from BOB:");
            srand(time(NULL));
            puts(bobs_blessings[rand()%4]);
        } else {
            perror("Wrong arguments :(");
            return EXIT_FAILURE;
        }
    case 1:
        FILE* f = fopen(".gitgore-repo", "r");
        if (!f) {
            perror("Failed to load repository name.");
            return EXIT_FAILURE;
        }
        int temp;
        int index = 0;
        while ((temp = fgetc(f)) != EOF && index < 256) {
            reponame_buffer[index] = temp;
        }
        fclose(f);
        sprintf_s(command_buffer, 256, "git commit -m \"-\"");
        system();
        break;
    default:
        perror("Syntax: gitgore [set <repo's-name>]");
    }
    return 0;
}


