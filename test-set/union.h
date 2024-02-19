
#ifndef UNION_H
# define UNION_H

int test_empty_with_pc(int fd, int *pc);
int test_empty(int fd);
int test_fazzing_with_pc(int fd, int *pc);
int test_fazzing(int fd);
int test_multiline_with_pc(int fd, int *pc);
int test_multiline(int fd);
int test_multiline_endline_with_pc(int fd, int *pc);
int test_multiline_endline(int fd);
int test_one_with_pc(int fd, int *pc);
int test_one(int fd);
int test_only_line_with_pc(int fd, int *pc);
int test_only_line(int fd);
int test_only_multiline_with_pc(int fd, int *pc);
int test_only_multiline(int fd);
int test_singleline_with_pc(int fd, int *pc);
int test_singleline(int fd);
int test_singleline_endline_with_pc(int fd, int *pc);
int test_singleline_endline(int fd);

#endif
