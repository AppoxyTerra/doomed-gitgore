#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <wchar.h>

char reponame_buffer[256] = {0};
char command_buffer[256] = {0};

const char* bobs_blessings[] = {
    "BOB wishes you a very good day.",
    "BOB will help you through the day.",
    "BOB has made cringe no longer an issue for you.",
    "BOB trusts you."
};

const wchar_t* git_icon[] = {
L"  /$$$$$$  /$$$$$$ /$$$$$$$$        /$$$$$$   /$$$$$$  /$$$$$$$  /$$$$$$$$\n"
" /$$__  $$|_  $$_/|__  $$__/       /$$__  $$ /$$__  $$| $$__  $$| $$_____/\n"
"| $$  \\__/  | $$     | $$         | $$  \\__/| $$  \\ $$| $$  \\ $$| $$\n"
"| $$ /$$$$  | $$     | $$         | $$ /$$$$| $$  | $$| $$$$$$$/| $$$$$\n"
"| $$|_  $$  | $$     | $$         | $$|_  $$| $$  | $$| $$__  $$| $$__/\n"
"| $$  \\ $$  | $$     | $$         | $$  \\ $$| $$  | $$| $$  \\ $$| $$\n"
"|  $$$$$$/ /$$$$$$   | $$         |  $$$$$$/|  $$$$$$/| $$  | $$| $$$$$$$$\n"
" \\______/ |______/   |__/          \\______/  \\______/ |__/  |__/|________/\n",

L"  ___  ____  ____     ___  _____  ____  ____ \n"
" / __)(_  _)(_  _)   / __)(  _  )(  _ \\( ___)\n"
"( (_-. _)(_   )(    ( (_-. )(_)(  )   / )__) \n"
" \\___/(____) (__)    \\___/(_____)(_)\\_)(____)",

L"   ___       ___       ___            ___       ___       ___       ___   \n"
"  /\\  \\     /\\  \\     /\\  \\          /\\  \\     /\\  \\     /\\  \\     /\\  \\  \n"
" /::\\  \\   _\\:\\  \\    \\:\\  \\        /::\\  \\   /::\\  \\   /::\\  \\   /::\\  \\ \n"
"/:/\\:\\__\\ /\\/::\\__\\   /::\\__\\      /:/\\:\\__\\ /:/\\:\\__\\ /::\\:\\__\\ /::\\:\\__\\\n"
"\\:\\:\\/__/ \\::/\\/__/  /:/\\/__/      \\:\\:\\/__/ \\:\\/:/  / \\;:::/  / \\:\\:\\/  /\n"
" \\::/  /   \\:\\__\\    \\/__/          \\::/  /   \\::/  /   |:\\/__/   \\:\\/  / \n"
"  \\/__/     \\/__/                    \\/__/     \\/__/     \\|__|     \\/__/  \n",

L"   ▄██████▄   ▄█      ███             ▄██████▄   ▄██████▄     ▄████████    ▄████████ \n"
"  ███    ███ ███  ▀█████████▄        ███    ███ ███    ███   ███    ███   ███    ███ \n"
"  ███    █▀  ███▌    ▀███▀▀██        ███    █▀  ███    ███   ███    ███   ███    █▀  \n"
" ▄███        ███▌     ███   ▀       ▄███        ███    ███  ▄███▄▄▄▄██▀  ▄███▄▄▄     \n"
"▀▀███ ████▄  ███▌     ███          ▀▀███ ████▄  ███    ███ ▀▀███▀▀▀▀▀   ▀▀███▀▀▀     \n"
"  ███    ███ ███      ███            ███    ███ ███    ███ ▀███████████   ███    █▄  \n"
"  ███    ███ ███      ███            ███    ███ ███    ███   ███    ███   ███    ███ \n"
"  ████████▀  █▀      ▄████▀          ████████▀   ▀██████▀    ███    ███   ██████████ \n"
"                                                             ███    ███              ",
};


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
    case 1: {
        srand(time(NULL));
        _putws(git_icon[rand()%4]);
        // FILE* f = fopen(".gitgore-repo", "r");
        // if (!f) {
        //     perror("Failed to load repository name.");
        //     return EXIT_FAILURE;
        // }
        // int temp;
        // int index = 0;
        // while ((temp = fgetc(f)) != EOF && index < 256) {
        //     reponame_buffer[index] = temp;
        // }
        // fclose(f);
        sprintf_s(command_buffer, 256,
            "git add * && "
            "git commit -m \"commit by %s\" && "
            "git push --force&& "
            "git pull", getenv("USERPROFILE"));
        while (true) {
            system(command_buffer);
            _sleep(1);
        }
        break;
    }
    default:
        perror("Syntax: gitgore [set <repo's-name>]");
    }
    return 0;
}


