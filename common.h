#ifndef __COMMON_H__
#define __COMMON_H__

extern int kbhit(void);
extern const char* dirType(const struct stat *buf);
extern const char* dirTime(struct stat *buf);
extern const char* Time();
extern int dirsize(struct stat *buf);
extern int updatedir(char *saved_dir, char *now_dir, char (*dir_names)[255]);

#endif