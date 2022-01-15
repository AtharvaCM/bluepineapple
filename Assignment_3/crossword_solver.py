import re

line = "sea word sky bond headshot skyfall sheer luck of the duck"
words = re.findall(r'[s]\w+', line)

print(words)
