import sys

vstup = sys.argv[1]

def soudelnost(radek, sloupec):
        for x in range(n, 0, -1):
            if radek % x == 0 and sloupec % x == 0:
                return x

try:
    k = int(vstup)

    if 0 < k < 100:
        for m in range(1, k + 1):
            for n in range(1, k + 1):
                if soudelnost(n, m) > 1:
                    print("x", end="")
                else:
                    print(" ", end="")
                if n != k:
                    print("|", end="")
                else:
                    print("\n", end="")
            if m != k:
                print("-" * ((k * 2) - 1))
    else:
        print("ERROR")
except ValueError:
    print("ERROR")