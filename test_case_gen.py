import random

infile = open("testcases/input7.txt", "w")

V = 2500
E = 5000
infile.write(str(V) + " " + str(E) + "\n");

# generate a connected graph
for i in range(V - 1):
    src = i
    dest = random.randrange(src+1, V)
    w = random.randrange(10000)
    infile.write(str(src) + " " + str(dest) + " " + str(w) + "\n")

for i in range(E - V + 1):
    src = random.randrange(V)
    dest = random.randrange(V)
    while (src == dest):
        dest = random.randrange(V)
    w = random.randrange(10000)
    infile.write(str(src) + " " + str(dest) + " " + str(w) + "\n")

infile.close()
