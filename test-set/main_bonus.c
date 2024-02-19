/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:42:41 by tookuyam          #+#    #+#             */
/*   Updated: 2024/02/05 18:47:51 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include "union.h"

char empty_file[] = "./files/empty.txt";
char fazzing_file[] = "./files/fazzing.txt";
char multiline_file[] = "./files/multiline.txt";
char multiline_endline_file[] = "./files/multiline_endline.txt";
char one_file[] = "./files/one.txt";
char only_line_file[] = "./files/only_line.txt";
char only_multiline_file[] = "./files/only_multiline.txt";
char singleline_file[] = "./files/singleline.txt";
char singleline_endline_file[] = "./files/singleline_endline.txt";

int multi_fd_random_reading();
int test_all_with_pc(int fd, int *pc, int (*f)(int fd, int *pc));
int test_all_and_more_one(int fd, int (*f)(int fd, int *pc));
void print_file_header(const char *file_name, int fd);
void print_footer(int fd);
int single_fd_test_template(const char *filename, int (*f)(int fd, int *pc));

int main() {
    printf("\n\033[33m" "single fd test\n" "\033[m");
    single_fd_test_template(empty_file, test_empty_with_pc);
    single_fd_test_template(fazzing_file, test_fazzing_with_pc);
    single_fd_test_template(multiline_file, test_multiline_with_pc);
    single_fd_test_template(multiline_endline_file, test_multiline_endline_with_pc);
    single_fd_test_template(one_file, test_one_with_pc);
    single_fd_test_template(only_line_file, test_only_line_with_pc);
    single_fd_test_template(only_multiline_file, test_only_multiline_with_pc);
    single_fd_test_template(singleline_file, test_singleline_with_pc);
    single_fd_test_template(singleline_endline_file, test_singleline_endline_with_pc);
    printf("\n\033[33m" "multi fd test\n" "\033[m");
    multi_fd_random_reading();
    return (0);
}

int multi_fd_random_reading() {
    typedef struct {
        char *file_name;
        int (*test_function)(int fd, int *pc);
    } t_template;
    t_template template_files[] = {
        {.file_name = empty_file, .test_function = test_empty_with_pc},
        {.file_name = fazzing_file, .test_function = test_fazzing_with_pc},
        {.file_name = multiline_file, .test_function = test_multiline_with_pc},
        {.file_name = multiline_endline_file, .test_function = test_multiline_endline_with_pc},
        {.file_name = one_file, .test_function = test_one_with_pc},
        {.file_name = only_line_file, .test_function = test_only_line_with_pc},
        {.file_name = only_multiline_file, .test_function = test_only_multiline_with_pc},
        {.file_name = singleline_file, .test_function = test_singleline_with_pc},
        {.file_name = singleline_endline_file, .test_function = test_singleline_endline_with_pc},
    };
    int target_cnt;
    int fd[1000];
    int pc[1000];
    int target_numbers[] = {
        0, 1, 2, 2, 2,
        2,
    };
    srand(time(NULL));
    target_cnt = sizeof(target_numbers) / sizeof(target_numbers[0]);
    for (int i = 0; i < target_cnt; i++)
        pc[i] = 0;
    // ファイルのオープン
    for (int i = 0; i < target_cnt; i++) {
        int no = target_numbers[i];
        fd[i] = open(template_files[no].file_name, O_RDONLY);
        print_file_header(template_files[no].file_name, fd[i]);
    }
    // ランダム処理
    for (int i = 0; i < 20; i++) {
        int target_index = arc4random() % target_cnt;
        int no = target_numbers[target_index];
        template_files[no].test_function(fd[target_index], &pc[target_index]);
    }
    // クローズ
    for (int i = 0; i < target_cnt; i++) {
        close(fd[i]);
        print_footer(fd[i]);
    }
    return (0);
}

int test_all_with_pc(int fd, int *pc, int (*f)(int fd, int *pc)) {
    while (f(fd, pc) <= 0)
        ;
    return (0);
}

int test_all_and_more_one(int fd, int (*f)(int fd, int *pc)) {
    int pc;

    pc = 0;
    test_all_with_pc(fd, &pc, f);
    f(fd, &pc);
    return (0);
}

void print_file_header(const char *file_name, int fd) {
    printf("\n");
    printf("fd: %d ---- %s ----\n", fd, file_name);
}

void print_footer(int fd) {
    printf("close: -------- %d\n", fd);
}

int single_fd_test_template(const char *filename, int (*f)(int fd, int *pc)) {
    int fd;

    fd = open(filename, O_RDONLY);
    print_file_header(filename, fd);
    test_all_and_more_one(fd, f);
    close(fd);
    print_footer(fd);
    return (0);
}
