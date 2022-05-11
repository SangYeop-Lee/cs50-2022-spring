# TODO

def get_number():
    try:
        number = input("Number: ")
        return int(number)
    except ValueError:
        pass

def validate(length, head, number):
    return number.startswith(head) and len(number) in length

while True:
    number = get_number()
    if number:
        number = str(number)
        break

acc = 0
for i, v in enumerate(reversed(number)):
    digit = int(v)
    if i%2:
        digit *= 2
    acc += digit % 10 + digit // 10

if acc % 10:
    print("INVALID")
    exit()

if validate([13, 16], ("4"), number):
    print("VISA")
elif validate([16], ("51", "52", "53", "54", "55"), number):
    print("MASTERCARD")
elif validate([15], ("34", "37"), number):
    print("AMEX")
else:
    print("INVALID")