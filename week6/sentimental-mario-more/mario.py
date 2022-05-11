# TODO

def get_height():
    height = input("Height: ")
    try:
        height = int(height)
        if 0 < height < 9:
            return height
    except ValueError:
        pass

def print_n_times(ch, iter):
    print(iter * ch, end="")

while True:
    height = get_height()
    if height:
        break

for i in range(height):
    print_n_times(" ", height-i-1)
    print_n_times("#", i+1)
    print_n_times(" ", 2)
    print_n_times("#", i+1)
    print("")