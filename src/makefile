CC = gcc
CFLAGS = -Wall -Wextra -Icontroller -Imodel -Iview -Iutils

SRC = main.c \
      controller/pessoa_controller.c \
      model/pessoa.c \
      view/pessoa_view.c \
      utils/utils.c

OBJ = $(SRC:.c=.o)

program: $(OBJ)
	$(CC) $(OBJ) -o program

clean:
	rm -f $(OBJ) program
