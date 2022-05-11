# TODO
import re

text = input("Text: ")

letters = len(re.findall(r'[A-z]', text))
words = len(re.findall(' ', text)) + 1
sentences = len(re.findall(r'[\.\!\?]', text))

L = 100 * letters / words
S = 100 * sentences / words

index = 0.0588 * L - 0.296 * S - 15.8
index = int(index)
if index < 1:
    print("Before Grade 1")
elif index > 15:
    print("Grade 16+")
else:
    print(f"Grade {index}")