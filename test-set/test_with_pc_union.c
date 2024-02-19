
#include <stddef.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *get_next_line(int fd);

int test_with_pc(int fd, const char *expects[], int size, int *pc);

int test_empty_with_pc(int fd, int *pc) {
    const char *expects[] = {
        NULL,
        NULL,
        NULL,
    };
    const int size = sizeof(expects) / sizeof(expects[0]);
    return test_with_pc(fd, expects, size, pc);
}

int test_fazzing_with_pc(int fd, int *pc) {
    const char *expects[] = {
        "\n",
        "0\n",
        "3210\n",
        "\n",
        "0\n",
        "0123\n",
        "\n",
        "\n",
    };
    const int size = sizeof(expects) / sizeof(expects[0]);
    return test_with_pc(fd, expects, size, pc);
}

int test_multiline_with_pc(int fd, int *pc) {
    const char *expects[] = {
        "0123456789\n",
        "0123456789\n",
        "0123456789\n",
        "0123456789\n",
        "0123456789\n",
        "0123456789\n",
        "0123456789\n",
        "0123456789\n",
        "0123456789\n",
        "0123456789",
    };
    const int size = sizeof(expects) / sizeof(expects[0]);
    return test_with_pc(fd, expects, size, pc);
}

int test_multiline_endline_with_pc(int fd, int *pc) {
    const char *expects[] = {
        "0123456789\n",
        "0123456789\n",
        "0123456789\n",
        "0123456789\n",
        "0123456789\n",
        "0123456789\n",
        "0123456789\n",
        "0123456789\n",
        "0123456789\n",
        "0123456789\n",
    };
    const int size = sizeof(expects) / sizeof(expects[0]);
    return test_with_pc(fd, expects, size, pc);
}

int test_one_with_pc(int fd, int *pc) {
    const char *expects[] = {
        "a",
    };
    const int size = sizeof(expects) / sizeof(expects[0]);
    return test_with_pc(fd, expects, size, pc);
}

int test_only_line_with_pc(int fd, int *pc) {
    const char *expects[] = {
        "\n",
    };
    const int size = sizeof(expects) / sizeof(expects[0]);
    return test_with_pc(fd, expects, size, pc);
}

int test_only_multiline_with_pc(int fd, int *pc) {
    const char *expects[] = {
        "\n",
        "\n",
        "\n",
        "\n",
        "\n",
    };
    const int size = sizeof(expects) / sizeof(expects[0]);
    return test_with_pc(fd, expects, size, pc);
}

int test_singleline_with_pc(int fd, int *pc) {
    const char *expects[] = {
        "123403923"
    };
    const int size = sizeof(expects) / sizeof(expects[0]);
    return test_with_pc(fd, expects, size, pc);
}

int test_singleline_endline_with_pc(int fd, int *pc) {
    const char *expects[] = {
        "123403923\n"
    };
    const int size = sizeof(expects) / sizeof(expects[0]);
    return test_with_pc(fd, expects, size, pc);
}

void print_escape_line(const char *str) {
    if (str == NULL) {
        printf("%s", NULL);
        return ;
    }
    while (*str != '\0')
    {
        if (*str == '\n')
            printf("\\n");
        else
            printf("%c", *str);
        str++;
    }
    return ;
}

int gnl_assert(int fd, const char *tobe) {
    char *result;

    result = get_next_line(fd);
    printf("%d expect: ", fd);
    print_escape_line(tobe);
    printf(" , return ");
    print_escape_line(result);
    printf(" - ");
    if (result == tobe || (result != NULL && tobe != NULL && strcmp(result, tobe) == 0))
        printf("\033[32m" "equal\n" "\033[m");
    else
        printf("\033[31m" "not equal\n" "\033[m");
    free(result);
    return 0;
}

int test_with_pc(int fd, const char *expects[], int size, int *pc) {
    int simple_pos; // -1 : infile, 0 : final, 1 : over

    assert(*pc >= 0);
    simple_pos = 0;
    if (*pc > size - 1) {
        gnl_assert(fd, NULL);
        simple_pos = 1;
    }
    else if (*pc == size - 1) {
        gnl_assert(fd, expects[size - 1]);
        simple_pos = 0;
    }
    else {
        gnl_assert(fd, expects[*pc]);
        simple_pos = -1;
    }
    *pc += 1;
    return (simple_pos);
}
