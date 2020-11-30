import sys
from fractions import Fraction

# filename = "soubor.txt"
filename = sys.argv[1]

with open(filename, "r") as f:
    pol_1 = list(map(Fraction, (f.readline().split())))
    pol_2 = list(map(Fraction, (f.readline().split())))

len1 = len(pol_1)
len2 = len(pol_2)

if len1 < len2:
    pol_1, pol_2 = pol_2, pol_1

pol_vysledek = [0] * (len1 - len2 + 1)

for i in range(len(pol_vysledek)):
    pol_vysledek[-1 - i] = pol_1[-1 - i] / pol_2[-1]
    for j in range(len2):
        pol_1[-1 - i - j] -= pol_vysledek[-1 - i] * pol_2[-1 - j]

for n in pol_vysledek:
    print(n, end= " ")

if all(p == 0 for p in pol_1):
    print("\n0")

else:
    print()
    for m in range(len2 - 1):
        if pol_1[m] != 0:
            print(pol_1[m], end= " ")
        elif any(pol_1[m + 1:]):
            print(pol_1[m], end= " ")
    print()
