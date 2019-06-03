from bs4 import BeautifulSoup as bs
import requests
import os

def format_num(num, is_solved=False):
    #s1 = f'<span style="color:{c}">**{num}**</span>'
    if is_solved:
        s2 = f"[{num}](problems/ID{num:03}/problem.md)"
    else:
        s2 = f"[{num}](https://projecteuler.net/problem={num})"
    
    return s2

pdirs = os.listdir('problems/')
inprogress = set()
solved = set()
numsolved = 0
solutions = {}

for prob in pdirs:
    idx = int(prob[2:])
    if os.path.exists(f'problems/{prob}/solution.txt'):
        numsolved = numsolved + 1
        solved.add(idx)
        with open(f'problems/{prob}/solution.txt') as sol:
            solutions[numsolved] = sol.read()
            
    else:
        inprogress.add(idx)       
    
url = 'https://projecteuler.net/recent'
page = requests.get(url)
sp = bs(page.content, 'html.parser')
pnum = int(sp.findAll('td', {'class':'id_column'})[0].text)

readmetemp = ''
with open('management/templates/README.md', 'r') as f:
    readmetemp = f.read()
    
    



r = 100
c = 10

assert r * c >= pnum, f"{r} * {c} ({r * c})  < {pnum} !"
table = ''
for i in range(r):
    if i == 1:
        table = table + '|-' * c + '\n'
    for j in range(c):
        num = c * i + j + 1
        if num <= pnum:
            if num in solved:
                table = table + f"|**{format_num(num, True)}** :white_check_mark:"
            elif num in inprogress:
                table = table + f"|**{format_num(num, True)}** :pencil:"
            else:
                table = table + f"|**{format_num(num)}** :x:"
                
    table = table + '\n'

readmetemp = readmetemp.format(allp=pnum, solved=numsolved, done=f'{numsolved / pnum *100:.2f}', table=table)
with open('README.md', 'w') as f:
    f.write(readmetemp)


with open('solutions.txt', 'w') as f:
    for i in range(pnum):
        if (i + 1) in solutions.keys():
            f.write(f'{i+1:>3}. {solutions[i+1]} \n')
        else:
            f.write(f'{i+1:>3}.\n')