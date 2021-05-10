import sys

abcd = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" 

filename = sys.argv[1]
with open(filename, 'r') as f:
    kod = f.readline().replace('\n', '')
    org = f.readline()

kod_ok = True
org_ok = True
for letter in kod:
    if not letter in abcd:
        kod_ok = False

for letter in org:
    if not letter in abcd:
        org_ok = False


if kod_ok == False or org_ok == False:
    print('Error: Chybny vstup!')

elif len(kod) != len(org):
    print('Error: Chybna delka vstupu!')

else:
    result_index = 0
    result = ''
    stejna_pismena = 0

    tmp_stejna_pismena = 0
    tmp_vysledek = ''
    for i in range(len(abcd) + 1):
        for letter in kod:
            letter_index = abcd.index(letter)
            try:
                letter = abcd[letter_index + i]
            except IndexError:
                letter = (abcd[letter_index + i - 52])
            tmp_vysledek += letter

        for j in range(10):
            if tmp_vysledek[j] == org[j]:
                tmp_stejna_pismena += 1

        if tmp_stejna_pismena > stejna_pismena:
            stejna_pismena = tmp_stejna_pismena
            result = tmp_vysledek
            result_index = i

        tmp_stejna_pismena = 0
        tmp_vysledek = ''

    with open ('output.txt', 'w') as o:
        o.write(result)
