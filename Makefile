# 编译器
CC = gcc
# 编译选项：-g生成调试信息，-Wall显示所有警告
CFLAGS = -g -Wall
# 目标文件
TARGET = contacts
# 源文件
SRCS = main.c contact.c
# 对象文件
OBJS = $(SRCS:.c=.o)

# 编译目标
$(TARGET): $(OBJS)  
	$(CC) $(OBJS) -o $(TARGET)

# 模式规则
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# 清理
clean:
	rm -f *.o $(TARGET)