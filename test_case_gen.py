import random

infile = open("testcases/input1.txt", "w")

V = random.randrange(10000)
E = random.randrange(10000)
infile.write(str(V) + " " + str(E) + "\n");

for i in range(E):
    src = random.randrange(E)
    dest = random.randrange(E)
    while (src == dest):
        dest = random.randrange(E)
    w = random.randrange(10000)
    infile.write(str(src) + " " + str(dest) + " " + str(w) + "\n")

infile.close()
