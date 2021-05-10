import sys

filename = sys.argv[1]
with open(filename, 'r') as f:
   text = f.read().replace('\n', '').replace(' ', '')

tagy = ''
pocet_tagu = 0

def nazev_tagu(index):
   nazev = ''
   for j in range(index + 1, len(text) - 1):
      if text[j] == '>':
         break
      else:
         nazev += text[j]
   return nazev


for i in range(len(text)):
   if text[i] == '<':
      tag = nazev_tagu(i)
      if tag[-1] == '/':
         pocet_tagu += 1
         continue
      elif ('/' in tag) == False:
         tagy = tag + tagy
         pocet_tagu += 1
         continue
      elif tag[0] == '/':
         if tag[1:] in tagy[:len(tag) - 1]:
            tagy = tagy.replace(tag[1:], '')
         else:
            print('text nevalidni')
            break


if len(tagy) == 0:
   print(f'pocet tagu: {pocet_tagu}')
   print('text validni')